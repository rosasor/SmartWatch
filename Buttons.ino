// Button Functions //

void initButtons() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

void updateButtons() {
  switch (mode) {
    case -1:
      for (int i = 0; i < 4; i++)  {
        buttons[i].update();
        if (buttons[i].rose()) {
          mode = i;
        }
      }
      break;

    case 0: //Displays watch time
      buttons[0].update();
      if (buttons[0].rose()) {
        mode = 0;
      }
      break;

    case 1: // Setting time

      buttons[0].update();
      if (buttons[0].rose()) { //Makes watch go to sleep
        buttons[0].update();
        if (buttons[0].rose()) { //Makes watch go to sleep
          mode = -1;
        }
        buttons[1].update();
        if (buttons[0].rose()) { //Makes watch go to sleep
          mode = 0;
        }
      }

      buttons[1].update();
      if (buttons[1].rose()) {
        addMin = 0;
        addHour = 0;
      }

      buttons[2].update();
      if (buttons[2].rose()) {
        addMin++;
      }

      buttons[3].update();
      if (buttons[3].rose()) {
        addHour++;
      }

      break;

    case 2: // Rainbow mode

      buttons[0].update();
      if (buttons[0].rose()) { //Makes watch go to sleep
        strip.setBrightness(10);
        mode = -1;
      }

      buttons[1].update();
      if (buttons[1].rose()) {
        strip.setBrightness(15);
        rainbow(10);
      }

      break;

    case 3: // Flashbang
      buttons[0].update();
      if (buttons[0].rose()) { //Makes watch go to sleep
        mode = -1;
      }

      buttons[3].update();
      if (buttons[3].rose()) {
        mode = 3;
      }
      break;
  }
}
