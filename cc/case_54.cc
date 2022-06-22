

#include <stdio.h>
#include "ap_fixed.h"

void case_54(
    ap_int<16> in_data[18],
    ap_int<16> out_data[10]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<4> in1;
in1.range(3, 0) = in_data[0].range(3, 0);
ap_int<16> in2;
in2.range(15, 0) = in_data[1].range(15, 0);
ap_int<12> in3;
in3.range(11, 0) = in_data[2].range(11, 0);
ap_int<7> in4;
in4.range(6, 0) = in_data[3].range(6, 0);
ap_int<6> in5;
in5.range(5, 0) = in_data[4].range(5, 0);
ap_int<5> in6;
in6.range(4, 0) = in_data[5].range(4, 0);
ap_int<14> in7;
in7.range(13, 0) = in_data[6].range(13, 0);
ap_int<16> in8;
in8.range(15, 0) = in_data[7].range(15, 0);
ap_int<9> in9;
in9.range(8, 0) = in_data[8].range(8, 0);
ap_int<2> in10;
in10.range(1, 0) = in_data[9].range(1, 0);
ap_int<11> in11;
in11.range(10, 0) = in_data[10].range(10, 0);
ap_int<13> in12;
in12.range(12, 0) = in_data[11].range(12, 0);
ap_int<16> in13;
in13.range(15, 0) = in_data[12].range(15, 0);
ap_int<4> in14;
in14.range(3, 0) = in_data[13].range(3, 0);
ap_int<11> in15;
in15.range(10, 0) = in_data[14].range(10, 0);
ap_int<11> in16;
in16.range(10, 0) = in_data[15].range(10, 0);
ap_int<5> in17;
in17.range(4, 0) = in_data[16].range(4, 0);
ap_int<6> in18;
in18.range(5, 0) = in_data[17].range(5, 0);

ap_int<15> m19;
ap_int<12> m20;
ap_int<15> m21;
ap_int<10> m22;
ap_int<13> m23;
ap_int<7> m24;
ap_int<9> m25;
ap_int<11> m26;
ap_int<8> m27;
ap_int<7> m28;
ap_int<10> m29;
ap_int<10> m30;
ap_int<8> m31;
ap_int<16> m32;
ap_int<8> m33;
ap_int<16> m34;
ap_int<4> m35;
ap_int<8> m36;
ap_int<7> m37;
ap_int<8> m38;
ap_int<10> m39;
ap_int<6> m40;
ap_int<4> m41;
ap_int<9> m42;
ap_int<4> m43;
ap_int<15> m44;
ap_int<6> m45;
ap_int<11> m46;
ap_int<11> m47;
ap_int<9> m48;
ap_int<10> m49;
ap_int<8> m50;
ap_int<5> m51;
ap_int<7> m52;
ap_int<3> m53;
ap_int<14> m54;
ap_int<4> m55;
ap_int<3> m56;
ap_int<9> m57;
ap_int<11> m58;
ap_int<5> m59;

m19 = in17 * in8;
m20 = in9 * in18;
m21 = in3 * in5;
m22 = in18 * in14;
m23 = in14 * m19;
m24 = in16 * m23;
m25 = m24 * in18;
m26 = in9 * in15;
m27 = m24 * in9;
m28 = in13 * m21;
m29 = in13 * m19;
m30 = m26 * m29;
m31 = m19 * m30;
m32 = m29 * m22;
m33 = in17 * in15;
m34 = m20 + m19;
m35 = m31 * m33;
m36 = m23 * m19;
m37 = m34 * m20;
m38 = m33 * m32;
m39 = m35 * m33;
m40 = m39 * m28;
m41 = m24 * m25;
m42 = m24 * m35;
m43 = m31 * m42;
m44 = m38 + m42;
m45 = m37 * m29;
m46 = m30 + m43;
m47 = m33 * m29;
m48 = m34 * m37;
m49 = m46 * m37;
m50 = m36 + m47;
m51 = m41 + m45;
m52 = m41 * m35;
m53 = m36 * m35;
m54 = m44 * m44;
m55 = m52 * m51;
m56 = m43 * m47;
m57 = m54 * m51;
m58 = m55 * m46;
m59 = m54 * m51;

out_data[0] = m27;
out_data[1] = m40;
out_data[2] = m48;
out_data[3] = m49;
out_data[4] = m50;
out_data[5] = m53;
out_data[6] = m56;
out_data[7] = m57;
out_data[8] = m58;
out_data[9] = m59;


}
    