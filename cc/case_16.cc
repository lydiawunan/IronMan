

#include <stdio.h>
#include "ap_fixed.h"

void case_16(
    ap_int<16> in_data[7],
    ap_int<16> out_data[9]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<13> in1;
in1.range(12, 0) = in_data[0].range(12, 0);
ap_int<5> in2;
in2.range(4, 0) = in_data[1].range(4, 0);
ap_int<12> in3;
in3.range(11, 0) = in_data[2].range(11, 0);
ap_int<6> in4;
in4.range(5, 0) = in_data[3].range(5, 0);
ap_int<16> in5;
in5.range(15, 0) = in_data[4].range(15, 0);
ap_int<11> in6;
in6.range(10, 0) = in_data[5].range(10, 0);
ap_int<6> in7;
in7.range(5, 0) = in_data[6].range(5, 0);

ap_int<6> m8;
ap_int<8> m9;
ap_int<15> m10;
ap_int<16> m11;
ap_int<12> m12;
ap_int<10> m13;
ap_int<7> m14;
ap_int<15> m15;
ap_int<10> m16;
ap_int<15> m17;
ap_int<10> m18;
ap_int<16> m19;
ap_int<7> m20;
ap_int<6> m21;
ap_int<14> m22;
ap_int<16> m23;
ap_int<11> m24;
ap_int<13> m25;
ap_int<7> m26;
ap_int<14> m27;
ap_int<11> m28;
ap_int<12> m29;
ap_int<6> m30;
ap_int<11> m31;
ap_int<14> m32;
ap_int<13> m33;
ap_int<14> m34;
ap_int<10> m35;
ap_int<11> m36;
ap_int<12> m37;
ap_int<13> m38;
ap_int<12> m39;
ap_int<12> m40;
ap_int<10> m41;
ap_int<13> m42;
ap_int<15> m43;
ap_int<10> m44;
ap_int<12> m45;
ap_int<12> m46;
ap_int<12> m47;
ap_int<10> m48;
ap_int<14> m49;
ap_int<13> m50;
ap_int<12> m51;
ap_int<15> m52;
ap_int<6> m53;
ap_int<14> m54;
ap_int<8> m55;
ap_int<3> m56;
ap_int<13> m57;
ap_int<13> m58;
ap_int<6> m59;
ap_int<7> m60;
ap_int<8> m61;
ap_int<6> m62;
ap_int<6> m63;

m8 = in1 * in2;
m9 = in2 * in7;
m10 = m9 * in3;
m11 = m10 * in5;
m12 = m10 * in7;
m13 = m8 * m12;
m14 = m10 * m11;
m15 = m12 * m14;
m16 = m12 * m9;
m17 = m16 * m11;
m18 = m16 + m15;
m19 = m12 * m15;
m20 = m19 * m16;
m21 = m16 * m17;
m22 = m18 + m15;
m23 = m17 * m20;
m24 = m17 * m17;
m25 = m23 * m24;
m26 = m24 + m22;
m27 = m25 + m26;
m28 = m27 + m26;
m29 = m25 * m24;
m30 = m26 * m24;
m31 = m27 * m27;
m32 = m25 * m30;
m33 = m30 + m28;
m34 = m31 * m33;
m35 = m32 * m31;
m36 = m35 + m35;
m37 = m34 * m32;
m38 = m35 * m36;
m39 = m37 * m38;
m40 = m39 * m35;
m41 = m35 + m34;
m42 = m41 * m36;
m43 = m37 * m40;
m44 = m43 * m43;
m45 = m44 + m40;
m46 = m44 * m39;
m47 = m42 * m46;
m48 = m41 * m44;
m49 = m42 * m48;
m50 = m46 * m45;
m51 = m50 * m46;
m52 = m48 * m45;
m53 = m49 + m47;
m54 = m52 * m52;
m55 = m48 * m53;
m56 = m53 * m53;
m57 = m55 * m53;
m58 = m57 * m55;
m59 = m53 * m53;
m60 = m53 * m55;
m61 = m55 * m55;
m62 = m56 + m58;
m63 = m60 * m58;

out_data[0] = m13;
out_data[1] = m21;
out_data[2] = m29;
out_data[3] = m51;
out_data[4] = m54;
out_data[5] = m59;
out_data[6] = m61;
out_data[7] = m62;
out_data[8] = m63;


}
    