

#include <stdio.h>
#include "ap_fixed.h"

void case_59(
    ap_int<16> in_data[5],
    ap_int<16> out_data[8]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<12> in1;
in1.range(11, 0) = in_data[0].range(11, 0);
ap_int<7> in2;
in2.range(6, 0) = in_data[1].range(6, 0);
ap_int<12> in3;
in3.range(11, 0) = in_data[2].range(11, 0);
ap_int<10> in4;
in4.range(9, 0) = in_data[3].range(9, 0);
ap_int<15> in5;
in5.range(14, 0) = in_data[4].range(14, 0);

ap_int<12> m6;
ap_int<12> m7;
ap_int<12> m8;
ap_int<10> m9;
ap_int<10> m10;
ap_int<7> m11;
ap_int<14> m12;
ap_int<10> m13;
ap_int<14> m14;
ap_int<7> m15;
ap_int<15> m16;
ap_int<12> m17;
ap_int<9> m18;
ap_int<10> m19;
ap_int<9> m20;
ap_int<13> m21;
ap_int<15> m22;
ap_int<16> m23;
ap_int<6> m24;
ap_int<14> m25;
ap_int<10> m26;
ap_int<7> m27;
ap_int<13> m28;
ap_int<11> m29;
ap_int<14> m30;
ap_int<6> m31;
ap_int<6> m32;
ap_int<11> m33;
ap_int<15> m34;
ap_int<5> m35;
ap_int<4> m36;
ap_int<15> m37;
ap_int<9> m38;
ap_int<9> m39;
ap_int<7> m40;
ap_int<7> m41;
ap_int<11> m42;
ap_int<10> m43;
ap_int<13> m44;
ap_int<9> m45;
ap_int<9> m46;
ap_int<6> m47;
ap_int<11> m48;
ap_int<12> m49;
ap_int<11> m50;
ap_int<10> m51;
ap_int<8> m52;
ap_int<7> m53;
ap_int<13> m54;
ap_int<9> m55;
ap_int<13> m56;
ap_int<12> m57;
ap_int<5> m58;
ap_int<6> m59;
ap_int<8> m60;
ap_int<2> m61;
ap_int<6> m62;
ap_int<5> m63;

m6 = in2 * in5;
m7 = in5 + in5;
m8 = in5 + in3;
m9 = m6 * in4;
m10 = in5 * m8;
m11 = m6 * m10;
m12 = m7 * m11;
m13 = m10 * m10;
m14 = m10 * m12;
m15 = m12 * m10;
m16 = m13 * m14;
m17 = m12 + m12;
m18 = m15 + m14;
m19 = m14 * m16;
m20 = m16 + m15;
m21 = m19 * m20;
m22 = m18 * m17;
m23 = m18 * m19;
m24 = m19 + m22;
m25 = m23 * m23;
m26 = m23 * m24;
m27 = m25 * m22;
m28 = m23 + m24;
m29 = m27 * m27;
m30 = m29 * m26;
m31 = m28 * m28;
m32 = m27 * m27;
m33 = m31 * m29;
m34 = m30 * m33;
m35 = m31 + m32;
m36 = m31 + m31;
m37 = m36 * m33;
m38 = m36 * m34;
m39 = m35 * m36;
m40 = m38 * m39;
m41 = m36 * m36;
m42 = m38 * m39;
m43 = m41 + m40;
m44 = m43 * m42;
m45 = m44 * m42;
m46 = m44 * m44;
m47 = m42 * m46;
m48 = m45 * m44;
m49 = m44 + m48;
m50 = m45 * m46;
m51 = m49 * m49;
m52 = m48 + m48;
m53 = m52 + m51;
m54 = m51 * m52;
m55 = m50 * m51;
m56 = m52 + m52;
m57 = m56 * m52;
m58 = m53 * m56;
m59 = m55 * m57;
m60 = m58 * m58;
m61 = m58 * m59;
m62 = m59 * m59;
m63 = m61 * m59;

out_data[0] = m9;
out_data[1] = m21;
out_data[2] = m37;
out_data[3] = m47;
out_data[4] = m54;
out_data[5] = m60;
out_data[6] = m62;
out_data[7] = m63;


}
    