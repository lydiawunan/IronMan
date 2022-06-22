

#include <stdio.h>
#include "ap_fixed.h"

void case_4(
    ap_int<16> in_data[24],
    ap_int<16> out_data[18]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    

ap_int<15> in1;
in1.range(14, 0) = in_data[0].range(14, 0);
ap_int<13> in2;
in2.range(12, 0) = in_data[1].range(12, 0);
ap_int<4> in3;
in3.range(3, 0) = in_data[2].range(3, 0);
ap_int<12> in4;
in4.range(11, 0) = in_data[3].range(11, 0);
ap_int<4> in5;
in5.range(3, 0) = in_data[4].range(3, 0);
ap_int<2> in6;
in6.range(1, 0) = in_data[5].range(1, 0);
ap_int<3> in7;
in7.range(2, 0) = in_data[6].range(2, 0);
ap_int<5> in8;
in8.range(4, 0) = in_data[7].range(4, 0);
ap_int<6> in9;
in9.range(5, 0) = in_data[8].range(5, 0);
ap_int<10> in10;
in10.range(9, 0) = in_data[9].range(9, 0);
ap_int<14> in11;
in11.range(13, 0) = in_data[10].range(13, 0);
ap_int<14> in12;
in12.range(13, 0) = in_data[11].range(13, 0);
ap_int<3> in13;
in13.range(2, 0) = in_data[12].range(2, 0);
ap_int<2> in14;
in14.range(1, 0) = in_data[13].range(1, 0);
ap_int<9> in15;
in15.range(8, 0) = in_data[14].range(8, 0);
ap_int<15> in16;
in16.range(14, 0) = in_data[15].range(14, 0);
ap_int<2> in17;
in17.range(1, 0) = in_data[16].range(1, 0);
ap_int<15> in18;
in18.range(14, 0) = in_data[17].range(14, 0);
ap_int<7> in19;
in19.range(6, 0) = in_data[18].range(6, 0);
ap_int<5> in20;
in20.range(4, 0) = in_data[19].range(4, 0);
ap_int<5> in21;
in21.range(4, 0) = in_data[20].range(4, 0);
ap_int<11> in22;
in22.range(10, 0) = in_data[21].range(10, 0);
ap_int<16> in23;
in23.range(15, 0) = in_data[22].range(15, 0);
ap_int<15> in24;
in24.range(14, 0) = in_data[23].range(14, 0);

ap_int<7> m25;
ap_int<16> m26;
ap_int<5> m27;
ap_int<6> m28;
ap_int<5> m29;
ap_int<6> m30;
ap_int<4> m31;
ap_int<4> m32;
ap_int<4> m33;
ap_int<10> m34;
ap_int<15> m35;
ap_int<5> m36;
ap_int<3> m37;
ap_int<12> m38;
ap_int<11> m39;
ap_int<12> m40;
ap_int<4> m41;
ap_int<4> m42;
ap_int<15> m43;
ap_int<2> m44;
ap_int<3> m45;
ap_int<14> m46;
ap_int<6> m47;
ap_int<11> m48;
ap_int<10> m49;
ap_int<7> m50;
ap_int<4> m51;
ap_int<9> m52;
ap_int<8> m53;
ap_int<11> m54;
ap_int<6> m55;
ap_int<6> m56;
ap_int<12> m57;
ap_int<12> m58;
ap_int<5> m59;
ap_int<6> m60;
ap_int<16> m61;
ap_int<6> m62;
ap_int<10> m63;
ap_int<2> m64;
ap_int<8> m65;
ap_int<15> m66;
ap_int<10> m67;
ap_int<6> m68;
ap_int<13> m69;
ap_int<12> m70;
ap_int<16> m71;
ap_int<7> m72;
ap_int<7> m73;
ap_int<5> m74;
ap_int<5> m75;
ap_int<5> m76;
ap_int<14> m77;
ap_int<5> m78;
ap_int<6> m79;
ap_int<13> m80;
ap_int<11> m81;
ap_int<15> m82;
ap_int<15> m83;
ap_int<7> m84;
ap_int<14> m85;
ap_int<8> m86;

m25 = in12 * in24;
m26 = in12 + in20;
m27 = in3 * in10;
m28 = in16 * in21;
m29 = in5 + m28;
m30 = m28 + in21;
m31 = in21 * m28;
m32 = m31 * in21;
m33 = in20 * in10;
m34 = m30 * m26;
m35 = in24 * in24;
m36 = m31 * m27;
m37 = in13 * m27;
m38 = in18 * in23;
m39 = m30 + in21;
m40 = m39 * m39;
m41 = m25 + m34;
m42 = in21 * m27;
m43 = in22 * m30;
m44 = m41 * m36;
m45 = m30 + m27;
m46 = in24 * in22;
m47 = m25 * m44;
m48 = m30 * m34;
m49 = m29 * m47;
m50 = m47 * m36;
m51 = m44 * m45;
m52 = m32 * m43;
m53 = m32 * m42;
m54 = m50 * m49;
m55 = m50 + m31;
m56 = m34 * m35;
m57 = m40 * m50;
m58 = m50 * m43;
m59 = m44 * m36;
m60 = m55 * m45;
m61 = m60 * m46;
m62 = m47 * m40;
m63 = m41 * m49;
m64 = m41 * m42;
m65 = m64 * m60;
m66 = m65 * m46;
m67 = m49 + m59;
m68 = m60 + m57;
m69 = m65 * m59;
m70 = m67 + m66;
m71 = m47 * m54;
m72 = m55 * m64;
m73 = m68 + m63;
m74 = m55 * m70;
m75 = m51 * m72;
m76 = m66 * m72;
m77 = m58 + m56;
m78 = m55 * m60;
m79 = m59 * m60;
m80 = m71 * m77;
m81 = m63 * m77;
m82 = m70 + m76;
m83 = m70 * m61;
m84 = m75 * m65;
m85 = m61 + m71;
m86 = m83 * m65;

out_data[0] = m33;
out_data[1] = m37;
out_data[2] = m38;
out_data[3] = m48;
out_data[4] = m52;
out_data[5] = m53;
out_data[6] = m62;
out_data[7] = m69;
out_data[8] = m73;
out_data[9] = m74;
out_data[10] = m78;
out_data[11] = m79;
out_data[12] = m80;
out_data[13] = m81;
out_data[14] = m82;
out_data[15] = m84;
out_data[16] = m85;
out_data[17] = m86;


}
    