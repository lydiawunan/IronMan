

#include <stdio.h>
#include "ap_fixed.h"

void case_26(
    ap_int<16> in_data[22],
    ap_int<16> out_data[15]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<13> in1;
in1.range(12, 0) = in_data[0].range(12, 0);
ap_int<6> in2;
in2.range(5, 0) = in_data[1].range(5, 0);
ap_int<11> in3;
in3.range(10, 0) = in_data[2].range(10, 0);
ap_int<12> in4;
in4.range(11, 0) = in_data[3].range(11, 0);
ap_int<15> in5;
in5.range(14, 0) = in_data[4].range(14, 0);
ap_int<2> in6;
in6.range(1, 0) = in_data[5].range(1, 0);
ap_int<16> in7;
in7.range(15, 0) = in_data[6].range(15, 0);
ap_int<4> in8;
in8.range(3, 0) = in_data[7].range(3, 0);
ap_int<5> in9;
in9.range(4, 0) = in_data[8].range(4, 0);
ap_int<6> in10;
in10.range(5, 0) = in_data[9].range(5, 0);
ap_int<15> in11;
in11.range(14, 0) = in_data[10].range(14, 0);
ap_int<3> in12;
in12.range(2, 0) = in_data[11].range(2, 0);
ap_int<2> in13;
in13.range(1, 0) = in_data[12].range(1, 0);
ap_int<11> in14;
in14.range(10, 0) = in_data[13].range(10, 0);
ap_int<13> in15;
in15.range(12, 0) = in_data[14].range(12, 0);
ap_int<5> in16;
in16.range(4, 0) = in_data[15].range(4, 0);
ap_int<14> in17;
in17.range(13, 0) = in_data[16].range(13, 0);
ap_int<9> in18;
in18.range(8, 0) = in_data[17].range(8, 0);
ap_int<16> in19;
in19.range(15, 0) = in_data[18].range(15, 0);
ap_int<16> in20;
in20.range(15, 0) = in_data[19].range(15, 0);
ap_int<5> in21;
in21.range(4, 0) = in_data[20].range(4, 0);
ap_int<13> in22;
in22.range(12, 0) = in_data[21].range(12, 0);

ap_int<3> m23;
ap_int<10> m24;
ap_int<7> m25;
ap_int<4> m26;
ap_int<6> m27;
ap_int<15> m28;
ap_int<5> m29;
ap_int<10> m30;
ap_int<11> m31;
ap_int<6> m32;
ap_int<14> m33;
ap_int<16> m34;
ap_int<14> m35;
ap_int<6> m36;
ap_int<10> m37;
ap_int<16> m38;
ap_int<15> m39;
ap_int<11> m40;
ap_int<7> m41;
ap_int<16> m42;
ap_int<4> m43;
ap_int<10> m44;
ap_int<14> m45;
ap_int<8> m46;
ap_int<5> m47;
ap_int<15> m48;
ap_int<11> m49;
ap_int<4> m50;
ap_int<13> m51;
ap_int<5> m52;
ap_int<10> m53;
ap_int<10> m54;
ap_int<13> m55;
ap_int<5> m56;
ap_int<7> m57;
ap_int<10> m58;
ap_int<9> m59;
ap_int<16> m60;
ap_int<9> m61;
ap_int<5> m62;
ap_int<12> m63;
ap_int<9> m64;
ap_int<6> m65;
ap_int<15> m66;
ap_int<3> m67;
ap_int<11> m68;
ap_int<10> m69;
ap_int<9> m70;
ap_int<13> m71;
ap_int<9> m72;
ap_int<5> m73;
ap_int<13> m74;
ap_int<14> m75;
ap_int<9> m76;
ap_int<5> m77;
ap_int<9> m78;
ap_int<10> m79;
ap_int<15> m80;
ap_int<4> m81;
ap_int<16> m82;
ap_int<10> m83;
ap_int<11> m84;
ap_int<6> m85;
ap_int<3> m86;
ap_int<12> m87;
ap_int<16> m88;
ap_int<8> m89;
ap_int<14> m90;

m23 = in12 * in2;
m24 = in15 * m23;
m25 = m23 * in18;
m26 = m23 * in8;
m27 = m25 * in8;
m28 = in14 + in22;
m29 = in22 * m23;
m30 = in22 * in20;
m31 = in17 * in14;
m32 = in12 * in15;
m33 = in15 * m25;
m34 = m33 * m27;
m35 = in15 + m28;
m36 = m33 + m30;
m37 = m23 * in15;
m38 = in20 * m31;
m39 = m36 * m24;
m40 = m38 * m25;
m41 = m28 * m35;
m42 = m29 * m33;
m43 = m26 * m30;
m44 = m40 * m40;
m45 = m37 * m35;
m46 = m29 * m33;
m47 = m25 * m32;
m48 = m38 * m38;
m49 = m40 * m30;
m50 = m49 * m41;
m51 = m44 * m33;
m52 = m46 * m41;
m53 = m33 * m42;
m54 = m46 * m42;
m55 = m49 * m43;
m56 = m48 + m36;
m57 = m47 * m38;
m58 = m56 * m41;
m59 = m37 + m57;
m60 = m41 * m45;
m61 = m52 * m49;
m62 = m59 + m49;
m63 = m56 * m46;
m64 = m53 * m51;
m65 = m56 * m58;
m66 = m49 + m47;
m67 = m56 * m50;
m68 = m63 * m50;
m69 = m52 + m53;
m70 = m58 * m60;
m71 = m59 * m53;
m72 = m68 * m52;
m73 = m70 * m64;
m74 = m54 * m68;
m75 = m63 * m63;
m76 = m73 * m74;
m77 = m75 * m65;
m78 = m71 * m67;
m79 = m69 * m77;
m80 = m78 + m65;
m81 = m71 * m73;
m82 = m61 * m61;
m83 = m75 * m78;
m84 = m74 * m80;
m85 = m64 * m75;
m86 = m81 * m81;
m87 = m65 * m84;
m88 = m79 * m80;
m89 = m80 * m67;
m90 = m84 * m75;

out_data[0] = m34;
out_data[1] = m39;
out_data[2] = m55;
out_data[3] = m62;
out_data[4] = m66;
out_data[5] = m72;
out_data[6] = m76;
out_data[7] = m82;
out_data[8] = m83;
out_data[9] = m85;
out_data[10] = m86;
out_data[11] = m87;
out_data[12] = m88;
out_data[13] = m89;
out_data[14] = m90;


}
    