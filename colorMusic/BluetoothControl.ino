const char *headers[]  = {
"brigh",   // 0
"rnstp",   // 1
"vsmooth",   // 2
"fcoef",   // 3
"fsmooth",   // 4
"speriod",   // 5
"mode", // 6
"lcolor", //7
};

enum names {
BRIGH,   // 0
RNSTP,   // 1
SMTH,   // 2
FCOEF,   // 3
FSMOOTH,    // 4
SPERIOD,    // 5
TMODE,     //6
LCOLOR,    //7
};

void BluetoothControl(){
  parsingSeparate();
  if (recievedFlag) {
  recievedFlag = false;
  Serial.println(prsValue);
  switch (thisName) {
    case TMODE:
      switch (prsValue.toInt()) {
              // режимы
              case 0: this_mode = 0;
                break;
              case 1: this_mode = 1;
                break;
              case 2: this_mode = 2;
                break;
              case 3: this_mode = 3;
                break;
              case 4: this_mode = 4;
                break;
              case 5: this_mode = 5;
                break;
              case 6: this_mode = 6;
                break;
              case 7: this_mode = 7;
                break;
              case 8: this_mode = 8;
                break;
            }
      break;
    case BRIGH:
      BRIGHTNESS = prsValue.toInt();
      Serial.println(BRIGHTNESS);
      break;
    case SMTH:
      SMOOTH = prsValue.toFloat();
      Serial.println(SMOOTH);
      break;
    case FCOEF:
      MAX_COEF_FREQ = prsValue.toFloat();
      Serial.println(MAX_COEF_FREQ);
      break;
    case RNSTP:
      RAINBOW_STEP = prsValue.toFloat();
      Serial.println(RAINBOW_STEP);
      break;
    case LCOLOR:
      lightHUE = prsValue.toInt();
      Serial.print(lightHUE);
      break;
  }
}
}
void parsingSeparate() {
  if (BTSerial.available() > 0) { // проверка данных на вход
    String buf = BTSerial.readString(); // читаем как string
    for (byte i = 0; i < comm_amount; i++) { // пробегаемся по всем именам
      if (buf.startsWith(headers[i])) { // если совпадаем по названию
        String thisHeader = headers[i]; // костыль
        prsValue = buf.substring(thisHeader.length()); // перевод в int
        recievedFlag = true; // флаг
        thisName = i; // запоминаем номер команды
      }
    }
  }
}