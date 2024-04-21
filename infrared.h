#include <IRremote.h>
#include <IRremote.h>
#include <IRremoteInt.h>

#define MAGIQUEST_PERIOD     1150
#define MAGIQUEST_MARK_ZERO  280
#define MAGIQUEST_SPACE_ZERO 850
#define MAGIQUEST_MARK_ONE   580
#define MAGIQUEST_SPACE_ONE  600
#define ERR 0
#define DECODED 1



union magiquest {
  uint64_t llword;
  uint8_t    byte[8];
  uint32_t  lword[2];
  struct {
    uint16_t magnitude;
    uint32_t wand_id;
    uint8_t  padding;
    uint8_t  scrap;
  } cmd ;
} ;

int recv_pin = D0;
IRrecv irrecv(recv_pin);
decode_results results;
magiquest data;

void setupInfrared() {
    irrecv.enableIRIn();
}

void debugIRData(magiquest data) {
    Serial.println("");
    Serial.print("wand_id: ");
    Serial.print(data.cmd.wand_id);
    Serial.print(" | scrap: ");
    Serial.print(data.cmd.scrap);
    Serial.print(" | padding: ");
    Serial.print(data.cmd.padding);
    Serial.print(" | magnitude: ");
    Serial.println(data.cmd.magnitude);
}

int32_t  decodeMagiQuest(decode_results *results, magiquest *mdata) {
    magiquest data;
    data.llword = 0;
    int16_t offset = 1;
    uint16_t mark_;
    uint16_t space_;
    uint8_t multiple_;
    if (irparams.rawlen < 2 * MAGIQUEST_BITS) {
        return ERR;
    }
    while (offset + 1 < irparams.rawlen) {
        mark_ = results->rawbuf[offset];
        space_ = results->rawbuf[offset+1];
        multiple_ = space_ / mark_;

        if (MATCH_MARK(space_ + mark_, MAGIQUEST_PERIOD)) {
            if (multiple_ > 1) {
                data.llword <<= 1;
            } else {
                data.llword = (data.llword << 1) | 1;
            }
        } else {
            return ERR;
        }
        offset++;
        offset++;
    }
    results->bits = (offset + 1) / 2;
    if (results->bits < 12) {
        results->bits = 0;
        return ERR;
    }
    results->value = data.cmd.wand_id;
    results->decode_type = MAGIQUEST;
    mdata->cmd.magnitude = data.cmd.magnitude;
    mdata->cmd.wand_id = data.cmd.wand_id;
    return DECODED;
}