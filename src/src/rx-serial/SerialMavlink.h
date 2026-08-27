#include "FIFO.h"
#include "SerialIO.h"

// Keep FIFOs modest on ESP32-C3 (less SRAM than ESP32/S3).
#if defined(PLATFORM_ESP32_C3)
#define MAV_INPUT_BUF_LEN   512
#define MAV_OUTPUT_BUF_LEN  256
#else
#define MAV_INPUT_BUF_LEN   1024
#define MAV_OUTPUT_BUF_LEN  512
#endif

class SerialMavlink : public SerialIO {
public:
    explicit SerialMavlink(Stream &out, Stream &in);
    virtual ~SerialMavlink() {}

    void queueLinkStatisticsPacket() override {}
    void queueMSPFrameTransmission(uint8_t* data) override {}
    uint32_t sendRCFrame(bool frameAvailable, bool frameMissed, uint32_t *channelData) override;

    int getMaxSerialReadSize() override;
    void sendQueuedData(uint32_t maxBytesToSend) override;

    void forwardMessage(const uint8_t *data);
    bool GetNextPayload(uint8_t *nextPayloadSize, uint8_t *payloadData);

private:
    void processBytes(uint8_t *bytes, u_int16_t size) override;

    const uint8_t this_system_id;
    const uint8_t this_component_id;

    const uint8_t target_system_id;
    const uint8_t target_component_id;

    uint32_t lastSentFlowCtrl = 0;

    // Variables / constants for Mavlink //
    FIFO<MAV_INPUT_BUF_LEN> mavlinkInputBuffer;
    FIFO<MAV_OUTPUT_BUF_LEN> mavlinkOutputBuffer;
};
