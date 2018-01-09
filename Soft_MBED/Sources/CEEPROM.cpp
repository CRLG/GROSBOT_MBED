/*! \file CEEPROM.cpp
	\brief Classe qui contient les méthoes pour la simulation EEPROM
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"
//#include <sys/string.h>


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CEEPROM::CEEPROM() 
{
 // Commence par lire le fichier d'entrée et affecter les valeurs de certaines données membres des claasses

 m_configFile.read("/local/eeprom.ini");
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CEEPROM::~CEEPROM() 
{

}


//___________________________________________________________________________
 /*!
   \brief Lit le fichier de parametrage	et renseigne les variables en RAM de l'application

   \param --
   \return --
*/
void CEEPROM::Read(void)
{
	 // Lit les paramèrtes de l'EEPROM et initialise les valeurs
	 // valeurs pour le module Globale
//    char *key;
//    key=strdup("ModeFonctionnement");
//    getValue(key, &Application.ModeFonctionnement);
//    free(key);
//    key=NULL;
     getValue("ModeFonctionnement", &Application.ModeFonctionnement);
	
	
	 // valeurs pour le module Asservissement
	getValue("cde_max", &(Application.m_asservissement.cde_max));
	getValue("cde_min", &(Application.m_asservissement.cde_min));
	getValue("kp_distance", &(Application.m_asservissement.kp_distance));
	getValue("ki_distance", &(Application.m_asservissement.ki_distance));
	getValue("kp_angle", &(Application.m_asservissement.kp_angle));
	getValue("ki_angle", &(Application.m_asservissement.ki_angle));
	getValue("k_angle", &(Application.m_asservissement.k_angle));
	getValue("seuil_conv_distance", &(Application.m_asservissement.seuil_conv_distance));
	getValue("seuil_conv_angle", &(Application.m_asservissement.seuil_conv_angle));
	getValue("compteur_max", &(Application.m_asservissement.compteur_max));
	getValue("zone_morte_D", &(Application.m_asservissement.zone_morte_D));
	getValue("zone_morte_G", &(Application.m_asservissement.zone_morte_G));

	getValue("rackCommandeMax", &(Application.m_asservissement_chariot.commande_chariot_max_C));
	getValue("rackGainPosVit", &(Application.m_asservissement_chariot.gain_position_vitesse_C));
	getValue("rackGainP", &(Application.m_asservissement_chariot.gain_prop_C));
	getValue("rackGainI", &(Application.m_asservissement_chariot.gain_int_C));
	getValue("rackSeuilConv", &(Application.m_asservissement_chariot.seuil_conv_C));
    getValue("rackZMdw", &(Application.m_asservissement_chariot.compensation_zone_morte_dw_C));
    getValue("rackZMup", &(Application.m_asservissement_chariot.compensation_zone_morte_up_C));
    getValue("rackGradVit", &(Application.m_asservissement_chariot.offset_vitesse_max_C));


}
	



//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, float *val)
{
  bool ret = false;
   
  if (m_configFile.getValue(key, &value[0], sizeof(value))) {
	sscanf(value, "%f", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}


//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, long *val)
{
  bool ret = false;

   if (m_configFile.getValue(key, &value[0], sizeof(value))) {
    sscanf(value, "%d", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}


//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, unsigned int *val)
{
  bool ret = false;
  			 
  if (m_configFile.getValue(key, &value[0], sizeof(value))) {
    sscanf(value, "%d", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}

//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, int *val)
{
  bool ret = false;
				 
  if (m_configFile.getValue(key, &value[0], sizeof(value))) {
	sscanf(value, "%d", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}


//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, char *val)
{
  bool ret = false;

  if (m_configFile.getValue(key, &val[0], sizeof(value))) {
	// pas de recopie, la valeur est rangée directement dans val
	ret= true;  // La donnée existe
  }
  return(ret);
}

bool CEEPROM::setValue(char *key, float val)
{
  bool ret = false;
  char tampon[10];
   sprintf(tampon,"%f",val);
   //todo mettre le flottant dans la chaine de caractere
   
	if (m_configFile.setValue(key, tampon)){
		if (m_configFile.write("/local/eeprom.ini")) 
			ret= true;  // La donnee a ete ecrite
		else
			ret=false;
	}
  
  return(ret);
}
bool CEEPROM::setValue(char *key, short val)
{
  bool ret = false;
  char tampon[10];
   sprintf(tampon,"%hd",val);
   //todo mettre le flottant dans la chaine de caractere
   
	if (m_configFile.setValue(key, tampon)){
		if (m_configFile.write("/local/eeprom.ini")) 
			ret= true;  // La donnee a ete ecrite
		else
			ret=false;
	}
  
  return(ret);
}
bool CEEPROM::setValue(char *key, unsigned short val)
{
  bool ret = false;
  char tampon[10];
   sprintf(tampon,"%hu",val);
   //todo mettre le flottant dans la chaine de caractere
   
	if (m_configFile.setValue(key, tampon)){
		if (m_configFile.write("/local/eeprom.ini")) 
			ret= true;  // La donnee a ete ecrite
		else
			ret=false;
	}
  
  return(ret);
}
//todo: ecriture en eeprom en fin de programme et les fonctions d'ecriture pour les autres types de donnees
 

