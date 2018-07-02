// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="nearest_neighbor_axim,hls_ip_2017_4_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z010clg225-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.508000,HLS_SYN_LAT=33025,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=63,HLS_SYN_LUT=122}" *)

module nearest_neighbor_axim (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        cam_fb_address0,
        cam_fb_ce0,
        cam_fb_q0,
        nn_fb_address0,
        nn_fb_ce0,
        nn_fb_we0,
        nn_fb_d0,
        ap_return
);

parameter    ap_ST_fsm_state1 = 4'd1;
parameter    ap_ST_fsm_state2 = 4'd2;
parameter    ap_ST_fsm_state3 = 4'd4;
parameter    ap_ST_fsm_state4 = 4'd8;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [11:0] cam_fb_address0;
output   cam_fb_ce0;
input  [31:0] cam_fb_q0;
output  [13:0] nn_fb_address0;
output   nn_fb_ce0;
output   nn_fb_we0;
output  [31:0] nn_fb_d0;
output  [31:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg cam_fb_ce0;
reg nn_fb_ce0;
reg nn_fb_we0;

(* fsm_encoding = "none" *) reg   [3:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [7:0] y_1_fu_89_p2;
reg   [7:0] y_1_reg_167;
wire    ap_CS_fsm_state2;
reg   [5:0] p_lshr_f_cast_reg_172;
wire   [0:0] exitcond1_fu_83_p2;
wire   [13:0] tmp_2_fu_109_p3;
reg   [13:0] tmp_2_reg_177;
wire   [7:0] x_1_fu_127_p2;
reg   [7:0] x_1_reg_185;
wire    ap_CS_fsm_state3;
wire   [0:0] exitcond_fu_121_p2;
wire   [13:0] tmp_7_fu_155_p2;
reg   [13:0] tmp_7_reg_195;
reg   [7:0] y_reg_61;
reg   [7:0] x_reg_72;
wire    ap_CS_fsm_state4;
wire   [63:0] tmp_6_fu_150_p1;
wire   [63:0] tmp_8_fu_160_p1;
wire   [6:0] tmp_fu_105_p1;
wire   [5:0] p_lshr_f1_cast_fu_133_p4;
wire   [11:0] tmp_5_fu_143_p3;
wire   [13:0] x_cast3_fu_117_p1;
reg   [3:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 4'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((exitcond1_fu_83_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        x_reg_72 <= 8'd0;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        x_reg_72 <= x_1_reg_185;
    end
end

always @ (posedge ap_clk) begin
    if (((exitcond_fu_121_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
        y_reg_61 <= y_1_reg_167;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        y_reg_61 <= 8'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((exitcond1_fu_83_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        p_lshr_f_cast_reg_172 <= {{y_reg_61[6:1]}};
        tmp_2_reg_177[13 : 7] <= tmp_2_fu_109_p3[13 : 7];
    end
end

always @ (posedge ap_clk) begin
    if (((exitcond_fu_121_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3))) begin
        tmp_7_reg_195 <= tmp_7_fu_155_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        x_1_reg_185 <= x_1_fu_127_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        y_1_reg_167 <= y_1_fu_89_p2;
    end
end

always @ (*) begin
    if (((exitcond1_fu_83_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((exitcond1_fu_83_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        cam_fb_ce0 = 1'b1;
    end else begin
        cam_fb_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        nn_fb_ce0 = 1'b1;
    end else begin
        nn_fb_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        nn_fb_we0 = 1'b1;
    end else begin
        nn_fb_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((exitcond1_fu_83_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            if (((exitcond_fu_121_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_return = 32'd0;

assign cam_fb_address0 = tmp_6_fu_150_p1;

assign exitcond1_fu_83_p2 = ((y_reg_61 == 8'd128) ? 1'b1 : 1'b0);

assign exitcond_fu_121_p2 = ((x_reg_72 == 8'd128) ? 1'b1 : 1'b0);

assign nn_fb_address0 = tmp_8_fu_160_p1;

assign nn_fb_d0 = cam_fb_q0;

assign p_lshr_f1_cast_fu_133_p4 = {{x_reg_72[6:1]}};

assign tmp_2_fu_109_p3 = {{tmp_fu_105_p1}, {7'd0}};

assign tmp_5_fu_143_p3 = {{p_lshr_f_cast_reg_172}, {p_lshr_f1_cast_fu_133_p4}};

assign tmp_6_fu_150_p1 = tmp_5_fu_143_p3;

assign tmp_7_fu_155_p2 = (tmp_2_reg_177 + x_cast3_fu_117_p1);

assign tmp_8_fu_160_p1 = tmp_7_reg_195;

assign tmp_fu_105_p1 = y_reg_61[6:0];

assign x_1_fu_127_p2 = (x_reg_72 + 8'd1);

assign x_cast3_fu_117_p1 = x_reg_72;

assign y_1_fu_89_p2 = (y_reg_61 + 8'd1);

always @ (posedge ap_clk) begin
    tmp_2_reg_177[6:0] <= 7'b0000000;
end

endmodule //nearest_neighbor_axim