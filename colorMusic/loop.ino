void loop() {
#if REMOTE_TYPE == 1
  remoteTick();     // опрос ИК пульта
#else if REMOTE_TYPE == 0
  BluetoothControl();     
#endif
  mainLoop();       // главный цикл обработки и отрисовки
  eepromTick();     // проверка не пора ли сохранить настройки
  
}