// ---------------------------------------------------------------------------- //
void EC_RGB(int ColorNo)
{
  switch (ColorNo)
  {
    case 0:
      digitalWrite(RGBEC_R, 0);
      digitalWrite(RGBEC_G, 0);
      digitalWrite(RGBEC_B, 0);
      break;
    //
    case 1:
      digitalWrite(RGBEC_R, 1);
      digitalWrite(RGBEC_G, 0);
      digitalWrite(RGBEC_B, 0);
      break;
    //
    case 2:
      digitalWrite(RGBEC_R, 0);
      digitalWrite(RGBEC_G, 1);
      digitalWrite(RGBEC_B, 0);
      break;
    //
    case 3:
      digitalWrite(RGBEC_R, 0);
      digitalWrite(RGBEC_G, 0);
      digitalWrite(RGBEC_B, 1);
      break;
    //
    case 4:
      digitalWrite(RGBEC_R, 1);
      digitalWrite(RGBEC_G, 1);
      digitalWrite(RGBEC_B, 0);
      break;
    //
    case 5:
      digitalWrite(RGBEC_R, 0);
      digitalWrite(RGBEC_G, 1);
      digitalWrite(RGBEC_B, 1);
      break;
    //
    case 6:
      digitalWrite(RGBEC_R, 1);
      digitalWrite(RGBEC_G, 0);
      digitalWrite(RGBEC_B, 1);
      break;
      //
  }
}
// ---------------------------------------------------------------------------- //
void EC_RGB_off()
{
  digitalWrite(RGBEC_R, 0);
  digitalWrite(RGBEC_G, 0);
  digitalWrite(RGBEC_B, 0);
}
// ---------------------------------------------------------------------------- //
