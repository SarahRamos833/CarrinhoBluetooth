#include <SoftwareSerial.h> //BIBLIOTECA

const int pinoRX = 11; //PINO DIGITAL 11 (RX)
const int pinoTX = 10; //PINO DIGITAL 10 (TX)
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
 
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  pinMode(9, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
}
 
void loop(){
  if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
       dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
 
    if(dadoBluetooth == '1'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("FRENTE"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(13, HIGH); 
      digitalWrite(3,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
    }
    if(dadoBluetooth == '2'){ //SE O VALOR RECEBIDO FOR IGUAL A 2, FAZ
      Serial.println("TRAZ"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(3, HIGH); 
      digitalWrite(13,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
    }
    if(dadoBluetooth == '3'){ //SE O VALOR RECEBIDO FOR IGUAL A 3, FAZ
      Serial.println("DIREITA"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(13, HIGH); 
      digitalWrite(3,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
    if(dadoBluetooth == '4'){ //SE O VALOR RECEBIDO FOR IGUAL A 4, FAZ
      Serial.println("ESQUERDA"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(3, LOW); 
      digitalWrite(13,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
    }
    if(dadoBluetooth == '0'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("DESLIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(13, LOW); 
      digitalWrite(3, LOW);
      digitalWrite(5, LOW); 
      digitalWrite(6, LOW);
    }
  }
}
