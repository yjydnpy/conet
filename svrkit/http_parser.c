
#line 1 "svrkit/http_parser.rl"
#include "http_parser.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define LEN(AT, FPC) (FPC - parser->AT)
#define MARK(M,FPC) (parser->M = FPC)
#define PTR_TO(F) (parser->F)

/** machine **/

#line 139 "svrkit/http_parser.rl"


/** Data **/

#line 25 "svrkit/http_parser.c"
static const char _http_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 14, 1, 
	16, 2, 0, 3, 2, 0, 5, 2, 
	0, 6, 2, 0, 8, 2, 0, 9, 
	2, 3, 0, 2, 3, 4, 2, 11, 
	13, 2, 15, 13, 3, 14, 15, 13
	
};

static const short _http_parser_key_offsets[] = {
	0, 0, 8, 17, 27, 29, 30, 31, 
	32, 33, 34, 36, 39, 41, 44, 45, 
	65, 66, 86, 92, 97, 102, 109, 118, 
	125, 132, 141, 148, 153, 162, 169, 176, 
	183, 189, 196, 203, 210, 216, 225, 232, 
	239, 246, 253, 260, 266, 274, 281, 288, 
	295, 302, 309, 316, 336, 358, 382, 404, 
	426, 450, 472, 492, 516, 538, 560, 582, 
	601, 623, 645, 667, 687, 711, 733, 755, 
	777, 799, 821, 841, 849, 871, 893, 915, 
	937, 959, 979, 1001, 1025, 1047, 1069, 1089, 
	1091, 1092, 1114, 1136, 1160, 1182, 1202, 1226, 
	1248, 1270, 1292, 1312, 1314, 1315, 1337, 1359, 
	1381, 1401, 1425, 1447, 1469, 1491, 1513, 1535, 
	1555, 1563, 1570, 1592, 1614, 1636, 1656, 1658, 
	1659, 1668, 1677, 1683, 1689, 1699, 1708, 1714, 
	1720, 1731, 1737, 1743, 1753, 1759, 1765, 1774, 
	1783, 1789, 1795, 1804, 1813, 1822, 1831, 1840, 
	1849, 1858, 1867, 1876, 1885, 1894, 1903, 1912, 
	1921, 1930, 1939, 1948, 1957, 1958
};

static const char _http_parser_trans_keys[] = {
	36, 95, 45, 46, 48, 57, 65, 90, 
	32, 36, 95, 45, 46, 48, 57, 65, 
	90, 42, 43, 47, 58, 45, 57, 65, 
	90, 97, 122, 32, 35, 72, 84, 84, 
	80, 47, 48, 57, 46, 48, 57, 48, 
	57, 13, 48, 57, 10, 13, 33, 65, 
	67, 97, 99, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 10, 33, 58, 65, 67, 97, 99, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 13, 32, 
	65, 67, 97, 99, 13, 65, 67, 97, 
	99, 13, 65, 67, 97, 99, 13, 65, 
	67, 79, 97, 99, 111, 13, 65, 67, 
	69, 79, 97, 99, 101, 111, 13, 65, 
	67, 79, 97, 99, 111, 13, 65, 67, 
	78, 97, 99, 110, 13, 65, 67, 78, 
	84, 97, 99, 110, 116, 13, 65, 67, 
	69, 97, 99, 101, 13, 65, 67, 97, 
	99, 13, 65, 67, 79, 84, 97, 99, 
	111, 116, 13, 65, 67, 73, 97, 99, 
	105, 13, 65, 67, 79, 97, 99, 111, 
	13, 65, 67, 78, 97, 99, 110, 13, 
	58, 65, 67, 97, 99, 13, 65, 67, 
	69, 97, 99, 101, 13, 65, 67, 78, 
	97, 99, 110, 13, 65, 67, 84, 97, 
	99, 116, 13, 45, 65, 67, 97, 99, 
	13, 65, 67, 76, 84, 97, 99, 108, 
	116, 13, 65, 67, 69, 97, 99, 101, 
	13, 65, 67, 78, 97, 99, 110, 13, 
	65, 67, 71, 97, 99, 103, 13, 65, 
	67, 84, 97, 99, 116, 13, 65, 67, 
	72, 97, 99, 104, 13, 58, 65, 67, 
	97, 99, 13, 32, 65, 67, 97, 99, 
	48, 57, 13, 65, 67, 97, 99, 48, 
	57, 13, 65, 67, 89, 97, 99, 121, 
	13, 65, 67, 80, 97, 99, 112, 13, 
	65, 67, 69, 97, 99, 101, 13, 65, 
	67, 80, 97, 99, 112, 13, 65, 67, 
	84, 97, 99, 116, 33, 58, 65, 67, 
	97, 99, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 79, 97, 99, 111, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 33, 58, 
	65, 67, 69, 79, 97, 99, 101, 111, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 33, 58, 
	65, 67, 79, 97, 99, 111, 124, 126, 
	35, 39, 42, 43, 45, 46, 48, 57, 
	66, 90, 94, 122, 33, 58, 65, 67, 
	78, 97, 99, 110, 124, 126, 35, 39, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	94, 122, 33, 58, 65, 67, 78, 84, 
	97, 99, 110, 116, 124, 126, 35, 39, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	94, 122, 33, 58, 65, 67, 69, 97, 
	99, 101, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 97, 99, 124, 126, 
	35, 39, 42, 43, 45, 46, 48, 57, 
	66, 90, 94, 122, 33, 58, 65, 67, 
	79, 84, 97, 99, 111, 116, 124, 126, 
	35, 39, 42, 43, 45, 46, 48, 57, 
	66, 90, 94, 122, 33, 58, 65, 67, 
	73, 97, 99, 105, 124, 126, 35, 39, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	94, 122, 33, 58, 65, 67, 79, 97, 
	99, 111, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 78, 97, 99, 110, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 33, 65, 
	67, 97, 99, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 69, 97, 99, 
	101, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 78, 97, 99, 110, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 58, 65, 
	67, 84, 97, 99, 116, 124, 126, 35, 
	39, 42, 43, 45, 46, 48, 57, 66, 
	90, 94, 122, 33, 45, 46, 58, 65, 
	67, 97, 99, 124, 126, 35, 39, 42, 
	43, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 76, 84, 97, 99, 108, 
	116, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 69, 97, 99, 101, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 58, 65, 
	67, 78, 97, 99, 110, 124, 126, 35, 
	39, 42, 43, 45, 46, 48, 57, 66, 
	90, 94, 122, 33, 58, 65, 67, 71, 
	97, 99, 103, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 84, 97, 99, 
	116, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 72, 97, 99, 104, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 58, 65, 
	67, 97, 99, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 13, 32, 65, 67, 97, 99, 48, 
	57, 33, 58, 65, 67, 89, 97, 99, 
	121, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 80, 97, 99, 112, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 58, 65, 
	67, 69, 97, 99, 101, 124, 126, 35, 
	39, 42, 43, 45, 46, 48, 57, 66, 
	90, 94, 122, 33, 58, 65, 67, 80, 
	97, 99, 112, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 84, 97, 99, 
	116, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 97, 99, 124, 126, 35, 
	39, 42, 43, 45, 46, 48, 57, 66, 
	90, 94, 122, 33, 58, 65, 67, 79, 
	97, 99, 111, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 69, 79, 97, 
	99, 101, 111, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 80, 97, 99, 
	112, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 84, 97, 99, 116, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 58, 65, 
	67, 97, 99, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 13, 32, 13, 33, 58, 65, 67, 
	79, 97, 99, 111, 124, 126, 35, 39, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	94, 122, 33, 58, 65, 67, 78, 97, 
	99, 110, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 78, 84, 97, 99, 
	110, 116, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 69, 97, 99, 101, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 33, 58, 
	65, 67, 97, 99, 124, 126, 35, 39, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	94, 122, 33, 58, 65, 67, 79, 84, 
	97, 99, 111, 116, 124, 126, 35, 39, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	94, 122, 33, 58, 65, 67, 73, 97, 
	99, 105, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 79, 97, 99, 111, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 33, 58, 
	65, 67, 78, 97, 99, 110, 124, 126, 
	35, 39, 42, 43, 45, 46, 48, 57, 
	66, 90, 94, 122, 33, 58, 65, 67, 
	97, 99, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	13, 32, 13, 33, 58, 65, 67, 69, 
	97, 99, 101, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 78, 97, 99, 
	110, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 84, 97, 99, 116, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 45, 46, 
	58, 65, 67, 97, 99, 124, 126, 35, 
	39, 42, 43, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 76, 84, 97, 
	99, 108, 116, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 69, 97, 99, 
	101, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 78, 97, 99, 110, 124, 
	126, 35, 39, 42, 43, 45, 46, 48, 
	57, 66, 90, 94, 122, 33, 58, 65, 
	67, 71, 97, 99, 103, 124, 126, 35, 
	39, 42, 43, 45, 46, 48, 57, 66, 
	90, 94, 122, 33, 58, 65, 67, 84, 
	97, 99, 116, 124, 126, 35, 39, 42, 
	43, 45, 46, 48, 57, 66, 90, 94, 
	122, 33, 58, 65, 67, 72, 97, 99, 
	104, 124, 126, 35, 39, 42, 43, 45, 
	46, 48, 57, 66, 90, 94, 122, 33, 
	58, 65, 67, 97, 99, 124, 126, 35, 
	39, 42, 43, 45, 46, 48, 57, 66, 
	90, 94, 122, 13, 32, 65, 67, 97, 
	99, 48, 57, 13, 65, 67, 97, 99, 
	48, 57, 33, 58, 65, 67, 89, 97, 
	99, 121, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	33, 58, 65, 67, 80, 97, 99, 112, 
	124, 126, 35, 39, 42, 43, 45, 46, 
	48, 57, 66, 90, 94, 122, 33, 58, 
	65, 67, 69, 97, 99, 101, 124, 126, 
	35, 39, 42, 43, 45, 46, 48, 57, 
	66, 90, 94, 122, 33, 58, 65, 67, 
	97, 99, 124, 126, 35, 39, 42, 43, 
	45, 46, 48, 57, 66, 90, 94, 122, 
	13, 32, 13, 32, 37, 60, 62, 127, 
	0, 31, 34, 35, 32, 37, 60, 62, 
	127, 0, 31, 34, 35, 48, 57, 65, 
	70, 97, 102, 48, 57, 65, 70, 97, 
	102, 43, 58, 45, 46, 48, 57, 65, 
	90, 97, 122, 32, 34, 35, 37, 60, 
	62, 127, 0, 31, 48, 57, 65, 70, 
	97, 102, 48, 57, 65, 70, 97, 102, 
	32, 34, 35, 37, 59, 60, 62, 63, 
	127, 0, 31, 48, 57, 65, 70, 97, 
	102, 48, 57, 65, 70, 97, 102, 32, 
	34, 35, 37, 60, 62, 63, 127, 0, 
	31, 48, 57, 65, 70, 97, 102, 48, 
	57, 65, 70, 97, 102, 32, 34, 35, 
	37, 60, 62, 127, 0, 31, 32, 34, 
	35, 37, 60, 62, 127, 0, 31, 48, 
	57, 65, 70, 97, 102, 48, 57, 65, 
	70, 97, 102, 32, 36, 95, 45, 46, 
	48, 57, 65, 90, 32, 36, 95, 45, 
	46, 48, 57, 65, 90, 32, 36, 95, 
	45, 46, 48, 57, 65, 90, 32, 36, 
	95, 45, 46, 48, 57, 65, 90, 32, 
	36, 95, 45, 46, 48, 57, 65, 90, 
	32, 36, 95, 45, 46, 48, 57, 65, 
	90, 32, 36, 95, 45, 46, 48, 57, 
	65, 90, 32, 36, 95, 45, 46, 48, 
	57, 65, 90, 32, 36, 95, 45, 46, 
	48, 57, 65, 90, 32, 36, 95, 45, 
	46, 48, 57, 65, 90, 32, 36, 95, 
	45, 46, 48, 57, 65, 90, 32, 36, 
	95, 45, 46, 48, 57, 65, 90, 32, 
	36, 95, 45, 46, 48, 57, 65, 90, 
	32, 36, 95, 45, 46, 48, 57, 65, 
	90, 32, 36, 95, 45, 46, 48, 57, 
	65, 90, 32, 36, 95, 45, 46, 48, 
	57, 65, 90, 32, 36, 95, 45, 46, 
	48, 57, 65, 90, 32, 36, 95, 45, 
	46, 48, 57, 65, 90, 32, 0
};

static const char _http_parser_single_lengths[] = {
	0, 2, 3, 4, 2, 1, 1, 1, 
	1, 1, 0, 1, 0, 1, 1, 8, 
	1, 8, 6, 5, 5, 7, 9, 7, 
	7, 9, 7, 5, 9, 7, 7, 7, 
	6, 7, 7, 7, 6, 9, 7, 7, 
	7, 7, 7, 6, 6, 5, 7, 7, 
	7, 7, 7, 8, 10, 12, 10, 10, 
	12, 10, 8, 12, 10, 10, 10, 7, 
	10, 10, 10, 10, 12, 10, 10, 10, 
	10, 10, 8, 6, 10, 10, 10, 10, 
	10, 8, 10, 12, 10, 10, 8, 2, 
	1, 10, 10, 12, 10, 8, 12, 10, 
	10, 10, 8, 2, 1, 10, 10, 10, 
	10, 12, 10, 10, 10, 10, 10, 8, 
	6, 5, 10, 10, 10, 8, 2, 1, 
	5, 5, 0, 0, 2, 7, 0, 0, 
	9, 0, 0, 8, 0, 0, 7, 7, 
	0, 0, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 1, 0
};

static const char _http_parser_range_lengths[] = {
	0, 3, 3, 3, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 1, 0, 6, 
	0, 6, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 6, 6, 6, 6, 6, 
	6, 6, 6, 6, 6, 6, 6, 6, 
	6, 6, 6, 5, 6, 6, 6, 6, 
	6, 6, 6, 1, 6, 6, 6, 6, 
	6, 6, 6, 6, 6, 6, 6, 0, 
	0, 6, 6, 6, 6, 6, 6, 6, 
	6, 6, 6, 0, 0, 6, 6, 6, 
	5, 6, 6, 6, 6, 6, 6, 6, 
	1, 1, 6, 6, 6, 6, 0, 0, 
	2, 2, 3, 3, 4, 1, 3, 3, 
	1, 3, 3, 1, 3, 3, 1, 1, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 0, 0
};

static const short _http_parser_index_offsets[] = {
	0, 0, 6, 13, 21, 24, 26, 28, 
	30, 32, 34, 36, 39, 41, 44, 46, 
	61, 63, 78, 85, 91, 97, 105, 115, 
	123, 131, 141, 149, 155, 165, 173, 181, 
	189, 196, 204, 212, 220, 227, 237, 245, 
	253, 261, 269, 277, 284, 292, 299, 307, 
	315, 323, 331, 339, 354, 371, 390, 407, 
	424, 443, 460, 475, 494, 511, 528, 545, 
	559, 576, 593, 610, 626, 645, 662, 679, 
	696, 713, 730, 745, 753, 770, 787, 804, 
	821, 838, 853, 870, 889, 906, 923, 938, 
	941, 943, 960, 977, 996, 1013, 1028, 1047, 
	1064, 1081, 1098, 1113, 1116, 1118, 1135, 1152, 
	1169, 1185, 1204, 1221, 1238, 1255, 1272, 1289, 
	1304, 1312, 1319, 1336, 1353, 1370, 1385, 1388, 
	1390, 1398, 1406, 1410, 1414, 1421, 1430, 1434, 
	1438, 1449, 1453, 1457, 1467, 1471, 1475, 1484, 
	1493, 1497, 1501, 1508, 1515, 1522, 1529, 1536, 
	1543, 1550, 1557, 1564, 1571, 1578, 1585, 1592, 
	1599, 1606, 1613, 1620, 1627, 1629
};

static const unsigned char _http_parser_indicies[] = {
	0, 0, 0, 0, 0, 1, 2, 3, 
	3, 3, 3, 3, 1, 4, 5, 6, 
	7, 5, 5, 5, 1, 8, 9, 1, 
	10, 1, 11, 1, 12, 1, 13, 1, 
	14, 1, 15, 1, 16, 15, 1, 17, 
	1, 18, 17, 1, 19, 1, 20, 21, 
	22, 23, 22, 23, 21, 21, 21, 21, 
	21, 21, 21, 21, 1, 24, 1, 25, 
	26, 27, 28, 27, 28, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 30, 31, 
	32, 33, 32, 33, 29, 35, 36, 37, 
	36, 37, 34, 35, 36, 38, 36, 38, 
	34, 35, 36, 39, 40, 36, 39, 40, 
	34, 35, 36, 37, 41, 40, 36, 37, 
	41, 40, 34, 35, 36, 37, 40, 36, 
	37, 40, 34, 35, 36, 37, 42, 36, 
	37, 42, 34, 35, 36, 37, 43, 44, 
	36, 37, 43, 44, 34, 35, 36, 37, 
	45, 36, 37, 45, 34, 35, 36, 46, 
	36, 46, 34, 35, 36, 37, 40, 47, 
	36, 37, 40, 47, 34, 35, 36, 37, 
	48, 36, 37, 48, 34, 35, 36, 37, 
	49, 36, 37, 49, 34, 35, 36, 37, 
	50, 36, 37, 50, 34, 35, 1, 36, 
	37, 36, 37, 34, 35, 36, 37, 51, 
	36, 37, 51, 34, 35, 36, 37, 52, 
	36, 37, 52, 34, 35, 36, 37, 53, 
	36, 37, 53, 34, 35, 54, 36, 37, 
	36, 37, 34, 35, 36, 37, 55, 56, 
	36, 37, 55, 56, 34, 35, 36, 37, 
	57, 36, 37, 57, 34, 35, 36, 37, 
	58, 36, 37, 58, 34, 35, 36, 37, 
	59, 36, 37, 59, 34, 35, 36, 37, 
	60, 36, 37, 60, 34, 35, 36, 37, 
	61, 36, 37, 61, 34, 35, 62, 36, 
	37, 36, 37, 34, 35, 62, 36, 37, 
	36, 37, 63, 34, 1, 36, 37, 36, 
	37, 64, 34, 35, 36, 37, 65, 36, 
	37, 65, 34, 35, 36, 37, 66, 36, 
	37, 66, 34, 35, 36, 37, 50, 36, 
	37, 50, 34, 35, 36, 37, 67, 36, 
	37, 67, 34, 35, 36, 37, 50, 36, 
	37, 50, 34, 25, 26, 27, 68, 27, 
	68, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 26, 27, 69, 70, 27, 
	69, 70, 25, 25, 25, 25, 25, 25, 
	25, 25, 1, 25, 26, 27, 28, 71, 
	70, 27, 28, 71, 70, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 25, 26, 
	27, 28, 70, 27, 28, 70, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 72, 27, 28, 72, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 73, 74, 27, 28, 
	73, 74, 25, 25, 25, 25, 25, 25, 
	25, 25, 1, 25, 26, 27, 28, 75, 
	27, 28, 75, 25, 25, 25, 25, 25, 
	25, 25, 25, 1, 25, 26, 27, 76, 
	27, 76, 25, 25, 25, 25, 25, 25, 
	25, 25, 1, 25, 26, 27, 28, 70, 
	77, 27, 28, 70, 77, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 25, 26, 
	27, 28, 78, 27, 28, 78, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 79, 27, 28, 79, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 80, 27, 28, 80, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 27, 28, 27, 28, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 81, 27, 28, 81, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 82, 27, 28, 82, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 83, 27, 28, 
	83, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 84, 25, 26, 27, 28, 
	27, 28, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 26, 27, 28, 85, 86, 
	27, 28, 85, 86, 25, 25, 25, 25, 
	25, 25, 25, 25, 1, 25, 26, 27, 
	28, 87, 27, 28, 87, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 25, 26, 
	27, 28, 88, 27, 28, 88, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 89, 27, 28, 89, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 90, 27, 28, 90, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 91, 27, 28, 
	91, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 92, 27, 28, 27, 28, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 30, 93, 32, 33, 32, 33, 94, 
	29, 25, 26, 27, 28, 95, 27, 28, 
	95, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 26, 27, 28, 96, 27, 
	28, 96, 25, 25, 25, 25, 25, 25, 
	25, 25, 1, 25, 26, 27, 28, 80, 
	27, 28, 80, 25, 25, 25, 25, 25, 
	25, 25, 25, 1, 25, 26, 27, 28, 
	97, 27, 28, 97, 25, 25, 25, 25, 
	25, 25, 25, 25, 1, 25, 26, 27, 
	28, 80, 27, 28, 80, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 25, 26, 
	27, 98, 27, 98, 25, 25, 25, 25, 
	25, 25, 25, 25, 1, 25, 26, 27, 
	99, 70, 27, 99, 70, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 25, 26, 
	27, 28, 100, 70, 27, 28, 100, 70, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 101, 27, 28, 
	101, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 26, 27, 28, 102, 27, 
	28, 102, 25, 25, 25, 25, 25, 25, 
	25, 25, 1, 25, 103, 27, 28, 27, 
	28, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 105, 106, 104, 108, 107, 25, 
	26, 27, 28, 109, 27, 28, 109, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 110, 27, 28, 110, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 111, 112, 27, 
	28, 111, 112, 25, 25, 25, 25, 25, 
	25, 25, 25, 1, 25, 26, 27, 28, 
	113, 27, 28, 113, 25, 25, 25, 25, 
	25, 25, 25, 25, 1, 25, 26, 27, 
	114, 27, 114, 25, 25, 25, 25, 25, 
	25, 25, 25, 1, 25, 26, 27, 28, 
	70, 115, 27, 28, 70, 115, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 116, 27, 28, 116, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 117, 27, 28, 117, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 118, 27, 28, 
	118, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 119, 27, 28, 27, 28, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 121, 122, 120, 124, 123, 25, 26, 
	27, 28, 125, 27, 28, 125, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 126, 27, 28, 126, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 127, 27, 28, 127, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 128, 25, 26, 27, 28, 27, 
	28, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 129, 130, 27, 
	28, 129, 130, 25, 25, 25, 25, 25, 
	25, 25, 25, 1, 25, 26, 27, 28, 
	131, 27, 28, 131, 25, 25, 25, 25, 
	25, 25, 25, 25, 1, 25, 26, 27, 
	28, 132, 27, 28, 132, 25, 25, 25, 
	25, 25, 25, 25, 25, 1, 25, 26, 
	27, 28, 133, 27, 28, 133, 25, 25, 
	25, 25, 25, 25, 25, 25, 1, 25, 
	26, 27, 28, 134, 27, 28, 134, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 135, 27, 28, 135, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 136, 27, 28, 27, 28, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	30, 137, 32, 33, 32, 33, 138, 29, 
	139, 36, 37, 36, 37, 140, 34, 25, 
	26, 27, 28, 141, 27, 28, 141, 25, 
	25, 25, 25, 25, 25, 25, 25, 1, 
	25, 26, 27, 28, 142, 27, 28, 142, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 25, 26, 27, 28, 143, 27, 28, 
	143, 25, 25, 25, 25, 25, 25, 25, 
	25, 1, 25, 144, 27, 28, 27, 28, 
	25, 25, 25, 25, 25, 25, 25, 25, 
	1, 146, 147, 145, 149, 148, 151, 152, 
	1, 1, 1, 1, 1, 150, 154, 155, 
	1, 1, 1, 1, 1, 153, 156, 156, 
	156, 1, 153, 153, 153, 1, 157, 158, 
	157, 157, 157, 157, 1, 8, 1, 9, 
	159, 1, 1, 1, 1, 158, 160, 160, 
	160, 1, 158, 158, 158, 1, 162, 1, 
	163, 164, 165, 1, 1, 166, 1, 1, 
	161, 167, 167, 167, 1, 161, 161, 161, 
	1, 8, 1, 9, 169, 1, 1, 170, 
	1, 1, 168, 171, 171, 171, 1, 168, 
	168, 168, 1, 173, 1, 174, 175, 1, 
	1, 1, 1, 172, 177, 1, 178, 179, 
	1, 1, 1, 1, 176, 180, 180, 180, 
	1, 176, 176, 176, 1, 2, 181, 181, 
	181, 181, 181, 1, 2, 182, 182, 182, 
	182, 182, 1, 2, 183, 183, 183, 183, 
	183, 1, 2, 184, 184, 184, 184, 184, 
	1, 2, 185, 185, 185, 185, 185, 1, 
	2, 186, 186, 186, 186, 186, 1, 2, 
	187, 187, 187, 187, 187, 1, 2, 188, 
	188, 188, 188, 188, 1, 2, 189, 189, 
	189, 189, 189, 1, 2, 190, 190, 190, 
	190, 190, 1, 2, 191, 191, 191, 191, 
	191, 1, 2, 192, 192, 192, 192, 192, 
	1, 2, 193, 193, 193, 193, 193, 1, 
	2, 194, 194, 194, 194, 194, 1, 2, 
	195, 195, 195, 195, 195, 1, 2, 196, 
	196, 196, 196, 196, 1, 2, 197, 197, 
	197, 197, 197, 1, 2, 198, 198, 198, 
	198, 198, 1, 2, 1, 1, 0
};

static const unsigned char _http_parser_trans_targs[] = {
	2, 0, 3, 138, 4, 124, 128, 125, 
	5, 120, 6, 7, 8, 9, 10, 11, 
	12, 13, 14, 15, 16, 17, 81, 89, 
	157, 17, 18, 51, 54, 19, 14, 18, 
	20, 23, 19, 14, 20, 23, 21, 22, 
	24, 49, 25, 26, 33, 27, 28, 29, 
	30, 31, 32, 34, 35, 36, 37, 38, 
	46, 39, 40, 41, 42, 43, 44, 45, 
	45, 47, 48, 50, 52, 53, 55, 79, 
	56, 57, 64, 58, 59, 60, 61, 62, 
	63, 65, 66, 67, 68, 69, 76, 70, 
	71, 72, 73, 74, 75, 75, 45, 77, 
	78, 80, 82, 83, 84, 85, 86, 87, 
	88, 14, 87, 88, 14, 90, 91, 92, 
	101, 93, 94, 95, 96, 97, 98, 99, 
	100, 14, 99, 100, 14, 102, 103, 104, 
	105, 106, 114, 107, 108, 109, 110, 111, 
	112, 112, 113, 14, 113, 115, 116, 117, 
	118, 119, 14, 118, 119, 14, 121, 5, 
	122, 121, 5, 122, 123, 124, 125, 126, 
	127, 128, 5, 120, 129, 131, 134, 130, 
	131, 132, 134, 133, 135, 5, 120, 136, 
	135, 5, 120, 136, 137, 139, 140, 141, 
	142, 143, 144, 145, 146, 147, 148, 149, 
	150, 151, 152, 153, 154, 155, 156
};

static const char _http_parser_trans_actions[] = {
	1, 0, 25, 0, 1, 1, 1, 1, 
	27, 27, 1, 0, 0, 0, 0, 0, 
	0, 0, 21, 0, 0, 3, 3, 3, 
	31, 0, 5, 0, 0, 7, 51, 7, 
	7, 7, 0, 9, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 5, 7, 48, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 36, 1, 0, 11, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 39, 1, 0, 13, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	5, 7, 33, 15, 0, 0, 0, 0, 
	0, 1, 42, 1, 0, 17, 1, 45, 
	1, 0, 19, 0, 0, 0, 0, 0, 
	0, 0, 54, 54, 0, 23, 23, 0, 
	0, 0, 0, 0, 29, 60, 60, 29, 
	0, 57, 57, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const int http_parser_start = 1;
static const int http_parser_first_final = 157;
static const int http_parser_error = 0;

static const int http_parser_en_main = 1;


#line 143 "svrkit/http_parser.rl"


void http_parser_init(http_parser_t *parser)  {
  int cs = 0;
  
#line 654 "svrkit/http_parser.c"
	{
	cs = http_parser_start;
	}

#line 148 "svrkit/http_parser.rl"

  parser->status = cs;
  parser->overflow_error = FALSE;
  parser->body_start = 0;
  parser->content_length = 0;
  parser->mark = 0;
  parser->nread = 0;
  parser->field_len = 0;
  parser->field_start = 0;
  parser->data = NULL;
  parser->http_field = NULL;
  parser->headers_num = 0;
}


/** exec **/
size_t http_parser_execute(http_parser_t *parser, const char *buffer, size_t len, size_t off)  {
  const char *p, *pe;
  int cs = parser->status;
  
  assert(off <= len && "offset past end of buffer");
  
  p = buffer+off;
  pe = buffer+len;
  
  
#line 686 "svrkit/http_parser.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _http_parser_trans_keys + _http_parser_key_offsets[cs];
	_trans = _http_parser_index_offsets[cs];

	_klen = _http_parser_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _http_parser_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _http_parser_indicies[_trans];
	cs = _http_parser_trans_targs[_trans];

	if ( _http_parser_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _http_parser_actions + _http_parser_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 19 "svrkit/http_parser.rl"
	{MARK(mark, p); }
	break;
	case 1:
#line 21 "svrkit/http_parser.rl"
	{ parser->header_start = p; }
	break;
	case 2:
#line 22 "svrkit/http_parser.rl"
	{ 
    int num = parser->headers_num;
    if(num >= 100) {
      parser->err_too_many_header = 1;
      {p++; goto _out; }
    }

    init_ref_str(&parser->headers[num].name, parser->header_start, p);
  }
	break;
	case 3:
#line 32 "svrkit/http_parser.rl"
	{ parser->header_val_start = p;}
	break;
	case 4:
#line 34 "svrkit/http_parser.rl"
	{
    int num = parser->headers_num;
    init_ref_str(&parser->headers[num].value, parser->header_val_start, p);
  }
	break;
	case 5:
#line 39 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->accept, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 6:
#line 42 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->connection, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 7:
#line 45 "svrkit/http_parser.rl"
	{
    parser->content_length = atoi(PTR_TO(mark));
    init_ref_str(&parser->content_type, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 8:
#line 50 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->content_type, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 9:
#line 54 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->fragment, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 10:
#line 58 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->version, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 11:
#line 62 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->path, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 12:
#line 66 "svrkit/http_parser.rl"
	{ 
    parser->on_element(parser->data, MONGREL_REQUEST_METHOD, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 13:
#line 70 "svrkit/http_parser.rl"
	{
    init_ref_str(&parser->uri, PTR_TO(mark), LEN(mark, p));
  }
	break;
	case 14:
#line 74 "svrkit/http_parser.rl"
	{MARK(query_start, p); }
	break;
	case 15:
#line 75 "svrkit/http_parser.rl"
	{ 
    init_ref_str(parser->query_string, PTR_TO(query_start), LEN(query_start, p));
  }
	break;
	case 16:
#line 80 "svrkit/http_parser.rl"
	{
    parser->body = p;
    {p++; goto _out; }
  }
	break;
#line 863 "svrkit/http_parser.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 174 "svrkit/http_parser.rl"
  
  parser->status = cs;

  parser->nread += p - (buffer + off);
  
  return(parser->nread);
}

int http_parser_finish(http_parser *parser)
{
  if (http_parser_has_error(parser))
    return -1;
  else if (http_parser_is_finished(parser))
    return 1;
  else
    return 0;
}

int http_parser_has_error(http_parser_t *parser) {
  return parser->status == http_parer_error || parser->err_too_many_header;
}

int http_parser_is_finished(http_parser_t *parser) {
  return parser->status >= http_parser_first_final;
}
