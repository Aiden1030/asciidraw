#!/bin/bash



if [[ ! -f asciidraw.c ]]
then
	echo "Error cannot locate asciidraw.c"
	exit 1
fi

gcc -o asciidraw asciidraw.c -lm



result=$?

if [[ $result -ne 0 ]]

then
	echo "Complier error. 
	result is $result"
	exit $result
fi

#1(grid test)
echo " --- test shapes that are partly not in grid --- "
echo '
./asciidraw <<ENDOFCMDS
GRID 40 50
LINE 30,40 70,60
LINE 0,10 100,154
CIRCLE 40,50 25
RECTANGLE 20,70 89,32
DISPLAY
END
ENDOFCMDS
'
./asciidraw<<ENDOFCMDS
GRID 40 50
LINE 30,40 70,60
LINE 0,10 100,154
CIRCLE 40,50 25
RECTANGLE 20,70 89,32
DISPLAY
END
ENDOFCMDS

#2(line test)
echo " --- test lines with different slope --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 40 40
LINE 17,59 90, 6
CHAR &
LINE 6,5 35,39
LINE 13,18 31,55

LINE 10,10 10,100
LINE 0,10 40,10
CHAR %
DISPLAY
END
ENDOFCMDS
'
./asciidraw <<ENDOFCMDS
GRID 40 40
LINE 17,59 90, 6
CHAR &
LINE 6,5 35,39
LINE 13,18 31,55

LINE 10,10 10,100
LINE 0,10 40,10
CHAR %
DISPLAY
END
ENDOFCMDS



#3(char test)
echo " --- test CHAR command --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
CIRCLE 20,30 40
CHAR $
RECTANGLE 12,70 59,10
CHAR ^
LINE 5,5 10,10
CHAR !
CIRCLE 94,29 43
END
ENDOFCMDS
'
./asciidraw <<ENDOFCMDS
GRID 100 100
CIRCLE 20,30 40
CHAR $
RECTANGLE 12,70 59,10
CHAR ^
LINE 5,5 10,10
CHAR !
CIRCLE 94,29 43
END
ENDOFCMDS


#4(invalid command test)
echo " --- test command misspelling cases --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
rectangle 40,40 223,10
CIRcle 90,20 9
CIRCLE 9,9 10
DISPLAY
END
ENDOFCMDS
'
./asciidraw <<ENDOFCMDS
GRID 100 100
rectangle 40,40 223,10
CIRcle 90,20 9
CIRCLE 9,9 10
DISPLAY
END
ENDOFCMDS

#5(GRID error test)
echo " --- test GRID changing error   --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
CIRCLE 30,30 10
GRID 20 20
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 100 100
CIRCLE 30,30 10
GRID 20 20
END
ENDOFCMDS


#6(CIRCLE test)
echo " --- test different sizes of circles  --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
CIRCLE 20,40 1
CIRCLE 40,30 18
CIRCLE 32 41 9
CIRCLE 100 100 69
DISPLAY
END
ENDOFCMDS
'
./asciidraw <<ENDOFCMDS
GRID 100 100
CIRCLE 20,40 1
CIRCLE 40,30 18
CIRCLE 32 41 9
CIRCLE 100 100 69
DISPLAY
END
ENDOFCMDS

#7(rectangle wrong coordinate test)
echo " --- test rectangles with invalid coorinates  --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
RECTANGLE 70,10 10,50
RECTANGLE 99,1 4,5
RECTANGLE 11,22 91,43
RECTANGLE 10,90 90,10 
DISPLAY
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 100 100
RECTANGLE 70,10 10,50
RECTANGLE 99,1 4,5
RECTANGLE 11,22 91,43
RECTANGLE 10,90 90,10 
DISPLAY
END
ENDOFCMDS

#8(coordinates invalid/out of grid test)
echo " --- test invalid coordinates  --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
CIRCLE 150,400 50
RECTANGLE 832,12 68,90
LINE 101,101 101,101
DISPLAY
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 100 100
CIRCLE 150,400 50
RECTANGLE 832,12 68,90
LINE 101,101 101,101
DISPLAY
END
ENDOFCMDS

#9(lines with only width < 5, connection test )
echo " --- test lines with large slope --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
LINE 1,4 4,100
LINE 5,8 9,88
LINE 15,34 14,100
DISPLAY
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 100 100
LINE 1,4 4,100
LINE 5,8 9,88
LINE 15,34 14,100
DISPLAY
END
ENDOFCMDS

#10(lines with only height <5, connection test)
echo " --- test lines with almost no slope --- "
echo '
./asciidraw <<
ENDOFCMDS
GRID 100 100
LINE 1,1 100,2
LINE 4,9 99,3
LINE 23,55 88,58
LINE 15,15 100,16
DISPLAY
END
ENDOFCMDS
'
./asciidraw <<ENDOFCMDS
GRID 100 100
LINE 1,1 100,2
LINE 4,9 99,3
LINE 23,55 88,58
LINE 15,15 100,16
DISPLAY
END
ENDOFCMDS


