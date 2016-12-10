
//Değişkenlerin pinleri>>Defines pins numbers
const int adimpin = 3; //steppin
const int yonpin = 4; //directionpin
const int butonpin = 5; //buttonpin

//Değişkenlerin değerleri>>Defines variables
int potsuresi, stephizi, durum; //Değişkenlerin değerleri>>Defines variables

void setup()
{
  //Değişkenlerin çıkış ve giriş olduğunu söyledik>>Sets the two pins as Outputs and one pins as INPUT.
  pinMode(adimpin, OUTPUT);
  pinMode(yonpin, OUTPUT);
  pinMode(butonpin,INPUT);
}

void loop()
{
 
  durum = digitalRead(butonpin); // Butona basılıp basılmadığını öğrendik>> Read buttonpin which push button or not push button
  stephizi = hiz(); // Step hızının değeri hız fonksiyonundan gelen değere eşitledik>>Gets custom delay values from the custom speedUp function
  //Motorun hızını potttan gelen değerelere bağlı kıldık ve bu sayede hızını kontrol ettik>> Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  if (durum == HIGH)
  {
    digitalWrite(yonpin, HIGH); //Motor + yönde harekete başlıcağını söyledik>>Enables the motor to move in a particular direction
    digitalWrite(adimpin, HIGH);
    delayMicroseconds(stephizi);
    digitalWrite(adimpin, LOW);
    delayMicroseconds(stephizi);
  }
  if (durum == LOW)
  {
    digitalWrite(yonpin, LOW); //Motor - yönde harekete başlıcağını söyledik>>Enables the motor to move in a particular direction
    digitalWrite(adimpin, HIGH);
    delayMicroseconds(stephizi);
    digitalWrite(adimpin, LOW);
    delayMicroseconds(stephizi);
  }
  /*digitalWrite(dirPin,HIGH); // Motor + yönde harekete başlıcağını söyledik>>Enables the motor to move in a particular direction
    //200 adım 360 derece yapar ve tam 1 tur döner>> Makes 200 pulses for making one full cycle rotation
    for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    }
    digitalWrite(dirPin,LOW); // Motor - yönde harekete başlıcağını söyledik>>Enables the motor to move in a particular direction
    //200 adım 360 derece yapar ve tam 1 tur döner>> Makes 200 pulses for making one full cycle rotation
    for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    }
  */
}
//Fonksiyon potansiyometredeki değere göre bekleme süresini ayarlıyo>> Function for reading the Potentiometer
int hiz()
{
  
  int potsuresi = analogRead(A0); //Potsüresine potttan gelen değerleri atadık >>Reads the potentiometer
  int yenipotsuresi = map(potsuresi, 0, 1023, 300, 4000); // Potansiyometreden gelen 0 ile 1023 arasındaki değerleri 300 ile 4000 arasındaki sayılara çevirdik>>Converts the read values of the potentiometer from 0 to 1023 into desireded delay values (300 to 4000)
  return yenipotsuresi;
}
