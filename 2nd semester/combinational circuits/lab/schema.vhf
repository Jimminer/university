--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : schema.vhf
-- /___/   /\     Timestamp : 05/30/2022 14:01:12
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3 -flat -suppress -vhdl C:/Users/lab/Desktop/xristos/ergasia4502/schema.vhf -w C:/Users/lab/Desktop/xristos/ergasia4502/schema.sch
--Design Name: schema
--Device: spartan3
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity schema is
   port ( inp  : in    std_logic; 
          outp : out   std_logic);
end schema;

architecture BEHAVIORAL of schema is
   attribute BOX_TYPE   : string ;
   attribute IOSTANDARD : string ;
   attribute SLEW       : string ;
   attribute DRIVE      : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_2 : std_logic;
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component OBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute IOSTANDARD of OBUF : component is "DEFAULT";
   attribute SLEW of OBUF : component is "SLOW";
   attribute DRIVE of OBUF : component is "12";
   attribute BOX_TYPE of OBUF : component is "BLACK_BOX";
   
   component IBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute IOSTANDARD of IBUF : component is "DEFAULT";
   attribute BOX_TYPE of IBUF : component is "BLACK_BOX";
   
begin
   XLXI_1 : INV
      port map (I=>XLXN_2,
                O=>XLXN_1);
   
   XLXI_3 : OBUF
      port map (I=>XLXN_1,
                O=>outp);
   
   XLXI_4 : IBUF
      port map (I=>inp,
                O=>XLXN_2);
   
end BEHAVIORAL;


