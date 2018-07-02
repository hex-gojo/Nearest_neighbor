-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2017.4.1
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity nearest_neighbor_axim is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    cam_fb_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
    cam_fb_ce0 : OUT STD_LOGIC;
    cam_fb_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    nn_fb_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
    nn_fb_ce0 : OUT STD_LOGIC;
    nn_fb_we0 : OUT STD_LOGIC;
    nn_fb_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    ap_return : OUT STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of nearest_neighbor_axim is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "nearest_neighbor_axim,hls_ip_2017_4_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z010clg225-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.508000,HLS_SYN_LAT=33025,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=63,HLS_SYN_LUT=122}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (3 downto 0) := "0010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (3 downto 0) := "0100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (3 downto 0) := "1000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv8_80 : STD_LOGIC_VECTOR (7 downto 0) := "10000000";
    constant ap_const_lv8_1 : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv7_0 : STD_LOGIC_VECTOR (6 downto 0) := "0000000";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal y_1_fu_89_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal y_1_reg_167 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal p_lshr_f_cast_reg_172 : STD_LOGIC_VECTOR (5 downto 0);
    signal exitcond1_fu_83_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_2_fu_109_p3 : STD_LOGIC_VECTOR (13 downto 0);
    signal tmp_2_reg_177 : STD_LOGIC_VECTOR (13 downto 0);
    signal x_1_fu_127_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal x_1_reg_185 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal exitcond_fu_121_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_7_fu_155_p2 : STD_LOGIC_VECTOR (13 downto 0);
    signal tmp_7_reg_195 : STD_LOGIC_VECTOR (13 downto 0);
    signal y_reg_61 : STD_LOGIC_VECTOR (7 downto 0);
    signal x_reg_72 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal tmp_6_fu_150_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_8_fu_160_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_fu_105_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal p_lshr_f1_cast_fu_133_p4 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_5_fu_143_p3 : STD_LOGIC_VECTOR (11 downto 0);
    signal x_cast3_fu_117_p1 : STD_LOGIC_VECTOR (13 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (3 downto 0);


begin




    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    x_reg_72_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond1_fu_83_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                x_reg_72 <= ap_const_lv8_0;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
                x_reg_72 <= x_1_reg_185;
            end if; 
        end if;
    end process;

    y_reg_61_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond_fu_121_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                y_reg_61 <= y_1_reg_167;
            elsif (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                y_reg_61 <= ap_const_lv8_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond1_fu_83_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                p_lshr_f_cast_reg_172 <= y_reg_61(6 downto 1);
                    tmp_2_reg_177(13 downto 7) <= tmp_2_fu_109_p3(13 downto 7);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond_fu_121_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                tmp_7_reg_195 <= tmp_7_fu_155_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                x_1_reg_185 <= x_1_fu_127_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                y_1_reg_167 <= y_1_fu_89_p2;
            end if;
        end if;
    end process;
    tmp_2_reg_177(6 downto 0) <= "0000000";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, exitcond1_fu_83_p2, ap_CS_fsm_state3, exitcond_fu_121_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((exitcond1_fu_83_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((exitcond_fu_121_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when others =>  
                ap_NS_fsm <= "XXXX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);

    ap_done_assign_proc : process(ap_CS_fsm_state2, exitcond1_fu_83_p2)
    begin
        if (((exitcond1_fu_83_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state2, exitcond1_fu_83_p2)
    begin
        if (((exitcond1_fu_83_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    ap_return <= ap_const_lv32_0;
    cam_fb_address0 <= tmp_6_fu_150_p1(12 - 1 downto 0);

    cam_fb_ce0_assign_proc : process(ap_CS_fsm_state3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            cam_fb_ce0 <= ap_const_logic_1;
        else 
            cam_fb_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    exitcond1_fu_83_p2 <= "1" when (y_reg_61 = ap_const_lv8_80) else "0";
    exitcond_fu_121_p2 <= "1" when (x_reg_72 = ap_const_lv8_80) else "0";
    nn_fb_address0 <= tmp_8_fu_160_p1(14 - 1 downto 0);

    nn_fb_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            nn_fb_ce0 <= ap_const_logic_1;
        else 
            nn_fb_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    nn_fb_d0 <= cam_fb_q0;

    nn_fb_we0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            nn_fb_we0 <= ap_const_logic_1;
        else 
            nn_fb_we0 <= ap_const_logic_0;
        end if; 
    end process;

    p_lshr_f1_cast_fu_133_p4 <= x_reg_72(6 downto 1);
    tmp_2_fu_109_p3 <= (tmp_fu_105_p1 & ap_const_lv7_0);
    tmp_5_fu_143_p3 <= (p_lshr_f_cast_reg_172 & p_lshr_f1_cast_fu_133_p4);
    tmp_6_fu_150_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_5_fu_143_p3),64));
    tmp_7_fu_155_p2 <= std_logic_vector(unsigned(tmp_2_reg_177) + unsigned(x_cast3_fu_117_p1));
    tmp_8_fu_160_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_7_reg_195),64));
    tmp_fu_105_p1 <= y_reg_61(7 - 1 downto 0);
    x_1_fu_127_p2 <= std_logic_vector(unsigned(x_reg_72) + unsigned(ap_const_lv8_1));
    x_cast3_fu_117_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(x_reg_72),14));
    y_1_fu_89_p2 <= std_logic_vector(unsigned(y_reg_61) + unsigned(ap_const_lv8_1));
end behav;
