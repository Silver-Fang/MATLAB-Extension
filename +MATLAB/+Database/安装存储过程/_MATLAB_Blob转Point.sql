CREATE OR REPLACE FUNCTION `_MATLAB_Blob转Point` (`Blob` TINYBLOB) RETURNS POINT COMMENT '输入一个4字节BLOB，将其重新解释为两个 SMALLINT UNSIGNED 组合成的POINT值' DETERMINISTIC NO SQL SQL SECURITY INVOKER
BEGIN DECLARE 整数 INT UNSIGNED;

SET
	整数 = CONV(HEX(REVERSE(`Blob`)), 16, 10);

RETURN POINT (整数 & b'1111', 整数 >> 4);

END