/*! \file CTelemetres.cpp
	\brief Classe qui contient les m�thodes pour le dialogue avec la capteur ultrason SRF08
*/
#include "RessourcesHardware.h"
#include "CTelemetres.h"
// ------------------------------------------------------
// Variables globales du fichier


unsigned char SRF08_buf[3];
// ------------------------------------------------------
// Variables globales externes

// ------------------------------------------------------
// Prototypes des fonctions externes

// ------------------------------------------------------
// Prototypes des fonctions locales


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CTelemetres::CTelemetres() 
{
 
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CTelemetres::~CTelemetres() 
{

}


//___________________________________________________________________________
 /*!
   \brief Configuration

   \param --
   \return --
*/
void CTelemetres::Config(void)
{
 unsigned char i=0;

 for (i=0; i<NOMBRE_TELEMETRES; i++) {
  // Suppose que adresses I2C des capteurs sont configur�es pour se suivre
  m_adresseI2C[i] = ADRESSE_SRF08_BASE + (i*2); 
  WriteRegister(m_adresseI2C[i], SRF08_reg_RANGE, SRF08_RESOLUTION_MAX); // R�solution max  de 46*0.043m + 0.043m = 2m�tres environ  
  WriteRegister(m_adresseI2C[i], SRF08_reg_MAX_GAIN, SRF08_MAX_GAIN);    // R�solution max  de 100*0.043m = 4.3m�tres environ  
 }
 // Initialise la machine d'�tat
 m_numSRF08 = 0;
}


//___________________________________________________________________________
 /*!
   \brief Traitement

   \param --
   \return --
   \remark la gestion des capteurs a ultrasons doit se faire de mani�re s�quentielle
   c'est � dire que la mesure de distance est lanc�e sur un capteur puis � la s�quence
   d'apr�s sur l'autre et ainsi de suite.
   La p�riode d'appel de cette fonction doit �tre calibr�e pour que l'�cho ultrason de la 
   pr�c�dente mesure soit revenu avant de lancer une mesure sur un nouveau capteur.
   Cette m�thode permet d'�viter les perturbations mutuelles d'un capteur sur l'autre.
*/
void CTelemetres::Traitement(void)
{
  static unsigned char tempoBootSRF08 = 0;
  unsigned int ui_tmp=0;
  unsigned char index;
  
  // Permet de s'assurer que le capteur a boot� avant de commencer les mesures (probl�me de blocage constat� en pratique) 
  if (tempoBootSRF08 < 10) {
    tempoBootSRF08++;
    if (tempoBootSRF08 == 7) {  // Une fois boot�, on envoie la config au SRF et on laisse un petit temps avant les mesures
        Config();
    }    
    return;   // Ne fait pas les mesures durant le temps de boot des SRF08
  }         
  
  // Lit les informations du dernier capteur
  if (m_numSRF08 == 0) {
    index = NOMBRE_TELEMETRES - 1;
  } 
  else {
    index = m_numSRF08-1;
  }
  m_buff[0] = SRF08_reg_1st_ECHO_MSB;
  _i2c.write(m_adresseI2C[index], m_buff, 1); // S�lectionne l'adresse � lire
  _i2c.read(m_adresseI2C[index], m_buff, 2);
  ui_tmp = (((unsigned int)m_buff[0])<<8) + ((unsigned int)m_buff[1]);
  if (ui_tmp > 1) {  // Patch pour �liminer les situations o� d'un seul coup, la mesure passe � "0" pendant quelques �chantillons -> pas de mise � jour de la donn�e sur le CAN si valeur erron�e
        m_distance[index] = ui_tmp;
  }
  
  // Lance la mesure pour le t�l�m�tre suivant
  WriteRegister(m_adresseI2C[index], SRF08_reg_COMMAND, SRF08_MEASURE_CM);

  // Passe au capteur suivant
  m_numSRF08++;
  if (m_numSRF08 >= NOMBRE_TELEMETRES) { m_numSRF08 = 0; }
}


//___________________________________________________________________________
 /*!
   \brief Ecrit dans un registre

   \param --
   \return --
*/
void CTelemetres::WriteRegister(unsigned char add, unsigned char reg, unsigned char val)
{
  m_buff[0] = reg;
  m_buff[1] = val;
  _i2c.write(add, m_buff, 2);
}




   
// -------------------------------------------------------
// S�quence � respecter tel d�crit dans la spec
void CTelemetres::ChangeAdresse(unsigned char oldAdd, unsigned char newAdd)
{
   WriteRegister(oldAdd, SRF08_reg_COMMAND, 0xA0);
   WriteRegister(oldAdd, SRF08_reg_COMMAND, 0xAA);
   WriteRegister(oldAdd, SRF08_reg_COMMAND, 0xA5);
   WriteRegister(oldAdd, SRF08_reg_COMMAND, newAdd);
}    



// END

