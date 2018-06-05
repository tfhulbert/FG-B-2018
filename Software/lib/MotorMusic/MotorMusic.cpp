#include <MotorMusic.h>

Timer RNATimer = Timer(0);

uint16_t RNA[] = { 
        0b1000000001010101, 0b1111111100111010, 0b1100000100111010, 0b0100000001010111, 
        0b1111111101000010, 0b1000000101000010, 0b1000000001010010, 0b1111111101000011, 
        0b1100000101000011, 0b0100000001010011, 0b1111111101000010, 0b1000000101000010, 
        0b1000000001001010, 0b1111111101000000, 0b1000000101000000, 0b1000000000111011, 
        0b1111111100111010, 0b1000000100111010, 0b1000000001010101, 0b1111111100111010, 
        0b0000000100111010, 0b1000000000111001, 0b1000000000110111, 0b1000000000110101, 
        0b1000000001000011, 0b1000000001000010, 0b1000000001000000, 0b1111111100101010, 
        0b0000000100101010, 0b1100000000110010, 0b0100000001011010, 0b1111111100110101, 
        0b1000000100110101, 0b1000000001010101, 0b1111111100100111, 0b0000000100100111, 
        0b1100000000101010, 0b0100000001010111, 0b1111111100110010, 0b1000000100110010, 
        0b1000000001010010, 0b1111111101000011, 0b0000000101000011, 0b1100000001000000, 
        0b0100000001010011, 0b1111111101000010, 0b1100000101000010, 0b0100000001001010, 
        0b1111111101000000, 0b1100000101000000, 0b0100000001010111, 0b1000000001000101, 
        0b1000000001000011, 0b1000000001000010, 0b1000000001000000, 0b1000000000111010, 
        0b1000000000111001, 0b1000000000111010, 0b1000000001000000, 0b1000000001000010, 
        0b1000000001011010, 0b1000000001000010, 0b1000000001011010, 0b1111111100110101, 
        0b0000000100110101, 0b1000000000111001, 0b1000000001000000, 0b1000000000110101, 
        0b1000000001011001, 0b1000000000110011, 0b1000000000110010, 0b1000000000100111, 
        0b1000000000110010, 0b1000000000100111, 0b1000000000101001, 0b1000000000101010, 
        0b1000000001010111, 0b1000000000110000, 0b1000000001010111, 0b1111111100110010, 
        0b0000000100110010, 0b1000000000110101, 0b1000000000111001, 0b1000000000110010, 
        0b1000000001010101, 0b1000000000110000, 0b1000000001011001, 0b1000000000110011, 
        0b1000000000110111, 0b1000000000111010, 0b0100000000111001, 0b0100000001011001, 
        0b1111111100110111, 0b1000000100110111, 0b0100000000110101, 0b0100000001011001, 
        0b1111111100110011, 0b0000000100110011, 0b1000000001010111, 0b1000000000111010, 
        0b1000000001000111, 0b1000000001000101, 0b1000000001000011, 0b1000000001000010, 
        0b1111111101000000, 0b0000000101000000, 0b1000000001000010, 0b1000000001000011, 
        0b1000000001000101, 0b1000000001100000, 0b1000000000110101, 0b1000000001100000, 
        0b1111111100111010, 0b0000000100111010, 0b1000000001000000, 0b1000000001011010, 
        0b1111111101000010, 0b0000000101000010, 0b1111111101000101, 0b0000000101000101, 
        0b1111111100111001, 0b0000000100111001, 0b1000000000111010, 0b1000000001000000, 
        0b1000000001000010, 0b1000000001011001, 0b1000000001000010, 0b1000000001011001, 
        0b1000000000110111, 0b1000000000111001, 0b1000000000111010, 0b1000000001000010, 
        0b1111111101000111, 0b0000000101000111, 0b1111111101000101, 0b0000000101000101, 
        0b1111111101000011, 0b0000000101000011, 0b1100000001000000, 0b0100000001010111, 
        0b1111111101000010, 0b1100000101000010, 0b0100000001001010, 0b1111111101000000, 
        0b1100000101000000, 0b0100000001010111, 0b1111111101000101, 0b0000000101000101, 
        0b1000000000110101, 0b1000000001010101, 0b1111111100111010, 0b1100000100111010, 
        0b0100000001010111, 0b1111111101000010, 0b1000000101000010, 0b1000000001010010, 
        0b1111111101000011, 0b1100000101000011, 0b0100000001010011, 0b1111111101000010, 
        0b1000000101000010, 0b1000000001001010, 0b1111111101000000, 0b1000000101000000, 
        0b1000000000111011, 0b1111111100111010, 0b1000000100111010, 0b1000000001010101, 
        0b1111111100111010, 0b0000000100111010, 0b1000000000111001, 0b1000000000110111, 
        0b1000000000110101, 0b1000000001000011, 0b1000000001000010, 0b1000000001000000, 
        0b1111111100101010, 0b0000000100101010, 0b1100000000110010, 0b0100000001011010, 
        0b1111111100110101, 0b1000000100110101, 0b1000000001010101, 0b1111111100100111, 
        0b0000000100100111, 0b1100000000101010, 0b0100000001010111, 0b1111111100110010, 
        0b1000000100110010, 0b1000000001010010, 0b1111111101000011, 0b0000000101000011, 
        0b1100000001000000, 0b0100000001010011, 0b1111111101000010, 0b1100000101000010, 
        0b0100000001001010, 0b1111111101000000, 0b1100000101000000, 0b0100000001010111, 
        0b1000000001000101, 0b1000000001000011, 0b1000000001000010, 0b1000000001000000, 
        0b1000000000111010, 0b1000000000111001, 0b1000000000111010, 0b1000000001000000, 
        0b1000000001000010, 0b1000000001011010, 0b1000000001000010, 0b1000000001011010, 
        0b1111111100110101, 0b0000000100110101, 0b1000000000111001, 0b1000000001000000, 
        0b1000000000110101, 0b1000000001011001, 0b1000000000110011, 0b1000000000110010, 
        0b1000000000100111, 0b1000000000110010, 0b1000000000100111, 0b1000000000101001, 
        0b1000000000101010, 0b1000000001010111, 0b1000000000110000, 0b1000000001010111, 
        0b1111111100110010, 0b0000000100110010, 0b1000000000110101, 0b1000000000111001, 
        0b1000000000110010, 0b1000000001010101, 0b1000000000110000, 0b1000000001011001, 
        0b1000000000110011, 0b1000000000110111, 0b1000000000111010, 0b0100000000111001, 
        0b0100000001011001, 0b1111111100110111, 0b1000000100110111, 0b0100000000110101, 
        0b0100000001011001, 0b1111111100110011, 0b0000000100110011, 0b1000000001010111, 
        0b1000000000111010, 0b1000000001000111, 0b1000000001000101, 0b1000000001000011, 
        0b1000000001000010, 0b1111111101000000, 0b0000000101000000, 0b1000000001000010, 
        0b1000000001000011, 0b1000000001000101, 0b1000000001100000, 0b1000000000110101, 
        0b1000000001100000, 0b1111111100111010, 0b0000000100111010, 0b1000000001000000, 
        0b1000000001011010, 0b1111111101000010, 0b0000000101000010, 0b1111111101000101, 
        0b0000000101000101, 0b1111111100111001, 0b0000000100111001, 0b1000000000111010, 
        0b1000000001000000, 0b1000000001000010, 0b1000000001011001, 0b1000000001000010, 
        0b1000000001011001, 0b1000000000110111, 0b1000000000111001, 0b1000000000111010, 
        0b1000000001000010, 0b1111111101000111, 0b0000000101000111, 0b1111111101000101, 
        0b0000000101000101, 0b1111111101000011, 0b0000000101000011, 0b1100000001000000, 
        0b0100000001010111, 0b1111111101000010, 0b1100000101000010, 0b0100000001001010, 
        0b1111111100110101, 0b1000000100110101, 0b1000000001011001, 0b1111111100111010, 
        0b1111111100111010, 0b0000001000111010, 
  };
uint16_t Freq8[] = {4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902};

void motorMusic(String song, int trackNum){
    if(song == "RNA"){
        /* RNA, tempo of 4 */
        playSong(RNA, sizeof(RNA)/sizeof(uint16_t), 4);
    }else if(song == "Ghostbusters"){
        /* Ghostbusters */
    }else if(song == "We are the champions"){
        /* We are the champions */
    }
}

void playSong(uint16_t songData[], const uint16_t songLength, const uint8_t tempo){
    for(uint16_t  x = 0; x < songLength; x++){
        uint16_t data = pgm_read_word((uint16_t *)&songData[x]);
        if((data & 0xF) == 0xF){
            writeFreq(19000);
        }else{
            int freq = pgm_read_word(&Freq8[data&0xF]) / (1<<(8 - (data>>4 & 0xF)));
            writeFreq(freq);
        }    
        int duration = data >> 8;
        while(duration--) delay(tempo);
    }
}

void playSongAsync(uint16_t songData[], uint16_t songLength, uint8_t tempo){
    // trackOneCount = 0;
    uint16_t data = pgm_read_word((uint16_t *)&songData[trackOneCount]);
    if((data & 0xF) == 0xF){
        writeFreq(19000);
    }else{
        int freq = pgm_read_word(&Freq8[data&0xF]) / (1<<(8 - (data>>4 & 0xF)));
        writeFreq(freq);
    }
    int duration = data >> 8;
    if(RNATimer.hasBeenMS(tempo)){
        duration--;
        RNATimer.reset();
    }
    if(duration-- == 0){
        trackOneCount++;
    }
    if(trackOneCount == songLength){
        trackOneCount = 0;
    }
}

