// for SPI Communication
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