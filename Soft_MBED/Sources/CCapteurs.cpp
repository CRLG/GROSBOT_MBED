/*! \file CCapteurs.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "RessourcesHardware.h"
#include "CGlobale.h"
#include "CCapteurs.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CCapteurs::CCapteurs() 
{
  m_compteurErrCom_dsPIC1 = 0;
  m_compteurErrCom_dsPIC2 = 0;
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CCapteurs::~CCapteurs() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialisation du module capteur

   \param --
   \return --
*/
void CCapteurs::Init(void)
{
 // Active les pulls up sur les entrées
  _Etor1.mode(PullUp);
  _Etor2.mode(PullUp);
  //_Etor3.mode(PullUp);
  _Etor4.mode(PullUp);
  _Etor5.mode(PullUp);
  _Etor6.mode(PullUp);
  _Etor_CanRx.mode(PullUp);
  _Etor_CanTx.mode(PullUp);
  //Init_CapteurCouleur();
}


//___________________________________________________________________________
 /*!
   \brief Acquisition et filtrage des capteurs

   \param --
   \return --
   \remark cette fonction est a appeler periodiquement par l'applicatif
*/
void CCapteurs::Traitement(void)
{
  Lecture_dsPIC1();
  Lecture_dsPIC2();
  AcquisitionEntreesTOR();
  AcquisitionEntreesANA();

  TraitementTensionBatterie();
  TraitementTelemetresUltrason();
  //TraitementDepartMatch();
  //TraitementCapteurRecalageBordure();

  //Lecture_CapteurCouleur();
}


//___________________________________________________________________________
 /*!
   \brief Acquisition des entrées TOR brutes

   \param --
   \return --
*/
void CCapteurs::AcquisitionEntreesTOR(void)
{
  m_b_Etor1 		= _Etor1.read();
  m_b_Etor2 		= _Etor2.read();
  m_b_Etor3 		= _Stor3.read(); // Attention, c'est une sortie
  m_b_Etor4 		= _Etor4.read();
  m_b_Etor5 		= _Etor5.read();
  m_b_Etor6 		= _Etor6.read();
  m_b_Etor_CanRx 	= _Etor_CanRx.read();
  m_b_Etor_CanTx 	= _Etor_CanTx.read();
}


//___________________________________________________________________________
 /*!
   \brief Acquisition des entrées TOR brutes

   \param --
   \return --
*/
void CCapteurs::AcquisitionEntreesANA(void)
{
  m_b_Mes_Vbat    = _Mes_Vbat.read() * TENSION_REF_EANA_MBED;
  m_b_Eana1       = _Eana1.read() * TENSION_REF_EANA_MBED;
  m_b_Eana2       = _Eana2.read() * TENSION_REF_EANA_MBED;
  m_b_Eana3       = _Eana3.read() * TENSION_REF_EANA_MBED;
  m_b_Eana4       = _Eana4.read() * TENSION_REF_EANA_MBED;
  m_b_Eana5       = _Eana5.read() * TENSION_REF_EANA_MBED;
}


//___________________________________________________________________________
 /*!
   \brief Traitement pour la mesure de la tension batterie

   \param --
   \return --
*/
void CCapteurs::TraitementTensionBatterie(void)
{
  m_tension_batterie = (m_b_Mes_Vbat / 0.17543859649) + 0.76;
  m_alerte_batterie_faible = Hysterisis(m_tension_batterie, &m_alerte_batterie_faible, SEUIL_TENSION_BATT_FAIBLE, SEUIL_TENSION_BATT_FAIBLE+3, 1, 0);
}


//___________________________________________________________________________
 /*!
   \brief Acquisition et filtrage des capteurs de recalage bordure

   \param --
   \return --
*/
void CCapteurs::TraitementCapteurRecalageBordure(void)
{
  //static unsigned char cptRecalageAVD=0;
  //static unsigned char cptRecalageAVG=0;
  
  m_recalage_AVD = !_Etor1.read();
  m_recalage_AVG = !_Etor2.read();
}




//___________________________________________________________________________
 /*!
   \brief Lecture des données du dsPIC1

   \param --
   \return --
*/
void CCapteurs::Lecture_dsPIC1(void)
{
  unsigned char checksum=0;
  unsigned char i;

  //m_buff[0] = 0x5A;
  //m_buff[1] = 0x12;
  //_i2c.write(ADRESSE_I2C_dsPIC1, m_buff, 2);
  //m_buff[15] = 0;

  m_buff[8] = 0xFF; // Pour être certain de ne pas conserver un bon checksum du coup d'avant
  _i2c.read(ADRESSE_I2C_dsPIC1, m_buff, 9);
  // Calcul le checksum à partir des données reçues
  for (i=0; i<8; i++) {
    checksum+= m_buff[i];
  }

  // Ne prend en compte les données reçues que si le checksum est bon
  if (checksum == m_buff[8]) {
    //_led2 = 1;
    m_CodeurPosition1 = (signed short)(m_buff[1] + (m_buff[0]<<8));
    m_CodeurPosition2 = (signed short)(m_buff[3] + (m_buff[2]<<8));
    
    m_b_Eana6 = m_buff[4] * COEF_TENSION_ANA_dsPIC;
    m_b_Eana7 = m_buff[5] * COEF_TENSION_ANA_dsPIC;
    m_b_Eana8 = m_buff[6] * COEF_TENSION_ANA_dsPIC;
    m_b_Eana9 = m_buff[7] * COEF_TENSION_ANA_dsPIC;
    
    m_CumulCodeurPosition1 += m_CodeurPosition1;
    m_CumulCodeurPosition2 += m_CodeurPosition2;
  }
  else {
    //_led2 = 0;
    m_compteurErrCom_dsPIC1++;
  }
}


//___________________________________________________________________________
 /*!
   \brief Lecture des données du dsPIC1

   \param --
   \return --
*/
void CCapteurs::Lecture_dsPIC2(void)
{
  unsigned char checksum=0;
  unsigned char i;
  
  m_buff[8] = 0xFF; // Pour être certain de ne pas conserver un bon checksum du coup d'avant
  _i2c.read(ADRESSE_I2C_dsPIC2, m_buff, 9);
  // Calcul le checksum à partir des données reçues
  for (i=0; i<8; i++) {
    checksum+= m_buff[i];
  }

  // Ne prend en compte les données reçues que si le checksum est bon
  if (checksum == m_buff[8]) {
    //_led4 = 1;
    m_CodeurPosition3 = (signed short)(m_buff[1] + (m_buff[0]<<8));
    m_CodeurPosition4 = (signed short)(m_buff[3] + (m_buff[2]<<8));
    
    m_b_Eana10 = m_buff[4] * COEF_TENSION_ANA_dsPIC;
    m_b_Eana11 = m_buff[5] * COEF_TENSION_ANA_dsPIC;
    m_b_Eana12 = m_buff[6] * COEF_TENSION_ANA_dsPIC;
    m_b_Eana13 = m_buff[7] * COEF_TENSION_ANA_dsPIC;
    
    m_CumulCodeurPosition3 += m_CodeurPosition3;
    m_CumulCodeurPosition4 += m_CodeurPosition4;
  }
  else {
    //_led4 = 0;
    m_compteurErrCom_dsPIC2++;
  }
}

//___________________________________________________________________________
 /*!
   \brief Initialisation d'un codeur a une position donnee (valeur par défaut 0)

   \param --
   \return --
*/
void CCapteurs::RAZ_PositionCodeur(unsigned char num_codeur, signed long val /*=0*/)
{
  switch(num_codeur) {
    case CODEUR_1 : m_CumulCodeurPosition1 = val;   break;
    case CODEUR_2 : m_CumulCodeurPosition2 = val;   break;
    case CODEUR_3 : m_CumulCodeurPosition3 = val;   break;
    case CODEUR_4 : m_CumulCodeurPosition4 = val;   break;
    default : /* ne rien faire */                   break;
  }
}

//___________________________________________________________________________
 /*!
   \brief Acquisition et filtrage des capteurs du suiveur de ligne

   \param --
   \return --
*/
void CCapteurs::TraitementDepartMatch(void)
{
  static unsigned int cptAvantDebutMatch=0;
  static unsigned int cptConfirmationTirette=0;
/* 
  if (_Etor3.read()) {
  	if (cptConfirmationTirette < 0xFFFF) { cptConfirmationTirette++; }
  }
  else {
 	cptConfirmationTirette = 0;
  }
*/ 
  // Met en forme une information pour le match
  // Comme Minibot n'a pas de tirette mais se sert du fait que 
  // GrosBot est parti pour partir à son tour, il ne faut pas que Minibot
  // parte dès qu'on met l'alimentation.
  // Cette tempo permet de laisser le temps de positionner Minibot correctement
  if (cptAvantDebutMatch<0xFFFF) { cptAvantDebutMatch++; }
  DepartMatch = (cptConfirmationTirette > TEMPO_100msec) && (cptAvantDebutMatch > TEMPO_5sec);
 
  //_led3 = _Etor3.read();
}


//___________________________________________________________________________
 /*!
   \brief Acquisition et filtrage des capteurs du suiveur de ligne

   \param --
   \return --
*/
#define COEF_TELEMETRE_ULTRASON (3.3 * 259.183)   // TODO : ajuster le coeff pour transformer en cm
void  CCapteurs::TraitementTelemetresUltrason(void)
{
  m_telemetres.Traitement();

  // Todo : appliquer un filtrage / une calibration automatique / une comparaison entre capteurs
  // Loi de commande : 9.8mV/inch = 9.8mV/2.54mm
  // resultat en cm
  //m_ultrason_AR = MoyenneGlissante_float(_Eana1.read() * COEF_TELEMETRE_ULTRASON, m_tabFiltUS_AV, NBRE_ECH_FILTRAGE_CAPTEURS_US);
  //m_ultrason_AV = MoyenneGlissante_float(_Eana2.read() * COEF_TELEMETRE_ULTRASON, m_tabFiltUS_AR, NBRE_ECH_FILTRAGE_CAPTEURS_US);

  // Confirme la présence d'un obstacle
  m_obstacleDetecte_AR = Hysterisis(m_ultrason_AR, &m_obstacleDetecte_AR, SEUIL_CM_DETECTION_OBSTACLE-3, SEUIL_CM_DETECTION_OBSTACLE+3, 1, 0);
  m_obstacleDetecte_AV = Hysterisis(m_ultrason_AV, &m_obstacleDetecte_AV, SEUIL_CM_DETECTION_OBSTACLE-3, SEUIL_CM_DETECTION_OBSTACLE+3, 1, 0);

}


// _____________________________________________________
/*!
   \brief Calcul la moyenne glissante sur un nombre donné d'échantillon pour des données de type char
    \param currentVal : le dernier echantillon recu
    \param *old_samples : le tableau des échantillons précédents
    \param samplesNumbers : le nombre d'echantillons pour le calcul la moyenne glissante
    \return La valeur moyenne entre le dernier echantillon recu et les (nbreEchantillonsMoyenne)  precedents echantillons
  
    \remarks La moyenne se fait sur "samplesNumbers" valeurs : 
			- L'echantillons courant currentVal
			- Les (samplesNumbers-1) echantillons precedents
			Le tableau old_sanmples doit donc avoir une taille de (samplesNumber - 1) valeurs
*/
float CCapteurs::MoyenneGlissante_float(float currentVal, float *buf_oldSamples, unsigned int samplesNumbers)
{
  float moy=currentVal;
  int i=0;  // Attention : doit être un "int" et non un "unsigned int" à cause du test de fin dans le "for"
  
  // Traite tous les échantillons sauf le 1er (index 0 du tableau) qui est un cas particulier
  for (i=(samplesNumbers-2); i>0; i--) {
	  moy = moy + buf_oldSamples[i];
	  buf_oldSamples[i] = buf_oldSamples[i-1];
  }
  
  // Cas particulier pour la 1ère case du tableau où la nouvelle valeur ne provient pas de l'index précédent du tableau mais du nouvel échantillon
  moy = moy + buf_oldSamples[0];
  buf_oldSamples[0] = currentVal;
  
  moy = moy / (float)samplesNumbers;
  
  return(moy);
}


// _____________________________________________________
/*!
   \brief Gestion d'un hysterisis
    \param vin le signal d'entree
    \param *etat la valeur precedente de la sortie
    \param swapOff le seuil de basculement vers inactif
    \param swapOn le seuil de basculement vers actif
    \param valOff la valeur de la sortie a l'etat inactif
    \param valOn la valeur de la sortie a l'etat actif

    \return la valeur de la sortie apres passage dans l'hysterisis
   
    \remarks
*/
unsigned char CCapteurs::Hysterisis (float vin, unsigned char *etat, float swapOff, float swapOn, unsigned char valOff, unsigned char valOn)
{
    if (vin <= swapOff) { // seuil bas
        *etat = valOff;
    } else if (vin >= swapOn) { // seuil haut
        *etat = valOn;
    } else {
        //on ne fait rien
    }
    if (*etat == 0xFF) { // cas d'init
        *etat = valOff;
    } // else on ne fait rien
    return *etat;
}

void CCapteurs::Init_CapteurCouleur(void){
	m_color_sensor_OK=false;
	// Connect to the Color sensor and verify the connection
	char id_regval[1] = {0x92};
	char data[1] = {0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,id_regval,1);
	_i2c.read(ADRESSE_I2C_COLOR_SENSOR,data,1);

	//hack the init with led2
	if ((data[0] != 0x44) && (data[0] != 0x10))
	  {
		m_color_sensor_OK=false;
		/*for(int j=0;j<5;j++){
						_led2 = 0;
						wait_ms (1000);
						_led2 = 1;
						wait_ms (1000);
						}*/
	  }
	else{

		m_color_sensor_OK=true;
		/*for(int j=0;j<10;j++){
				_led2 = 0;
				wait_ms (500);
				_led2 = 1;
				wait_ms (500);
				}*/
	}
	/*if (data[0]==68)
	{
		for(int j=0;j<10;j++){
		_led2 = 0;
		wait_ms (500);
		_led2 = 1;
		wait_ms (500);
		}
	}
	else{
		for(int j=0;j<5;j++){
				_led2 = 0;
				wait_ms (1000);
				_led2 = 1;
				wait_ms (1000);
				}
	}*/

	// Initialize color sensor

	char timing_register[2] = {0x81,0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,timing_register,2);

	char control_register[2] = {0x8F,0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,control_register,2);

	char enable_register[2] = {0x80,0x03};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,enable_register,2);
}

void CCapteurs::Lecture_CapteurCouleur(void)
{
	// Read data from color sensor (Clear/Red/Green/Blue)
	// TODO connect the led to a digitalout and enable it

/*
#define TCS34725_COMMAND_BIT      (0x80)

#define TCS34725_ENABLE           (0x00)
#define TCS34725_AILTL            (0x04)    // Clear channel lower interrupt threshold
#define TCS34725_AILTH            (0x05)
#define TCS34725_AIHTL            (0x06)    // Clear channel upper interrupt threshold
#define TCS34725_AIHTH            (0x07)
#define TCS34725_CONFIG           (0x0D)
#define TCS34725_CONFIG_WLONG     (0x02)    //Choose between short and long (12x) wait times via TCS34725_WTIME
#define TCS34725_CONTROL          (0x0F)    // Set the gain level for the sensor
#define TCS34725_ID               (0x12)    // 0x44 = TCS34721/TCS34725, 0x4D = TCS34723/TCS34727
#define TCS34725_STATUS           (0x13)
#define TCS34725_STATUS_AINT      (0x10)    // RGBC Clean channel interrupt
#define TCS34725_STATUS_AVALID    (0x01)    // Indicates that the RGBC channels have completed an integration cycle
#define TCS34725_CDATAL           (0x14)    // Clear channel data
#define TCS34725_CDATAH           (0x15)
#define TCS34725_RDATAL           (0x16)    // Red channel data
#define TCS34725_RDATAH           (0x17)
#define TCS34725_GDATAL           (0x18)    // Green channel data
#define TCS34725_GDATAH           (0x19)
#define TCS34725_BDATAL           (0x1A)    // Blue channel data
#define TCS34725_BDATAH           (0x1B)
*/
	//clear register
	char clear_reg[1] = {0x94};
	char clear_data[2] = {0,0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,clear_reg,1);
	_i2c.read(ADRESSE_I2C_COLOR_SENSOR,clear_data,2);

	int clear_value = ((int)clear_data[1] << 8) | clear_data[0];

	//get red value
	char red_reg[1] = {0x96};
	char red_data[2] = {0,0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,red_reg,1);
	_i2c.read(ADRESSE_I2C_COLOR_SENSOR,red_data,2);

	m_color_sensor_R = ((int)red_data[1] << 8) | red_data[0];

	//get green value
	char green_reg[1] = {0x98};
	char green_data[2] = {0,0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,green_reg,1);
	_i2c.read(ADRESSE_I2C_COLOR_SENSOR,green_data,2);

	m_color_sensor_G = ((int)green_data[1] << 8) | green_data[0];

	//get blue value
	char blue_reg[1] = {0x9A};
	char blue_data[2] = {0,0};
	_i2c.write(ADRESSE_I2C_COLOR_SENSOR,blue_reg,1);
	_i2c.read(ADRESSE_I2C_COLOR_SENSOR,blue_data,2);

	m_color_sensor_B = ((int)blue_data[1] << 8) | blue_data[0];

	// print sensor readings
	//pc.printf("Clear (%d), Red (%d), Green (%d), Blue (%d)\n", clear_value, red_value, green_value, blue_value);
}




