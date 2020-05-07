

void BluetoothControl(){
  parsingSeparate();
  if (recievedFlag) {
  recievedFlag = false;
  Serial.println(prsValue);
  switch (thisName) {
    case BT_MODE:
      switch (prsValue.toInt()) {
              // режими
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
    case BT_BRIGH:
      BRIGHTNESS = prsValue.toInt();
      Serial.println(BRIGHTNESS);
      break;
    case BT_EMPTY:
      EMPTY_BRIGHT = prsValue.toInt();
      Serial.println(EMPTY_BRIGHT);
      break;
    case BT_RAINBOW_STEP:
      RAINBOW_STEP = prsValue.toFloat();
      Serial.println(RAINBOW_STEP);
      break;
    case BT_SMOOTH:
      SMOOTH = prsValue.toFloat();
      Serial.println(SMOOTH);
      break;
    case BT_SMOOTH_FREQ:
      SMOOTH_FREQ = prsValue.toFloat();
      Serial.println(SMOOTH_FREQ);
      break;
    case BT_MAX_COEF_FREQ:
      MAX_COEF_FREQ = prsValue.toFloat();
      Serial.println(MAX_COEF_FREQ);
      break;
    case LCOLOR:
      lightHUE = prsValue.toInt();
      Serial.print(lightHUE);
      break;
    case BT_STROBE_SMOOTH:
      STROBE_SMOOTH = prsValue.toInt();
      Serial.print(STROBE_SMOOTH);
      break;
    case BT_STROBE_PERIOD:
      STROBE_PERIOD = prsValue.toInt();
      Serial.print(STROBE_PERIOD);
      break;
    case BT_RUNNING_SPEED:
      RUNNING_SPEED = prsValue.toInt();
      Serial.print(RUNNING_SPEED);
      break;
    case BT_HUE_START:
      HUE_START = prsValue.toInt();
      Serial.print(HUE_START);
      break;
    case CALIBRATION:
      fullLowPass();
      Serial.print("Calibration");
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
