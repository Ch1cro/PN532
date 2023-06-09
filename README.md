# PN532
Conexão do modulo PN532 no modo SPI com o arduino


- ## 1º Passo - Colocar o modulo em modo SPI

![PN532_DIP_Switch_ConfiguraC3A7C3A3o](https://github.com/Ch1cro/PN532/assets/120192957/72cf1eb0-fc50-4465-8da6-5164898ceab2)


- ## 2º Passo - Conectar os cabos seguindo o diagrama

<img src="https://github.com/Ch1cro/PN532/assets/120192957/47e7b713-532b-4a47-9545-e093f4314587" alt="Imagem" width="700" height="600">


- ## 3º Passo - Colocar o código no arduino IDE
``` arduino
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>
PN532_SPI interface(SPI, 10);
NfcAdapter nfc = NfcAdapter(interface);
String tagId = "None";
void setup(void) {
 	Serial.begin(115200);
 	Serial.println("System initialized");
 	nfc.begin();
}
void loop() {
 	readNFC();
}
void readNFC() {
 	if (nfc.tagPresent())
 	{
 			NfcTag tag = nfc.read();
 			tag.print();
 			tagId = tag.getUidString();
 	}
 	delay(5000);
}
```

- ## 4º Passo - Compilar e passar o código para dentro do Arduino

- ## 5º Passo - Abrir o serial monitor e colocar o BAUD em 115.200

- ## 6º Passo - Aproximar um cartão NFC ou RFID
