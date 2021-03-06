library IEEE;
LIBRARY WORK;
use IEEE.STD_LOGIC_1164.ALL;
USE WORK.MI_PAQUETE.ALL;

entity PRINCIPAL is
    Port ( CLK, CLR : in  STD_LOGIC;
           INI : in  STD_LOGIC;
           D : in  STD_LOGIC_VECTOR (7 downto 0);
			  AN : out STD_LOGIC_VECTOR (7 downto 0);
           DISP : out  STD_LOGIC_VECTOR (6 downto 0)
			  );
end PRINCIPAL;

architecture Behavioral of PRINCIPAL is
	-- ESTAS SEÑALES SON LAS QUE SE CONECTAN EL CONTADOR Y PRINCIPAL
	SIGNAL IB : STD_LOGIC;
	SIGNAL LB : STD_LOGIC;
	SIGNAL QB : STD_LOGIC_VECTOR (3 DOWNTO 0);

-- ESTAS SEÑALES SON DEL CONVERTIDOR
	SIGNAL QBCD : STD_LOGIC_VECTOR(6 DOWNTO 0);

-- SEÑALES DE UNIDAD DE CONTROL
	SIGNAL Z : STD_LOGIC;
	SIGNAL LA: STD_LOGIC;
	SIGNAL SH: STD_LOGIC;
	SIGNAL S : STD_LOGIC;

-- SEÑALES DEL REGISTRO
	SIGNAL QA : STD_LOGIC_VECTOR( 7 DOWNTO 0);

begin

	AN <= "11111110";
	-- ==== CONTADOR =====
	CONTB : CONTADOR GENERIC MAP (4) PORT MAP( CLK, CLR, IB, LB, X"0", QB ); --Notacion posicional

	-- === CONVERTIDOR ====
	CONV_COD : CONVERTIDOR PORT MAP( --Notacion nominal
				BCD => QB, 
				SEG => QBCD
	); 
	
	-- ==== CONTROL ====
	CTRL : CONTROL PORT MAP(
		CLK => CLK,
		CLR => CLR,
		INI => INI,
		Z => Z,
		A0 => QA(0),
		LA => LA,
		SH => SH,
		LB => LB,
		IB => IB,
		S => S
	);

	-- ==== REGISTRO ====
	REG : REGISTRO GENERIC MAP (8) PORT MAP ( CLK, CLR, SH, LA, X"00", QA);

	-- ==== MUX ====
	DISP <= "1111110" WHEN S = '0' ELSE QBCD;

	
end Behavioral;

