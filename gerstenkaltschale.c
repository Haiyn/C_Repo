/* Bei einer Höhe von 10er Additionen  beträgt Inhalt 0.08 Liter (10mm, 20mm, 30mm)
    max höhe: 200 mm, max breite: 100 mm */

#include <stdio.h>
#include <math.h>

int main(void) {
  float stdvol = (M_PI * (50 * 50) * 10)/1000000;               // Zylidervolumen: V = pi * r² * h        1000mm³ = 1 dm³ = 1 Liter, Teilung Faktor 1000 (mm auf dm) * 1000 (mm auf mm³)
  float curvol = 0;
  for(int i = 0; i <= 200; i = i + 10) {
    printf("\nBei einer Höhe von  %i  ", i);
    printf("mm beträgt das Volumen   %.3f   ", curvol);
    printf("Liter!");

    curvol = curvol + stdvol;
  }
}
