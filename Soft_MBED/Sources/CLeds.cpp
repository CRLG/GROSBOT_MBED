/*! \file CLed.cpp
	\brief Classe qui contient toute l'application
*/
#include "CLeds.h"
#include "mbed.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CLeds::CLeds()
  : m_led1(&_led1),
    m_led2(&_led2),
    m_led3(&_led3),
    m_led4(&_led4)
{
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CLeds::~CLeds()
{

}

//___________________________________________________________________________
 /*!
   \brief Allume ou éteint une ou des LED

   \param led numéro de la LED (ALL_LED pour affecter toutes les LEDs)
   \param state souhaité état de la LED
   \return --
*/
void CLeds::setState(tLed led, bool state)
{
    switch(led) {
        case LED_1 : m_led1.setState(state); break;
        case LED_2 : m_led2.setState(state); break;
        case LED_3 : m_led3.setState(state); break;
        case LED_4 : m_led4.setState(state); break;

        case ALL_LED :
            m_led1.setState(state);
            m_led2.setState(state);
            m_led3.setState(state);
            m_led4.setState(state);
        break;
    }
}

//___________________________________________________________________________
 /*!
   \brief Change l'état d'une ou de toutes les LED

   \param led numéro de la LED (ALL_LED pour affecter toutes les LEDs)
   \return --
*/
void CLeds::toggle(tLed led)
{
    switch(led) {
        case LED_1 : m_led1.toggle(); break;
        case LED_2 : m_led2.toggle(); break;
        case LED_3 : m_led3.toggle(); break;
        case LED_4 : m_led4.toggle(); break;

        case ALL_LED :
            m_led1.toggle();
            m_led2.toggle();
            m_led3.toggle();
            m_led4.toggle();
        break;
    }
}

//___________________________________________________________________________
 /*!
   \brief Traitement périodiques nécessaires à la gestion des LED
   \return --
*/
void CLeds::compute()
{
    m_led1.compute();
    m_led2.compute();
    m_led3.compute();
    m_led4.compute();
}

//___________________________________________________________________________
 /*!
   \brief Initie un pattern sur toutes les LED

   \param pattern_id : le numéro de pattern à jouer parmi ceux prédéfinis
   \param sample_duration : la durée entre 2 échantillons du pattern
   \param num_cylce : le nombre de fois où le pattern doit être répété avant de s'arrêter (INIFINITE) pour jouer le pattern indéfiniment
   \return --
*/
void CLeds::setPattern(tLedPattern pattern_id, unsigned short sample_duration_ms, unsigned short num_cycle)
{
    if (pattern_id >= PATTERNS_MAX_SIZE) return;

    m_led1.setPattern(m_patterns[pattern_id], 0x1, sample_duration_ms, num_cycle);
    m_led2.setPattern(m_patterns[pattern_id], 0x2, sample_duration_ms, num_cycle);
    m_led3.setPattern(m_patterns[pattern_id], 0x4, sample_duration_ms, num_cycle);
    m_led4.setPattern(m_patterns[pattern_id], 0x8, sample_duration_ms, num_cycle);
}

// ============================================================
//        Gestion d'une LED
// ============================================================
CLed::CLed(DigitalOut *led)
{
    m_led = led;
    m_mode = LEDMODE_MANUAL;
}

CLed::~CLed()
{
}

//___________________________________________________________________________
 /*!
   \brief Fixe l'état d'une LED.
   \return --
   \remark en utilisant cette méthode, la LED passe en mode manuel
*/
void CLed::setState(bool state)
{
    *m_led = state;
    m_mode = LEDMODE_MANUAL;
}

//___________________________________________________________________________
 /*!
   \brief Change l'état de la LED
   \return --
*/
void CLed::toggle()
{
    setState( !(*m_led) );
}

//___________________________________________________________________________
 /*!
   \brief Lit l'état de la LED
   \return l'état On/Off de la LED
*/
bool CLed::read()
{
    return *m_led;
}

//___________________________________________________________________________
 /*!
   \brief Passe la LED en mode impulsion
   \param on_duration : la durée à l'état ON de la LED [msec]
   \param off_duration : la durée à l'état OFF de la LED [msec]
   \param num_cycle : le nombre d'impulsions à jouer (INFINIT = indéfiniement)
   \return --
*/
void CLed::setPulse(unsigned short on_duration, unsigned short off_duration, unsigned short num_cycle)
{
    m_on_duration = on_duration;
    m_off_duration = off_duration;
    m_num_cycle = num_cycle;

    m_time = 0;
    m_count = 0;

    m_mode = LEDMODE_PULSE;
}

//___________________________________________________________________________
 /*!
   \brief Passe la LED en mode pattern
   \param pattern : le tableau de valeur à jouer
   \param pattern_mask : le masque à appliquer à la valeur pour définir l'état de la LED (car la même valeur peut représenter l'état de plusieurs LED)
   \param sample_duration : la durée entre 2 échantillons du pattern
   \param num_cycle : le nombre d'impulsions à jouer (INFINIT = indéfiniement)
   \remark dans ce mode, un tableau est joué
   \remark cette fonction ne fait que mémoriser les paramètres du pattern. Il n'est réellement joué que dans la fonction compute
   \return --
*/
void CLed::setPattern(const unsigned char *pattern, unsigned char pattern_mask, unsigned short sample_duration, unsigned short num_cycle)
{
    // Attention : le tableau de valeur n'est pas recopié. On suppose qu'il n'est pas détruit
    // durant le déroulement du pattern
    m_pattern = pattern;
    m_on_duration = sample_duration;   // on utilise m_on_duration pour définir la durée d'un échantillon
    m_pattern_mask = pattern_mask;
    m_num_cycle = num_cycle;

    m_time = 0;
    m_count = 0;
    m_index_array = 0;

    m_mode = LEDMODE_PATTERN;
}

//___________________________________________________________________________
 /*!
   \brief Gestion périodique de la LED
   \return --
   \remark pour gérer l'état de la LED dans les modes PULSE et PATTERN, il est
            nécessaire d'appeler périodiquement cette fonction
*/
void CLed::compute()
{
    switch(m_mode)
    {
        // ________________________________________________
        case LEDMODE_PULSE :
            //   |-------------|__________________________|-------------|___________
            //   < on_duration ><       off_duration      >
            if (m_time < m_on_duration) *m_led = 1;
            else *m_led = 0;
            if (m_time >= (m_on_duration + m_off_duration)) {
                if (m_num_cycle != INFINITE) m_count++;
                if (m_count >= m_num_cycle) {
                    setState(0);  // repasse en mode manuel LED éteinte
                }
                else {  // Recommence un cycle
                    m_time = 0;
                }
            }
            else {
                m_time += LED_REFRESH_PERIOD;
            }
        break;
        // ________________________________________________ Joue le pattern passé en paramètre
        case LEDMODE_PATTERN:
            if (m_time == 0) {
                *m_led =m_pattern[m_index_array] & m_pattern_mask;  // la LED prend la valeur du tableau à l'index courant
            }
            m_time += LED_REFRESH_PERIOD;
            if (m_time > m_on_duration) {  // il est l'heure de changer d'index
                m_time = 0;
                if (m_pattern[m_index_array+1] != 0xFF) m_index_array++;
                else {
                    m_index_array = 0;
                    if (m_num_cycle != INFINITE) m_count++;  // Refait le cycle ou termine
                    if (m_count >= m_num_cycle) {
                        setState(0);  // repasse en mode manuel LED éteinte
                    }
                }
            }
        break;
        // ________________________________________________
        default :
            // ne rien faire
        break;
    }
}
