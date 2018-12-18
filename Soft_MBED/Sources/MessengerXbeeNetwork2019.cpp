#include "MessengerXbeeNetwork2019.h"
#include "messagebase.h"
#include "CGlobale.h"

MessengerXbeeNetwork::MessengerXbeeNetwork()
{
    init(&m_transporter, &m_database);
    m_database.m_TimestampMatch.setTransmitPeriod(100);
}

MessengerXbeeNetwork::~MessengerXbeeNetwork()
{
}

// ______________________________________________
void MessengerXbeeNetwork::start()
{
    while (_rs232_xbee_network_rx.readable()) _rs232_xbee_network_rx.getc(); // Nettoie tout octet en attente dans le buffer
    m_database.restart();
    _rs232_xbee_network_rx.attach(this, &MessengerXbeeNetwork::IRQ_ReceiveRS232);  	// Callback sur réception d'une donnée sur la RS232
}
// ______________________________________________
void MessengerXbeeNetwork::stop()
{
    _rs232_xbee_network_rx.attach(NULL); // Supprime l'IRQ sur réception RS232
}

// ______________________________________________
void MessengerXbeeNetwork::IRQ_ReceiveRS232()
{
    char rxData;
    rxData = _rs232_xbee_network_rx.getc();
    decode(rxData);
}

// ______________________________________________
void MessengerXbeeNetwork::execute()
{
    // RX messages
    if (m_database.m_ExperienceStatus.isNewMessage()) {
        Application.m_leds.toggle(LED_1);  // pour essayer
        // ....
    }
    // TX messages
    int current_time = _Global_Timer.read_ms();
    if (m_database.m_TimestampMatch.isTimeToSend(current_time)) {
        m_database.m_TimestampMatch.Timestamp+= 10;
        m_database.m_TimestampMatch.send();
    }
}

// ===================================================
//              MESSENGER OUTPUT
// ===================================================
// ______________________________________________
void MessengerXbeeNetwork::encode(unsigned char *buff_data, unsigned short buff_size, unsigned short dest_address)
{
    for (int i=0; i< buff_size; i++) {
        _rs232_xbee_network_tx.putc(buff_data[i]);
    }
}

// ===================================================
//                  MESSENGER EVENTS
// ===================================================
// ______________________________________________
void MessengerXbeeNetwork::newFrameReceived(tMessengerFrame *frame)
{
    //Application.m_leds.toggle(LED_1);
}

// ______________________________________________
void MessengerXbeeNetwork::newMessageReceived(MessageBase *msg)
{
    //Application.m_leds.toggle(LED_2);
}

// ______________________________________________
void MessengerXbeeNetwork::frameTransmited(tMessengerFrame *frame)
{
}

// ______________________________________________
void MessengerXbeeNetwork::messageTransmited(MessageBase *msg)
{
}

// ______________________________________________
void MessengerXbeeNetwork::dataUpdated(char *name, char *val_str)
{
    //Application.m_leds.toggle(LED_3);
}

// ______________________________________________
void MessengerXbeeNetwork::dataChanged(char *name, char *val_str)
{
    //Application.m_leds.toggle(LED_4);
}


// ===================================================
//                  LOCAL METHODS
// ===================================================
// ______________________________________________
void MessengerXbeeNetwork::test_RX()
{
    // Simulate data reception
    // Message_TIMESTAMP_MATCH : ID 0x0001
    unsigned char data[] = { 'T', 0x00, 0x01, 0x02, 0x00, 0x11, 0x14 };
    for (unsigned int i=0; i<sizeof(data);  i++) {
        decode(data[i]);
    }
}

void MessengerXbeeNetwork::test_TX()
{
    // Send message
    Message_EXPERIENCE_STATUS *msg = &m_database.m_ExperienceStatus;
    msg->ExperienceStatus = 0xABCD;
    m_database.m_ExperienceStatus.setDestinationAddress(98);
    msg->send();
    m_database.m_ExperienceStatus.setDestinationAddress(95);  // send once again to another destination
    msg->send();
}
