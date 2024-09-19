CREATE OR REPLACE FUNCTION `_MATLAB_Blob转Float` (`Blob` TINYBLOB) RETURNS FLOAT COMMENT '输入一个4字节BLOB，将其重新解释为FLOAT值' DETERMINISTIC NO SQL SQL SECURITY INVOKER
BEGIN DECLARE 整数 INT UNSIGNED;

SET
	整数 = CONV(HEX(REVERSE(`Blob`)), 16, 10);

RETURN (1 - (整数 >> 31) * 2) * ((整数 & (1 << 23) -1) / (1 << 23) + 1) * POWER(
	2,
	CAST(整数 >> 23 & (1 << 8) -1 AS SIGNED) - CAST(1 << 7 AS SIGNED) + 1
);

END