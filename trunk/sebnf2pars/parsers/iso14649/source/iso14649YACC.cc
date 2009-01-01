/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADVANCEDBREPSHAPEREPRESENTATION = 258,
     ANGLETAPER = 259,
     APPROACH = 260,
     APPROVAL = 261,
     APPROVALSTATUS = 262,
     AXIS1PLACEMENT = 263,
     AXIS2PLACEMENT3D = 264,
     BACKBORING = 265,
     BACKSIDECOUNTERBORE = 266,
     BACKSIDECOUNTERSINK = 267,
     BALLENDMILL = 268,
     BIDIRECTIONALMILLING = 269,
     BLOCK = 270,
     BORING = 271,
     BOSS = 272,
     BOTTOMANDSIDEFINISHMILLING = 273,
     BOTTOMANDSIDEROUGHMILLING = 274,
     BULLNOSEENDMILL = 275,
     C = 276,
     CALENDARDATE = 277,
     CARTESIAN = 278,
     CARTESIANPOINT = 279,
     CCP = 280,
     CCW = 281,
     CENTERDRILL = 282,
     CENTERDRILLING = 283,
     CHAMFER = 284,
     CHANNEL = 285,
     CIRCLE = 286,
     CIRCULAROFFSET = 287,
     CIRCULAROMIT = 288,
     CIRCULARPATTERN = 289,
     CLIMB = 290,
     CLOSEDPOCKET = 291,
     COMBINEDDRILLANDREAMER = 292,
     COMPLETECIRCULARPATH = 293,
     COMPOSITECURVE = 294,
     COMPOSITECURVESEGMENT = 295,
     CONICALHOLEBOTTOM = 296,
     CONNECT = 297,
     CONTACT = 298,
     CONTINUOUS = 299,
     CONTOURPARALLEL = 300,
     CONTSAMEGRADIENT = 301,
     CONTSAMEGRADIENTSAMECURVATURE = 302,
     CONVENTIONAL = 303,
     COUNTERBORE = 304,
     COUNTERBOREHOLE = 305,
     COUNTERSINK = 306,
     COUNTERSINKING = 307,
     COUNTERSUNKHOLE = 308,
     CUTTERLOCATIONTRAJECTORY = 309,
     CUTTINGCOMPONENT = 310,
     CUTTINGEDGETECHNOLOGICALDATA = 311,
     CW = 312,
     DATA = 313,
     DATEANDTIME = 314,
     DEGOUGE = 315,
     DESCRIPTIVEPARAMETER = 316,
     DIAMETERTAPER = 317,
     DIRECTION = 318,
     DISCONTINUOUS = 319,
     DISPLAYMESSAGE = 320,
     DRILLING = 321,
     DRILLINGTYPESTRATEGY = 322,
     EDGEROUND = 323,
     ELLIPSE = 324,
     ENDSEC = 325,
     EXCHANGEPALLET = 326,
     FACEMILL = 327,
     FALSE = 328,
     FEEDSTOP = 329,
     FILEDESCRIPTION = 330,
     FILEEND = 331,
     FILENAME = 332,
     FILESCHEMA = 333,
     FILESTART = 334,
     FLATHOLEBOTTOM = 335,
     FLATSLOTENDTYPE = 336,
     FLATWITHRADIUSHOLEBOTTOM = 337,
     FORWARD = 338,
     FREEFORMOPERATION = 339,
     GENERALPATH = 340,
     GENERALPATTERN = 341,
     GENERALPOCKETBOTTOMCONDITION = 342,
     HEADER = 343,
     HELIX = 344,
     HOLE = 345,
     HYPERBOLA = 346,
     INDEXPALLET = 347,
     INDEXTABLE = 348,
     INPROCESSGEOMETRY = 349,
     LEADINGLINESTRATEGY = 350,
     LEFT = 351,
     LIFT = 352,
     LIFTSHIFTPLUNGE = 353,
     LIMITSANDFITS = 354,
     LINE = 355,
     LINEARPATH = 356,
     LINEARPROFILE = 357,
     LOADTOOL = 358,
     LOOPBACK = 359,
     LOOPSLOTENDTYPE = 360,
     MACHININGWORKINGSTEP = 361,
     MATERIAL = 362,
     MILLINGCUTTINGTOOL = 363,
     MILLINGMACHINEFUNCTIONS = 364,
     MILLINGTECHNOLOGY = 365,
     MILLINGTOOLDIMENSION = 366,
     MULTISTEPDRILLING = 367,
     NCVARIABLE = 368,
     NONCONTACT = 369,
     NUMERICPARAMETER = 370,
     OFFSETVECTOR = 371,
     OPENSLOTENDTYPE = 372,
     OPTIONALSTOP = 373,
     PARABOLA = 374,
     PARAMETER = 375,
     PARTIALCIRCULARPATH = 376,
     PERSONANDADDRESS = 377,
     PLANARFACE = 378,
     PLANARPOCKETBOTTOMCONDITION = 379,
     PLANE = 380,
     PLANECCSTRATEGY = 381,
     PLANECLSTRATEGY = 382,
     PLANEFINISHMILLING = 383,
     PLANEROUGHMILLING = 384,
     PLUNGEHELIX = 385,
     PLUNGERAMP = 386,
     PLUNGETOOLAXIS = 387,
     PLUNGEZIGZAG = 388,
     PLUSMINUSVALUE = 389,
     POLYLINE = 390,
     PROCESSMODEL = 391,
     PROCESSMODELLIST = 392,
     PROGRAMSTOP = 393,
     PROJECT = 394,
     RADIUSEDPOCKETBOTTOMCONDITION = 395,
     RADIUSEDSLOTENDTYPE = 396,
     RAPID = 397,
     RAPIDMOVEMENT = 398,
     REAMING = 399,
     RECTANGULARCLOSEDPROFILE = 400,
     RECTANGULAROFFSET = 401,
     RECTANGULAROMIT = 402,
     RECTANGULARPATTERN = 403,
     REGIONPROJECTION = 404,
     RIGHT = 405,
     RIGHTCIRCULARCYLINDER = 406,
     ROUNDEDUPROFILE = 407,
     ROUNDHOLE = 408,
     SETMARK = 409,
     SETUP = 410,
     SETUPINSTRUCTION = 411,
     SHAFT = 412,
     SIDEFINISHMILLING = 413,
     SIDEROUGHMILLING = 414,
     SLOT = 415,
     SPHERICALCAP = 416,
     SPHERICALHOLEBOTTOM = 417,
     SPHERICALSURFACE = 418,
     SQUAREUPROFILE = 419,
     STEP = 420,
     STRAIGHTLINE = 421,
     TAPEREDENDMILL = 422,
     TAPEREDREAMER = 423,
     TAPPING = 424,
     TCP = 425,
     THREADDRILLING = 426,
     THREEAXES = 427,
     THROUGHBOTTOMCONDITION = 428,
     THROUGHPOCKETBOTTOMCONDITION = 429,
     TOLERANCEDLENGTHMEASURE = 430,
     TOLERANCES = 431,
     TOOLPATHFEATURE = 432,
     TOOLPATHLIST = 433,
     TOOLPROBING = 434,
     TOUCHPROBE = 435,
     TRAJECTORYPATH = 436,
     TRIMMEDCURVE = 437,
     TRUE = 438,
     TWISTDRILL = 439,
     TWOAXES = 440,
     UNIDIRECTIONALMILLING = 441,
     UNKNOWN = 442,
     UNLOADTOOL = 443,
     UNSPECIFIED = 444,
     UVSTRATEGY = 445,
     VECTOR = 446,
     VEEPROFILE = 447,
     WAITFORMARK = 448,
     WOODRUFFSLOTENDTYPE = 449,
     WORKPIECE = 450,
     WORKPIECECOMPLETEPROBING = 451,
     WORKPIECEPROBING = 452,
     WORKPIECESETUP = 453,
     WORKPLAN = 454,
     ZIGZAG = 455,
     CHARSTRING = 456,
     INTSTRING = 457,
     REALSTRING = 458,
     BAD = 459,
     COLON = 460,
     DOLLAR = 461,
     EQUALS = 462,
     LBOX = 463,
     LPAREN = 464,
     RBOX = 465,
     RPAREN = 466,
     SEMICOLON = 467,
     SHARP = 468,
     SLASH = 469
   };
#endif
/* Tokens.  */
#define ADVANCEDBREPSHAPEREPRESENTATION 258
#define ANGLETAPER 259
#define APPROACH 260
#define APPROVAL 261
#define APPROVALSTATUS 262
#define AXIS1PLACEMENT 263
#define AXIS2PLACEMENT3D 264
#define BACKBORING 265
#define BACKSIDECOUNTERBORE 266
#define BACKSIDECOUNTERSINK 267
#define BALLENDMILL 268
#define BIDIRECTIONALMILLING 269
#define BLOCK 270
#define BORING 271
#define BOSS 272
#define BOTTOMANDSIDEFINISHMILLING 273
#define BOTTOMANDSIDEROUGHMILLING 274
#define BULLNOSEENDMILL 275
#define C 276
#define CALENDARDATE 277
#define CARTESIAN 278
#define CARTESIANPOINT 279
#define CCP 280
#define CCW 281
#define CENTERDRILL 282
#define CENTERDRILLING 283
#define CHAMFER 284
#define CHANNEL 285
#define CIRCLE 286
#define CIRCULAROFFSET 287
#define CIRCULAROMIT 288
#define CIRCULARPATTERN 289
#define CLIMB 290
#define CLOSEDPOCKET 291
#define COMBINEDDRILLANDREAMER 292
#define COMPLETECIRCULARPATH 293
#define COMPOSITECURVE 294
#define COMPOSITECURVESEGMENT 295
#define CONICALHOLEBOTTOM 296
#define CONNECT 297
#define CONTACT 298
#define CONTINUOUS 299
#define CONTOURPARALLEL 300
#define CONTSAMEGRADIENT 301
#define CONTSAMEGRADIENTSAMECURVATURE 302
#define CONVENTIONAL 303
#define COUNTERBORE 304
#define COUNTERBOREHOLE 305
#define COUNTERSINK 306
#define COUNTERSINKING 307
#define COUNTERSUNKHOLE 308
#define CUTTERLOCATIONTRAJECTORY 309
#define CUTTINGCOMPONENT 310
#define CUTTINGEDGETECHNOLOGICALDATA 311
#define CW 312
#define DATA 313
#define DATEANDTIME 314
#define DEGOUGE 315
#define DESCRIPTIVEPARAMETER 316
#define DIAMETERTAPER 317
#define DIRECTION 318
#define DISCONTINUOUS 319
#define DISPLAYMESSAGE 320
#define DRILLING 321
#define DRILLINGTYPESTRATEGY 322
#define EDGEROUND 323
#define ELLIPSE 324
#define ENDSEC 325
#define EXCHANGEPALLET 326
#define FACEMILL 327
#define FALSE 328
#define FEEDSTOP 329
#define FILEDESCRIPTION 330
#define FILEEND 331
#define FILENAME 332
#define FILESCHEMA 333
#define FILESTART 334
#define FLATHOLEBOTTOM 335
#define FLATSLOTENDTYPE 336
#define FLATWITHRADIUSHOLEBOTTOM 337
#define FORWARD 338
#define FREEFORMOPERATION 339
#define GENERALPATH 340
#define GENERALPATTERN 341
#define GENERALPOCKETBOTTOMCONDITION 342
#define HEADER 343
#define HELIX 344
#define HOLE 345
#define HYPERBOLA 346
#define INDEXPALLET 347
#define INDEXTABLE 348
#define INPROCESSGEOMETRY 349
#define LEADINGLINESTRATEGY 350
#define LEFT 351
#define LIFT 352
#define LIFTSHIFTPLUNGE 353
#define LIMITSANDFITS 354
#define LINE 355
#define LINEARPATH 356
#define LINEARPROFILE 357
#define LOADTOOL 358
#define LOOPBACK 359
#define LOOPSLOTENDTYPE 360
#define MACHININGWORKINGSTEP 361
#define MATERIAL 362
#define MILLINGCUTTINGTOOL 363
#define MILLINGMACHINEFUNCTIONS 364
#define MILLINGTECHNOLOGY 365
#define MILLINGTOOLDIMENSION 366
#define MULTISTEPDRILLING 367
#define NCVARIABLE 368
#define NONCONTACT 369
#define NUMERICPARAMETER 370
#define OFFSETVECTOR 371
#define OPENSLOTENDTYPE 372
#define OPTIONALSTOP 373
#define PARABOLA 374
#define PARAMETER 375
#define PARTIALCIRCULARPATH 376
#define PERSONANDADDRESS 377
#define PLANARFACE 378
#define PLANARPOCKETBOTTOMCONDITION 379
#define PLANE 380
#define PLANECCSTRATEGY 381
#define PLANECLSTRATEGY 382
#define PLANEFINISHMILLING 383
#define PLANEROUGHMILLING 384
#define PLUNGEHELIX 385
#define PLUNGERAMP 386
#define PLUNGETOOLAXIS 387
#define PLUNGEZIGZAG 388
#define PLUSMINUSVALUE 389
#define POLYLINE 390
#define PROCESSMODEL 391
#define PROCESSMODELLIST 392
#define PROGRAMSTOP 393
#define PROJECT 394
#define RADIUSEDPOCKETBOTTOMCONDITION 395
#define RADIUSEDSLOTENDTYPE 396
#define RAPID 397
#define RAPIDMOVEMENT 398
#define REAMING 399
#define RECTANGULARCLOSEDPROFILE 400
#define RECTANGULAROFFSET 401
#define RECTANGULAROMIT 402
#define RECTANGULARPATTERN 403
#define REGIONPROJECTION 404
#define RIGHT 405
#define RIGHTCIRCULARCYLINDER 406
#define ROUNDEDUPROFILE 407
#define ROUNDHOLE 408
#define SETMARK 409
#define SETUP 410
#define SETUPINSTRUCTION 411
#define SHAFT 412
#define SIDEFINISHMILLING 413
#define SIDEROUGHMILLING 414
#define SLOT 415
#define SPHERICALCAP 416
#define SPHERICALHOLEBOTTOM 417
#define SPHERICALSURFACE 418
#define SQUAREUPROFILE 419
#define STEP 420
#define STRAIGHTLINE 421
#define TAPEREDENDMILL 422
#define TAPEREDREAMER 423
#define TAPPING 424
#define TCP 425
#define THREADDRILLING 426
#define THREEAXES 427
#define THROUGHBOTTOMCONDITION 428
#define THROUGHPOCKETBOTTOMCONDITION 429
#define TOLERANCEDLENGTHMEASURE 430
#define TOLERANCES 431
#define TOOLPATHFEATURE 432
#define TOOLPATHLIST 433
#define TOOLPROBING 434
#define TOUCHPROBE 435
#define TRAJECTORYPATH 436
#define TRIMMEDCURVE 437
#define TRUE 438
#define TWISTDRILL 439
#define TWOAXES 440
#define UNIDIRECTIONALMILLING 441
#define UNKNOWN 442
#define UNLOADTOOL 443
#define UNSPECIFIED 444
#define UVSTRATEGY 445
#define VECTOR 446
#define VEEPROFILE 447
#define WAITFORMARK 448
#define WOODRUFFSLOTENDTYPE 449
#define WORKPIECE 450
#define WORKPIECECOMPLETEPROBING 451
#define WORKPIECEPROBING 452
#define WORKPIECESETUP 453
#define WORKPLAN 454
#define ZIGZAG 455
#define CHARSTRING 456
#define INTSTRING 457
#define REALSTRING 458
#define BAD 459
#define COLON 460
#define DOLLAR 461
#define EQUALS 462
#define LBOX 463
#define LPAREN 464
#define RBOX 465
#define RPAREN 466
#define SEMICOLON 467
#define SHARP 468
#define SLASH 469




/* Copy the first part of user declarations.  */



/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

#include <string.h>  // for strlen, strcpy, strcat
#include <stdio.h>   // for fopen, etc.
#include <stdlib.h>  // for exit
#include "iso14649classes.hh"

#define YYERROR_VERBOSE
#define YYDEBUG 1
#define INSTANCEMAX 100000

/********************************************************************/

#define WRITE_LINKER(TYP) \
std::list<TYP **> TYP ## _refs;\
std::list<int> TYP ## _nums;\
\
void link_ ## TYP()\
{\
  std::list<TYP **>::iterator refIter;\
  std::list<int>::iterator numIter;\
  for (refIter = TYP ## _refs.begin(),\
	 numIter = TYP ## _nums.begin();\
       refIter != TYP ## _refs.end();\
       refIter++, numIter++)\
    {\
      if (instances[*numIter] == 0)\
	 {\
	   fprintf(report,\
		   "Error: referenced instance #%d does not exist\n",\
		   *numIter);\
	   numErrors++;\
	 }\
      else if (instances[*numIter]->isA(TYP ## _E))\
	{\
	  **refIter = dynamic_cast<TYP *>(instances[*numIter]);\
	}\
      else\
	{\
	  fprintf(report, "Error: #%d used incorrectly\n",\
		  instances[*numIter]->get_id()->get_val());\
	  numErrors++;\
	}\
    }\
  TYP ## _refs.clear();\
  TYP ## _nums.clear();\
}


/********************************************************************/

/*

The lineText array is used for saving everything on a line up to the end
of the line, 4096 characters, or an error, whichever comes first. The
lineText is used (printed by yyerror) only if there is an error. This 
lets the user see the point in the Part 21 file at which an error occurred.
Lines longer than 4096 characters will not overflow the lineText array.

*/

extern FILE * yyin;
extern int yylex();

int numErrors = 0;
char lineText[4096];
char lexMessage[80];
FILE * report;
inputFile * tree;
char errorMessage[256];
instance * instances[INSTANCEMAX] = {0};

/********************************************************************/

WRITE_LINKER(angleTaper)
WRITE_LINKER(approachRetractStrategy)
WRITE_LINKER(approval)
WRITE_LINKER(approvalStatus)
WRITE_LINKER(axis1placement)
WRITE_LINKER(axis2placement3d)
WRITE_LINKER(backBoring)
WRITE_LINKER(backsideCounterbore)
WRITE_LINKER(backsideCountersink)
WRITE_LINKER(ballEndmill)
WRITE_LINKER(bidirectionalMilling)
WRITE_LINKER(blindBottomCondition)
WRITE_LINKER(block)
WRITE_LINKER(boring)
WRITE_LINKER(boringOperation)
WRITE_LINKER(boss)
WRITE_LINKER(bottomAndSideFinishMilling)
WRITE_LINKER(bottomAndSideMilling)
WRITE_LINKER(bottomAndSideRoughMilling)
WRITE_LINKER(boundedCurve)
WRITE_LINKER(boundingGeometrySelect)
WRITE_LINKER(bullnoseEndmill)
WRITE_LINKER(calendarDate)
WRITE_LINKER(cartesianPoint)
WRITE_LINKER(centerDrill)
WRITE_LINKER(centerDrilling)
WRITE_LINKER(chamfer)
WRITE_LINKER(channel)
WRITE_LINKER(circle)
WRITE_LINKER(circularOffset)
WRITE_LINKER(circularOmit)
WRITE_LINKER(circularPath)
WRITE_LINKER(circularPattern)
WRITE_LINKER(closedPocket)
WRITE_LINKER(closedProfile)
WRITE_LINKER(combinedDrillAndReamer)
WRITE_LINKER(completeCircularPath)
WRITE_LINKER(compositeCurve)
WRITE_LINKER(compositeCurveSegment)
WRITE_LINKER(compoundFeature)
WRITE_LINKER(compoundFeatureSelect)
WRITE_LINKER(conic)
WRITE_LINKER(conicalHoleBottom)
WRITE_LINKER(contourParallel)
WRITE_LINKER(counterbore)
WRITE_LINKER(counterboreHole)
WRITE_LINKER(counterboreParent)
WRITE_LINKER(countersink)
WRITE_LINKER(counterSinking)
WRITE_LINKER(countersinkParent)
WRITE_LINKER(countersunkHole)
WRITE_LINKER(curve)
WRITE_LINKER(cutterLocationTrajectory)
WRITE_LINKER(cuttingComponent)
WRITE_LINKER(cuttingEdgeTechnologicalData)
WRITE_LINKER(cuttingTool)
WRITE_LINKER(date)
WRITE_LINKER(dateAndTime)
WRITE_LINKER(descriptiveParameter)
WRITE_LINKER(diameterTaper)
WRITE_LINKER(direction)
WRITE_LINKER(displayMessage)
WRITE_LINKER(drill)
WRITE_LINKER(drilling)
WRITE_LINKER(drillingOperation)
WRITE_LINKER(drillingTypeOperation)
WRITE_LINKER(drillingTypeStrategy)
WRITE_LINKER(edgeRound)
WRITE_LINKER(elementarySurface)
WRITE_LINKER(ellipse)
WRITE_LINKER(endmill)
WRITE_LINKER(exchangePallet)
WRITE_LINKER(executable)
WRITE_LINKER(facemill)
WRITE_LINKER(feedstop)
WRITE_LINKER(flatHoleBottom)
WRITE_LINKER(flatSlotEndType)
WRITE_LINKER(flatWithRadiusHoleBottom)
WRITE_LINKER(freeformOperation)
WRITE_LINKER(freeformStrategy)
WRITE_LINKER(generalPath)
WRITE_LINKER(generalPattern)
WRITE_LINKER(generalPocketBottomCondition)
WRITE_LINKER(helix)
WRITE_LINKER(holeBottomCondition)
WRITE_LINKER(hyperbola)
WRITE_LINKER(indexPallet)
WRITE_LINKER(indexTable)
WRITE_LINKER(leadingLineStrategy)
WRITE_LINKER(limitsAndFits)
WRITE_LINKER(line)
WRITE_LINKER(linearPath)
WRITE_LINKER(linearProfile)
WRITE_LINKER(loadTool)
WRITE_LINKER(loopSlotEndType)
WRITE_LINKER(machineFunctions)
WRITE_LINKER(machiningFeature)
WRITE_LINKER(machiningOperation)
WRITE_LINKER(machiningTool)
WRITE_LINKER(machiningWorkingstep)
WRITE_LINKER(manufacturingFeature)
WRITE_LINKER(material)
WRITE_LINKER(millingCutter)
WRITE_LINKER(millingCuttingTool)
WRITE_LINKER(millingMachineFunctions)
WRITE_LINKER(millingMachiningOperation)
WRITE_LINKER(millingTechnology)
WRITE_LINKER(millingToolBody)
WRITE_LINKER(millingToolDimension)
WRITE_LINKER(millingTypeOperation)
WRITE_LINKER(multistepDrilling)
WRITE_LINKER(ncFunction)
WRITE_LINKER(ncVariable)
WRITE_LINKER(numericParameter)
WRITE_LINKER(openProfile)
WRITE_LINKER(openSlotEndType)
WRITE_LINKER(operation)
WRITE_LINKER(optionalStop)
WRITE_LINKER(parabola)
WRITE_LINKER(partialCircularPath)
WRITE_LINKER(personAndAddress)
WRITE_LINKER(placement)
WRITE_LINKER(planarFace)
WRITE_LINKER(planarPocketBottomCondition)
WRITE_LINKER(plane)
WRITE_LINKER(planeCcStrategy)
WRITE_LINKER(planeClStrategy)
WRITE_LINKER(planeFinishMilling)
WRITE_LINKER(planeMilling)
WRITE_LINKER(planeRoughMilling)
WRITE_LINKER(plungeStrategy)
WRITE_LINKER(plungeHelix)
WRITE_LINKER(plungeRamp)
WRITE_LINKER(plungeToolaxis)
WRITE_LINKER(plungeZigzag)
WRITE_LINKER(plusMinusValue)
WRITE_LINKER(pocket)
WRITE_LINKER(pocketBottomCondition)
WRITE_LINKER(polyline)
WRITE_LINKER(processModel)
WRITE_LINKER(processModelList)
WRITE_LINKER(profile)
WRITE_LINKER(programStructure)
WRITE_LINKER(programStop)
WRITE_LINKER(project)
WRITE_LINKER(propertyParameter)
WRITE_LINKER(radiusedPocketBottomCondition)
WRITE_LINKER(radiusedSlotEndType)
WRITE_LINKER(rapidMovement)
WRITE_LINKER(reamer)
WRITE_LINKER(reaming)
WRITE_LINKER(rectangularClosedProfile)
WRITE_LINKER(rectangularOffset)
WRITE_LINKER(rectangularOmit)
WRITE_LINKER(rectangularPattern)
WRITE_LINKER(region)
WRITE_LINKER(regionProjection)
WRITE_LINKER(replicateFeature)
WRITE_LINKER(representationItem)
WRITE_LINKER(restrictedAreaSelect)
WRITE_LINKER(rightCircularCylinder)
WRITE_LINKER(roundedUProfile)
WRITE_LINKER(roundHole)
WRITE_LINKER(setMark)
WRITE_LINKER(setup)
WRITE_LINKER(setupInstruction)
WRITE_LINKER(sideMilling)
WRITE_LINKER(sideFinishMilling)
WRITE_LINKER(sideRoughMilling)
WRITE_LINKER(slot)
WRITE_LINKER(slotEndType)
WRITE_LINKER(sphericalCap)
WRITE_LINKER(sphericalHoleBottom)
WRITE_LINKER(sphericalSurface)
WRITE_LINKER(squareUProfile)
WRITE_LINKER(step)
WRITE_LINKER(taperedEndmill)
WRITE_LINKER(taperedReamer)
WRITE_LINKER(taperSelect)
WRITE_LINKER(tapping)
WRITE_LINKER(technology)
WRITE_LINKER(threadDrilling)
WRITE_LINKER(threeAxes)
WRITE_LINKER(throughBottomCondition)
WRITE_LINKER(throughPocketBottomCondition)
WRITE_LINKER(tolerancedLengthMeasure)
WRITE_LINKER(tolerances)
WRITE_LINKER(toleranceSelect)
WRITE_LINKER(toolBody)
WRITE_LINKER(toolDirection)
WRITE_LINKER(toolpath)
WRITE_LINKER(toolpathFeature)
WRITE_LINKER(toolpathList)
WRITE_LINKER(toolProbing)
WRITE_LINKER(touchProbe)
WRITE_LINKER(touchProbing)
WRITE_LINKER(trajectory)
WRITE_LINKER(transitionFeature)
WRITE_LINKER(travelPath)
WRITE_LINKER(trimmedCurve)
WRITE_LINKER(trimmingSelect)
WRITE_LINKER(twistDrill)
WRITE_LINKER(twoAxes)
WRITE_LINKER(two5DmanufacturingFeature)
WRITE_LINKER(two5DmillingOperation)
WRITE_LINKER(two5DmillingStrategy)
WRITE_LINKER(unidirectionalMilling)
WRITE_LINKER(unloadTool)
WRITE_LINKER(uvStrategy)
WRITE_LINKER(vector)
WRITE_LINKER(veeProfile)
WRITE_LINKER(waitForMark)
WRITE_LINKER(woodruffSlotEndType)
WRITE_LINKER(workingstep)
WRITE_LINKER(workpiece)
WRITE_LINKER(workpieceCompleteProbing)
WRITE_LINKER(workpieceProbing)
WRITE_LINKER(workpieceSetup)
WRITE_LINKER(workplan)

/********************************************************************/

/* linkAll

The instances array, which is used by all the linking functions called
here, is not needed after linking is finished. That array needs to be
cleared in order to parse another file, so it is cleared at the
end of this function.

*/

void linkAll()
{
  int n;

  link_angleTaper();
  link_approachRetractStrategy();
  link_approval();
  link_approvalStatus();
  link_axis1placement();
  link_axis2placement3d();
  link_backBoring();
  link_backsideCounterbore();
  link_backsideCountersink();
  link_ballEndmill();
  link_bidirectionalMilling();
  link_blindBottomCondition();
  link_block();
  link_boring();
  link_boringOperation();
  link_boss();
  link_bottomAndSideFinishMilling();
  link_bottomAndSideMilling();
  link_bottomAndSideRoughMilling();
  link_boundedCurve();
  link_boundingGeometrySelect();
  link_bullnoseEndmill();
  link_calendarDate();
  link_cartesianPoint();
  link_centerDrill();
  link_centerDrilling();
  link_chamfer();
  link_channel();
  link_circle();
  link_circularOffset();
  link_circularOmit();
  link_circularPath();
  link_circularPattern();
  link_closedPocket();
  link_closedProfile();
  link_combinedDrillAndReamer();
  link_completeCircularPath();
  link_compositeCurve();
  link_compositeCurveSegment();
  link_compoundFeature();
  link_compoundFeatureSelect();
  link_conic();
  link_conicalHoleBottom();
  link_contourParallel();
  link_counterbore();
  link_counterboreHole();
  link_counterboreParent();
  link_countersink();
  link_counterSinking();
  link_countersinkParent();
  link_countersunkHole();
  link_curve();
  link_cutterLocationTrajectory();
  link_cuttingComponent();
  link_cuttingEdgeTechnologicalData();
  link_cuttingTool();
  link_date();
  link_dateAndTime();
  link_descriptiveParameter();
  link_diameterTaper();
  link_direction();
  link_displayMessage();
  link_drill();
  link_drilling();
  link_drillingOperation();
  link_drillingTypeOperation();
  link_drillingTypeStrategy();
  link_edgeRound();
  link_elementarySurface();
  link_ellipse();
  link_endmill();
  link_exchangePallet();
  link_executable();
  link_facemill();
  link_feedstop();
  link_flatHoleBottom();
  link_flatSlotEndType();
  link_flatWithRadiusHoleBottom();
  link_freeformOperation();
  link_freeformStrategy();
  link_generalPath();
  link_generalPattern();
  link_generalPocketBottomCondition();
  link_helix();
  link_holeBottomCondition();
  link_hyperbola();
  link_indexPallet();
  link_indexTable();
  link_leadingLineStrategy();
  link_limitsAndFits();
  link_line();
  link_linearPath();
  link_linearProfile();
  link_loadTool();
  link_loopSlotEndType();
  link_machineFunctions();
  link_machiningFeature();
  link_machiningOperation();
  link_machiningTool();
  link_machiningWorkingstep();
  link_manufacturingFeature();
  link_material();
  link_millingCutter();
  link_millingCuttingTool();
  link_millingMachineFunctions();
  link_millingMachiningOperation();
  link_millingTechnology();
  link_millingToolBody();
  link_millingToolDimension();
  link_millingTypeOperation();
  link_multistepDrilling();
  link_ncFunction();
  link_ncVariable();
  link_numericParameter();
  link_openProfile();
  link_openSlotEndType();
  link_operation();
  link_optionalStop();
  link_parabola();
  link_partialCircularPath();
  link_personAndAddress();
  link_placement();
  link_planarFace();
  link_planarPocketBottomCondition();
  link_plane();
  link_planeCcStrategy();
  link_planeClStrategy();
  link_planeFinishMilling();
  link_planeMilling();
  link_planeRoughMilling();
  link_plungeStrategy();
  link_plungeHelix();
  link_plungeRamp();
  link_plungeToolaxis();
  link_plungeZigzag();
  link_plusMinusValue();
  link_pocket();
  link_pocketBottomCondition();
  link_polyline();
  link_processModel();
  link_processModelList();
  link_profile();
  link_programStructure();
  link_programStop();
  link_project();
  link_propertyParameter();
  link_radiusedPocketBottomCondition();
  link_radiusedSlotEndType();
  link_rapidMovement();
  link_reamer();
  link_reaming();
  link_rectangularClosedProfile();
  link_rectangularOffset();
  link_rectangularOmit();
  link_rectangularPattern();
  link_region();
  link_regionProjection();
  link_replicateFeature();
  link_representationItem();
  link_restrictedAreaSelect();
  link_rightCircularCylinder();
  link_roundedUProfile();
  link_roundHole();
  link_setMark();
  link_setup();
  link_setupInstruction();
  link_sideMilling();
  link_sideFinishMilling();
  link_sideRoughMilling();
  link_slot();
  link_slotEndType();
  link_sphericalCap();
  link_sphericalHoleBottom();
  link_sphericalSurface();
  link_squareUProfile();
  link_step();
  link_taperedEndmill();
  link_taperedReamer();
  link_taperSelect();
  link_tapping();
  link_technology();
  link_threadDrilling();
  link_threeAxes();
  link_throughBottomCondition();
  link_throughPocketBottomCondition();
  link_tolerancedLengthMeasure();
  link_tolerances();
  link_toleranceSelect();
  link_toolBody();
  link_toolDirection();
  link_toolpath();
  link_toolpathFeature();
  link_toolpathList();
  link_toolProbing();
  link_touchProbe();
  link_touchProbing();
  link_trajectory();
  link_transitionFeature();
  link_travelPath();
  link_trimmedCurve();
  link_trimmingSelect();
  link_twistDrill();
  link_twoAxes();
  link_two5DmanufacturingFeature();
  link_two5DmillingOperation();
  link_two5DmillingStrategy();
  link_unidirectionalMilling();
  link_unloadTool();
  link_uvStrategy();
  link_vector();
  link_veeProfile();
  link_waitForMark();
  link_woodruffSlotEndType();
  link_workingstep();
  link_workpiece();
  link_workpieceCompleteProbing();
  link_workpieceProbing();
  link_workpieceSetup();
  link_workplan();
  for (n = 0; n < INSTANCEMAX; n++)
    {
      instances[n] = 0;
    }
}

/********************************************************************/

/* yyerror

If lexMessage contains a message, lexMessage[0] will not be 0,
and a syntax error will have occurred, since BAD will have been
returned by the lexer. In this case, only the lexMessage is
printed, since reporting the syntax error (s) only adds confusion.

*/

int yyerror(char * s)
{
  int n;

  if (lexMessage[0])
    {
      fprintf(report, "Error: %s\n", lexMessage);
      lexMessage[0] = 0;
    }
  else
    fprintf(report, "Error: %s\n", s);
  fprintf(report, "%s\n", lineText);
  for (n = 0; lineText[n] != 0; n++);
  if (lineText[n-1] != '\n')
    fprintf(report, "\n");
  return 0;
}

/********************************************************************/

int yyparse();

/********************************************************************/

/* parseManyFiles

This parses all the input files whose names are given in the
file whose name is fileNameFile. As it runs, it prints the name
of each file it parses followed by either "0 errors" or some error
messages followed by "N errors".

*/

void parseManyFiles(
 char * fileNameFile,
 char * reportName)
{
  FILE * fileList;
  static char fileName[256];
  int nameLength;

  fileList = fopen(fileNameFile, "r");
  if (fileList == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n",
              fileNameFile);
      exit(1);
    }
  if (reportName)
    {
      report = fopen(reportName, "wb");
      if (report == 0)
        {
          fprintf(stderr, "unable to open file %s for writing\n",
                  reportName);
	  exit(1);
	}
    }
  else
    report = stdout;
  lexMessage[0] = 0;
  while (fgets(fileName, 256, fileList))
    {
      nameLength = strlen(fileName);
      if (nameLength == 255)
	{
	  fprintf(stderr, "file name too long: %s\n", fileName);
	  exit(1);
        }
      while ((fileName[nameLength - 1] == 10) ||
             (fileName[nameLength - 1] == 13))
	{ // get rid of the end of line character(s)
	  fileName[nameLength - 1] = 0;
	  nameLength--;
	}
      if (strcmp((fileName + nameLength - 4), ".stp"))
	{
	  fprintf(stderr, "file name does not end in .stp: %s\n",
                  fileName);
	  exit(1);
	}
      fprintf(report, "*****************************************\n\n");
      fprintf(report, "%s\n\n", fileName);
      yyin = fopen(fileName, "rb");
      if (yyin == 0)
	{
	  fprintf(stderr, "unable to open file %s for reading\n",
                  fileName);
	  exit(1);
	}
      yyparse();
      fclose(yyin);
      if (numErrors == 0)
	linkAll();
      fprintf(report, "%d errors\n\n", numErrors);
      if (tree)
	{
	  delete tree;
	  tree = 0;
	}
      numErrors = 0;
    }
  fclose(fileList);
  fprintf(report, "\n");
  if (report != stdout)
    fclose(report);
}

/********************************************************************/

/* parseOneFile

This parses one input file.

*/

int parseOneFile(
 const char * part21Name,
 char * reportName,
 bool quiet)
{
  if (reportName)
    {
      report = fopen(reportName, "wb");
      if (report == 0)
        {
          fprintf(stderr, "unable to open file %s for writing\n",
                  reportName);
	  exit(1);
	}
    }
  else
    report = stdout;
  lexMessage[0] = 0;
  yyin = fopen(part21Name, "rb");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n",
              part21Name);
      exit(1);
    }
  yyparse();
  fclose(yyin);
  if (numErrors == 0)
    linkAll();
  else if (tree)
    {
      delete tree;
      tree = 0;
    }
  if (!quiet || numErrors)
    fprintf(report, "%d error%s\n",
	    numErrors, ((numErrors == 1) ? "" : "s"));
  if (report != stdout)
    fclose(report);
  return numErrors;
}

/********************************************************************/



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
  inputFile                        * val1;
  dataSection                      * val2;
  dataStarter                      * val3;
  endSection                       * val4;
  fileDescription                  * val5;
  fileEnd                          * val6;
  fileName                         * val7;
  fileSchema                       * val8;
  fileStart                        * val9;
  headerSection                    * val10;
  headerStarter                    * val11;
  instanceId                       * val12;
  std::list<instance *>            * val13;
  parenRealListFull                * val14;
  parenStringList                  * val15;
  parenStringListFull              * val16;
  real                             * val17;
  std::list<real *>                * val18;
  std::list<char *>                * val19;
  instance                         * val20;
  advancedBrepShapeRepresentation  * val21;
  angleTaper                       * val22;
  approach                         * val23;
  approval                         * val24;
  approvalStatus                   * val25;
  axis1placement                   * val26;
  axis2placement3d                 * val27;
  std::list<axis2placement3d *>    * val28;
  backBoring                       * val29;
  backsideCounterbore              * val30;
  backsideCountersink              * val31;
  ballEndmill                      * val32;
  bidirectionalMilling             * val33;
  block                            * val34;
  boolean                          * val35;
  booleanTrue                      * val36;
  booleanFalse                     * val37;
  boring                           * val38;
  boss                             * val39;
  std::list<boss *>                * val40;
  bottomAndSideFinishMilling       * val41;
  bottomAndSideRoughMilling        * val42;
  bullnoseEndmill                  * val43;
  calendarDate                     * val44;
  cartesian                        * val45;
  cartesianPoint                   * val46;
  std::list<cartesianPoint *>      * val47;
  centerDrill                      * val48;
  centerDrilling                   * val49;
  chamfer                          * val50;
  channel                          * val51;
  circle                           * val52;
  circularOffset                   * val53;
  circularOmit                     * val54;
  std::list<circularOffset *>      * val55;
  std::list<circularOmit *>        * val56;
  circularPattern                  * val57;
  closedPocket                     * val58;
  combinedDrillAndReamer           * val59;
  completeCircularPath             * val60;
  compositeCurve                   * val61;
  compositeCurveSegment            * val62;
  std::list<compositeCurveSegment *> * val63;
  std::list<compoundFeatureSelect *> * val64;
  conicalHoleBottom                * val65;
  connect                          * val66;
  contact                          * val67;
  continuous                       * val68;
  contSameGradient                 * val69;
  contSameGradientSameCurvature    * val70;
  contourParallel                  * val71;
  counterbore                      * val72;
  counterboreHole                  * val73;
  countersink                      * val74;
  counterSinking                   * val75;
  countersunkHole                  * val76;
  cutmodeType                      * val77;
  cutmodeTypeClimb                 * val78;
  cutmodeTypeConventional          * val79;
  cutterLocationTrajectory         * val80;
  cuttingComponent                 * val81;
  std::list<cuttingComponent *>    * val82;
  cuttingEdgeTechnologicalData     * val83;
  dateAndTime                      * val84;
  degouge                          * val85;
  descriptiveParameter             * val86;
  diameterTaper                    * val87;
  direction                        * val88;
  discontinuous                    * val89;
  displayMessage                   * val90;
  drilling                         * val91;
  drillingTypeStrategy             * val92;
  edgeRound                        * val93;
  ellipse                          * val94;
  exchangePallet                   * val95;
  std::list<executable *>          * val96;
  facemill                         * val97;
  feedstop                         * val98;
  fittingType                      * val99;
  fittingTypeHole                  * val100;
  fittingTypeShaft                 * val101;
  flatHoleBottom                   * val102;
  flatSlotEndType                  * val103;
  flatWithRadiusHoleBottom         * val104;
  freeformOperation                * val105;
  generalPath                      * val106;
  generalPattern                   * val107;
  generalPocketBottomCondition     * val108;
  hand                             * val109;
  handRight                        * val110;
  handLeft                         * val111;
  helix                            * val112;
  hyperbola                        * val113;
  indexPallet                      * val114;
  indexTable                       * val115;
  inProcessGeometry                * val116;
  integer                          * val117;
  leadingLineStrategy              * val118;
  leftOrRight                      * val119;
  leftOrRightLeft                  * val120;
  leftOrRightRight                 * val121;
  lift                             * val122;
  liftShiftPlunge                  * val123;
  limitsAndFits                    * val124;
  line                             * val125;
  linearPath                       * val126;
  linearProfile                    * val127;
  loadTool                         * val128;
  logical                          * val129;
  logicalUnknown                   * val130;
  loopBack                         * val131;
  loopSlotEndType                  * val132;
  std::list<machiningOperation *>  * val133;
  machiningWorkingstep             * val134;
  material                         * val135;
  millingCuttingTool               * val136;
  millingMachineFunctions          * val137;
  millingTechnology                * val138;
  millingToolDimension             * val139;
  multistepDrilling                * val140;
  ncVariable                       * val141;
  std::list<ncVariable *>          * val142;
  nonContact                       * val143;
  numericParameter                 * val144;
  offsetVector                     * val145;
  openSlotEndType                  * val146;
  optionalStop                     * val147;
  parabola                         * val148;
  parameter                        * val149;
  parenAxis2placement3dListFull    * val150;
  parenBossList                    * val151;
  parenCartesianPointList          * val152;
  parenCartesianPointListFull      * val153;
  parenCircularOffsetList          * val154;
  parenCircularOmitList            * val155;
  parenCompositeCurveSegmentListFull * val156;
  parenCompoundFeatureSelectListFull * val157;
  parenCuttingComponentListFull    * val158;
  parenExecutableList              * val159;
  parenMachiningOperationList      * val160;
  parenNcVariableListFull          * val161;
  parenProcessModelLiszt           * val162;
  parenPropertyParameterList       * val163;
  parenRectangularOffsetList       * val164;
  parenRectangularOmitList         * val165;
  parenSetupInstructionList        * val166;
  parenSlotEndTypeList             * val167;
  parenToolpathLisztFull           * val168;
  parenTrimmingSelectListFull      * val169;
  parenWorkpieceList               * val170;
  parenWorkpieceSetupList          * val171;
  partialCircularPath              * val172;
  pathmodeType                     * val173;
  pathmodeTypeForward              * val174;
  pathmodeTypeZigzag               * val175;
  personAndAddress                 * val176;
  planarFace                       * val177;
  planarPocketBottomCondition      * val178;
  plane                            * val179;
  planeCcStrategy                  * val180;
  planeClStrategy                  * val181;
  planeFinishMilling               * val182;
  planeRoughMilling                * val183;
  plungeHelix                      * val184;
  plungeRamp                       * val185;
  plungeToolaxis                   * val186;
  plungeZigzag                     * val187;
  plusMinusValue                   * val188;
  polyline                         * val189;
  processModel                     * val190;
  processModelList                 * val191;
  std::list<processModel *>        * val192;
  programStop                      * val193;
  project                          * val194;
  std::list<propertyParameter *>   * val195;
  radiusedPocketBottomCondition    * val196;
  radiusedSlotEndType              * val197;
  rapidMovement                    * val198;
  reaming                          * val199;
  rectangularClosedProfile         * val200;
  rectangularOffset                * val201;
  std::list<rectangularOffset *>   * val202;
  rectangularOmit                  * val203;
  std::list<rectangularOmit *>     * val204;
  rectangularPattern               * val205;
  regionProjection                 * val206;
  rightCircularCylinder            * val207;
  rotDirection                     * val208;
  rotDirectionCw                   * val209;
  rotDirectionCcw                  * val210;
  roundedUProfile                  * val211;
  roundHole                        * val212;
  setMark                          * val213;
  setup                            * val214;
  setupInstruction                 * val215;
  std::list<setupInstruction *>    * val216;
  sideFinishMilling                * val217;
  sideRoughMilling                 * val218;
  slot                             * val219;
  std::list<slotEndType *>         * val220;
  speedName                        * val221;
  sphericalCap                     * val222;
  sphericalHoleBottom              * val223;
  sphericalSurface                 * val224;
  squareUProfile                   * val225;
  step                             * val226;
  straightline                     * val227;
  strokeConnectionStrategy         * val228;
  taperedEndmill                   * val229;
  taperedReamer                    * val230;
  tapping                          * val231;
  threadDrilling                   * val232;
  threeAxes                        * val233;
  throughBottomCondition           * val234;
  throughPocketBottomCondition     * val235;
  tolerancedLengthMeasure          * val236;
  tolerances                       * val237;
  toolpathFeature                  * val238;
  toolpathList                     * val239;
  std::list<toolpath *>            * val240;
  toolpathSpeedprofile             * val241;
  toolpathType                     * val242;
  toolProbing                      * val243;
  toolReferencePoint               * val244;
  toolReferencePointCcp            * val245;
  toolReferencePointTcp            * val246;
  touchProbe                       * val247;
  trajectoryPath                   * val248;
  transitionCode                   * val249;
  trimmedCurve                     * val250;
  trimmingPreference               * val251;
  std::list<trimmingSelect *>      * val252;
  twistDrill                       * val253;
  twoAxes                          * val254;
  unidirectionalMilling            * val255;
  unloadTool                       * val256;
  unspecified                      * val257;
  uvStrategy                       * val258;
  vector                           * val259;
  veeProfile                       * val260;
  waitForMark                      * val261;
  woodruffSlotEndType              * val262;
  workpiece                        * val263;
  workpieceCompleteProbing         * val264;
  std::list<workpiece *>           * val265;
  workpieceProbing                 * val266;
  workpieceSetup                   * val267;
  std::list<workpieceSetup *>      * val268;
  workplan                         * val269;
  char                             * sval;
  int                                ival;
  double                             rval;
}
/* Line 187 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  313
/* YYNRULES -- Number of rules.  */
#define YYNRULES  575
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2397

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   469

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    12,    15,    18,    26,    29,    32,
      35,    53,    56,    62,    65,    68,    71,    77,    80,    83,
      85,    88,    93,    96,    98,   100,   104,   108,   111,   115,
     117,   119,   123,   125,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   165,   167,   169,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   231,   233,   235,   237,   239,
     241,   243,   245,   247,   249,   251,   253,   255,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   299,
     301,   303,   305,   307,   309,   311,   313,   315,   317,   319,
     321,   323,   325,   327,   329,   331,   333,   335,   337,   339,
     341,   343,   345,   347,   349,   351,   353,   355,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   375,   377,   379,
     381,   383,   385,   387,   389,   391,   393,   395,   397,   399,
     401,   403,   405,   407,   409,   411,   413,   415,   417,   419,
     421,   423,   425,   427,   429,   431,   433,   435,   439,   444,
     446,   453,   458,   467,   478,   480,   484,   515,   528,   543,
     556,   569,   582,   584,   586,   588,   590,   627,   644,   646,
     650,   685,   720,   733,   742,   744,   751,   753,   757,   770,
     801,   818,   823,   832,   839,   844,   846,   850,   852,   856,
     881,   906,   921,   928,   937,   946,   948,   952,   954,   958,
     965,   967,   969,   971,   973,   975,   986,   999,  1012,  1027,
    1058,  1071,  1073,  1075,  1077,  1079,  1100,  1113,  1115,  1119,
    1128,  1135,  1137,  1144,  1149,  1156,  1158,  1165,  1196,  1211,
    1230,  1241,  1246,  1248,  1252,  1265,  1280,  1282,  1284,  1286,
    1288,  1292,  1299,  1304,  1331,  1338,  1353,  1358,  1360,  1362,
    1364,  1366,  1377,  1388,  1395,  1402,  1411,  1413,  1426,  1428,
    1430,  1432,  1434,  1436,  1438,  1447,  1456,  1465,  1472,  1479,
    1481,  1483,  1485,  1487,  1489,  1493,  1495,  1499,  1512,  1521,
    1536,  1559,  1580,  1597,  1636,  1643,  1645,  1649,  1651,  1660,
    1667,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,
    1689,  1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,  1707,
    1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,  1725,  1727,
    1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,
    1749,  1751,  1756,  1758,  1760,  1762,  1764,  1766,  1768,  1770,
    1772,  1774,  1776,  1778,  1780,  1782,  1784,  1786,  1788,  1790,
    1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,  1808,  1810,
    1812,  1814,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,
    1832,  1834,  1836,  1838,  1840,  1849,  1851,  1855,  1859,  1862,
    1866,  1869,  1873,  1877,  1880,  1884,  1887,  1891,  1895,  1899,
    1903,  1906,  1910,  1913,  1917,  1921,  1925,  1928,  1932,  1935,
    1939,  1942,  1946,  1949,  1953,  1956,  1960,  1964,  1968,  1971,
    1975,  1978,  1987,  1989,  1991,  1993,  1995,  2002,  2023,  2027,
    2034,  2047,  2060,  2091,  2122,  2131,  2138,  2143,  2152,  2161,
    2168,  2175,  2180,  2182,  2186,  2191,  2206,  2208,  2212,  2219,
    2223,  2234,  2271,  2280,  2291,  2293,  2297,  2304,  2306,  2310,
    2338,  2355,  2366,  2368,  2370,  2372,  2374,  2381,  2400,  2405,
    2416,  2423,  2425,  2429,  2462,  2495,  2514,  2516,  2520,  2522,
    2539,  2544,  2553,  2568,  2587,  2589,  2591,  2593,  2595,  2597,
    2612,  2627,  2659,  2691,  2695,  2699,  2703,  2710,  2717,  2730,
    2735,  2737,  2741,  2743,  2745,  2747,  2749,  2751,  2753,  2755,
    2757,  2776,  2778,  2780,  2782,  2784,  2789,  2791,  2793,  2795,
    2797,  2799,  2814,  2816,  2818,  2820,  2822,  2826,  2839,  2843,
    2854,  2861,  2863,  2878,  2887,  2898,  2905,  2910,  2927,  2948,
    2950,  2954,  2977,  2990,  2992,  2996
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     216,     0,    -1,   224,   225,   217,   221,    -1,   218,   228,
     219,    -1,    58,   212,    -1,    70,   212,    -1,    75,   209,
     233,    21,   201,   211,   212,    -1,     1,   212,    -1,    76,
     212,    -1,     1,   212,    -1,    77,   209,   201,    21,   201,
      21,   233,    21,   233,    21,   201,    21,   201,    21,   201,
     211,   212,    -1,     1,   212,    -1,    78,   209,   232,   211,
     212,    -1,     1,   212,    -1,    79,   212,    -1,     1,   212,
      -1,   226,   220,   222,   223,   219,    -1,    88,   212,    -1,
     213,   202,    -1,   229,    -1,   228,   229,    -1,   227,   207,
     237,   212,    -1,     1,   212,    -1,   234,    -1,   206,    -1,
     209,   235,   211,    -1,   209,   236,   211,    -1,   209,   211,
      -1,   209,   236,   211,    -1,   203,    -1,   234,    -1,   235,
      21,   234,    -1,   201,    -1,   236,    21,   201,    -1,   239,
      -1,   241,    -1,   242,    -1,   243,    -1,   244,    -1,   246,
      -1,   247,    -1,   248,    -1,   249,    -1,   250,    -1,   251,
      -1,   255,    -1,   256,    -1,   258,    -1,   259,    -1,   260,
      -1,   261,    -1,   263,    -1,   265,    -1,   266,    -1,   267,
      -1,   268,    -1,   269,    -1,   270,    -1,   271,    -1,   274,
      -1,   275,    -1,   276,    -1,   277,    -1,   278,    -1,   279,
      -1,   282,    -1,   288,    -1,   289,    -1,   290,    -1,   291,
      -1,   292,    -1,   293,    -1,   297,    -1,   298,    -1,   300,
      -1,   301,    -1,   303,    -1,   304,    -1,   307,    -1,   308,
      -1,   309,    -1,   305,    -1,   310,    -1,   311,    -1,   312,
      -1,   315,    -1,   314,    -1,   319,    -1,   320,    -1,   321,
      -1,   322,    -1,   323,    -1,   324,    -1,   325,    -1,   329,
      -1,   330,    -1,   331,    -1,   332,    -1,   335,    -1,   341,
      -1,   342,    -1,   343,    -1,   344,    -1,   345,    -1,   349,
      -1,   351,    -1,   352,    -1,   353,    -1,   354,    -1,   355,
      -1,   356,    -1,   357,    -1,   358,    -1,   361,    -1,   363,
      -1,   384,    -1,   406,    -1,   430,    -1,   434,    -1,   435,
      -1,   436,    -1,   437,    -1,   438,    -1,   439,    -1,   440,
      -1,   441,    -1,   442,    -1,   443,    -1,   444,    -1,   445,
      -1,   446,    -1,   447,    -1,   448,    -1,   449,    -1,   451,
      -1,   452,    -1,   454,    -1,   455,    -1,   456,    -1,   457,
      -1,   458,    -1,   463,    -1,   459,    -1,   461,    -1,   464,
      -1,   465,    -1,   469,    -1,   470,    -1,   471,    -1,   472,
      -1,   473,    -1,   475,    -1,   476,    -1,   477,    -1,   480,
      -1,   481,    -1,   482,    -1,   483,    -1,   484,    -1,   487,
      -1,   488,    -1,   489,    -1,   490,    -1,   491,    -1,   492,
      -1,   493,    -1,   494,    -1,   495,    -1,   496,    -1,   497,
      -1,   501,    -1,   505,    -1,   508,    -1,   511,    -1,   512,
      -1,   513,    -1,   514,    -1,   516,    -1,   517,    -1,   518,
      -1,   519,    -1,   520,    -1,   521,    -1,   522,    -1,   524,
      -1,   525,    -1,   527,    -1,     3,   209,   211,    -1,     4,
     209,   234,   211,    -1,     5,    -1,     6,   209,   227,    21,
     201,   211,    -1,     7,   209,   201,   211,    -1,     8,   209,
     201,    21,   227,    21,   227,   211,    -1,     9,   209,   201,
      21,   227,    21,   227,    21,   377,   211,    -1,   227,    -1,
     245,    21,   227,    -1,    10,   209,   401,    21,   400,    21,
     201,    21,   230,    21,   371,    21,   227,    21,   227,    21,
     227,    21,   230,    21,   230,    21,   230,    21,   230,    21,
     230,    21,   378,   211,    -1,    11,   209,   227,    21,   383,
      21,   381,    21,   368,    21,   230,   211,    -1,    12,   209,
     227,    21,   383,    21,   381,    21,   368,    21,   230,    21,
     230,   211,    -1,    13,   209,   227,    21,   383,    21,   381,
      21,   368,    21,   230,   211,    -1,    14,   209,   230,    21,
     368,    21,   377,    21,   385,    21,   396,   211,    -1,    15,
     209,   201,    21,   227,    21,   203,    21,   203,    21,   203,
     211,    -1,   253,    -1,   254,    -1,   183,    -1,    73,    -1,
      16,   209,   401,    21,   400,    21,   201,    21,   230,    21,
     371,    21,   227,    21,   227,    21,   227,    21,   230,    21,
     230,    21,   230,    21,   230,    21,   230,    21,   378,    21,
     252,    21,   230,    21,   371,   211,    -1,    17,   209,   201,
      21,   227,    21,   418,    21,   227,    21,   227,    21,   227,
      21,   230,   211,    -1,   227,    -1,   257,    21,   227,    -1,
      18,   209,   401,    21,   400,    21,   201,    21,   230,    21,
     371,    21,   227,    21,   227,    21,   227,    21,   230,    21,
     365,    21,   365,    21,   403,    21,   230,    21,   230,    21,
     230,    21,   230,   211,    -1,    19,   209,   401,    21,   400,
      21,   201,    21,   230,    21,   371,    21,   227,    21,   227,
      21,   227,    21,   230,    21,   365,    21,   365,    21,   403,
      21,   230,    21,   230,    21,   230,    21,   230,   211,    -1,
      20,   209,   227,    21,   383,    21,   381,    21,   368,    21,
     230,   211,    -1,    22,   209,   202,    21,   202,    21,   202,
     211,    -1,    23,    -1,    24,   209,   201,    21,   231,   211,
      -1,   227,    -1,   264,    21,   227,    -1,    27,   209,   227,
      21,   383,    21,   381,    21,   368,    21,   230,   211,    -1,
      28,   209,   401,    21,   400,    21,   201,    21,   230,    21,
     371,    21,   227,    21,   227,    21,   227,    21,   230,    21,
     230,    21,   230,    21,   230,    21,   230,    21,   378,   211,
      -1,    29,   209,   201,    21,   227,    21,   418,    21,   227,
      21,   227,    21,   203,    21,   227,   211,    -1,    30,   209,
     201,   211,    -1,    31,   209,   201,    21,   227,    21,   203,
     211,    -1,    32,   209,   203,    21,   202,   211,    -1,    33,
     209,   202,   211,    -1,   227,    -1,   272,    21,   227,    -1,
     227,    -1,   273,    21,   227,    -1,    34,   209,   201,    21,
     227,    21,   418,    21,   227,    21,   227,    21,   203,    21,
     202,    21,   412,    21,   413,    21,   399,    21,   203,   211,
      -1,    36,   209,   201,    21,   227,    21,   418,    21,   227,
      21,   227,    21,   409,    21,   230,    21,   227,    21,   399,
      21,   399,    21,   227,   211,    -1,    37,   209,   227,    21,
     383,    21,   381,    21,   368,    21,   230,    21,   230,   211,
      -1,    38,   209,   367,    21,   227,   211,    -1,    39,   209,
     201,    21,   414,    21,   346,   211,    -1,    40,   209,   507,
      21,   252,    21,   227,   211,    -1,   227,    -1,   280,    21,
     227,    -1,   227,    -1,   281,    21,   227,    -1,    41,   209,
     234,    21,   399,   211,    -1,    42,    -1,    43,    -1,    44,
      -1,    46,    -1,    47,    -1,    45,   209,   230,    21,   368,
      21,   466,    21,   374,   211,    -1,    49,   209,   227,    21,
     383,    21,   381,    21,   368,    21,   230,   211,    -1,    50,
     209,   201,    21,   227,    21,   418,    21,   227,    21,   415,
     211,    -1,    51,   209,   227,    21,   383,    21,   381,    21,
     368,    21,   230,    21,   230,   211,    -1,    52,   209,   401,
      21,   400,    21,   201,    21,   230,    21,   371,    21,   227,
      21,   227,    21,   227,    21,   230,    21,   230,    21,   230,
      21,   230,    21,   230,    21,   378,   211,    -1,    53,   209,
     201,    21,   227,    21,   418,    21,   227,    21,   415,   211,
      -1,   295,    -1,   296,    -1,    35,    -1,    48,    -1,    54,
     209,   252,    21,   500,    21,   402,    21,   398,    21,   386,
      21,   368,    21,   227,    21,   369,    21,   369,   211,    -1,
      55,   209,   203,    21,   388,    21,   375,    21,   230,    21,
     389,   211,    -1,   227,    -1,   299,    21,   227,    -1,    56,
     209,   230,    21,   230,    21,   230,   211,    -1,    59,   209,
     227,    21,   201,   211,    -1,    60,    -1,    61,   209,   201,
      21,   201,   211,    -1,    62,   209,   227,   211,    -1,    63,
     209,   201,    21,   231,   211,    -1,    64,    -1,    65,   209,
     201,    21,   201,   211,    -1,    66,   209,   401,    21,   400,
      21,   201,    21,   230,    21,   371,    21,   227,    21,   227,
      21,   227,    21,   230,    21,   230,    21,   230,    21,   230,
      21,   230,    21,   378,   211,    -1,    67,   209,   230,    21,
     230,    21,   230,    21,   230,    21,   230,    21,   230,   211,
      -1,    68,   209,   201,    21,   227,    21,   418,    21,   227,
      21,   227,    21,   227,    21,   399,    21,   399,   211,    -1,
      69,   209,   201,    21,   227,    21,   203,    21,   203,   211,
      -1,    71,   209,   201,   211,    -1,   227,    -1,   313,    21,
     227,    -1,    72,   209,   227,    21,   383,    21,   381,    21,
     368,    21,   230,   211,    -1,    74,   209,   252,    21,   500,
      21,   402,    21,   398,    21,   386,    21,   203,   211,    -1,
     318,    -1,   317,    -1,    90,    -1,   157,    -1,    80,   209,
     211,    -1,    81,   209,   227,    21,   227,   211,    -1,    82,
     209,   227,   211,    -1,    84,   209,   401,    21,   400,    21,
     201,    21,   230,    21,   371,    21,   227,    21,   227,    21,
     227,    21,   230,    21,   365,    21,   365,    21,   380,   211,
      -1,    85,   209,   367,    21,   227,   211,    -1,    86,   209,
     201,    21,   227,    21,   418,    21,   227,    21,   227,    21,
     408,   211,    -1,    87,   209,   227,   211,    -1,   327,    -1,
     328,    -1,   150,    -1,    96,    -1,    89,   209,   201,    21,
     227,    21,   203,    21,   203,   211,    -1,    91,   209,   201,
      21,   227,    21,   203,    21,   203,   211,    -1,    92,   209,
     201,    21,   202,   211,    -1,    93,   209,   201,    21,   202,
     211,    -1,    94,   209,   364,    21,   364,    21,   364,   211,
      -1,   202,    -1,    95,   209,   431,    21,   294,    21,   227,
      21,   230,    21,   227,   211,    -1,   337,    -1,   338,    -1,
      96,    -1,   150,    -1,    97,    -1,    98,    -1,    99,   209,
     203,    21,   203,    21,   379,   211,    -1,   100,   209,   201,
      21,   227,    21,   227,   211,    -1,   101,   209,   367,    21,
     227,    21,   227,   211,    -1,   102,   209,   367,    21,   227,
     211,    -1,   103,   209,   201,    21,   227,   211,    -1,   253,
      -1,   254,    -1,   347,    -1,   187,    -1,   104,    -1,   105,
     209,   211,    -1,   227,    -1,   350,    21,   227,    -1,   106,
     209,   201,    21,   227,    21,   227,    21,   227,    21,   382,
     211,    -1,   107,   209,   201,    21,   201,    21,   421,   211,
      -1,   108,   209,   201,    21,   227,    21,   416,    21,   230,
      21,   377,    21,   230,   211,    -1,   109,   209,   252,    21,
     230,    21,   368,    21,   252,    21,   230,    21,   232,    21,
     252,    21,   377,    21,   393,    21,   421,   211,    -1,   110,
     209,   230,    21,   502,    21,   230,    21,   230,    21,   230,
      21,   252,    21,   252,    21,   252,    21,   368,   211,    -1,
     111,   209,   203,    21,   230,    21,   230,    21,   230,    21,
     230,    21,   230,    21,   230,   211,    -1,   112,   209,   401,
      21,   400,    21,   201,    21,   230,    21,   371,    21,   227,
      21,   227,    21,   227,    21,   230,    21,   230,    21,   230,
      21,   230,    21,   230,    21,   378,    21,   203,    21,   203,
      21,   203,    21,   230,   211,    -1,   113,   209,   201,    21,
     230,   211,    -1,   227,    -1,   359,    21,   227,    -1,   114,
      -1,   115,   209,   201,    21,   203,    21,   201,   211,    -1,
     116,   209,   419,    21,   391,   211,    -1,   117,   209,   211,
      -1,   238,    -1,   206,    -1,   227,    -1,   206,    -1,   227,
      -1,   206,    -1,   227,    -1,   206,    -1,   252,    -1,   206,
      -1,   227,    -1,   206,    -1,   227,    -1,   206,    -1,   227,
      -1,   206,    -1,   227,    -1,   206,    -1,   227,    -1,   206,
      -1,   294,    -1,   206,    -1,   227,    -1,   206,    -1,   227,
      -1,   206,    -1,   227,    -1,   206,    -1,   227,    -1,   206,
      -1,   316,    -1,   206,    -1,   227,    -1,   206,    -1,   326,
      -1,   206,    -1,   333,    -1,   206,    -1,   334,    -1,   206,
      -1,   118,   209,   201,   211,    -1,   336,    -1,   206,    -1,
     227,    -1,   206,    -1,   227,    -1,   206,    -1,   227,    -1,
     206,    -1,   227,    -1,   206,    -1,   362,    -1,   206,    -1,
     419,    -1,   206,    -1,   227,    -1,   206,    -1,   227,    -1,
     206,    -1,   227,    -1,   206,    -1,   227,    -1,   206,    -1,
     486,    -1,   206,    -1,   227,    -1,   206,    -1,   227,    -1,
     206,    -1,   227,    -1,   206,    -1,   227,    -1,   206,    -1,
     227,    -1,   206,    -1,   499,    -1,   206,    -1,   227,    -1,
     206,    -1,   227,    -1,   206,    -1,   227,    -1,   206,    -1,
     119,   209,   201,    21,   227,    21,   203,   211,    -1,   120,
      -1,   209,   245,   211,    -1,   209,   257,   211,    -1,   209,
     211,    -1,   209,   264,   211,    -1,   209,   211,    -1,   209,
     264,   211,    -1,   209,   272,   211,    -1,   209,   211,    -1,
     209,   273,   211,    -1,   209,   211,    -1,   209,   280,   211,
      -1,   209,   281,   211,    -1,   209,   299,   211,    -1,   209,
     313,   211,    -1,   209,   211,    -1,   209,   350,   211,    -1,
     209,   211,    -1,   209,   359,   211,    -1,   209,   450,   211,
      -1,   209,   453,   211,    -1,   209,   211,    -1,   209,   460,
     211,    -1,   209,   211,    -1,   209,   462,   211,    -1,   209,
     211,    -1,   209,   474,   211,    -1,   209,   211,    -1,   209,
     478,   211,    -1,   209,   211,    -1,   209,   498,   211,    -1,
     209,   510,   211,    -1,   209,   523,   211,    -1,   209,   211,
      -1,   209,   526,   211,    -1,   209,   211,    -1,   121,   209,
     367,    21,   227,    21,   203,   211,    -1,   432,    -1,   433,
      -1,    83,    -1,   200,    -1,   122,   209,   201,    21,   201,
     211,    -1,   123,   209,   201,    21,   227,    21,   418,    21,
     227,    21,   227,    21,   227,    21,   227,    21,   373,    21,
     409,   211,    -1,   124,   209,   211,    -1,   125,   209,   201,
      21,   227,   211,    -1,   126,   209,   431,    21,   294,    21,
     227,    21,   230,    21,   227,   211,    -1,   127,   209,   431,
      21,   294,    21,   227,    21,   230,    21,   227,   211,    -1,
     128,   209,   401,    21,   400,    21,   201,    21,   230,    21,
     371,    21,   227,    21,   227,    21,   227,    21,   230,    21,
     365,    21,   365,    21,   403,    21,   230,    21,   230,   211,
      -1,   129,   209,   401,    21,   400,    21,   201,    21,   230,
      21,   371,    21,   227,    21,   227,    21,   227,    21,   230,
      21,   365,    21,   365,    21,   403,    21,   230,    21,   230,
     211,    -1,   130,   209,   377,    21,   203,    21,   203,   211,
      -1,   131,   209,   377,    21,   203,   211,    -1,   132,   209,
     377,   211,    -1,   133,   209,   377,    21,   203,    21,   203,
     211,    -1,   134,   209,   203,    21,   203,    21,   202,   211,
      -1,   135,   209,   201,    21,   411,   211,    -1,   136,   209,
     201,    21,   201,   211,    -1,   137,   209,   420,   211,    -1,
     227,    -1,   450,    21,   227,    -1,   138,   209,   201,   211,
      -1,   139,   209,   201,    21,   227,    21,   428,    21,   392,
      21,   376,    21,   366,   211,    -1,   227,    -1,   453,    21,
     227,    -1,   140,   209,   227,    21,   227,   211,    -1,   141,
     209,   211,    -1,   143,   209,   201,    21,   227,    21,   401,
      21,   400,   211,    -1,   144,   209,   401,    21,   400,    21,
     201,    21,   230,    21,   371,    21,   227,    21,   227,    21,
     227,    21,   230,    21,   230,    21,   230,    21,   230,    21,
     230,    21,   378,    21,   252,    21,   230,    21,   371,   211,
      -1,   145,   209,   367,    21,   227,    21,   227,   211,    -1,
     146,   209,   227,    21,   203,    21,   202,    21,   202,   211,
      -1,   227,    -1,   460,    21,   227,    -1,   147,   209,   202,
      21,   202,   211,    -1,   227,    -1,   462,    21,   227,    -1,
     148,   209,   201,    21,   227,    21,   418,    21,   227,    21,
     227,   227,    21,   227,    21,   383,    21,   202,    21,   399,
      21,   377,    21,   422,    21,   423,   211,    -1,   149,   209,
     201,    21,   227,    21,   418,    21,   367,    21,   227,    21,
     227,    21,   227,   211,    -1,   151,   209,   201,    21,   227,
      21,   203,    21,   203,   211,    -1,   467,    -1,   468,    -1,
      57,    -1,    26,    -1,   152,   209,   367,    21,   227,   211,
      -1,   153,   209,   201,    21,   227,    21,   418,    21,   227,
      21,   227,    21,   227,    21,   397,    21,   227,   211,    -1,
     154,   209,   201,   211,    -1,   155,   209,   201,    21,   367,
      21,   227,    21,   429,   211,    -1,   156,   209,   201,    21,
     201,   211,    -1,   227,    -1,   474,    21,   227,    -1,   158,
     209,   401,    21,   400,    21,   201,    21,   230,    21,   371,
      21,   227,    21,   227,    21,   227,    21,   230,    21,   365,
      21,   365,    21,   403,    21,   230,    21,   230,    21,   230,
     211,    -1,   159,   209,   401,    21,   400,    21,   201,    21,
     230,    21,   371,    21,   227,    21,   227,    21,   227,    21,
     230,    21,   365,    21,   365,    21,   403,    21,   230,    21,
     230,    21,   230,   211,    -1,   160,   209,   201,    21,   227,
      21,   418,    21,   227,    21,   227,    21,   227,    21,   227,
      21,   425,   211,    -1,   227,    -1,   478,    21,   227,    -1,
     142,    -1,   161,   209,   201,    21,   227,    21,   418,    21,
     227,    21,   227,    21,   227,    21,   227,   211,    -1,   162,
     209,   227,   211,    -1,   163,   209,   201,    21,   227,    21,
     203,   211,    -1,   164,   209,   367,    21,   227,    21,   227,
      21,   203,    21,   227,    21,   203,   211,    -1,   165,   209,
     201,    21,   227,    21,   418,    21,   227,    21,   227,    21,
     227,    21,   404,    21,   409,   211,    -1,   166,    -1,   485,
      -1,   340,    -1,   302,    -1,   348,    -1,   167,   209,   227,
      21,   383,    21,   381,    21,   368,    21,   230,    21,   230,
     211,    -1,   168,   209,   227,    21,   383,    21,   381,    21,
     368,    21,   230,    21,   230,   211,    -1,   169,   209,   401,
      21,   400,    21,   201,    21,   230,    21,   371,    21,   227,
      21,   227,    21,   227,    21,   230,    21,   230,    21,   230,
      21,   230,    21,   230,    21,   378,   252,   211,    -1,   171,
     209,   401,    21,   400,    21,   201,    21,   230,    21,   371,
      21,   227,    21,   227,    21,   227,    21,   230,    21,   230,
      21,   230,    21,   230,    21,   230,    21,   378,   252,   211,
      -1,   172,   209,   211,    -1,   173,   209,   211,    -1,   174,
     209,   211,    -1,   175,   209,   203,    21,   227,   211,    -1,
     176,   209,   203,    21,   203,   211,    -1,   177,   209,   201,
      21,   227,    21,   418,    21,   227,    21,   227,   211,    -1,
     178,   209,   426,   211,    -1,   227,    -1,   498,    21,   227,
      -1,   234,    -1,   479,    -1,   240,    -1,   339,    -1,   283,
      -1,   360,    -1,   284,    -1,   506,    -1,   179,   209,   201,
      21,   227,    21,   401,    21,   400,    21,   227,    21,   227,
      21,   203,    21,   227,   211,    -1,   503,    -1,   504,    -1,
      25,    -1,   170,    -1,   180,   209,   201,   211,    -1,   181,
      -1,   306,    -1,   285,    -1,   286,    -1,   287,    -1,   182,
     209,   201,    21,   227,    21,   427,    21,   427,    21,   252,
      21,   509,   211,    -1,   262,    -1,   407,    -1,   515,    -1,
     227,    -1,   510,    21,   227,    -1,   184,   209,   227,    21,
     383,    21,   381,    21,   368,    21,   230,   211,    -1,   185,
     209,   211,    -1,   186,   209,   230,    21,   368,    21,   377,
      21,   374,   211,    -1,   188,   209,   201,    21,   387,   211,
      -1,   189,    -1,   190,   209,   431,    21,   294,    21,   227,
      21,   230,    21,   227,    21,   227,   211,    -1,   191,   209,
     201,    21,   227,    21,   203,   211,    -1,   192,   209,   367,
      21,   227,    21,   203,    21,   203,   211,    -1,   193,   209,
     201,    21,   227,   211,    -1,   194,   209,   227,   211,    -1,
     195,   209,   201,    21,   388,    21,   230,    21,   405,    21,
     364,    21,   370,    21,   410,   211,    -1,   196,   209,   201,
      21,   227,    21,   401,    21,   400,    21,   227,    21,   227,
      21,   227,    21,   227,    21,   362,   211,    -1,   227,    -1,
     523,    21,   227,    -1,   197,   209,   201,    21,   227,    21,
     401,    21,   400,    21,   227,    21,   227,    21,   227,    21,
     227,    21,   227,    21,   227,   211,    -1,   198,   209,   227,
      21,   227,    21,   390,    21,   394,    21,   424,   211,    -1,
     227,    -1,   526,    21,   227,    -1,   199,   209,   201,    21,
     417,    21,   372,    21,   395,    21,   382,   211,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1526,  1526,  1532,  1537,  1542,  1547,  1549,  1557,  1559,
    1567,  1569,  1577,  1579,  1587,  1589,  1597,  1602,  1607,  1612,
    1615,  1621,  1642,  1650,  1652,  1657,  1662,  1664,  1669,  1674,
    1679,  1682,  1688,  1691,  1697,  1699,  1701,  1703,  1705,  1707,
    1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,  1725,  1727,
    1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,
    1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1767,
    1769,  1771,  1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,
    1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,  1805,  1807,
    1809,  1811,  1813,  1815,  1817,  1819,  1821,  1823,  1825,  1827,
    1829,  1831,  1833,  1835,  1837,  1839,  1841,  1843,  1845,  1847,
    1849,  1851,  1853,  1855,  1857,  1859,  1861,  1863,  1865,  1867,
    1869,  1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,
    1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,
    1909,  1911,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,
    1929,  1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,
    1949,  1951,  1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,
    1969,  1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1987,
    1989,  1991,  1993,  1995,  1997,  1999,  2001,  2006,  2011,  2016,
    2021,  2030,  2035,  2047,  2067,  2073,  2082,  2129,  2138,  2147,
    2156,  2170,  2179,  2181,  2186,  2191,  2196,  2251,  2269,  2275,
    2284,  2347,  2410,  2419,  2424,  2429,  2434,  2440,  2449,  2458,
    2505,  2523,  2528,  2537,  2542,  2547,  2553,  2562,  2568,  2577,
    2600,  2637,  2646,  2663,  2668,  2677,  2683,  2692,  2698,  2707,
    2721,  2726,  2731,  2736,  2741,  2746,  2751,  2760,  2772,  2781,
    2828,  2840,  2842,  2847,  2852,  2857,  2898,  2928,  2934,  2943,
    2948,  2957,  2962,  2967,  2976,  2981,  2986,  2991,  3038,  3043,
    3077,  3086,  3091,  3097,  3106,  3115,  3137,  3139,  3144,  3149,
    3154,  3159,  3171,  3180,  3243,  3260,  3275,  3284,  3286,  3291,
    3296,  3301,  3310,  3319,  3324,  3329,  3334,  3339,  3351,  3353,
    3358,  3363,  3368,  3373,  3378,  3383,  3395,  3415,  3432,  3441,
    3443,  3445,  3450,  3455,  3460,  3465,  3471,  3480,  3495,  3500,
    3517,  3539,  3544,  3549,  3596,  3601,  3607,  3616,  3621,  3626,
    3631,  3636,  3638,  3643,  3647,  3652,  3656,  3661,  3665,  3670,
    3672,  3677,  3681,  3686,  3690,  3695,  3699,  3704,  3708,  3713,
    3717,  3722,  3724,  3729,  3733,  3738,  3742,  3747,  3751,  3756,
    3760,  3765,  3767,  3772,  3776,  3781,  3783,  3788,  3790,  3795,
    3797,  3802,  3807,  3809,  3814,  3818,  3823,  3827,  3832,  3836,
    3841,  3845,  3850,  3852,  3857,  3859,  3864,  3868,  3873,  3877,
    3882,  3886,  3891,  3895,  3900,  3902,  3907,  3911,  3916,  3920,
    3925,  3929,  3934,  3938,  3943,  3947,  3952,  3954,  3959,  3963,
    3968,  3972,  3977,  3981,  3986,  3995,  4000,  4005,  4007,  4012,
    4014,  4019,  4024,  4026,  4031,  4033,  4038,  4043,  4048,  4053,
    4055,  4060,  4062,  4067,  4072,  4077,  4079,  4084,  4086,  4091,
    4093,  4098,  4100,  4105,  4107,  4112,  4117,  4122,  4124,  4129,
    4131,  4136,  4153,  4155,  4160,  4165,  4170,  4175,  4204,  4209,
    4218,  4230,  4242,  4305,  4368,  4382,  4396,  4410,  4424,  4429,
    4434,  4439,  4444,  4450,  4459,  4464,  4497,  4503,  4512,  4524,
    4529,  4554,  4609,  4629,  4638,  4644,  4653,  4658,  4664,  4673,
    4710,  4736,  4745,  4747,  4752,  4757,  4762,  4779,  4808,  4813,
    4830,  4835,  4841,  4850,  4913,  4976,  4997,  5003,  5012,  5017,
    5038,  5047,  5056,  5079,  5105,  5110,  5112,  5114,  5116,  5121,
    5130,  5139,  5186,  5233,  5238,  5243,  5248,  5257,  5262,  5277,
    5282,  5288,  5297,  5299,  5304,  5306,  5308,  5310,  5312,  5314,
    5319,  5353,  5355,  5360,  5365,  5370,  5375,  5380,  5382,  5384,
    5386,  5391,  5400,  5402,  5404,  5409,  5415,  5424,  5433,  5438,
    5452,  5466,  5471,  5486,  5495,  5512,  5521,  5530,  5560,  5597,
    5603,  5612,  5655,  5675,  5681,  5690
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADVANCEDBREPSHAPEREPRESENTATION",
  "ANGLETAPER", "APPROACH", "APPROVAL", "APPROVALSTATUS", "AXIS1PLACEMENT",
  "AXIS2PLACEMENT3D", "BACKBORING", "BACKSIDECOUNTERBORE",
  "BACKSIDECOUNTERSINK", "BALLENDMILL", "BIDIRECTIONALMILLING", "BLOCK",
  "BORING", "BOSS", "BOTTOMANDSIDEFINISHMILLING",
  "BOTTOMANDSIDEROUGHMILLING", "BULLNOSEENDMILL", "C", "CALENDARDATE",
  "CARTESIAN", "CARTESIANPOINT", "CCP", "CCW", "CENTERDRILL",
  "CENTERDRILLING", "CHAMFER", "CHANNEL", "CIRCLE", "CIRCULAROFFSET",
  "CIRCULAROMIT", "CIRCULARPATTERN", "CLIMB", "CLOSEDPOCKET",
  "COMBINEDDRILLANDREAMER", "COMPLETECIRCULARPATH", "COMPOSITECURVE",
  "COMPOSITECURVESEGMENT", "CONICALHOLEBOTTOM", "CONNECT", "CONTACT",
  "CONTINUOUS", "CONTOURPARALLEL", "CONTSAMEGRADIENT",
  "CONTSAMEGRADIENTSAMECURVATURE", "CONVENTIONAL", "COUNTERBORE",
  "COUNTERBOREHOLE", "COUNTERSINK", "COUNTERSINKING", "COUNTERSUNKHOLE",
  "CUTTERLOCATIONTRAJECTORY", "CUTTINGCOMPONENT",
  "CUTTINGEDGETECHNOLOGICALDATA", "CW", "DATA", "DATEANDTIME", "DEGOUGE",
  "DESCRIPTIVEPARAMETER", "DIAMETERTAPER", "DIRECTION", "DISCONTINUOUS",
  "DISPLAYMESSAGE", "DRILLING", "DRILLINGTYPESTRATEGY", "EDGEROUND",
  "ELLIPSE", "ENDSEC", "EXCHANGEPALLET", "FACEMILL", "FALSE", "FEEDSTOP",
  "FILEDESCRIPTION", "FILEEND", "FILENAME", "FILESCHEMA", "FILESTART",
  "FLATHOLEBOTTOM", "FLATSLOTENDTYPE", "FLATWITHRADIUSHOLEBOTTOM",
  "FORWARD", "FREEFORMOPERATION", "GENERALPATH", "GENERALPATTERN",
  "GENERALPOCKETBOTTOMCONDITION", "HEADER", "HELIX", "HOLE", "HYPERBOLA",
  "INDEXPALLET", "INDEXTABLE", "INPROCESSGEOMETRY", "LEADINGLINESTRATEGY",
  "LEFT", "LIFT", "LIFTSHIFTPLUNGE", "LIMITSANDFITS", "LINE", "LINEARPATH",
  "LINEARPROFILE", "LOADTOOL", "LOOPBACK", "LOOPSLOTENDTYPE",
  "MACHININGWORKINGSTEP", "MATERIAL", "MILLINGCUTTINGTOOL",
  "MILLINGMACHINEFUNCTIONS", "MILLINGTECHNOLOGY", "MILLINGTOOLDIMENSION",
  "MULTISTEPDRILLING", "NCVARIABLE", "NONCONTACT", "NUMERICPARAMETER",
  "OFFSETVECTOR", "OPENSLOTENDTYPE", "OPTIONALSTOP", "PARABOLA",
  "PARAMETER", "PARTIALCIRCULARPATH", "PERSONANDADDRESS", "PLANARFACE",
  "PLANARPOCKETBOTTOMCONDITION", "PLANE", "PLANECCSTRATEGY",
  "PLANECLSTRATEGY", "PLANEFINISHMILLING", "PLANEROUGHMILLING",
  "PLUNGEHELIX", "PLUNGERAMP", "PLUNGETOOLAXIS", "PLUNGEZIGZAG",
  "PLUSMINUSVALUE", "POLYLINE", "PROCESSMODEL", "PROCESSMODELLIST",
  "PROGRAMSTOP", "PROJECT", "RADIUSEDPOCKETBOTTOMCONDITION",
  "RADIUSEDSLOTENDTYPE", "RAPID", "RAPIDMOVEMENT", "REAMING",
  "RECTANGULARCLOSEDPROFILE", "RECTANGULAROFFSET", "RECTANGULAROMIT",
  "RECTANGULARPATTERN", "REGIONPROJECTION", "RIGHT",
  "RIGHTCIRCULARCYLINDER", "ROUNDEDUPROFILE", "ROUNDHOLE", "SETMARK",
  "SETUP", "SETUPINSTRUCTION", "SHAFT", "SIDEFINISHMILLING",
  "SIDEROUGHMILLING", "SLOT", "SPHERICALCAP", "SPHERICALHOLEBOTTOM",
  "SPHERICALSURFACE", "SQUAREUPROFILE", "STEP", "STRAIGHTLINE",
  "TAPEREDENDMILL", "TAPEREDREAMER", "TAPPING", "TCP", "THREADDRILLING",
  "THREEAXES", "THROUGHBOTTOMCONDITION", "THROUGHPOCKETBOTTOMCONDITION",
  "TOLERANCEDLENGTHMEASURE", "TOLERANCES", "TOOLPATHFEATURE",
  "TOOLPATHLIST", "TOOLPROBING", "TOUCHPROBE", "TRAJECTORYPATH",
  "TRIMMEDCURVE", "TRUE", "TWISTDRILL", "TWOAXES", "UNIDIRECTIONALMILLING",
  "UNKNOWN", "UNLOADTOOL", "UNSPECIFIED", "UVSTRATEGY", "VECTOR",
  "VEEPROFILE", "WAITFORMARK", "WOODRUFFSLOTENDTYPE", "WORKPIECE",
  "WORKPIECECOMPLETEPROBING", "WORKPIECEPROBING", "WORKPIECESETUP",
  "WORKPLAN", "ZIGZAG", "CHARSTRING", "INTSTRING", "REALSTRING", "BAD",
  "COLON", "DOLLAR", "EQUALS", "LBOX", "LPAREN", "RBOX", "RPAREN",
  "SEMICOLON", "SHARP", "SLASH", "$accept", "inputFile", "dataSection",
  "dataStarter", "endSection", "fileDescription", "fileEnd", "fileName",
  "fileSchema", "fileStart", "headerSection", "headerStarter",
  "instanceId", "instanceList", "instancePlus", "optReal",
  "parenRealListFull", "parenStringList", "parenStringListFull", "real",
  "realList", "stringList", "instance", "advancedBrepShapeRepresentation",
  "angleTaper", "approach", "approval", "approvalStatus", "axis1placement",
  "axis2placement3d", "axis2placement3dList", "backBoring",
  "backsideCounterbore", "backsideCountersink", "ballEndmill",
  "bidirectionalMilling", "block", "boolean", "booleanTrue",
  "booleanFalse", "boring", "boss", "bossList",
  "bottomAndSideFinishMilling", "bottomAndSideRoughMilling",
  "bullnoseEndmill", "calendarDate", "cartesian", "cartesianPoint",
  "cartesianPointList", "centerDrill", "centerDrilling", "chamfer",
  "channel", "circle", "circularOffset", "circularOmit",
  "circularOffsetList", "circularOmitList", "circularPattern",
  "closedPocket", "combinedDrillAndReamer", "completeCircularPath",
  "compositeCurve", "compositeCurveSegment", "compositeCurveSegmentList",
  "compoundFeatureSelectList", "conicalHoleBottom", "connect", "contact",
  "continuous", "contSameGradient", "contSameGradientSameCurvature",
  "contourParallel", "counterbore", "counterboreHole", "countersink",
  "counterSinking", "countersunkHole", "cutmodeType", "cutmodeTypeClimb",
  "cutmodeTypeConventional", "cutterLocationTrajectory",
  "cuttingComponent", "cuttingComponentList",
  "cuttingEdgeTechnologicalData", "dateAndTime", "degouge",
  "descriptiveParameter", "diameterTaper", "direction", "discontinuous",
  "displayMessage", "drilling", "drillingTypeStrategy", "edgeRound",
  "ellipse", "exchangePallet", "executableList", "facemill", "feedstop",
  "fittingType", "fittingTypeHole", "fittingTypeShaft", "flatHoleBottom",
  "flatSlotEndType", "flatWithRadiusHoleBottom", "freeformOperation",
  "generalPath", "generalPattern", "generalPocketBottomCondition", "hand",
  "handRight", "handLeft", "helix", "hyperbola", "indexPallet",
  "indexTable", "inProcessGeometry", "integer", "leadingLineStrategy",
  "leftOrRight", "leftOrRightLeft", "leftOrRightRight", "lift",
  "liftShiftPlunge", "limitsAndFits", "line", "linearPath",
  "linearProfile", "loadTool", "logical", "logicalUnknown", "loopBack",
  "loopSlotEndType", "machiningOperationList", "machiningWorkingstep",
  "material", "millingCuttingTool", "millingMachineFunctions",
  "millingTechnology", "millingToolDimension", "multistepDrilling",
  "ncVariable", "ncVariableList", "nonContact", "numericParameter",
  "offsetVector", "openSlotEndType", "optAdvancedBrepShapeRepresentation",
  "optApproachRetractStrategy", "optApproval", "optAxis2placement3d",
  "optBoolean", "optBoundedCurve", "optBoundingGeometrySelect",
  "optCartesianPoint", "optChannel", "optClosedProfile", "optCutmodeType",
  "optCuttingEdgeTechnologicalData", "optDateAndTime", "optDirection",
  "optDrillingTypeStrategy", "optFittingType", "optFreeformStrategy",
  "optHand", "optInProcessGeometry", "optInteger", "optionalStop",
  "optLeftOrRight", "optMachineFunctions", "optMachiningTool",
  "optMaterial", "optMillingTechnology", "optOffsetVector",
  "optParenNcVariableListFull", "optPersonAndAddress",
  "optProcessModelList", "optRestrictedAreaSelect", "optSetup",
  "optStrokeConnectionStrategy", "optTaperSelect", "optTechnology",
  "optTolerancedLengthMeasure", "optToolDirection", "optToolpathList",
  "optToolpathSpeedprofile", "optTwo5DmillingStrategy", "optVeeProfile",
  "optWorkpiece", "parabola", "parameter", "parenAxis2placement3dListFull",
  "parenBossList", "parenCartesianPointList",
  "parenCartesianPointListFull", "parenCircularOffsetList",
  "parenCircularOmitList", "parenCompositeCurveSegmentListFull",
  "parenCompoundFeatureSelectListFull", "parenCuttingComponentListFull",
  "parenExecutableList", "parenMachiningOperationList",
  "parenNcVariableListFull", "parenProcessModelLiszt",
  "parenPropertyParameterList", "parenRectangularOffsetList",
  "parenRectangularOmitList", "parenSetupInstructionList",
  "parenSlotEndTypeList", "parenToolpathLisztFull",
  "parenTrimmingSelectListFull", "parenWorkpieceList",
  "parenWorkpieceSetupList", "partialCircularPath", "pathmodeType",
  "pathmodeTypeForward", "pathmodeTypeZigzag", "personAndAddress",
  "planarFace", "planarPocketBottomCondition", "plane", "planeCcStrategy",
  "planeClStrategy", "planeFinishMilling", "planeRoughMilling",
  "plungeHelix", "plungeRamp", "plungeToolaxis", "plungeZigzag",
  "plusMinusValue", "polyline", "processModel", "processModelList",
  "processModelLiszt", "programStop", "project", "propertyParameterList",
  "radiusedPocketBottomCondition", "radiusedSlotEndType", "rapidMovement",
  "reaming", "rectangularClosedProfile", "rectangularOffset",
  "rectangularOffsetList", "rectangularOmit", "rectangularOmitList",
  "rectangularPattern", "regionProjection", "rightCircularCylinder",
  "rotDirection", "rotDirectionCw", "rotDirectionCcw", "roundedUProfile",
  "roundHole", "setMark", "setup", "setupInstruction",
  "setupInstructionList", "sideFinishMilling", "sideRoughMilling", "slot",
  "slotEndTypeList", "speedName", "sphericalCap", "sphericalHoleBottom",
  "sphericalSurface", "squareUProfile", "step", "straightline",
  "strokeConnectionStrategy", "taperedEndmill", "taperedReamer", "tapping",
  "threadDrilling", "threeAxes", "throughBottomCondition",
  "throughPocketBottomCondition", "tolerancedLengthMeasure", "tolerances",
  "toolpathFeature", "toolpathList", "toolpathLiszt",
  "toolpathSpeedprofile", "toolpathType", "toolProbing",
  "toolReferencePoint", "toolReferencePointCcp", "toolReferencePointTcp",
  "touchProbe", "trajectoryPath", "transitionCode", "trimmedCurve",
  "trimmingPreference", "trimmingSelectList", "twistDrill", "twoAxes",
  "unidirectionalMilling", "unloadTool", "unspecified", "uvStrategy",
  "vector", "veeProfile", "waitForMark", "woodruffSlotEndType",
  "workpiece", "workpieceCompleteProbing", "workpieceList",
  "workpieceProbing", "workpieceSetup", "workpieceSetupList", "workplan", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   215,   216,   217,   218,   219,   220,   220,   221,   221,
     222,   222,   223,   223,   224,   224,   225,   226,   227,   228,
     228,   229,   229,   230,   230,   231,   232,   232,   233,   234,
     235,   235,   236,   236,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   245,   246,   247,   248,   249,
     250,   251,   252,   252,   253,   254,   255,   256,   257,   257,
     258,   259,   260,   261,   262,   263,   264,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   272,   273,   273,   274,
     275,   276,   277,   278,   279,   280,   280,   281,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   294,   295,   296,   297,   298,   299,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   313,   314,   315,   316,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     346,   346,   347,   348,   349,   350,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   359,   360,   361,   362,
     363,   364,   364,   365,   365,   366,   366,   367,   367,   368,
     368,   369,   369,   370,   370,   371,   371,   372,   372,   373,
     373,   374,   374,   375,   375,   376,   376,   377,   377,   378,
     378,   379,   379,   380,   380,   381,   381,   382,   382,   383,
     383,   384,   385,   385,   386,   386,   387,   387,   388,   388,
     389,   389,   390,   390,   391,   391,   392,   392,   393,   393,
     394,   394,   395,   395,   396,   396,   397,   397,   398,   398,
     399,   399,   400,   400,   401,   401,   402,   402,   403,   403,
     404,   404,   405,   405,   406,   407,   408,   409,   409,   410,
     410,   411,   412,   412,   413,   413,   414,   415,   416,   417,
     417,   418,   418,   419,   420,   421,   421,   422,   422,   423,
     423,   424,   424,   425,   425,   426,   427,   428,   428,   429,
     429,   430,   431,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   450,   451,   452,   453,   453,   454,   455,
     456,   457,   458,   459,   460,   460,   461,   462,   462,   463,
     464,   465,   466,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   474,   475,   476,   477,   478,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   486,   486,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   498,   499,   499,   500,   500,   500,   500,   500,   500,
     501,   502,   502,   503,   504,   505,   506,   507,   507,   507,
     507,   508,   509,   509,   509,   510,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     523,   524,   525,   526,   526,   527
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     2,     7,     2,     2,     2,
      17,     2,     5,     2,     2,     2,     5,     2,     2,     1,
       2,     4,     2,     1,     1,     3,     3,     2,     3,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       6,     4,     8,    10,     1,     3,    30,    12,    14,    12,
      12,    12,     1,     1,     1,     1,    36,    16,     1,     3,
      34,    34,    12,     8,     1,     6,     1,     3,    12,    30,
      16,     4,     8,     6,     4,     1,     3,     1,     3,    24,
      24,    14,     6,     8,     8,     1,     3,     1,     3,     6,
       1,     1,     1,     1,     1,    10,    12,    12,    14,    30,
      12,     1,     1,     1,     1,    20,    12,     1,     3,     8,
       6,     1,     6,     4,     6,     1,     6,    30,    14,    18,
      10,     4,     1,     3,    12,    14,     1,     1,     1,     1,
       3,     6,     4,    26,     6,    14,     4,     1,     1,     1,
       1,    10,    10,     6,     6,     8,     1,    12,     1,     1,
       1,     1,     1,     1,     8,     8,     8,     6,     6,     1,
       1,     1,     1,     1,     3,     1,     3,    12,     8,    14,
      22,    20,    16,    38,     6,     1,     3,     1,     8,     6,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     1,     3,     3,     2,     3,
       2,     3,     3,     2,     3,     2,     3,     3,     3,     3,
       2,     3,     2,     3,     3,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     3,     3,     2,     3,
       2,     8,     1,     1,     1,     1,     6,    20,     3,     6,
      12,    12,    30,    30,     8,     6,     4,     8,     8,     6,
       6,     4,     1,     3,     4,    14,     1,     3,     6,     3,
      10,    36,     8,    10,     1,     3,     6,     1,     3,    27,
      16,    10,     1,     1,     1,     1,     6,    18,     4,    10,
       6,     1,     3,    32,    32,    18,     1,     3,     1,    16,
       4,     8,    14,    18,     1,     1,     1,     1,     1,    14,
      14,    31,    31,     3,     3,     3,     6,     6,    12,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
      18,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,    14,     1,     1,     1,     1,     3,    12,     3,    10,
       6,     1,    14,     8,    10,     6,     4,    16,    20,     1,
       3,    22,    12,     1,     3,    12
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,    15,    14,     1,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     2,     0,     0,     0,     0,    19,     7,     0,     0,
       0,     0,     9,     8,    22,    18,     0,     0,     3,    20,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    81,    78,    79,    80,    82,
      83,    84,    86,    85,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   142,   143,
     141,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     5,    32,     0,     0,     0,    13,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    28,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,   405,   404,
       0,     0,     0,     0,    24,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,   337,     0,     0,   242,
     243,   244,   265,   548,   549,   550,   547,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   204,     0,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   454,   455,     0,   452,   453,
       0,     0,     0,     0,     0,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   330,     0,     0,     0,     0,
       0,   458,     0,     0,     0,     0,     0,   358,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,   524,   525,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,    27,     0,     0,   188,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,   271,     0,
       0,     0,   282,     0,     0,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,     0,
       0,     0,     0,   472,     0,   471,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   530,     0,   529,
       0,   545,     0,     0,     0,     0,     0,     0,     0,     0,
     566,     0,     0,     0,     0,     0,     6,     0,    26,    12,
       0,     0,     0,   403,   402,     0,   296,   370,   369,     0,
       0,     0,   340,   339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,   400,     0,     0,
       0,     0,     0,     0,     0,   189,   240,   241,   302,   327,
     546,   534,   536,   538,   535,   537,     0,   539,   379,   378,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,     0,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,   544,     0,   541,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     445,     0,     0,     0,     0,   377,   376,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,   215,     0,     0,     0,
       0,   223,     0,     0,     0,   232,   235,     0,     0,     0,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,   262,   264,   266,     0,     0,     0,     0,     0,     0,
     281,     0,   284,     0,     0,     0,   293,   294,     0,     0,
       0,     0,   307,   308,     0,     0,     0,     0,     0,     0,
       0,   324,     0,     0,     0,   456,     0,   459,     0,     0,
       0,     0,     0,   465,     0,     0,   216,     0,   469,   470,
     473,     0,   478,     0,     0,     0,     0,   486,     0,     0,
       0,   496,     0,     0,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   527,     0,   531,
       0,     0,     0,     0,   560,     0,     0,     0,   565,     0,
       0,     0,     0,   430,   272,     0,     0,     0,     0,     0,
       0,   290,   289,   366,   365,   287,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,   426,
     312,   309,   310,     0,   311,     0,   495,   494,     0,   492,
     493,     0,     0,     0,     0,     0,   508,   407,   532,     0,
     533,   406,   354,   353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,   362,
     361,   277,   276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   421,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   383,   382,     0,     0,   429,   348,   347,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   315,     0,     0,     0,     0,     0,   213,    31,
       0,     0,     0,   222,     0,     0,     0,   236,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,     0,   436,   476,     0,   318,   257,     0,
       0,     0,     0,     0,     0,   328,   414,   451,     0,     0,
       0,     0,     0,   464,   467,   468,   217,   448,   569,     0,
       0,     0,     0,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   511,     0,     0,     0,     0,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,   563,
       0,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,     0,     0,     0,   300,   301,   373,   372,   298,   299,
       0,     0,     0,     0,   431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   352,   351,     0,     0,     0,
       0,     0,     0,   399,   398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,     0,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   447,   387,   386,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,   413,   412,     0,     0,
       0,     0,     0,   391,   390,     0,   393,   392,     0,     0,
     193,     0,     0,     0,     0,     0,     0,     0,   316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   291,   292,     0,     0,   477,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570,     0,   480,     0,   483,     0,     0,   491,     0,
     450,   573,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   556,     0,     0,   559,
       0,   564,     0,     0,     0,   325,     0,     0,     0,     0,
       0,   346,   345,     0,     0,     0,     0,   261,   303,   313,
     514,   395,   517,   516,   518,     0,   515,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   375,   374,     0,   381,
     380,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   368,   367,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   356,   355,     0,     0,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
     331,     0,     0,     0,     0,   433,   385,     0,   384,     0,
       0,     0,     0,     0,   197,     0,   199,   200,   201,     0,
       0,     0,     0,   212,   218,     0,     0,     0,     0,     0,
     246,   237,     0,   247,     0,     0,   250,     0,   256,     0,
       0,     0,   274,     0,     0,     0,   297,     0,   317,     0,
       0,     0,     0,     0,     0,   460,   461,     0,     0,     0,
       0,     0,     0,     0,   574,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,   557,     0,
       0,     0,     0,     0,   326,   329,   442,   501,     0,   572,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,   415,   561,   552,   553,     0,   554,
       0,   187,   344,   343,     0,     0,     0,     0,   441,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,   418,
     208,     0,     0,   231,   238,   248,     0,     0,     0,   268,
       0,   275,     0,   194,     0,   285,     0,   319,     0,     0,
       0,     0,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,     0,   512,     0,   519,   520,     0,     0,
       0,   551,   562,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   397,   396,     0,
       0,     0,     0,     0,   411,   410,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,   207,     0,     0,
       0,   220,     0,   209,     0,     0,     0,     0,     0,     0,
     195,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   490,     0,     0,     0,     0,   509,     0,     0,     0,
       0,   420,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,   341,     0,     0,     0,
       0,     0,     0,     0,     0,   350,   349,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   419,     0,     0,     0,     0,     0,     0,     0,   423,
     225,     0,     0,     0,     0,     0,     0,   269,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
       0,   444,   506,     0,   505,   513,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,   422,     0,     0,
       0,     0,     0,     0,     0,   389,   388,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   443,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   425,
     227,     0,     0,     0,     0,   255,     0,     0,     0,   321,
       0,   457,     0,     0,     0,     0,     0,     0,   507,     0,
       0,   568,     0,     0,     0,   334,   333,     0,     0,     0,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,     0,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   229,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   409,   408,     0,     0,     0,     0,     0,   364,   363,
       0,     0,     0,     0,     0,   438,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     283,     0,     0,     0,     0,     0,   437,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,   440,   487,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   439,     0,     0,     0,     0,
     360,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,   196,     0,
       0,     0,   219,   249,   267,     0,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     521,   522,     0,     0,     0,     0,     0,   503,   504,     0,
       0,     0,     0,     0,     0,   210,   211,     0,     0,     0,
       0,     0,   206,     0,   481,     0,   323
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    13,    14,    38,    17,    21,    31,    46,     4,
       9,    10,   529,    25,    26,   535,   883,   521,    41,   536,
    1045,   356,   200,  1720,   201,   911,   202,   203,   204,   205,
    1904,   206,   207,   208,   209,   210,   211,   873,   578,   579,
     212,   213,  1891,   214,   215,   216,   217,  1866,   218,  1117,
     219,   220,   221,   222,   223,   224,   225,  2071,  2141,   226,
     227,   228,   229,   230,   231,  1057,  1752,   232,   912,   913,
     563,   564,   565,   233,   234,   235,   236,   237,   238,  1456,
     943,   944,   239,   240,  1369,   241,   242,  1642,   243,   244,
     245,   566,   246,   247,   248,   249,   250,   251,  1165,   252,
     253,  1240,  1241,  1242,   254,   255,   256,   257,   258,   259,
     260,  1174,  1175,  1176,   261,   262,   263,   264,  1682,   868,
     265,  1437,  1438,  1439,   914,  1643,   266,   267,   268,   269,
     270,  1203,  1204,  1644,   271,  1323,   272,   273,   274,   275,
     276,   277,   278,   279,  1626,   915,   280,  1304,   281,  1721,
    2167,  1847,   557,   874,  2037,  1874,  1633,  1310,  2047,  1457,
    1224,  1696,   639,  2332,  1243,  2260,  1177,  1683,   869,   282,
    1440,  1668,  1017,   920,  1671,  1305,  1727,  1497,  2117,  1535,
    1538,  1645,  1969,  1465,   898,   865,   530,  1219,  2253,  1976,
    1528,   283,  1867,  1835,  1822,  1981,   977,  2032,  2109,   894,
    1662,  1250,  1027,  1184,  1532,   647,  1248,  2244,  2288,  1730,
    2056,   684,  1293,  1269,  1506,   284,   607,   608,   609,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   804,   301,   302,  1366,   303,
     304,   305,   306,   307,   308,  2267,   309,  2307,   310,   311,
     312,  1208,  1209,  1210,   313,   314,   315,   316,   317,  1808,
     318,   319,   320,  2093,  1220,   321,   322,   323,   324,   325,
    1646,  1647,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   838,  1221,   916,   337,   956,   957,   958,
     338,   917,   567,   339,  1868,  1414,   340,   341,   342,   343,
    1869,   344,   345,   346,   347,   348,   349,   350,  1389,   351,
     352,  1602,   353
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2050
static const yytype_int16 yypact[] =
{
      71,  -126,  -107,   118,    40, -2050, -2050, -2050,   -88,    89,
      98, -2050,   -53,    80,    15,   -41,   -37,    88, -2050,   -35,
     -20, -2050,    -3,   -11,    -7,    21, -2050, -2050,     2,     4,
      58,    86, -2050, -2050, -2050, -2050,  2874,    18, -2050, -2050,
      41,   212, -2050,    53,    60,    64,   169,    68,    77,    84,
      95,    96,   126,   132,   136,   150,   153,   159,   178,   186,
     189,   199,   204,   216,   217,   218,   219,   220,   221,   223,
     224,   225,   226,   227,   228,   229,   230,   235,   236,   237,
     238,   239,   240,   242,   243,   244,   247,   248,   249,   250,
     252,   253,   254,   255,   256,   257,   258,   259,   261,   263,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   279,   280,   281,   282,   283,   285,   287,   288,
     289,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050,    -8,   379,   560, -2050,
     373, -2050,    75,    76,   387,   388,   389,   -98,    76,    76,
      76,   -62,   390,   -98,   391,   -98,   -98,    76,    90,   392,
      76,   -98,   393,   394,   395,   396,   399,   397,   401,    76,
     -77,   402,    91,    75,   -62,    76,   403,    76,   -98,   404,
      22,   405,   -62,    76,   406,    76,   408,   409,   -98,   -62,
     411,   413,   414,    76,    22,   407,    76,    76,   -98,   -77,
     415,    76,   416,   418,   419,   420,   -22,   421,   424,   -77,
     -77,   425,   417,   426,   428,   429,    22,   -62,   430,   -98,
     433,   434,   427,   435,   436,   -77,   438,   439,   431,   440,
     -22,   -22,   -98,   -98,   -60,   -60,   -60,   -60,   441,   442,
     444,   422,   445,   446,    76,   437,   448,   -98,   -77,    76,
     449,   451,   452,   453,   -77,   454,   455,   456,   457,   -98,
     -98,   458,   459,    76,   460,   -77,   461,    76,    76,   -98,
     -98,   462,   463,   464,   447,   465,   466,   467,   469,   470,
     471,    76,   468,   -62,   479,   -22,   480,   -77,   481,    76,
     482,   483,   484,    76,   486, -2050,   487, -2050,   478,   489,
    -101,   485, -2050,   491,   601,   492,   642,   643, -2050, -2050,
     644,   645,   670,   671, -2050,   672, -2050,   673,   674,   679,
     688,   689,   690,   691,   694,   696,   697,   700,   513,   705,
     706,   518,   711,   713,   715, -2050, -2050,   716,   717, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050,   718,   720,   723,
     724,   725,   727,   731,   734, -2050, -2050,   735, -2050, -2050,
     736,   737,   743,   745,   556,   747,   749,   750,   751,   754,
     757,   568,   761,   762, -2050,   763,   574,   765,   766,   767,
     578,   769,   770,   771,   777, -2050, -2050,   778, -2050, -2050,
     784,   786,   791,   795,   796, -2050,   802,   803,   804,   806,
     808,   809,   815,   820,   822, -2050,   633,   825,   826,   827,
     828, -2050,   829,   830,   833,   834,   835, -2050, -2050,   836,
     837,   649,   841,   842,   843,   844,    76,   655,   656,   847,
     850, -2050,   851,   853,   854,   855,   857,   859,   860,   861,
     862,   863,   675,   864,   866,   867,   868,   869,   870,   681,
     872,   873,   874,   875,   876,   877,   878, -2050, -2050, -2050,
     879,   880,   881,    76,   692,   883,   695,   884,   886, -2050,
     887,   888,   889,   890,   891,   892,   703,   894,   895,   896,
     897,   898, -2050,   708,   900, -2050,     3,   710, -2050,   722,
   -2050,    76,    76,   -12,   -86,   -86,   -86,   -43,    76,   -12,
      76,   -12,   -12,   -86,   726,   721,   -86,   -12,    76, -2050,
      76,   729, -2050,    76,    76,   -86,    76,   728,    22,    14,
     -43,   -86,    76,   -86,   -12,    76,    83,    16,   -62,   732,
     733, -2050,   721,   738,   -12,   -62,    76,    76, -2050,   -86,
      83,    76, -2050,   -12,    76,    76, -2050,    76,    76,   730,
     739,    61,   740,    76,    76,    76,    76,    76,   741,    76,
     -62,    -2,   -62,   -12,   -62,   742, -2050,    76,    76,   746,
      76,    76,    61,    61,   -12,   -12,   748,   752, -2050,   753,
     755,   744,   756, -2050,     6, -2050, -2050,    76,    76,    76,
     -12,    76,   758,   764,    76,    76,    76,    76,    76, -2050,
     -77,   759,   -12,   -12,    76,    76, -2050,    76,    76,    76,
     -86,   -86,   -12,   -12,    76,   760,    76, -2050,     7, -2050,
      76, -2050,    76,   -86,   -43,    69,    61,    76,    76,    76,
   -2050,    16,    76,    76,    76,   768, -2050,     2, -2050, -2050,
     714,   903,   905, -2050, -2050,   906, -2050, -2050, -2050,   908,
     914,   915, -2050, -2050,   917,   919,   923,   925,   927,   928,
     929,   931,    75,   772,   933,   938,   943,   946,   773,   947,
     948,   949,   774,    76,   950,   952, -2050, -2050,   776,   953,
     954,   955,   957,   958,   959, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050,   960, -2050, -2050, -2050,
     961,   967,   779,   780,   781,   782,   968,   973,   975,   976,
     977,   978,   789,   980,   792,   981,   983,   984,   797,   798,
   -2050, -2050,   985, -2050, -2050,   986,   989,   990,   807,   810,
     992,   993,   994,   998, -2050, -2050,   999, -2050, -2050,  1002,
    1003,   814,  1005,  1007,  1008,   819,  1010,   821,  1012,  1013,
    1014,  1015,  1016,   831,  1017,  1018,    76,   832,   838,    76,
   -2050,  1019,   839,  1020,  1023,  1025,  1026,   840,  1027,  1031,
    1032,   845,  1034,  1036,   848,  1037,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,   871,   882,  1049,    76,
   -2050,  1050,  1051,  1052,  1054, -2050, -2050,   885,  1057,  1058,
    1060,   893,  1062,  1063,  1064,  1065,    35,  1066,  1067, -2050,
      76,    76,   899,   -31,   -31,   -31,   -60,   902,   901,   904,
     907,   909,   -31,   910, -2050,     8, -2050,   -31,   913,   904,
     912, -2050,   904,   904,   -31, -2050, -2050,    10,   -29,    76,
   -2050,    66,   -31,   904,   -31,   916,   904,     1,    70,   -62,
   -2050, -2050, -2050, -2050,   920,   -62,   904,   921,   -31,     1,
   -2050,   922, -2050,   904,   924,   930, -2050, -2050,    76,   -27,
      76,    76, -2050, -2050,    76,   911,   926,   -43,   -62,   -62,
     935, -2050,   936,   937,   939, -2050,   904, -2050,    76,    76,
     942,   944,   941, -2050,   945,   932, -2050,    12, -2050, -2050,
   -2050,   940, -2050,   -98,   956,    76,   951, -2050,   904,   904,
     962, -2050,   904,    76, -2050,   963,   965,   904,   904,   964,
      76,   904,   -31,   -31,   969,   970, -2050, -2050,   904, -2050,
     -98,   966,   -31,   -60, -2050,    76,   971,   974, -2050,   -62,
     -98,   -98,   -36, -2050, -2050,    20,    81,     2,   972,  1068,
    1069, -2050, -2050, -2050, -2050, -2050, -2050,  1070,  1071,  1076,
    1077,  1078,  1080,   161,  1082,  1085,  1086,  1088,   979,    75,
   -2050,  1095,  1097,  1101,   982,  1104,  1107,  1109,    76, -2050,
   -2050, -2050, -2050,   987, -2050,   988, -2050, -2050,  1110, -2050,
   -2050,  1111,  1117,  1125,  1126,  1129, -2050, -2050, -2050,  1130,
   -2050, -2050, -2050, -2050,  1133,   991,  1134,  1135,  1137,  1138,
    1139,  1140,  1141,  1142,  1147,  1151,  1152, -2050, -2050, -2050,
   -2050, -2050, -2050,   995,   996,   997,  1155,   166,  1000,    76,
    1157,  1158,  1159,  1160,  1161,  1001,  1004,  1006,  1164,  1165,
    1166,  1167,  1168,  1009,  1011,  1021,    76, -2050,   171,  1170,
    1171,  1173,  1028,  1174,  1175,  1176,  1179,  1180,  1182,  1183,
    1184,  1188,  1189,  1029,  1192,  1193,  1195,  1198,  1200,  1202,
    1203,  1204,    76,  1205,  1206,  1207,  1208,  1030,  1209,  1210,
    1213,  1215,  1033, -2050, -2050,  1216,    76, -2050, -2050, -2050,
    1217,  1222, -2050,   -60,   -62,   -43,   -43,   -43,   -19,  1055,
     -62, -2050, -2050,    24,    76,   -62,   -62,   -43, -2050, -2050,
     -43,   -62,    76, -2050,    76,    76,   -43, -2050, -2050, -2050,
     -10,   -43,    76,   -43,   -62,    76,    93,   -62, -2050,   -62,
     -62,    76,  1056,   -43,    93,   -62,    76,  1059,  1072,   -62,
   -2050, -2050, -2050,    76, -2050, -2050,    25, -2050, -2050,    26,
     -62,    22,   -62,   -62,   -62, -2050, -2050, -2050,    76,   -62,
     -62,   -62,   -62, -2050, -2050, -2050, -2050, -2050, -2050,    27,
      97,   -12,   -62, -2050,  1053,    76,   -77,  1073,    76,  1035,
     -62,   -62,    76,    76, -2050,  1074,    76,   -43,   -43,   -62,
     -62,    76,   -12, -2050,    30,   966,   -43,   -10,   -62, -2050,
    1079,   101,   -12,   -12,  1038,   103, -2050,   105,  1083,  1075,
    1224,  1225,  1227,  1228, -2050, -2050, -2050, -2050, -2050, -2050,
    1229,  1230,  1232,    76, -2050,  1236,  1239,  1240,  1242,  1243,
    1244,  1245,  1246,  1247,  1248, -2050, -2050,  1084,  1249,  1250,
    1251,  1252,  1253, -2050, -2050,  1258,  1259,  1260,  1262,  1264,
    1087,  1266,  1267,  1268,  1269,  1089,  1090,  1270,  1272,    76,
   -2050,    76, -2050,  1273,  1275,  1276,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,    76, -2050, -2050, -2050,  1288,  1100,  1291,
    1102,  1293,  1294,  1105,  1296,   177,  1108,  1301,  1302,  1303,
    1304,  1305,  1306,  1308,  1309,  1312,  1313,  1314,  1315,    76,
   -2050,  1317,  1318,  1132,  1320,  1136, -2050, -2050,  1323,  1324,
    1325,    76,  1327, -2050, -2050,  1329, -2050, -2050,  1331,  1332,
   -2050,   107,   -62,   -62,   -62,     0,  1153,   107, -2050,    76,
     107,   107,   -62,   -62,   107,    76,    76,    76,   -62, -2050,
     -62,  1145,   -62,   107,  1145,   111,   113,   107,   -62,    76,
   -2050,   -62,   111,   107,    76, -2050, -2050,    76,   -21, -2050,
   -2050,   -60,   -62,   -62,   -62,   107,    76,    76,    76,   107,
     107, -2050,   115, -2050,   107, -2050,    76,    76, -2050,    76,
   -2050, -2050,    32, -2050,   107,   107,    76,    76,    76,    76,
     -62,   -62,   107,   107,    76,    76, -2050,    22,   -62, -2050,
      76, -2050,     9,    76,    76, -2050,    33,   -64,  1146,   -21,
    1156, -2050, -2050,  1337,  1148,  1339,  1150, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050,  1154, -2050, -2050,  1162,  1341,
    1342,  1345,  1346,  1163,  1169,  1347,  1348,  1349,  1350,  1354,
    1172,    76,  1185,  1357,  1358,  1190, -2050, -2050,  1364, -2050,
   -2050,  1191,  1365,  1366,  1369,  1194,  1370,  1372,  1373,  1199,
    1186, -2050, -2050,  1201,  1378,  1379,  1382,  1383,  1385,  1393,
    1211,  1212,  1394,  1395, -2050, -2050,  1396,  1397,    76,  1398,
    1399,    76, -2050,  1400,  1403,  1404,  1405,  1406,  1407,  1409,
    1410,  1411,  1412,  1223,  1414,  1415,  1226,  1417,  1231, -2050,
   -2050,  1418,  1420,  1421,    76, -2050, -2050,  1233, -2050,   181,
    1234,  1235,  1422,    76, -2050,   -62, -2050, -2050, -2050,    76,
      76,    76,    76, -2050, -2050,    76,  1254,  1255,  1238,   -62,
   -2050, -2050,    34, -2050,   -62,    76, -2050,   -43, -2050,    76,
     -62,    76, -2050,  1256,    76,  1241, -2050,     9, -2050,   -62,
     373,    22,   -62,    76,    76, -2050, -2050,    76,    76,   116,
      76,  1427,    76,    76, -2050,    76,    76,    76,    76,  1257,
      76,   -62,   -62,    76,    76, -2050,    76,    19, -2050,    76,
    1261,   117,    76,    76, -2050, -2050, -2050, -2050,    36, -2050,
   -2050,  1263,  1428,  1265,  1430,  1431,  1432,  1433,  1435,  1440,
    1441,   193,  1445,  1271,    76, -2050,  1274,  1447,  1448,  1450,
    1277,  1452,  1278,  1453,    76,  1279,  1454,  1289,  1456,  1457,
    1459,  1460,  1462,  1463,  1465, -2050, -2050,  1290,  1466,    76,
    1471,  1472,  1473,  1474,  1475,  1476,  1292,  1478,  1295,  1297,
    1481,  1483,  1486, -2050, -2050, -2050, -2050, -2050,  1300, -2050,
    1307, -2050, -2050, -2050,  1491,  1492,  1493,    76, -2050,  1310,
      76, -2050,    76,   -62,    76,    76,    76,    76,  1321, -2050,
   -2050,    38,   -62, -2050, -2050, -2050,    76,    76,    76, -2050,
      14, -2050,    76, -2050,    45, -2050,     9, -2050,    22,    22,
     -62,    76,    76,    76,    76, -2050,    76,  1494,    76,   119,
      76,    76,    76,    76, -2050,   121, -2050, -2050,    76,    76,
    1316, -2050, -2050,  1311,    76,    76, -2050,  1319,  1495,  1501,
    1328,  1503,  1504,  1505,  1333,  1507,    76, -2050,  1508,  1509,
    1511,  1513,  1517,  1524,    76, -2050,  1525,  1526,  1527,  1343,
    1535,  1536,  1540,  1541,  1544,   -86,  1355, -2050, -2050,  1547,
    1548,  1549,  1556,  1368, -2050, -2050,  1560,  1563,  1565,  1566,
     198,  1377,  1568,  1575, -2050,    76,    76, -2050,    76,    76,
      76, -2050,  1388, -2050,    76,    76,   127,    76,    14,    76,
   -2050,     9,   -60,    22, -2050,    76,   130,    76,    76,    76,
    1581, -2050,    76,    76,    76,  1402, -2050,  1238,    76,    76,
      76, -2050,    46, -2050,    76,    76,  1582,  1584,  1586,  1587,
    1591,   201,  1592,  1593,  1594, -2050, -2050,  1595,  1596,  1408,
    1597,  1413,  1599,  1600,  1601, -2050, -2050,  1602,  1604,  1605,
    1606,  1426,  1419,  1608,  1610,   206,  1423,  1424,  1611,  1612,
    1425, -2050,  1616,  1617,   -62,   -62,   -62,   -62,   -62, -2050,
   -2050,    47,  1434,    14,   -62,   127,   -62, -2050,   -62, -2050,
     131,   -43,   -62,  1238,   -62,   -62,   -62,  1618, -2050,   -62,
     -62, -2050, -2050,    48, -2050, -2050,   -62,   -62, -2050,  1528,
      76,  1619,  1620,  1621,  1624,  1625,    76, -2050,   207,  1627,
    1628,  1629,  1442,  1630,  1631, -2050, -2050,  1633,  1444,  1635,
    1446,  1637,  1638,  1639,    14,  1640,  1641,    76, -2050,  1642,
    1643,  1455,  1644,   -62,   -62,   140,   140,   -62, -2050, -2050,
   -2050,    49,    14,    14,   -62, -2050,   -62,   140,   911, -2050,
     -62, -2050,   140,   140,   -62,  1646,   140,   140, -2050,   -62,
     -62, -2050,    76,  1647,  1648, -2050, -2050,  1649,  1650,  1651,
      76, -2050,  1652,  1653,  1654,  1655,  1656,  1467,  1658,  1659,
    1660,  1661,   -60,  1662,  1664,  1665,  1667,  1479,   -62,   -62,
     140,   140,   -62, -2050,  1488,    76,   -62,   -62,   140, -2050,
     -62,   140,   140,   -62,  1668,   140,   140,   -62,   -62, -2050,
    1671,  1672,  1673,  1674,  1675,  1487,  1489,  1676,  1678,  1680,
    1681,  1682,  1683,  1684,  1497,  1686,  1687,  1688,  1690,   -62,
     -62,   144,   144,   -62, -2050, -2050,   -62,   -62,   152,   -62,
     144,   144,   -62,   210,  1691,   144,   144,   -62,   -62,  1692,
    1693, -2050, -2050,  1695,  1696,  1697,  1699,  1700, -2050, -2050,
    1512,  1701,  1703,  1708,  1711, -2050, -2050,    50,  1529,  1712,
    1713,  1714,  1715,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
   -2050,   -62,   -62,   -62,   -62,    76, -2050,   211,  1531,   -62,
     -62,   -62,   -62,  1716,  1718,  1719,  1722,  1723,  1725,  1727,
    1728,  1730,  1731,  1732, -2050, -2050, -2050,    55, -2050,  1733,
    1734,  1735,  1736,   165,   165,   -62,   -62,   165,   165,   165,
     165,   -62,   -62,   165,    76, -2050,   -62,   -62,   165,   165,
   -2050, -2050,  1550,  1737,  1741,  1746,  1559,  1564,  1567,  1756,
    1570,  1572,  1763, -2050,  1765,  1769,    22,    22, -2050,    22,
     -62,   -62, -2050, -2050, -2050,  1588, -2050, -2050,    22,   -62,
     -62,  1583,  1585,  1771,  1772,  1774,  1776,  1777,  1589,  1590,
   -2050, -2050,   -62,   -62,   -62,  1603,   -62, -2050, -2050,  1778,
    1607,  1613,  1781,  1782,   107, -2050, -2050,  1609,   107,  1614,
    1783,  1615, -2050,   -62, -2050,  1622, -2050
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2050, -2050, -2050, -2050,  1759, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050,   -14, -2050,  1786,  1061,  1092,    43,  -855,  -344,
   -2050,  1299, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050,  -399,   788,   790,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,  -172,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,  -660,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050,  -285, -2050, -1746,
   -1805, -2050,  -410,  -730,  -260, -2050, -1511, -2050, -2050,   400,
   -2050, -2050,  -452, -2049, -2050, -2050,  -852,   192,  -709, -2050,
   -2050,   251, -2050,  1024, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050,   473, -1892,  -570,  -291,   775, -1944, -2050,
   -2050, -2050, -2050, -2050, -1914, -2050, -2050, -2050, -2050, -2050,
     264, -2050, -2050,  -768,   195, -2050,  -319, -2050, -2050, -2050,
   -2050, -2050,   423, -2050, -2050, -2050,  -338, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050,  1091, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050, -2050,
   -2050, -2050, -2050
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,   577,  1028,   640,   641,   642,   870,   871,  1952,   598,
     899,    24,  1718,   516,   880,   593,    22,   884,   523,   612,
     613,  1836,    22,   954,   516,   940,   891,   979,  1009,  1189,
     575,  1198,   900,  1266,   902,   628,  1649,   619,   941,  1651,
    1652,  1306,  1863,  1655,   575,  1443,  1479,  1481,  1493,   568,
     930,  1519,  1664,  1701,  1724,  1824,  1672,  1877,   654,  1946,
    1637,   605,  1677,  1237,   660,  1171,  1954,  1266,  2106,  2127,
    2170,  2285,     1,  1680,  1688,   671,  2324,  1434,  1692,  1693,
    1302,    19,   538,  1697,   540,   541,     5,    44,   905,    29,
     546,    37,  1206,  1703,  1704,   575,   940,   694,  1638,    15,
     355,  1711,  1712,  2057,  1639,     6,  2039,   573,   528,   941,
     705,   942,   633,   634,  1014,    23,   866,   587,     7,  1172,
     867,  1002,  1003,  1207,    11,   906,   907,   597,     8,   555,
    1238,  1435,   968,   969,  1013,   559,    23,   560,   561,  1864,
     576,   522,  1726,  1216,   534,  1531,   637,    12,   622,   876,
       2,   878,   879,    23,   576,   562,    20,   885,  1200,    18,
    1956,   635,   636,   872,    45,    30,  1640,   692,   955,  2120,
    1303,    27,    28,    16,   903,  1173,   653,    32,   606,  1239,
     908,  2110,  1178,  1179,   926,  1681,  1018,  1436,   665,   666,
    1187,    35,    33,   933,   863,  1191,  1455,   909,   675,   676,
      36,    23,  1197,   517,   522,   576,  1641,  1217,  1865,    34,
    1211,    40,  1213,   960,   858,  1719,    42,   980,  1010,  1190,
     896,  1199,   918,  1267,   970,   971,  1230,    23,    23,    23,
     354,  1307,  2155,   357,    23,  1444,  1480,  1482,  1494,    37,
     984,  1520,   355,  1702,  1725,  1825,  1163,  1878,    23,  1947,
    2172,  2173,   995,   996,   358,  2041,  1955,  2061,  2107,  2128,
    2171,  2286,  1004,  1005,   910,  2333,  2325,    43,  2336,  2337,
    2338,  2339,   359,   360,  2342,  1015,  1222,   362,   522,  2346,
    2347,  1193,    23,    23,  1195,  1196,   363,  1308,  2254,    23,
    1286,  1287,   543,   364,    23,  1212,  2262,  2263,  1215,  1463,
    1294,  2269,  2270,  1495,   365,   366,    23,  1526,  1228,  1533,
      23,  1536,  1311,  1631,    23,  1233,    23,  1666,    23,  1669,
      23,  1694,  1845,  1872,    23,  1967,    23,  1974,    23,    23,
      23,  2168,    23,  2035,    23,   367,  2045,  2115,  1258,   895,
      23,   368,  2176,    23,    23,   369,  2165,  2179,  2180,   524,
    2251,  2183,  2184,    23,   531,   532,   533,    23,  2258,   370,
    1274,  1275,   371,   542,  1277,    23,   545,  1251,   372,  1281,
    1282,  2330,  1321,  1285,    23,   554,   556,  1364,    23,    23,
    1290,   570,  1387,   572,    23,  2212,  2213,   373,  1600,   582,
      23,   584,  1806,  2219,    23,   374,  2221,  2222,   375,   592,
    2225,  2226,   595,   596,  1889,   556,    23,   600,   376,  2021,
     993,    23,  2069,   377,    23,   556,   556,  2091,  2139,    23,
      23,  2265,  2305,    23,    23,   378,   379,   380,   381,   382,
     383,   556,   384,   385,   386,   387,   388,   389,   390,   391,
     638,   638,   638,   638,   392,   393,   394,   395,   396,   397,
     650,   398,   399,   400,   556,   655,   401,   402,   403,   404,
     556,   405,   406,   407,   408,   409,   410,   411,   412,   669,
     413,   556,   414,   673,   674,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   688,   427,   428,
     429,   430,   431,   556,   432,   696,   433,   434,   435,   700,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,  1044,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     518,   519,   520,   515,  1180,  1431,  1432,  1433,   525,   526,
     527,   537,   539,   544,   547,   548,   549,  1448,   552,   550,
    1449,   551,   553,   558,   571,   574,  1454,   583,   580,   585,
     586,  1458,   589,  1460,   590,   591,   599,   601,   594,   602,
     603,   604,   709,  1471,   610,   611,   614,   616,   615,   617,
     618,   646,   803,   621,   623,   624,   626,   627,   625,   629,
     630,   632,   631,   644,   643,   645,   648,   649,   651,   652,
     680,   656,   657,   658,   659,   661,   662,   663,   664,   667,
     668,   670,   672,   711,   712,   713,   714,   682,   681,   837,
     685,   686,   687,   677,   678,   679,   683,  1513,  1514,   689,
     691,   693,   695,   697,   698,   699,  1522,   701,   702,   703,
     704,   715,   716,   717,   718,   719,   707,   861,   862,   864,
     720,  1295,   708,   710,   875,   864,   877,   864,   864,   721,
     722,   723,   724,   864,   886,   725,   887,   726,   727,   889,
     890,   728,   892,  1218,   729,   897,   730,   731,   901,   732,
     864,   904,   733,   919,   734,  1218,   735,   736,   737,   738,
     864,   739,   928,   929,   740,   741,   742,   932,   743,   864,
     934,   935,   744,   936,   937,   745,   746,   747,   748,   946,
     947,   948,   949,   950,   749,   952,   750,   751,   752,   864,
     753,   754,   755,   963,   964,   756,   966,   967,   757,   758,
     864,   864,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   981,   982,   983,   864,   985,   770,   771,
     988,   989,   990,   991,   992,   772,   556,   773,   864,   864,
     997,   998,   774,   999,  1000,  1001,   775,   776,   864,   864,
    1006,  1498,  1008,   777,   778,   779,  1011,   780,  1012,   781,
     782,  1016,  1270,  1019,  1020,  1021,   783,   919,  1023,  1024,
    1025,   784,  1518,   785,   786,  1329,   787,   788,   789,   790,
     791,   792,  1529,  1530,   793,   794,   795,   796,   797,  1291,
     798,  1429,   799,   800,   801,   802,   805,   806,   807,  1300,
    1301,   808,   809,  2389,   810,   811,   812,  2391,   813,  1056,
     814,   815,   816,   817,   818,   820,   819,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   839,   840,   842,   841,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   859,   860,  1030,  1029,  1031,  1032,   881,  1033,
     882,   888,   938,   922,   923,  1034,  1035,   893,  1036,   925,
    1037,   939,   951,   945,  1038,   962,  1039,   965,  1040,  1041,
    1042,   972,  1043,   976,  1047,   973,   974,   978,   975,  1048,
     994,   986,  1116,  1007,  1049,  1120,   987,  1050,  1052,  1053,
    1054,  1058,  1484,  1059,  1061,  1062,  1063,  1026,  1064,  1065,
    1066,  1067,  1068,  1046,  1051,  1055,  1502,  1060,  1069,  1074,
    1070,  1071,  1072,  1073,  1075,  1149,  1076,  1077,  1078,  1079,
    1080,  1081,  1083,  1082,  1084,  1085,  1088,  1089,  1086,  1087,
    1090,  1091,  1164,  1094,  1095,  1096,  1168,  1169,  1092,  1097,
    1098,  1093,   638,  1099,  1100,  1101,  1102,  1828,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1114,  1115,
    1121,  1123,  1113,  1118,  1124,  1205,  1125,  1126,  1128,  1119,
    1122,  1127,  1129,  1130,  1223,  1132,  1131,  1133,  1135,  1134,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1148,  1150,  1151,  1152,  1236,  1153,  1244,  1245,  1155,  1156,
    1246,  1157,  1146,  1159,  1160,  1161,  1162,  1166,  1167,  1313,
    1314,  1315,  1316,  1147,  1259,  1260,  1154,  1317,  1318,  1319,
    1170,  1320,  1182,  1324,  1158,  1181,  1325,  1326,  1185,  1327,
    1186,  1272,  1188,  1183,  1192,  1194,  1330,  1214,  1331,  1278,
    1247,  1226,  1332,  1232,  1229,  1334,  1284,  1234,  1335,  1684,
    1336,  1340,  1341,  1235,  1265,  1249,  1254,  1255,  1342,   638,
    1256,  1296,  1257,  1261,  1263,  1262,  1343,  1344,  1264,  1268,
    1345,  1346,  1309,  1273,  1347,  1349,  1350,  1271,  1351,  1352,
    1353,  1354,  1355,  1356,  1279,  1276,  1280,  1283,  1357,  1322,
    1288,  1289,  1358,  1359,  1297,  1292,  1363,  1298,  1370,  1371,
    1372,  1373,  1374,  1312,  1337,  1378,  1379,  1380,  1381,  1382,
    1328,  1390,  1391,  1333,  1392,  1394,  1395,  1396,  1338,  1339,
    1397,  1398,  1348,  1399,  1400,  1401,  1360,  1361,  1362,  1402,
    1403,  1367,  1375,  1405,  1406,  1376,  1407,  1377,  1715,  1408,
    1383,  1409,  1384,  1410,  1411,  1412,  1415,  1416,  1417,  1418,
    1420,  1421,  1385,  1365,  1422,  1368,  1423,  1425,  1427,  1393,
    1404,  1419,  1424,  1428,  1505,  1541,  1542,  1531,  1543,  1544,
    1545,  1546,  1386,  1547,  1388,  1500,  2010,  1549,  1441,  1470,
    1550,  1551,  1475,  1552,  1553,  1554,  1555,  1556,  1557,  1558,
    1560,  1561,  1562,  1563,  1564,  1476,  1503,  1511,  1413,  1565,
    1566,  1567,  1525,  1568,  1539,  1569,  1540,  1571,  1572,  1573,
    1574,  1577,  1426,  1578,  1581,  1559,  1582,  1583,  1570,   638,
    1575,  1576,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1592,
    1445,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1451,  1603,
    1452,  1453,  1604,  1605,  1606,  1607,  1608,  1609,  1459,  1610,
    1611,  1462,  1464,  1612,  1613,  1614,  1615,  1469,  1617,  1618,
    1464,  1620,  1474,  1619,  1622,  1623,  1624,  1621,  1627,  1478,
    1628,  2118,  1629,  1630,  1661,  1729,  1648,  1732,  1733,  1734,
    1735,  1736,  1739,  1740,  1488,  1737,  1741,  1742,  1745,  1746,
    1747,  1748,  1839,  1738,  1743,  1749,  1496,   864,  1754,  1755,
    1744,  1501,   556,  1750,  1504,  1757,  1759,  1760,  1509,  1510,
    1761,  1763,  1512,  1764,  1765,  1767,  1753,  1517,   864,  1769,
    1770,  1756,  1758,  1771,  1772,  1762,  1773,  1527,   864,   864,
    1766,  1534,  1768,  1537,  1774,  1777,  1778,  1779,  1780,  1782,
    1783,  1785,  1775,  1776,  1786,  1787,  1788,  1789,  1790,  1548,
    1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1801,
    1800,  1802,  1803,  1811,  1805,  1809,  1810,  1821,  1849,  1880,
    1834,  1882,  1883,  1884,  1885,   569,  1886,  1819,  1820,  1832,
    1856,  1887,  1888,   581,  1879,  1579,  1892,  1580,  1896,  1897,
     588,  1898,  1871,  1900,  1902,  1906,  1881,  1908,  1909,  1591,
    1910,  1911,  1893,  1912,  1913,  1895,  1914,  1916,  1899,  1901,
    1905,  1601,  1918,  1919,  1920,  1921,  1922,  1923,   620,  1925,
    1907,  1915,  1928,  1924,  1929,  1616,  1926,  1930,  1927,  1957,
    1958,  1931,  1933,  1934,  1935,  1965,  1985,  1625,  1932,  1979,
    1980,  1937,  1986,  1945,  1988,  1989,  1990,  1632,  1992,  1994,
    1995,  1984,  1996,  1632,  1997,  1650,  1632,  1632,  1998,  1987,
    1632,  1656,  1657,  1658,  1991,  1999,  2001,  2002,  2003,  1632,
    2042,  1667,  1670,  1632,  2004,  1674,  2005,  2006,  1667,  1632,
    1678,  2007,  2008,  1679,   690,  2009,  2011,   638,  2012,  2013,
    2014,  1632,  1689,  1690,  1691,  1632,  1632,  2015,  1695,  2016,
    1632,  2017,  1698,  1699,  2018,  1700,  2019,  2020,  2023,  2024,
    1632,  1632,  1705,  1706,  1707,  1708,  2025,  2031,  1632,  1632,
    1713,  1714,  2051,  2064,  2043,  2065,  1717,  2066,  2067,  1722,
    1723,  2055,  2068,  2072,  2073,  2074,  2075,  2076,  2078,  2077,
    2080,  2081,  2082,  2083,  2079,  2084,  2085,  2086,  2087,  2089,
    2088,  2090,  2096,  2097,  2094,  2095,  2098,  2099,  2100,  2124,
    2133,  2134,  2135,  2108,  1302,  2136,  2137,  1751,  2142,  2143,
    2144,  2146,  2147,  2145,  2148,  2149,  2150,  2151,  2152,  2153,
    2154,  2156,  2157,  2159,  2160,  2162,  2161,  2182,  2188,  2189,
    2190,  2191,  2192,  2194,  2195,  2196,  2197,  2198,  2199,  2200,
    2201,  2202,  2203,  2205,  1781,  2206,  2207,  1784,  2208,  2224,
    2209,  2215,  2229,  2230,  2231,  2232,  2233,  2236,  2234,  2237,
    2235,  2238,  2239,  2240,  2241,  2242,  2243,  2245,  2246,  2247,
    1804,  2248,  2268,  2273,  2274,  1807,  2275,  2276,  2277,  1812,
    2278,  2279,  2281,  2280,  2282,  1814,  1815,  1816,  1817,  2283,
    2204,  1818,  2284,  2289,  2290,  2291,  2292,  2313,  2287,  2314,
    2315,  1827,  2308,  2316,  2317,  1829,  2318,  1831,  2319,  2320,
    1833,  2321,  2322,  2323,  2326,  2327,  2328,  2329,  2349,  1841,
    1842,  2348,  2350,  1843,  1844,  1846,  1848,  2351,  1850,  1851,
    2352,  1852,  1853,  1854,  1855,  2353,  1857,  2355,  2354,  1860,
    1861,  2356,  1862,  2357,  2358,  1870,  2359,  1873,  1875,  1876,
    2360,  2366,  2372,  2373,  2370,  2374,  2371,  2375,  2376,  2384,
    2377,  2378,  2387,  2388,  2393,   361,  2382,  1890,  2022,   921,
    1894,    39,  2390,  1838,  2131,  2112,   927,  1523,  2385,   706,
    1903,  1731,  1728,  1676,  2386,  2392,  2394,  1472,  1665,  2177,
       0,     0,     0,  2396,     0,  1917,     0,     0,  1521,     0,
       0,   953,     0,   959,   924,   961,  1201,     0,  1202,     0,
       0,   931,     0,     0,  1231,     0,     0,     0,     0,     0,
       0,     0,     0,  1936,     0,     0,  1938,     0,  1939,     0,
    1941,  1942,  1943,  1944,     0,  1022,     0,     0,     0,     0,
       0,     0,  1949,  1950,  1951,     0,   897,     0,  1953,     0,
       0,     0,     0,     0,     0,     0,     0,  1960,  1961,  1962,
    1963,     0,  1964,     0,  1966,  1968,  1970,  1971,  1972,  1973,
       0,  1975,     0,     0,  1977,  1978,     0,     0,     0,     0,
    1982,  1983,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1993,     0,     0,     0,     0,     0,     0,     0,
    2000,     0,     0,     0,     0,     0,     0,  2361,  2362,     0,
    2363,     0,     0,     0,     0,     0,     0,     0,     0,  2367,
       0,     0,     0,     0,     0,     0,  1116,     0,     0,     0,
       0,  2026,  2027,     0,  2028,  2029,  2030,     0,     0,     0,
    2033,  2034,  2036,  2038,   897,  2040,     0,     0,   638,     0,
       0,  2044,  2046,  2048,  2049,  2050,     0,     0,  2052,  2053,
    2054,     0,     0,     0,  2058,  2059,  2060,     0,     0,     0,
    2062,  2063,     0,     0,     0,     0,     0,  2070,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2092,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   897,
       0,  2036,     0,     0,     0,     0,  2116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2132,     0,     0,     0,
       0,     0,  2138,     0,  2140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     897,     0,     0,  2158,     0,     0,     0,     0,     0,     0,
       0,  2166,  2166,     0,     0,     0,     0,     0,   897,   897,
    1225,     0,     0,  2166,     0,     0,  1227,     0,  2166,  2166,
       0,     0,  2166,  2166,     0,     0,     0,     0,  2187,     0,
       0,     0,     0,     0,     0,     0,  2193,     0,     0,  1252,
    1253,     0,     0,     0,     0,     0,     0,     0,   638,     0,
       0,     0,     0,     0,     0,     0,  2166,  2166,     0,     0,
       0,  2216,     0,     0,  2166,     0,     0,  2166,  2166,     0,
       0,  2166,  2166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2252,  2252,     0,
    1299,     0,     0,     0,  2259,     0,  2252,  2252,     0,  2266,
       0,  2252,  2252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2304,     0,  2306,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2331,
    2331,     0,     0,  2331,  2331,  2331,  2331,     0,     0,  2331,
    2343,     0,     0,     0,  2331,  2331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1632,     0,     0,     0,  1632,  1430,     0,     0,     0,     0,
       0,  1442,     0,     0,     0,     0,  1446,  1447,     0,     0,
       0,     0,  1450,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1461,     0,     0,  1466,     0,
    1467,  1468,     0,     0,     0,     0,  1473,     0,     0,     0,
    1477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1483,     0,  1485,  1486,  1487,     0,     0,     0,     0,
    1489,  1490,  1491,  1492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1499,     0,     0,     0,     0,     0,     0,
       0,  1507,  1508,     0,     0,     0,     0,     0,     0,     0,
    1515,  1516,     0,     0,     0,     0,     0,     0,     0,  1524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1634,  1635,  1636,     0,     0,     0,     0,
       0,     0,     0,  1653,  1654,     0,     0,     0,     0,  1659,
       0,  1660,     0,  1663,     0,     0,     0,     0,     0,  1673,
       0,     0,  1675,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1685,  1686,  1687,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1709,  1710,     0,     0,     0,     0,     0,     0,  1716,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1813,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1823,     0,     0,     0,     0,  1826,     0,     0,     0,     0,
       0,  1830,     0,     0,     0,     0,     0,     0,     0,     0,
    1837,     0,     0,  1840,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1858,  1859,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,     0,    64,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,     0,    92,
      93,    94,    95,    96,  1940,    97,    98,     0,    99,     0,
       0,     0,     0,  1948,   100,   101,   102,     0,   103,   104,
     105,   106,     0,   107,     0,   108,   109,   110,     0,   111,
       0,  1959,     0,   112,   113,   114,   115,   116,     0,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,     0,   164,   165,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   185,     0,   186,   187,
     188,     0,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2101,  2102,  2103,  2104,  2105,
       0,     0,     0,     0,     0,  2111,     0,  2113,     0,  2114,
       0,     0,     0,  2119,     0,  2121,  2122,  2123,     0,     0,
    2125,  2126,     0,     0,     0,     0,     0,  2129,  2130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2163,  2164,     0,     0,  2169,     0,
       0,     0,     0,     0,     0,  2174,     0,  2175,     0,     0,
       0,  2178,     0,     0,     0,  2181,     0,     0,     0,     0,
    2185,  2186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2210,
    2211,     0,     0,  2214,     0,     0,     0,  2217,  2218,     0,
       0,  2220,     0,     0,  2223,     0,     0,     0,  2227,  2228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2249,  2250,     0,     0,  2255,     0,     0,  2256,  2257,     0,
    2261,     0,     0,  2264,     0,     0,     0,     0,  2271,  2272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2293,  2294,  2295,  2296,  2297,  2298,
    2299,     0,  2300,  2301,  2302,  2303,     0,     0,     0,     0,
    2309,  2310,  2311,  2312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2334,  2335,     0,     0,
       0,     0,  2340,  2341,     0,     0,     0,  2344,  2345,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2364,  2365,     0,     0,     0,     0,     0,     0,     0,
    2368,  2369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2379,  2380,  2381,     0,  2383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2395
};

static const yytype_int16 yycheck[] =
{
      14,   400,   857,   455,   456,   457,   715,   716,  1900,   419,
     740,    25,     3,    21,   723,   414,     1,   726,   362,   429,
     430,  1767,     1,    25,    21,    35,   735,    21,    21,    21,
      73,    21,   741,    21,   743,   445,  1547,   436,    48,  1550,
    1551,    21,    23,  1554,    73,    21,    21,    21,    21,   393,
     759,    21,  1563,    21,    21,    21,  1567,    21,   468,    21,
      60,    83,  1573,    90,   474,    96,    21,    21,    21,    21,
      21,    21,     1,    94,  1585,   485,    21,    96,  1589,  1590,
     116,     1,   373,  1594,   375,   376,   212,     1,     5,     1,
     381,    70,    26,  1604,  1605,    73,    35,   507,    98,     1,
     201,  1612,  1613,  2017,   104,   212,  1998,   398,   206,    48,
     211,   771,   450,   451,   844,   213,   202,   408,     0,   150,
     206,   830,   831,    57,   212,    42,    43,   418,    88,   206,
     157,   150,   792,   793,   843,    44,   213,    46,    47,   120,
     183,   203,   206,   142,   206,   209,   206,    58,   439,   719,
      79,   721,   722,   213,   183,    64,    76,   727,   187,   212,
    1906,   452,   453,   206,    78,    77,   166,   505,   170,  2083,
     206,   212,   209,    75,   744,   206,   467,   212,   200,   206,
      97,  2073,  1034,  1035,   754,   206,   846,   206,   479,   480,
    1042,   202,   212,   763,   206,  1047,   206,   114,   489,   490,
     207,   213,  1054,   211,   203,   183,   206,   206,   189,   212,
    1062,   209,  1064,   783,   211,   206,   212,   211,   211,   211,
     206,   211,   206,   211,   794,   795,  1078,   213,   213,   213,
     212,   211,  2124,    21,   213,   211,   211,   211,   211,    70,
     810,   211,   201,   211,   211,   211,   211,   211,   213,   211,
    2142,  2143,   822,   823,   201,  2001,   211,   211,   211,   211,
     211,   211,   832,   833,   181,  2314,   211,   209,  2317,  2318,
    2319,  2320,   212,   209,  2323,   206,   206,   209,   203,  2328,
    2329,  1049,   213,   213,  1052,  1053,   209,   206,  2232,   213,
    1142,  1143,   202,   209,   213,  1063,  2240,  2241,  1066,   206,
    1152,  2245,  2246,   206,   209,   209,   213,   206,  1076,   206,
     213,   206,  1167,   206,   213,  1083,   213,   206,   213,   206,
     213,   206,   206,   206,   213,   206,   213,   206,   213,   213,
     213,  2136,   213,   206,   213,   209,   206,   206,  1106,   738,
     213,   209,  2147,   213,   213,   209,   206,  2152,  2153,   363,
     206,  2156,  2157,   213,   368,   369,   370,   213,   206,   209,
    1128,  1129,   209,   377,  1132,   213,   380,  1097,   209,  1137,
    1138,   206,   211,  1141,   213,   389,   390,   211,   213,   213,
    1148,   395,   211,   397,   213,  2190,  2191,   209,   211,   403,
     213,   405,   211,  2198,   213,   209,  2201,  2202,   209,   413,
    2205,  2206,   416,   417,   211,   419,   213,   421,   209,   211,
     820,   213,   211,   209,   213,   429,   430,   211,   211,   213,
     213,   211,   211,   213,   213,   209,   209,   209,   209,   209,
     209,   445,   209,   209,   209,   209,   209,   209,   209,   209,
     454,   455,   456,   457,   209,   209,   209,   209,   209,   209,
     464,   209,   209,   209,   468,   469,   209,   209,   209,   209,
     474,   209,   209,   209,   209,   209,   209,   209,   209,   483,
     209,   485,   209,   487,   488,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   501,   209,   209,
     209,   209,   209,   507,   209,   509,   209,   209,   209,   513,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   882,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     201,    21,   209,   212,  1036,  1315,  1316,  1317,   201,   201,
     201,   201,   201,   201,   201,   201,   201,  1327,   201,   203,
    1330,   202,   201,   201,   201,   201,  1336,   201,   203,   201,
     201,  1341,   201,  1343,   201,   201,   201,   201,   211,   201,
     201,   201,    21,  1353,   203,   201,   201,   201,   211,   201,
     201,   209,   646,   203,   201,   201,   201,   201,   211,   201,
     201,   201,   211,   201,   203,   201,   201,   201,   211,   201,
     203,   202,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,    21,    21,    21,    21,   201,   203,   683,
     201,   201,   201,   211,   211,   211,   209,  1407,  1408,   211,
     201,   201,   201,   201,   201,   201,  1416,   201,   201,   211,
     201,    21,    21,    21,    21,    21,   211,   711,   712,   713,
      21,  1153,   211,   211,   718,   719,   720,   721,   722,    21,
      21,    21,    21,   727,   728,    21,   730,    21,    21,   733,
     734,    21,   736,  1067,   211,   739,    21,    21,   742,   211,
     744,   745,    21,   747,    21,  1079,    21,    21,    21,    21,
     754,    21,   756,   757,    21,    21,    21,   761,    21,   763,
     764,   765,    21,   767,   768,    21,    21,    21,    21,   773,
     774,   775,   776,   777,    21,   779,    21,   211,    21,   783,
      21,    21,    21,   787,   788,    21,   790,   791,    21,   211,
     794,   795,    21,    21,    21,   211,    21,    21,    21,   211,
      21,    21,    21,   807,   808,   809,   810,   811,    21,    21,
     814,   815,   816,   817,   818,    21,   820,    21,   822,   823,
     824,   825,    21,   827,   828,   829,    21,    21,   832,   833,
     834,  1391,   836,    21,    21,    21,   840,    21,   842,    21,
      21,   845,  1123,   847,   848,   849,    21,   851,   852,   853,
     854,    21,  1412,    21,   211,  1189,    21,    21,    21,    21,
      21,    21,  1422,  1423,    21,    21,    21,    21,    21,  1150,
     211,  1313,    21,    21,    21,    21,   211,   211,    21,  1160,
    1161,    21,    21,  2384,    21,    21,    21,  2388,    21,   893,
      21,    21,    21,    21,    21,    21,   211,    21,    21,    21,
      21,    21,   211,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,   211,    21,    21,   211,    21,    21,    21,
      21,    21,    21,    21,   211,    21,    21,    21,    21,    21,
     212,    21,   212,   201,    21,   211,    21,    21,   202,    21,
     209,   202,   202,   201,   201,    21,    21,   209,    21,   201,
      21,   202,   201,   203,    21,   203,    21,   201,    21,    21,
      21,   203,    21,   209,    21,   203,   203,   201,   203,    21,
     201,   203,   976,   203,    21,   979,   202,    21,    21,    21,
      21,    21,  1371,    21,    21,    21,    21,   209,    21,    21,
      21,    21,    21,   211,   211,   211,  1396,   211,    21,    21,
     211,   211,   211,   211,    21,  1009,    21,    21,    21,    21,
     211,    21,    21,   211,    21,    21,    21,    21,   211,   211,
      21,    21,  1026,    21,    21,    21,  1030,  1031,   211,    21,
      21,   211,  1036,    21,    21,   211,    21,  1757,    21,    21,
     211,    21,   211,    21,    21,    21,    21,    21,    21,    21,
      21,    21,   211,   211,    21,  1059,    21,    21,    21,   211,
     211,   211,    21,    21,  1068,    21,   211,    21,    21,   211,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,  1088,    21,  1090,  1091,    21,    21,
    1094,    21,   211,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,   211,  1108,  1109,   211,    21,    21,    21,
     201,    21,   201,    21,   211,   203,    21,    21,   201,    21,
     201,  1125,   202,   209,   201,   203,    21,   201,    21,  1133,
     209,   201,    21,   201,   203,    21,  1140,   203,    21,  1581,
      21,    21,    21,   203,   202,   209,   201,   201,    21,  1153,
     203,  1155,   203,   201,   203,   201,    21,    21,   203,   209,
      21,    21,  1166,   202,    21,    21,    21,   201,    21,    21,
      21,    21,    21,    21,   201,   203,   201,   203,    21,  1183,
     201,   201,    21,    21,   203,   209,    21,   203,    21,    21,
      21,    21,    21,   211,  1198,    21,    21,    21,    21,    21,
     211,    21,    21,   211,    21,    21,    21,    21,   211,   211,
      21,    21,   211,    21,    21,    21,   211,   211,   211,    21,
      21,   211,   211,    21,    21,   211,    21,   211,  1617,    21,
     211,    21,   211,    21,    21,    21,    21,    21,    21,    21,
      21,    21,   211,  1247,    21,  1249,    21,    21,    21,   211,
     211,   211,   209,    21,   209,    21,    21,   209,    21,    21,
      21,    21,  1266,    21,  1268,   202,  1965,    21,   203,   203,
      21,    21,   203,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,   203,   203,   203,  1292,    21,
      21,    21,   203,    21,   201,    21,   211,    21,    21,    21,
      21,    21,  1306,    21,    21,   211,    21,    21,   211,  1313,
     211,   211,    21,    21,    21,    21,    21,    21,    21,    21,
    1324,   211,    21,   211,    21,    21,   211,    21,  1332,   211,
    1334,  1335,    21,    21,    21,    21,    21,    21,  1342,    21,
      21,  1345,  1346,    21,    21,    21,    21,  1351,    21,    21,
    1354,    21,  1356,   211,    21,    21,    21,   211,    21,  1363,
      21,  2081,    21,    21,   209,   209,   203,   201,    21,   211,
      21,   211,    21,    21,  1378,   211,    21,    21,    21,    21,
      21,    21,  1771,   211,   211,    21,  1390,  1391,    21,    21,
     211,  1395,  1396,   211,  1398,    21,    21,    21,  1402,  1403,
      21,    21,  1406,    21,    21,   209,   211,  1411,  1412,    21,
      21,   211,   211,    21,    21,   211,    21,  1421,  1422,  1423,
     211,  1425,   211,  1427,    21,    21,    21,    21,    21,    21,
      21,    21,   211,   211,    21,    21,    21,    21,    21,  1443,
      21,    21,    21,    21,   211,    21,    21,   211,    21,    21,
     209,    21,    21,    21,   211,   211,   211,   209,    21,    21,
     209,    21,    21,    21,    21,   394,    21,   203,   203,   203,
     203,    21,    21,   402,   201,  1479,    21,  1481,    21,    21,
     409,    21,   211,    21,    21,    21,   211,    21,    21,  1493,
      21,    21,   211,    21,    21,   211,    21,    21,   211,   211,
     211,  1505,    21,    21,    21,    21,    21,    21,   437,    21,
     211,   211,    21,   211,    21,  1519,   211,    21,   211,  1908,
    1909,   211,    21,    21,    21,    21,    21,  1531,   211,   203,
     209,   211,    21,   202,    21,    21,    21,  1541,    21,    21,
      21,   212,    21,  1547,    21,  1549,  1550,  1551,    21,   211,
    1554,  1555,  1556,  1557,   211,    21,    21,    21,    21,  1563,
    2002,  1565,  1566,  1567,   211,  1569,    21,    21,  1572,  1573,
    1574,    21,    21,  1577,   503,    21,   211,  1581,    21,    21,
      21,  1585,  1586,  1587,  1588,  1589,  1590,    21,  1592,   211,
    1594,    21,  1596,  1597,    21,  1599,    21,    21,   211,    21,
    1604,  1605,  1606,  1607,  1608,  1609,    21,   209,  1612,  1613,
    1614,  1615,    21,    21,  2003,    21,  1620,    21,    21,  1623,
    1624,   209,    21,    21,    21,    21,    21,    21,    21,   211,
      21,    21,    21,    21,   211,    21,    21,    21,   202,    21,
     211,    21,    21,    21,   211,   211,   211,    21,    21,    21,
      21,    21,    21,   209,   116,    21,    21,  1661,    21,    21,
      21,    21,    21,   211,    21,   211,    21,   211,    21,    21,
      21,    21,    21,    21,    21,    21,   211,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,   211,    21,
      21,    21,    21,    21,  1698,    21,    21,  1701,    21,    21,
     211,   203,    21,    21,    21,    21,    21,    21,   211,    21,
     211,    21,    21,    21,    21,    21,   209,    21,    21,    21,
    1724,    21,    21,    21,    21,  1729,    21,    21,    21,  1733,
      21,    21,    21,   211,    21,  1739,  1740,  1741,  1742,    21,
    2182,  1745,    21,    21,    21,    21,    21,    21,   209,    21,
      21,  1755,   211,    21,    21,  1759,    21,  1761,    21,    21,
    1764,    21,    21,    21,    21,    21,    21,    21,    21,  1773,
    1774,   211,    21,  1777,  1778,  1779,  1780,    21,  1782,  1783,
     211,  1785,  1786,  1787,  1788,   211,  1790,    21,   211,  1793,
    1794,   211,  1796,   211,    21,  1799,    21,  1801,  1802,  1803,
      21,   203,    21,    21,   211,    21,   211,    21,    21,    21,
     211,   211,    21,    21,    21,    46,   203,  1821,  1980,   748,
    1824,    25,   203,  1770,  2099,  2075,   755,  1417,   211,   520,
    1834,  1629,  1627,  1572,   211,   211,   211,  1354,  1564,  2148,
      -1,    -1,    -1,   211,    -1,  1849,    -1,    -1,  1415,    -1,
      -1,   780,    -1,   782,   752,   784,  1058,    -1,  1058,    -1,
      -1,   760,    -1,    -1,  1079,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1877,    -1,    -1,  1880,    -1,  1882,    -1,
    1884,  1885,  1886,  1887,    -1,   851,    -1,    -1,    -1,    -1,
      -1,    -1,  1896,  1897,  1898,    -1,  1900,    -1,  1902,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,  1912,  1913,
    1914,    -1,  1916,    -1,  1918,  1919,  1920,  1921,  1922,  1923,
      -1,  1925,    -1,    -1,  1928,  1929,    -1,    -1,    -1,    -1,
    1934,  1935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1954,    -1,    -1,    -1,    -1,    -1,    -1,  2346,  2347,    -1,
    2349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2358,
      -1,    -1,    -1,    -1,    -1,    -1,  1980,    -1,    -1,    -1,
      -1,  1985,  1986,    -1,  1988,  1989,  1990,    -1,    -1,    -1,
    1994,  1995,  1996,  1997,  1998,  1999,    -1,    -1,  2002,    -1,
      -1,  2005,  2006,  2007,  2008,  2009,    -1,    -1,  2012,  2013,
    2014,    -1,    -1,    -1,  2018,  2019,  2020,    -1,    -1,    -1,
    2024,  2025,    -1,    -1,    -1,    -1,    -1,  2031,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2073,
      -1,  2075,    -1,    -1,    -1,    -1,  2080,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2100,    -1,    -1,    -1,
      -1,    -1,  2106,    -1,  2108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2124,    -1,    -1,  2127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2135,  2136,    -1,    -1,    -1,    -1,    -1,  2142,  2143,
    1069,    -1,    -1,  2147,    -1,    -1,  1075,    -1,  2152,  2153,
      -1,    -1,  2156,  2157,    -1,    -1,    -1,    -1,  2162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2170,    -1,    -1,  1098,
    1099,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2190,  2191,    -1,    -1,
      -1,  2195,    -1,    -1,  2198,    -1,    -1,  2201,  2202,    -1,
      -1,  2205,  2206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2231,  2232,    -1,
    1159,    -1,    -1,    -1,  2238,    -1,  2240,  2241,    -1,  2243,
      -1,  2245,  2246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2285,    -1,  2287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2313,
    2314,    -1,    -1,  2317,  2318,  2319,  2320,    -1,    -1,  2323,
    2324,    -1,    -1,    -1,  2328,  2329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2384,    -1,    -1,    -1,  2388,  1314,    -1,    -1,    -1,    -1,
      -1,  1320,    -1,    -1,    -1,    -1,  1325,  1326,    -1,    -1,
      -1,    -1,  1331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,  1347,    -1,
    1349,  1350,    -1,    -1,    -1,    -1,  1355,    -1,    -1,    -1,
    1359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1370,    -1,  1372,  1373,  1374,    -1,    -1,    -1,    -1,
    1379,  1380,  1381,  1382,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1400,  1401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1409,  1410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1542,  1543,  1544,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1552,  1553,    -1,    -1,    -1,    -1,  1558,
      -1,  1560,    -1,  1562,    -1,    -1,    -1,    -1,    -1,  1568,
      -1,    -1,  1571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1582,  1583,  1584,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1610,  1611,    -1,    -1,    -1,    -1,    -1,    -1,  1618,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1749,    -1,    -1,    -1,    -1,  1754,    -1,    -1,    -1,    -1,
      -1,  1760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1769,    -1,    -1,  1772,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1791,  1792,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    59,    -1,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,  1883,    71,    72,    -1,    74,    -1,
      -1,    -1,    -1,  1892,    80,    81,    82,    -1,    84,    85,
      86,    87,    -1,    89,    -1,    91,    92,    93,    -1,    95,
      -1,  1910,    -1,    99,   100,   101,   102,   103,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,   169,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2064,  2065,  2066,  2067,  2068,
      -1,    -1,    -1,    -1,    -1,  2074,    -1,  2076,    -1,  2078,
      -1,    -1,    -1,  2082,    -1,  2084,  2085,  2086,    -1,    -1,
    2089,  2090,    -1,    -1,    -1,    -1,    -1,  2096,  2097,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2133,  2134,    -1,    -1,  2137,    -1,
      -1,    -1,    -1,    -1,    -1,  2144,    -1,  2146,    -1,    -1,
      -1,  2150,    -1,    -1,    -1,  2154,    -1,    -1,    -1,    -1,
    2159,  2160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2188,
    2189,    -1,    -1,  2192,    -1,    -1,    -1,  2196,  2197,    -1,
      -1,  2200,    -1,    -1,  2203,    -1,    -1,    -1,  2207,  2208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2229,  2230,    -1,    -1,  2233,    -1,    -1,  2236,  2237,    -1,
    2239,    -1,    -1,  2242,    -1,    -1,    -1,    -1,  2247,  2248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2273,  2274,  2275,  2276,  2277,  2278,
    2279,    -1,  2281,  2282,  2283,  2284,    -1,    -1,    -1,    -1,
    2289,  2290,  2291,  2292,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2315,  2316,    -1,    -1,
      -1,    -1,  2321,  2322,    -1,    -1,    -1,  2326,  2327,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2350,  2351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2359,  2360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2372,  2373,  2374,    -1,  2376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2393
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    79,   216,   224,   212,   212,     0,    88,   225,
     226,   212,    58,   217,   218,     1,    75,   220,   212,     1,
      76,   221,     1,   213,   227,   228,   229,   212,   209,     1,
      77,   222,   212,   212,   212,   202,   207,    70,   219,   229,
     209,   233,   212,   209,     1,    78,   223,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    24,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    40,    41,    45,
      49,    50,    51,    52,    53,    54,    55,    56,    59,    61,
      62,    63,    65,    66,    67,    68,    69,    71,    72,    74,
      80,    81,    82,    84,    85,    86,    87,    89,    91,    92,
      93,    95,    99,   100,   101,   102,   103,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   115,   117,   118,   119,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   144,   145,   146,   147,   148,   149,   151,   152,
     153,   154,   155,   156,   158,   159,   160,   161,   162,   163,
     164,   165,   167,   168,   169,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   182,   184,   185,   186,   188,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     237,   239,   241,   242,   243,   244,   246,   247,   248,   249,
     250,   251,   255,   256,   258,   259,   260,   261,   263,   265,
     266,   267,   268,   269,   270,   271,   274,   275,   276,   277,
     278,   279,   282,   288,   289,   290,   291,   292,   293,   297,
     298,   300,   301,   303,   304,   305,   307,   308,   309,   310,
     311,   312,   314,   315,   319,   320,   321,   322,   323,   324,
     325,   329,   330,   331,   332,   335,   341,   342,   343,   344,
     345,   349,   351,   352,   353,   354,   355,   356,   357,   358,
     361,   363,   384,   406,   430,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   451,   452,   454,   455,   456,   457,   458,   459,   461,
     463,   464,   465,   469,   470,   471,   472,   473,   475,   476,
     477,   480,   481,   482,   483,   484,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   501,   505,   508,
     511,   512,   513,   514,   516,   517,   518,   519,   520,   521,
     522,   524,   525,   527,   212,   201,   236,    21,   201,   212,
     209,   219,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   212,    21,   211,   201,    21,
     209,   232,   203,   234,   227,   201,   201,   201,   206,   227,
     401,   227,   227,   227,   206,   230,   234,   201,   401,   201,
     401,   401,   227,   202,   201,   227,   401,   201,   201,   201,
     203,   202,   201,   201,   227,   206,   227,   367,   201,    44,
      46,    47,    64,   285,   286,   287,   306,   507,   234,   230,
     227,   201,   227,   401,   201,    73,   183,   252,   253,   254,
     203,   230,   227,   201,   227,   201,   201,   401,   230,   201,
     201,   201,   227,   252,   211,   227,   227,   401,   367,   201,
     227,   201,   201,   201,   201,    83,   200,   431,   432,   433,
     203,   201,   367,   367,   201,   211,   201,   201,   201,   252,
     230,   203,   401,   201,   201,   211,   201,   201,   367,   201,
     201,   211,   201,   431,   431,   401,   401,   206,   227,   377,
     377,   377,   377,   203,   201,   201,   209,   420,   201,   201,
     227,   211,   201,   401,   367,   227,   202,   201,   201,   201,
     367,   201,   201,   201,   201,   401,   401,   201,   201,   227,
     201,   367,   201,   227,   227,   401,   401,   211,   211,   211,
     203,   203,   201,   209,   426,   201,   201,   201,   227,   211,
     230,   201,   431,   201,   367,   201,   227,   201,   201,   201,
     227,   201,   201,   211,   201,   211,   236,   211,   211,    21,
     211,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,   211,
      21,    21,   211,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,   211,    21,    21,    21,    21,    21,    21,   211,    21,
      21,    21,   211,    21,    21,    21,   211,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,   211,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,   211,    21,
      21,    21,    21,   227,   450,   211,   211,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,   211,
      21,    21,    21,    21,    21,    21,   211,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,   227,   498,   211,
      21,   211,    21,    21,    21,    21,    21,    21,    21,    21,
     211,    21,    21,    21,    21,    21,   212,    21,   211,   212,
     201,   227,   227,   206,   227,   400,   202,   206,   334,   383,
     383,   383,   206,   252,   368,   227,   400,   227,   400,   400,
     383,   202,   209,   231,   383,   400,   227,   227,   202,   227,
     227,   383,   227,   209,   414,   252,   206,   227,   399,   368,
     383,   227,   383,   400,   227,     5,    42,    43,    97,   114,
     181,   240,   283,   284,   339,   360,   500,   506,   206,   227,
     388,   230,   201,   201,   231,   201,   400,   230,   227,   227,
     383,   500,   227,   400,   227,   227,   227,   227,   202,   202,
      35,    48,   294,   295,   296,   203,   227,   227,   227,   227,
     227,   201,   227,   230,    25,   170,   502,   503,   504,   230,
     400,   230,   203,   227,   227,   201,   227,   227,   294,   294,
     400,   400,   203,   203,   203,   203,   209,   411,   201,    21,
     211,   227,   227,   227,   400,   227,   203,   202,   227,   227,
     227,   227,   227,   367,   201,   400,   400,   227,   227,   227,
     227,   227,   383,   383,   400,   400,   227,   203,   227,    21,
     211,   227,   227,   383,   368,   206,   227,   387,   294,   227,
     227,   227,   388,   227,   227,   227,   209,   417,   233,   211,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,   234,   235,   211,    21,    21,    21,
      21,   211,    21,    21,    21,   211,   227,   280,    21,    21,
     211,    21,    21,    21,    21,    21,    21,    21,    21,    21,
     211,   211,   211,   211,    21,    21,    21,    21,    21,    21,
     211,    21,   211,    21,    21,    21,   211,   211,    21,    21,
      21,    21,   211,   211,    21,    21,    21,    21,    21,    21,
      21,   211,    21,    21,    21,   211,    21,   211,    21,    21,
      21,    21,    21,   211,    21,    21,   227,   264,   211,   211,
     227,    21,   211,    21,    21,    21,    21,   211,    21,    21,
      21,   211,    21,    21,   211,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,   211,   211,    21,   227,
      21,    21,    21,    21,   211,    21,    21,    21,   211,    21,
      21,    21,    21,   211,   227,   313,    21,    21,   227,   227,
     201,    96,   150,   206,   326,   327,   328,   381,   381,   381,
     377,   203,   201,   209,   418,   201,   201,   381,   202,    21,
     211,   381,   201,   418,   203,   418,   418,   381,    21,   211,
     187,   253,   254,   346,   347,   227,    26,    57,   466,   467,
     468,   381,   418,   381,   201,   418,   142,   206,   234,   402,
     479,   499,   206,   227,   375,   230,   201,   230,   418,   203,
     381,   402,   201,   418,   203,   203,   227,    90,   157,   206,
     316,   317,   318,   379,   227,   227,   227,   209,   421,   209,
     416,   368,   230,   230,   201,   201,   203,   203,   418,   227,
     227,   201,   201,   203,   203,   202,    21,   211,   209,   428,
     401,   201,   227,   202,   418,   418,   203,   418,   227,   201,
     201,   418,   418,   203,   227,   418,   381,   381,   201,   201,
     418,   401,   209,   427,   381,   377,   227,   203,   203,   230,
     401,   401,   116,   206,   362,   390,    21,   211,   206,   227,
     372,   233,   211,    21,    21,    21,    21,    21,    21,    21,
      21,   211,   227,   350,    21,    21,    21,    21,   211,   234,
      21,    21,    21,   211,    21,    21,    21,   227,   211,   211,
      21,    21,    21,    21,    21,    21,    21,    21,   211,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
     211,   211,   211,    21,   211,   227,   453,   211,   227,   299,
      21,    21,    21,    21,    21,   211,   211,   211,    21,    21,
      21,    21,    21,   211,   211,   211,   227,   211,   227,   523,
      21,    21,    21,   211,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,   211,    21,    21,    21,    21,    21,
      21,    21,    21,   227,   510,    21,    21,    21,    21,   211,
      21,    21,    21,    21,   209,    21,   227,    21,    21,   377,
     230,   368,   368,   368,    96,   150,   206,   336,   337,   338,
     385,   203,   230,    21,   211,   227,   230,   230,   368,   368,
     230,   227,   227,   227,   368,   206,   294,   374,   368,   227,
     368,   230,   227,   206,   227,   398,   230,   230,   230,   227,
     203,   368,   398,   230,   227,   203,   203,   230,   227,    21,
     211,    21,   211,   230,   252,   230,   230,   230,   227,   230,
     230,   230,   230,    21,   211,   206,   227,   392,   400,   230,
     202,   227,   367,   203,   227,   209,   429,   230,   230,   227,
     227,   203,   227,   368,   368,   230,   230,   227,   400,    21,
     211,   427,   368,   374,   230,   203,   206,   227,   405,   400,
     400,   209,   419,   206,   227,   394,   206,   227,   395,   201,
     211,    21,    21,    21,    21,    21,    21,    21,   227,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,   211,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
     211,    21,    21,    21,    21,   211,   211,    21,    21,   227,
     227,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,   227,    21,   211,    21,   211,    21,    21,   211,    21,
     211,   227,   526,   211,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,   227,    21,    21,   211,
      21,   211,    21,    21,    21,   227,   359,    21,    21,    21,
      21,   206,   227,   371,   230,   230,   230,    60,    98,   104,
     166,   206,   302,   340,   348,   396,   485,   486,   203,   371,
     227,   371,   371,   230,   230,   371,   227,   227,   227,   230,
     230,   209,   415,   230,   371,   415,   206,   227,   386,   206,
     227,   389,   371,   230,   227,   230,   386,   371,   227,   227,
      94,   206,   333,   382,   377,   230,   230,   230,   371,   227,
     227,   227,   371,   371,   206,   227,   376,   371,   227,   227,
     227,    21,   211,   371,   371,   227,   227,   227,   227,   230,
     230,   371,   371,   227,   227,   252,   230,   227,     3,   206,
     238,   364,   227,   227,    21,   211,   206,   391,   419,   209,
     424,   382,   201,    21,   211,    21,   211,   211,   211,    21,
      21,    21,    21,   211,   211,    21,    21,    21,    21,    21,
     211,   227,   281,   211,    21,    21,   211,    21,   211,    21,
      21,    21,   211,    21,    21,    21,   211,   209,   211,    21,
      21,    21,    21,    21,    21,   211,   211,    21,    21,    21,
      21,   227,    21,    21,   227,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,   211,    21,    21,   211,    21,
     209,    21,    21,    21,   227,   211,   211,   227,   474,   211,
     211,    21,   227,   230,   227,   227,   227,   227,   227,   203,
     203,   209,   409,   230,    21,   211,   230,   227,   368,   227,
     230,   227,   203,   227,   209,   408,   364,   230,   232,   252,
     230,   227,   227,   227,   227,   206,   227,   366,   227,    21,
     227,   227,   227,   227,   227,   227,   203,   227,   230,   230,
     227,   227,   227,    23,   120,   189,   262,   407,   509,   515,
     227,   211,   206,   227,   370,   227,   227,    21,   211,   201,
      21,   211,    21,    21,    21,    21,    21,    21,    21,   211,
     227,   257,    21,   211,   227,   211,    21,    21,    21,   211,
      21,   211,    21,   227,   245,   211,    21,   211,    21,    21,
      21,    21,    21,    21,    21,   211,    21,   227,    21,    21,
      21,    21,    21,    21,   211,    21,   211,   211,    21,    21,
      21,   211,   211,    21,    21,    21,   227,   211,   227,   227,
     230,   227,   227,   227,   227,   202,    21,   211,   230,   227,
     227,   227,   399,   227,    21,   211,   364,   252,   252,   230,
     227,   227,   227,   227,   227,    21,   227,   206,   227,   397,
     227,   227,   227,   227,   206,   227,   404,   227,   227,   203,
     209,   410,   227,   227,   212,    21,    21,   211,    21,    21,
      21,   211,    21,   227,    21,    21,    21,    21,    21,    21,
     227,    21,    21,    21,   211,    21,    21,    21,    21,    21,
     383,   211,    21,    21,    21,    21,   211,    21,    21,    21,
      21,   211,   264,   211,    21,    21,   227,   227,   227,   227,
     227,   209,   412,   227,   227,   206,   227,   369,   227,   399,
     227,   364,   377,   252,   227,   206,   227,   373,   227,   227,
     227,    21,   227,   227,   227,   209,   425,   409,   227,   227,
     227,   211,   227,   227,    21,    21,    21,    21,    21,   211,
     227,   272,    21,    21,    21,    21,    21,   211,    21,   211,
      21,    21,    21,    21,    21,    21,    21,   202,   211,    21,
      21,   211,   227,   478,   211,   211,    21,    21,   211,    21,
      21,   230,   230,   230,   230,   230,    21,   211,   209,   413,
     399,   230,   369,   230,   230,   206,   227,   393,   368,   230,
     409,   230,   230,   230,    21,   230,   230,    21,   211,   230,
     230,   362,   227,    21,    21,    21,    21,    21,   227,   211,
     227,   273,    21,    21,    21,   211,    21,    21,    21,   211,
      21,   211,    21,    21,    21,   399,    21,    21,   227,    21,
      21,   211,    21,   230,   230,   206,   227,   365,   365,   230,
      21,   211,   399,   399,   230,   230,   365,   421,   230,   365,
     365,   230,    21,   365,   365,   230,   230,   227,    21,    21,
      21,    21,    21,   227,    21,    21,    21,    21,    21,   211,
      21,    21,    21,    21,   377,    21,    21,    21,    21,   211,
     230,   230,   365,   365,   230,   203,   227,   230,   230,   365,
     230,   365,   365,   230,    21,   365,   365,   230,   230,    21,
      21,    21,    21,    21,   211,   211,    21,    21,    21,    21,
      21,    21,    21,   209,   422,    21,    21,    21,    21,   230,
     230,   206,   227,   403,   403,   230,   230,   230,   206,   227,
     380,   230,   403,   403,   230,   211,   227,   460,    21,   403,
     403,   230,   230,    21,    21,    21,    21,    21,    21,    21,
     211,    21,    21,    21,    21,    21,   211,   209,   423,    21,
      21,    21,    21,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   227,   211,   227,   462,   211,   230,
     230,   230,   230,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,   211,    21,    21,    21,    21,
     206,   227,   378,   378,   230,   230,   378,   378,   378,   378,
     230,   230,   378,   227,   230,   230,   378,   378,   211,    21,
      21,    21,   211,   211,   211,    21,   211,   211,    21,    21,
      21,   252,   252,   252,   230,   230,   203,   252,   230,   230,
     211,   211,    21,    21,    21,    21,    21,   211,   211,   230,
     230,   230,   203,   230,    21,   211,   211,    21,    21,   371,
     203,   371,   211,    21,   211,   230,   211
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { (yyval.val1) = new inputFile((yyvsp[(1) - (4)].val9), (yyvsp[(2) - (4)].val10), (yyvsp[(3) - (4)].val2), (yyvsp[(4) - (4)].val6));
	      tree = (yyval.val1); ;}
    break;

  case 3:

    { (yyval.val2) = new dataSection((yyvsp[(1) - (3)].val3), (yyvsp[(2) - (3)].val13), (yyvsp[(3) - (3)].val4)); ;}
    break;

  case 4:

    { (yyval.val3) = new dataStarter(); ;}
    break;

  case 5:

    { (yyval.val4) = new endSection(); ;}
    break;

  case 6:

    { (yyval.val5) = new fileDescription((yyvsp[(3) - (7)].val16), (yyvsp[(5) - (7)].sval)); ;}
    break;

  case 7:

    {
	    numErrors++;
	    yyerrok;
	  ;}
    break;

  case 8:

    { (yyval.val6) = new fileEnd(); ;}
    break;

  case 9:

    {
	    numErrors++;
	    yyerrok;
	  ;}
    break;

  case 10:

    { (yyval.val7) = new fileName((yyvsp[(3) - (17)].sval), (yyvsp[(5) - (17)].sval), (yyvsp[(7) - (17)].val16), (yyvsp[(9) - (17)].val16), (yyvsp[(11) - (17)].sval), (yyvsp[(13) - (17)].sval), (yyvsp[(15) - (17)].sval)); ;}
    break;

  case 11:

    {
	    numErrors++;
	    yyerrok;
	  ;}
    break;

  case 12:

    { (yyval.val8) = new fileSchema((yyvsp[(3) - (5)].val15)); ;}
    break;

  case 13:

    {
	    numErrors++;
	    yyerrok;
	  ;}
    break;

  case 14:

    { (yyval.val9) = new fileStart(); ;}
    break;

  case 15:

    {
	    numErrors++;
	    yyerrok;
	  ;}
    break;

  case 16:

    { (yyval.val10) = new headerSection((yyvsp[(1) - (5)].val11), (yyvsp[(2) - (5)].val5), (yyvsp[(3) - (5)].val7), (yyvsp[(4) - (5)].val8), (yyvsp[(5) - (5)].val4)); ;}
    break;

  case 17:

    { (yyval.val11) = new headerStarter(); ;}
    break;

  case 18:

    { (yyval.val12) = new instanceId((yyvsp[(2) - (2)].ival)); ;}
    break;

  case 19:

    { (yyval.val13) = new std::list<instance *>;
	      (yyval.val13)->push_back((yyvsp[(1) - (1)].val20)); ;}
    break;

  case 20:

    { (yyval.val13) = (yyvsp[(1) - (2)].val13);
	      (yyval.val13)->push_back((yyvsp[(2) - (2)].val20)); ;}
    break;

  case 21:

    { int n;
	      (yyval.val20) = (yyvsp[(3) - (4)].val20);
	      (yyvsp[(3) - (4)].val20)->set_id((yyvsp[(1) - (4)].val12));
	      n = (yyvsp[(1) - (4)].val12)->get_val();
	      if (n < INSTANCEMAX)
		{
		  if (instances[n])
		    {
		      fprintf(report, "instance id %d reused\n", n);
		      numErrors++;
		    }
		  else
		    instances[n] = (yyval.val20);
		}
	      else
		{
		  fprintf(report, "instance id %d is too large\n", n);
		  numErrors++;
		}
	    ;}
    break;

  case 22:

    {
	    numErrors++;
	    yyerrok;
	  ;}
    break;

  case 23:

    { (yyval.val17) = (yyvsp[(1) - (1)].val17) ;}
    break;

  case 24:

    { (yyval.val17) = 0; ;}
    break;

  case 25:

    { (yyval.val14) = new parenRealListFull((yyvsp[(2) - (3)].val18)); ;}
    break;

  case 26:

    { (yyval.val15) = new parenStringList((yyvsp[(2) - (3)].val19)); ;}
    break;

  case 27:

    { (yyval.val15) = new parenStringList(new std::list<char *>); ;}
    break;

  case 28:

    { (yyval.val16) = new parenStringListFull((yyvsp[(2) - (3)].val19)); ;}
    break;

  case 29:

    { (yyval.val17) = new real((yyvsp[(1) - (1)].rval)); ;}
    break;

  case 30:

    { (yyval.val18) = new std::list<real *>;
	      (yyval.val18)->push_back((yyvsp[(1) - (1)].val17)); ;}
    break;

  case 31:

    { (yyval.val18) = (yyvsp[(1) - (3)].val18);
	      (yyval.val18)->push_back((yyvsp[(3) - (3)].val17)); ;}
    break;

  case 32:

    { (yyval.val19) = new std::list<char *>;
	      (yyval.val19)->push_back((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 33:

    { (yyval.val19) = (yyvsp[(1) - (3)].val19);
	      (yyval.val19)->push_back((yyvsp[(3) - (3)].sval)); ;}
    break;

  case 34:

    { (yyval.val20) = (yyvsp[(1) - (1)].val22); ;}
    break;

  case 35:

    { (yyval.val20) = (yyvsp[(1) - (1)].val24); ;}
    break;

  case 36:

    { (yyval.val20) = (yyvsp[(1) - (1)].val25); ;}
    break;

  case 37:

    { (yyval.val20) = (yyvsp[(1) - (1)].val26); ;}
    break;

  case 38:

    { (yyval.val20) = (yyvsp[(1) - (1)].val27); ;}
    break;

  case 39:

    { (yyval.val20) = (yyvsp[(1) - (1)].val29); ;}
    break;

  case 40:

    { (yyval.val20) = (yyvsp[(1) - (1)].val30); ;}
    break;

  case 41:

    { (yyval.val20) = (yyvsp[(1) - (1)].val31); ;}
    break;

  case 42:

    { (yyval.val20) = (yyvsp[(1) - (1)].val32); ;}
    break;

  case 43:

    { (yyval.val20) = (yyvsp[(1) - (1)].val33); ;}
    break;

  case 44:

    { (yyval.val20) = (yyvsp[(1) - (1)].val34); ;}
    break;

  case 45:

    { (yyval.val20) = (yyvsp[(1) - (1)].val38); ;}
    break;

  case 46:

    { (yyval.val20) = (yyvsp[(1) - (1)].val39); ;}
    break;

  case 47:

    { (yyval.val20) = (yyvsp[(1) - (1)].val41); ;}
    break;

  case 48:

    { (yyval.val20) = (yyvsp[(1) - (1)].val42); ;}
    break;

  case 49:

    { (yyval.val20) = (yyvsp[(1) - (1)].val43); ;}
    break;

  case 50:

    { (yyval.val20) = (yyvsp[(1) - (1)].val44); ;}
    break;

  case 51:

    { (yyval.val20) = (yyvsp[(1) - (1)].val46); ;}
    break;

  case 52:

    { (yyval.val20) = (yyvsp[(1) - (1)].val48); ;}
    break;

  case 53:

    { (yyval.val20) = (yyvsp[(1) - (1)].val49); ;}
    break;

  case 54:

    { (yyval.val20) = (yyvsp[(1) - (1)].val50); ;}
    break;

  case 55:

    { (yyval.val20) = (yyvsp[(1) - (1)].val51); ;}
    break;

  case 56:

    { (yyval.val20) = (yyvsp[(1) - (1)].val52); ;}
    break;

  case 57:

    { (yyval.val20) = (yyvsp[(1) - (1)].val53); ;}
    break;

  case 58:

    { (yyval.val20) = (yyvsp[(1) - (1)].val54); ;}
    break;

  case 59:

    { (yyval.val20) = (yyvsp[(1) - (1)].val57); ;}
    break;

  case 60:

    { (yyval.val20) = (yyvsp[(1) - (1)].val58); ;}
    break;

  case 61:

    { (yyval.val20) = (yyvsp[(1) - (1)].val59); ;}
    break;

  case 62:

    { (yyval.val20) = (yyvsp[(1) - (1)].val60); ;}
    break;

  case 63:

    { (yyval.val20) = (yyvsp[(1) - (1)].val61); ;}
    break;

  case 64:

    { (yyval.val20) = (yyvsp[(1) - (1)].val62); ;}
    break;

  case 65:

    { (yyval.val20) = (yyvsp[(1) - (1)].val65); ;}
    break;

  case 66:

    { (yyval.val20) = (yyvsp[(1) - (1)].val71); ;}
    break;

  case 67:

    { (yyval.val20) = (yyvsp[(1) - (1)].val72); ;}
    break;

  case 68:

    { (yyval.val20) = (yyvsp[(1) - (1)].val73); ;}
    break;

  case 69:

    { (yyval.val20) = (yyvsp[(1) - (1)].val74); ;}
    break;

  case 70:

    { (yyval.val20) = (yyvsp[(1) - (1)].val75); ;}
    break;

  case 71:

    { (yyval.val20) = (yyvsp[(1) - (1)].val76); ;}
    break;

  case 72:

    { (yyval.val20) = (yyvsp[(1) - (1)].val80); ;}
    break;

  case 73:

    { (yyval.val20) = (yyvsp[(1) - (1)].val81); ;}
    break;

  case 74:

    { (yyval.val20) = (yyvsp[(1) - (1)].val83); ;}
    break;

  case 75:

    { (yyval.val20) = (yyvsp[(1) - (1)].val84); ;}
    break;

  case 76:

    { (yyval.val20) = (yyvsp[(1) - (1)].val86); ;}
    break;

  case 77:

    { (yyval.val20) = (yyvsp[(1) - (1)].val87); ;}
    break;

  case 78:

    { (yyval.val20) = (yyvsp[(1) - (1)].val90); ;}
    break;

  case 79:

    { (yyval.val20) = (yyvsp[(1) - (1)].val91); ;}
    break;

  case 80:

    { (yyval.val20) = (yyvsp[(1) - (1)].val92); ;}
    break;

  case 81:

    { (yyval.val20) = (yyvsp[(1) - (1)].val88); ;}
    break;

  case 82:

    { (yyval.val20) = (yyvsp[(1) - (1)].val93); ;}
    break;

  case 83:

    { (yyval.val20) = (yyvsp[(1) - (1)].val94); ;}
    break;

  case 84:

    { (yyval.val20) = (yyvsp[(1) - (1)].val95); ;}
    break;

  case 85:

    { (yyval.val20) = (yyvsp[(1) - (1)].val98); ;}
    break;

  case 86:

    { (yyval.val20) = (yyvsp[(1) - (1)].val97); ;}
    break;

  case 87:

    { (yyval.val20) = (yyvsp[(1) - (1)].val102); ;}
    break;

  case 88:

    { (yyval.val20) = (yyvsp[(1) - (1)].val103); ;}
    break;

  case 89:

    { (yyval.val20) = (yyvsp[(1) - (1)].val104); ;}
    break;

  case 90:

    { (yyval.val20) = (yyvsp[(1) - (1)].val105); ;}
    break;

  case 91:

    { (yyval.val20) = (yyvsp[(1) - (1)].val106); ;}
    break;

  case 92:

    { (yyval.val20) = (yyvsp[(1) - (1)].val107); ;}
    break;

  case 93:

    { (yyval.val20) = (yyvsp[(1) - (1)].val108); ;}
    break;

  case 94:

    { (yyval.val20) = (yyvsp[(1) - (1)].val112); ;}
    break;

  case 95:

    { (yyval.val20) = (yyvsp[(1) - (1)].val113); ;}
    break;

  case 96:

    { (yyval.val20) = (yyvsp[(1) - (1)].val114); ;}
    break;

  case 97:

    { (yyval.val20) = (yyvsp[(1) - (1)].val115); ;}
    break;

  case 98:

    { (yyval.val20) = (yyvsp[(1) - (1)].val118); ;}
    break;

  case 99:

    { (yyval.val20) = (yyvsp[(1) - (1)].val124); ;}
    break;

  case 100:

    { (yyval.val20) = (yyvsp[(1) - (1)].val125); ;}
    break;

  case 101:

    { (yyval.val20) = (yyvsp[(1) - (1)].val126); ;}
    break;

  case 102:

    { (yyval.val20) = (yyvsp[(1) - (1)].val127); ;}
    break;

  case 103:

    { (yyval.val20) = (yyvsp[(1) - (1)].val128); ;}
    break;

  case 104:

    { (yyval.val20) = (yyvsp[(1) - (1)].val132); ;}
    break;

  case 105:

    { (yyval.val20) = (yyvsp[(1) - (1)].val134); ;}
    break;

  case 106:

    { (yyval.val20) = (yyvsp[(1) - (1)].val135); ;}
    break;

  case 107:

    { (yyval.val20) = (yyvsp[(1) - (1)].val136); ;}
    break;

  case 108:

    { (yyval.val20) = (yyvsp[(1) - (1)].val137); ;}
    break;

  case 109:

    { (yyval.val20) = (yyvsp[(1) - (1)].val138); ;}
    break;

  case 110:

    { (yyval.val20) = (yyvsp[(1) - (1)].val139); ;}
    break;

  case 111:

    { (yyval.val20) = (yyvsp[(1) - (1)].val140); ;}
    break;

  case 112:

    { (yyval.val20) = (yyvsp[(1) - (1)].val141); ;}
    break;

  case 113:

    { (yyval.val20) = (yyvsp[(1) - (1)].val144); ;}
    break;

  case 114:

    { (yyval.val20) = (yyvsp[(1) - (1)].val146); ;}
    break;

  case 115:

    { (yyval.val20) = (yyvsp[(1) - (1)].val147); ;}
    break;

  case 116:

    { (yyval.val20) = (yyvsp[(1) - (1)].val148); ;}
    break;

  case 117:

    { (yyval.val20) = (yyvsp[(1) - (1)].val172); ;}
    break;

  case 118:

    { (yyval.val20) = (yyvsp[(1) - (1)].val176); ;}
    break;

  case 119:

    { (yyval.val20) = (yyvsp[(1) - (1)].val177); ;}
    break;

  case 120:

    { (yyval.val20) = (yyvsp[(1) - (1)].val178); ;}
    break;

  case 121:

    { (yyval.val20) = (yyvsp[(1) - (1)].val179); ;}
    break;

  case 122:

    { (yyval.val20) = (yyvsp[(1) - (1)].val180); ;}
    break;

  case 123:

    { (yyval.val20) = (yyvsp[(1) - (1)].val181); ;}
    break;

  case 124:

    { (yyval.val20) = (yyvsp[(1) - (1)].val182); ;}
    break;

  case 125:

    { (yyval.val20) = (yyvsp[(1) - (1)].val183); ;}
    break;

  case 126:

    { (yyval.val20) = (yyvsp[(1) - (1)].val184); ;}
    break;

  case 127:

    { (yyval.val20) = (yyvsp[(1) - (1)].val185); ;}
    break;

  case 128:

    { (yyval.val20) = (yyvsp[(1) - (1)].val186); ;}
    break;

  case 129:

    { (yyval.val20) = (yyvsp[(1) - (1)].val187); ;}
    break;

  case 130:

    { (yyval.val20) = (yyvsp[(1) - (1)].val188); ;}
    break;

  case 131:

    { (yyval.val20) = (yyvsp[(1) - (1)].val189); ;}
    break;

  case 132:

    { (yyval.val20) = (yyvsp[(1) - (1)].val190); ;}
    break;

  case 133:

    { (yyval.val20) = (yyvsp[(1) - (1)].val191); ;}
    break;

  case 134:

    { (yyval.val20) = (yyvsp[(1) - (1)].val193); ;}
    break;

  case 135:

    { (yyval.val20) = (yyvsp[(1) - (1)].val194); ;}
    break;

  case 136:

    { (yyval.val20) = (yyvsp[(1) - (1)].val196); ;}
    break;

  case 137:

    { (yyval.val20) = (yyvsp[(1) - (1)].val197); ;}
    break;

  case 138:

    { (yyval.val20) = (yyvsp[(1) - (1)].val198); ;}
    break;

  case 139:

    { (yyval.val20) = (yyvsp[(1) - (1)].val199); ;}
    break;

  case 140:

    { (yyval.val20) = (yyvsp[(1) - (1)].val200); ;}
    break;

  case 141:

    { (yyval.val20) = (yyvsp[(1) - (1)].val205); ;}
    break;

  case 142:

    { (yyval.val20) = (yyvsp[(1) - (1)].val201); ;}
    break;

  case 143:

    { (yyval.val20) = (yyvsp[(1) - (1)].val203); ;}
    break;

  case 144:

    { (yyval.val20) = (yyvsp[(1) - (1)].val206); ;}
    break;

  case 145:

    { (yyval.val20) = (yyvsp[(1) - (1)].val207); ;}
    break;

  case 146:

    { (yyval.val20) = (yyvsp[(1) - (1)].val211); ;}
    break;

  case 147:

    { (yyval.val20) = (yyvsp[(1) - (1)].val212); ;}
    break;

  case 148:

    { (yyval.val20) = (yyvsp[(1) - (1)].val213); ;}
    break;

  case 149:

    { (yyval.val20) = (yyvsp[(1) - (1)].val214); ;}
    break;

  case 150:

    { (yyval.val20) = (yyvsp[(1) - (1)].val215); ;}
    break;

  case 151:

    { (yyval.val20) = (yyvsp[(1) - (1)].val217); ;}
    break;

  case 152:

    { (yyval.val20) = (yyvsp[(1) - (1)].val218); ;}
    break;

  case 153:

    { (yyval.val20) = (yyvsp[(1) - (1)].val219); ;}
    break;

  case 154:

    { (yyval.val20) = (yyvsp[(1) - (1)].val222); ;}
    break;

  case 155:

    { (yyval.val20) = (yyvsp[(1) - (1)].val223); ;}
    break;

  case 156:

    { (yyval.val20) = (yyvsp[(1) - (1)].val224); ;}
    break;

  case 157:

    { (yyval.val20) = (yyvsp[(1) - (1)].val225); ;}
    break;

  case 158:

    { (yyval.val20) = (yyvsp[(1) - (1)].val226); ;}
    break;

  case 159:

    { (yyval.val20) = (yyvsp[(1) - (1)].val229); ;}
    break;

  case 160:

    { (yyval.val20) = (yyvsp[(1) - (1)].val230); ;}
    break;

  case 161:

    { (yyval.val20) = (yyvsp[(1) - (1)].val231); ;}
    break;

  case 162:

    { (yyval.val20) = (yyvsp[(1) - (1)].val232); ;}
    break;

  case 163:

    { (yyval.val20) = (yyvsp[(1) - (1)].val233); ;}
    break;

  case 164:

    { (yyval.val20) = (yyvsp[(1) - (1)].val234); ;}
    break;

  case 165:

    { (yyval.val20) = (yyvsp[(1) - (1)].val235); ;}
    break;

  case 166:

    { (yyval.val20) = (yyvsp[(1) - (1)].val236); ;}
    break;

  case 167:

    { (yyval.val20) = (yyvsp[(1) - (1)].val237); ;}
    break;

  case 168:

    { (yyval.val20) = (yyvsp[(1) - (1)].val238); ;}
    break;

  case 169:

    { (yyval.val20) = (yyvsp[(1) - (1)].val239); ;}
    break;

  case 170:

    { (yyval.val20) = (yyvsp[(1) - (1)].val243); ;}
    break;

  case 171:

    { (yyval.val20) = (yyvsp[(1) - (1)].val247); ;}
    break;

  case 172:

    { (yyval.val20) = (yyvsp[(1) - (1)].val250); ;}
    break;

  case 173:

    { (yyval.val20) = (yyvsp[(1) - (1)].val253); ;}
    break;

  case 174:

    { (yyval.val20) = (yyvsp[(1) - (1)].val254); ;}
    break;

  case 175:

    { (yyval.val20) = (yyvsp[(1) - (1)].val255); ;}
    break;

  case 176:

    { (yyval.val20) = (yyvsp[(1) - (1)].val256); ;}
    break;

  case 177:

    { (yyval.val20) = (yyvsp[(1) - (1)].val258); ;}
    break;

  case 178:

    { (yyval.val20) = (yyvsp[(1) - (1)].val259); ;}
    break;

  case 179:

    { (yyval.val20) = (yyvsp[(1) - (1)].val260); ;}
    break;

  case 180:

    { (yyval.val20) = (yyvsp[(1) - (1)].val261); ;}
    break;

  case 181:

    { (yyval.val20) = (yyvsp[(1) - (1)].val262); ;}
    break;

  case 182:

    { (yyval.val20) = (yyvsp[(1) - (1)].val263); ;}
    break;

  case 183:

    { (yyval.val20) = (yyvsp[(1) - (1)].val264); ;}
    break;

  case 184:

    { (yyval.val20) = (yyvsp[(1) - (1)].val266); ;}
    break;

  case 185:

    { (yyval.val20) = (yyvsp[(1) - (1)].val267); ;}
    break;

  case 186:

    { (yyval.val20) = (yyvsp[(1) - (1)].val269); ;}
    break;

  case 187:

    { (yyval.val21) = new advancedBrepShapeRepresentation(); ;}
    break;

  case 188:

    { (yyval.val22) = new angleTaper((yyvsp[(3) - (4)].val17)); ;}
    break;

  case 189:

    { (yyval.val23) = new approach(); ;}
    break;

  case 190:

    { (yyval.val24) = new approval(0, (yyvsp[(5) - (6)].sval));
	      approvalStatus_refs.push_back(&((yyval.val24)->status));
	      approvalStatus_nums.push_back((yyvsp[(3) - (6)].val12)->get_val());
	      delete (yyvsp[(3) - (6)].val12);
	    ;}
    break;

  case 191:

    { (yyval.val25) = new approvalStatus((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 192:

    { (yyval.val26) = new axis1placement((yyvsp[(3) - (8)].sval), 0, 0);
	      cartesianPoint_refs.push_back(&((yyval.val26)->location));
	      cartesianPoint_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	      direction_refs.push_back(&((yyval.val26)->axis));
	      direction_nums.push_back((yyvsp[(7) - (8)].val12)->get_val());
	      delete (yyvsp[(7) - (8)].val12);
	    ;}
    break;

  case 193:

    { (yyval.val27) = new axis2placement3d((yyvsp[(3) - (10)].sval), 0, 0, (yyvsp[(9) - (10)].val88));
	      cartesianPoint_refs.push_back(&((yyval.val27)->location));
	      cartesianPoint_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	      direction_refs.push_back(&((yyval.val27)->axis));
	      direction_nums.push_back((yyvsp[(7) - (10)].val12)->get_val());
	      delete (yyvsp[(7) - (10)].val12);
	      if ((yyvsp[(9) - (10)].val88))
		{
		  (yyval.val27)->set_refDirection(0);
		  direction_refs.push_back(&((yyval.val27)->refDirection));
		  direction_nums.push_back((yyvsp[(9) - (10)].val88)->get_id()->get_val());
		  delete (yyvsp[(9) - (10)].val88)->get_id();
		  delete (yyvsp[(9) - (10)].val88);
		}
	    ;}
    break;

  case 194:

    { (yyval.val28) = new std::list<axis2placement3d *>;
	      (yyval.val28)->push_back(0);
	      axis2placement3d_refs.push_back(&((yyval.val28)->back()));
	      axis2placement3d_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 195:

    { (yyval.val28) = (yyvsp[(1) - (3)].val28);
	      (yyval.val28)->push_back(0);
	      axis2placement3d_refs.push_back(&((yyval.val28)->back()));
	      axis2placement3d_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 196:

    { (yyval.val29) = new backBoring((yyvsp[(3) - (30)].val239), (yyvsp[(5) - (30)].val233), (yyvsp[(7) - (30)].sval), (yyvsp[(9) - (30)].val17), (yyvsp[(11) - (30)].val46), 0, 0, 0, (yyvsp[(19) - (30)].val17), (yyvsp[(21) - (30)].val17), (yyvsp[(23) - (30)].val17), (yyvsp[(25) - (30)].val17), (yyvsp[(27) - (30)].val17), (yyvsp[(29) - (30)].val92));
	      if ((yyvsp[(3) - (30)].val239))
		{
		  (yyval.val29)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val29)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (30)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (30)].val239)->get_id();
		  delete (yyvsp[(3) - (30)].val239);
		}
	      if ((yyvsp[(5) - (30)].val233))
		{
		  (yyval.val29)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val29)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (30)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (30)].val233)->get_id();
		  delete (yyvsp[(5) - (30)].val233);
		}
	      if ((yyvsp[(11) - (30)].val46))
		{
		  (yyval.val29)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val29)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (30)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (30)].val46)->get_id();
		  delete (yyvsp[(11) - (30)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val29)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (30)].val12)->get_val());
	      delete (yyvsp[(13) - (30)].val12);
	      technology_refs.push_back(&((yyval.val29)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (30)].val12)->get_val());
	      delete (yyvsp[(15) - (30)].val12);
	      machineFunctions_refs.push_back(&((yyval.val29)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (30)].val12)->get_val());
	      delete (yyvsp[(17) - (30)].val12);
	      if ((yyvsp[(29) - (30)].val92))
		{
		  (yyval.val29)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val29)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (30)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (30)].val92)->get_id();
		  delete (yyvsp[(29) - (30)].val92);
		}
	    ;}
    break;

  case 197:

    { (yyval.val30) = new backsideCounterbore(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val30)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 198:

    { (yyval.val31) = new backsideCountersink(0, (yyvsp[(5) - (14)].val117), (yyvsp[(7) - (14)].val109), (yyvsp[(9) - (14)].val35), (yyvsp[(11) - (14)].val17), (yyvsp[(13) - (14)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val31)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (14)].val12)->get_val());
	      delete (yyvsp[(3) - (14)].val12);
	    ;}
    break;

  case 199:

    { (yyval.val32) = new ballEndmill(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val32)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 200:

    { (yyval.val33) = new bidirectionalMilling((yyvsp[(3) - (12)].val17), (yyvsp[(5) - (12)].val35), (yyvsp[(7) - (12)].val88), (yyvsp[(9) - (12)].val119), (yyvsp[(11) - (12)].val228));
	      if ((yyvsp[(7) - (12)].val88))
		{
		  (yyval.val33)->set_feedDirection(0);
		  direction_refs.push_back(&((yyval.val33)->feedDirection));
		  direction_nums.push_back((yyvsp[(7) - (12)].val88)->get_id()->get_val());
		  delete (yyvsp[(7) - (12)].val88)->get_id();
		  delete (yyvsp[(7) - (12)].val88);
		}
	    ;}
    break;

  case 201:

    { (yyval.val34) = new block((yyvsp[(3) - (12)].sval), 0, (yyvsp[(7) - (12)].rval), (yyvsp[(9) - (12)].rval), (yyvsp[(11) - (12)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val34)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (12)].val12)->get_val());
	      delete (yyvsp[(5) - (12)].val12);
	    ;}
    break;

  case 202:

    { (yyval.val35) = (yyvsp[(1) - (1)].val36); ;}
    break;

  case 203:

    { (yyval.val35) = (yyvsp[(1) - (1)].val37); ;}
    break;

  case 204:

    { (yyval.val36) = new booleanTrue(); ;}
    break;

  case 205:

    { (yyval.val37) = new booleanFalse(); ;}
    break;

  case 206:

    { (yyval.val38) = new boring((yyvsp[(3) - (36)].val239), (yyvsp[(5) - (36)].val233), (yyvsp[(7) - (36)].sval), (yyvsp[(9) - (36)].val17), (yyvsp[(11) - (36)].val46), 0, 0, 0, (yyvsp[(19) - (36)].val17), (yyvsp[(21) - (36)].val17), (yyvsp[(23) - (36)].val17), (yyvsp[(25) - (36)].val17), (yyvsp[(27) - (36)].val17), (yyvsp[(29) - (36)].val92), (yyvsp[(31) - (36)].val35), (yyvsp[(33) - (36)].val17), (yyvsp[(35) - (36)].val46));
	      if ((yyvsp[(3) - (36)].val239))
		{
		  (yyval.val38)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val38)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (36)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (36)].val239)->get_id();
		  delete (yyvsp[(3) - (36)].val239);
		}
	      if ((yyvsp[(5) - (36)].val233))
		{
		  (yyval.val38)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val38)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (36)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (36)].val233)->get_id();
		  delete (yyvsp[(5) - (36)].val233);
		}
	      if ((yyvsp[(11) - (36)].val46))
		{
		  (yyval.val38)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val38)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (36)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (36)].val46)->get_id();
		  delete (yyvsp[(11) - (36)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val38)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (36)].val12)->get_val());
	      delete (yyvsp[(13) - (36)].val12);
	      technology_refs.push_back(&((yyval.val38)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (36)].val12)->get_val());
	      delete (yyvsp[(15) - (36)].val12);
	      machineFunctions_refs.push_back(&((yyval.val38)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (36)].val12)->get_val());
	      delete (yyvsp[(17) - (36)].val12);
	      if ((yyvsp[(29) - (36)].val92))
		{
		  (yyval.val38)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val38)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (36)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (36)].val92)->get_id();
		  delete (yyvsp[(29) - (36)].val92);
		}
	      if ((yyvsp[(35) - (36)].val46))
		{
		  (yyval.val38)->set_waitingPosition(0);
		  cartesianPoint_refs.push_back(&((yyval.val38)->waitingPosition));
		  cartesianPoint_nums.push_back((yyvsp[(35) - (36)].val46)->get_id()->get_val());
		  delete (yyvsp[(35) - (36)].val46)->get_id();
		  delete (yyvsp[(35) - (36)].val46);
		}
	    ;}
    break;

  case 207:

    { (yyval.val39) = new boss((yyvsp[(3) - (16)].sval), 0, (yyvsp[(7) - (16)].val160), 0, 0, 0, (yyvsp[(15) - (16)].val17));
	      workpiece_refs.push_back(&((yyval.val39)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (16)].val12)->get_val());
	      delete (yyvsp[(5) - (16)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val39)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (16)].val12)->get_val());
	      delete (yyvsp[(9) - (16)].val12);
	      elementarySurface_refs.push_back(&((yyval.val39)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (16)].val12)->get_val());
	      delete (yyvsp[(11) - (16)].val12);
	      closedProfile_refs.push_back(&((yyval.val39)->itsBoundary));
	      closedProfile_nums.push_back((yyvsp[(13) - (16)].val12)->get_val());
	      delete (yyvsp[(13) - (16)].val12);
	    ;}
    break;

  case 208:

    { (yyval.val40) = new std::list<boss *>;
	      (yyval.val40)->push_back(0);
	      boss_refs.push_back(&((yyval.val40)->back()));
	      boss_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 209:

    { (yyval.val40) = (yyvsp[(1) - (3)].val40);
	      (yyval.val40)->push_back(0);
	      boss_refs.push_back(&((yyval.val40)->back()));
	      boss_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 210:

    { (yyval.val41) = new bottomAndSideFinishMilling((yyvsp[(3) - (34)].val239), (yyvsp[(5) - (34)].val233), (yyvsp[(7) - (34)].sval), (yyvsp[(9) - (34)].val17), (yyvsp[(11) - (34)].val46), 0, 0, 0, (yyvsp[(19) - (34)].val17), (yyvsp[(21) - (34)].val184), (yyvsp[(23) - (34)].val184), (yyvsp[(25) - (34)].val33), (yyvsp[(27) - (34)].val17), (yyvsp[(29) - (34)].val17), (yyvsp[(31) - (34)].val17), (yyvsp[(33) - (34)].val17));
	      if ((yyvsp[(3) - (34)].val239))
		{
		  (yyval.val41)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val41)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (34)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (34)].val239)->get_id();
		  delete (yyvsp[(3) - (34)].val239);
		}
	      if ((yyvsp[(5) - (34)].val233))
		{
		  (yyval.val41)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val41)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (34)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (34)].val233)->get_id();
		  delete (yyvsp[(5) - (34)].val233);
		}
	      if ((yyvsp[(11) - (34)].val46))
		{
		  (yyval.val41)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val41)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (34)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (34)].val46)->get_id();
		  delete (yyvsp[(11) - (34)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val41)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (34)].val12)->get_val());
	      delete (yyvsp[(13) - (34)].val12);
	      technology_refs.push_back(&((yyval.val41)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (34)].val12)->get_val());
	      delete (yyvsp[(15) - (34)].val12);
	      machineFunctions_refs.push_back(&((yyval.val41)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (34)].val12)->get_val());
	      delete (yyvsp[(17) - (34)].val12);
	      if ((yyvsp[(21) - (34)].val184))
		{
		  (yyval.val41)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val41)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (34)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (34)].val184)->get_id();
		  delete (yyvsp[(21) - (34)].val184);
		}
	      if ((yyvsp[(23) - (34)].val184))
		{
		  (yyval.val41)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val41)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (34)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (34)].val184)->get_id();
		  delete (yyvsp[(23) - (34)].val184);
		}
	      if ((yyvsp[(25) - (34)].val33))
		{
		  (yyval.val41)->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&((yyval.val41)->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back((yyvsp[(25) - (34)].val33)->get_id()->get_val());
		  delete (yyvsp[(25) - (34)].val33)->get_id();
		  delete (yyvsp[(25) - (34)].val33);
		}
	    ;}
    break;

  case 211:

    { (yyval.val42) = new bottomAndSideRoughMilling((yyvsp[(3) - (34)].val239), (yyvsp[(5) - (34)].val233), (yyvsp[(7) - (34)].sval), (yyvsp[(9) - (34)].val17), (yyvsp[(11) - (34)].val46), 0, 0, 0, (yyvsp[(19) - (34)].val17), (yyvsp[(21) - (34)].val184), (yyvsp[(23) - (34)].val184), (yyvsp[(25) - (34)].val33), (yyvsp[(27) - (34)].val17), (yyvsp[(29) - (34)].val17), (yyvsp[(31) - (34)].val17), (yyvsp[(33) - (34)].val17));
	      if ((yyvsp[(3) - (34)].val239))
		{
		  (yyval.val42)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val42)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (34)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (34)].val239)->get_id();
		  delete (yyvsp[(3) - (34)].val239);
		}
	      if ((yyvsp[(5) - (34)].val233))
		{
		  (yyval.val42)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val42)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (34)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (34)].val233)->get_id();
		  delete (yyvsp[(5) - (34)].val233);
		}
	      if ((yyvsp[(11) - (34)].val46))
		{
		  (yyval.val42)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val42)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (34)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (34)].val46)->get_id();
		  delete (yyvsp[(11) - (34)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val42)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (34)].val12)->get_val());
	      delete (yyvsp[(13) - (34)].val12);
	      technology_refs.push_back(&((yyval.val42)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (34)].val12)->get_val());
	      delete (yyvsp[(15) - (34)].val12);
	      machineFunctions_refs.push_back(&((yyval.val42)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (34)].val12)->get_val());
	      delete (yyvsp[(17) - (34)].val12);
	      if ((yyvsp[(21) - (34)].val184))
		{
		  (yyval.val42)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val42)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (34)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (34)].val184)->get_id();
		  delete (yyvsp[(21) - (34)].val184);
		}
	      if ((yyvsp[(23) - (34)].val184))
		{
		  (yyval.val42)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val42)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (34)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (34)].val184)->get_id();
		  delete (yyvsp[(23) - (34)].val184);
		}
	      if ((yyvsp[(25) - (34)].val33))
		{
		  (yyval.val42)->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&((yyval.val42)->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back((yyvsp[(25) - (34)].val33)->get_id()->get_val());
		  delete (yyvsp[(25) - (34)].val33)->get_id();
		  delete (yyvsp[(25) - (34)].val33);
		}
	    ;}
    break;

  case 212:

    { (yyval.val43) = new bullnoseEndmill(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val43)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 213:

    { (yyval.val44) = new calendarDate((yyvsp[(3) - (8)].ival), (yyvsp[(5) - (8)].ival), (yyvsp[(7) - (8)].ival)); ;}
    break;

  case 214:

    { (yyval.val45) = new cartesian(); ;}
    break;

  case 215:

    { (yyval.val46) = new cartesianPoint((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].val14)); ;}
    break;

  case 216:

    { (yyval.val47) = new std::list<cartesianPoint *>;
	      (yyval.val47)->push_back(0);
	      cartesianPoint_refs.push_back(&((yyval.val47)->back()));
	      cartesianPoint_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 217:

    { (yyval.val47) = (yyvsp[(1) - (3)].val47);
	      (yyval.val47)->push_back(0);
	      cartesianPoint_refs.push_back(&((yyval.val47)->back()));
	      cartesianPoint_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 218:

    { (yyval.val48) = new centerDrill(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val48)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 219:

    { (yyval.val49) = new centerDrilling((yyvsp[(3) - (30)].val239), (yyvsp[(5) - (30)].val233), (yyvsp[(7) - (30)].sval), (yyvsp[(9) - (30)].val17), (yyvsp[(11) - (30)].val46), 0, 0, 0, (yyvsp[(19) - (30)].val17), (yyvsp[(21) - (30)].val17), (yyvsp[(23) - (30)].val17), (yyvsp[(25) - (30)].val17), (yyvsp[(27) - (30)].val17), (yyvsp[(29) - (30)].val92));
	      if ((yyvsp[(3) - (30)].val239))
		{
		  (yyval.val49)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val49)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (30)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (30)].val239)->get_id();
		  delete (yyvsp[(3) - (30)].val239);
		}
	      if ((yyvsp[(5) - (30)].val233))
		{
		  (yyval.val49)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val49)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (30)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (30)].val233)->get_id();
		  delete (yyvsp[(5) - (30)].val233);
		}
	      if ((yyvsp[(11) - (30)].val46))
		{
		  (yyval.val49)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val49)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (30)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (30)].val46)->get_id();
		  delete (yyvsp[(11) - (30)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val49)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (30)].val12)->get_val());
	      delete (yyvsp[(13) - (30)].val12);
	      technology_refs.push_back(&((yyval.val49)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (30)].val12)->get_val());
	      delete (yyvsp[(15) - (30)].val12);
	      machineFunctions_refs.push_back(&((yyval.val49)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (30)].val12)->get_val());
	      delete (yyvsp[(17) - (30)].val12);
	      if ((yyvsp[(29) - (30)].val92))
		{
		  (yyval.val49)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val49)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (30)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (30)].val92)->get_id();
		  delete (yyvsp[(29) - (30)].val92);
		}
	    ;}
    break;

  case 220:

    { (yyval.val50) = new chamfer((yyvsp[(3) - (16)].sval), 0, (yyvsp[(7) - (16)].val160), 0, 0, (yyvsp[(13) - (16)].rval), 0);
	      workpiece_refs.push_back(&((yyval.val50)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (16)].val12)->get_val());
	      delete (yyvsp[(5) - (16)].val12);
	      machiningFeature_refs.push_back(&((yyval.val50)->firstFeature));
	      machiningFeature_nums.push_back((yyvsp[(9) - (16)].val12)->get_val());
	      delete (yyvsp[(9) - (16)].val12);
	      machiningFeature_refs.push_back(&((yyval.val50)->secondFeature));
	      machiningFeature_nums.push_back((yyvsp[(11) - (16)].val12)->get_val());
	      delete (yyvsp[(11) - (16)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val50)->firstOffsetAmount));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(15) - (16)].val12)->get_val());
	      delete (yyvsp[(15) - (16)].val12);
	    ;}
    break;

  case 221:

    { (yyval.val51) = new channel((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 222:

    { (yyval.val52) = new circle((yyvsp[(3) - (8)].sval), 0, (yyvsp[(7) - (8)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val52)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	    ;}
    break;

  case 223:

    { (yyval.val53) = new circularOffset((yyvsp[(3) - (6)].rval), (yyvsp[(5) - (6)].ival)); ;}
    break;

  case 224:

    { (yyval.val54) = new circularOmit((yyvsp[(3) - (4)].ival)); ;}
    break;

  case 225:

    { (yyval.val55) = new std::list<circularOffset *>;
	      (yyval.val55)->push_back(0);
	      circularOffset_refs.push_back(&((yyval.val55)->back()));
	      circularOffset_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 226:

    { (yyval.val55) = (yyvsp[(1) - (3)].val55);
	      (yyval.val55)->push_back(0);
	      circularOffset_refs.push_back(&((yyval.val55)->back()));
	      circularOffset_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 227:

    { (yyval.val56) = new std::list<circularOmit *>;
	      (yyval.val56)->push_back(0);
	      circularOmit_refs.push_back(&((yyval.val56)->back()));
	      circularOmit_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 228:

    { (yyval.val56) = (yyvsp[(1) - (3)].val56);
	      (yyval.val56)->push_back(0);
	      circularOmit_refs.push_back(&((yyval.val56)->back()));
	      circularOmit_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 229:

    { (yyval.val57) = new circularPattern((yyvsp[(3) - (24)].sval), 0, (yyvsp[(7) - (24)].val160), 0, 0, (yyvsp[(13) - (24)].rval), (yyvsp[(15) - (24)].ival), (yyvsp[(17) - (24)].val154), (yyvsp[(19) - (24)].val155), (yyvsp[(21) - (24)].val236), (yyvsp[(23) - (24)].rval));
	      workpiece_refs.push_back(&((yyval.val57)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (24)].val12)->get_val());
	      delete (yyvsp[(5) - (24)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val57)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (24)].val12)->get_val());
	      delete (yyvsp[(9) - (24)].val12);
	      two5DmanufacturingFeature_refs.push_back(&((yyval.val57)->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back((yyvsp[(11) - (24)].val12)->get_val());
	      delete (yyvsp[(11) - (24)].val12);
	      if ((yyvsp[(21) - (24)].val236))
		{
		  (yyval.val57)->set_baseFeatureDiameter(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val57)->baseFeatureDiameter));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(21) - (24)].val236)->get_id()->get_val());
		  delete (yyvsp[(21) - (24)].val236)->get_id();
		  delete (yyvsp[(21) - (24)].val236);
		}
	    ;}
    break;

  case 230:

    { (yyval.val58) = new closedPocket((yyvsp[(3) - (24)].sval), 0, (yyvsp[(7) - (24)].val160), 0, 0, (yyvsp[(13) - (24)].val151), (yyvsp[(15) - (24)].val17), 0, (yyvsp[(19) - (24)].val236), (yyvsp[(21) - (24)].val236), 0);
	      workpiece_refs.push_back(&((yyval.val58)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (24)].val12)->get_val());
	      delete (yyvsp[(5) - (24)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val58)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (24)].val12)->get_val());
	      delete (yyvsp[(9) - (24)].val12);
	      elementarySurface_refs.push_back(&((yyval.val58)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (24)].val12)->get_val());
	      delete (yyvsp[(11) - (24)].val12);
	      pocketBottomCondition_refs.push_back(&((yyval.val58)->bottomCondition));
	      pocketBottomCondition_nums.push_back((yyvsp[(17) - (24)].val12)->get_val());
	      delete (yyvsp[(17) - (24)].val12);
	      if ((yyvsp[(19) - (24)].val236))
		{
		  (yyval.val58)->set_planarRadius(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val58)->planarRadius));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(19) - (24)].val236)->get_id()->get_val());
		  delete (yyvsp[(19) - (24)].val236)->get_id();
		  delete (yyvsp[(19) - (24)].val236);
		}
	      if ((yyvsp[(21) - (24)].val236))
		{
		  (yyval.val58)->set_orthogonalRadius(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val58)->orthogonalRadius));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(21) - (24)].val236)->get_id()->get_val());
		  delete (yyvsp[(21) - (24)].val236)->get_id();
		  delete (yyvsp[(21) - (24)].val236);
		}
	      closedProfile_refs.push_back(&((yyval.val58)->featureBoundary));
	      closedProfile_nums.push_back((yyvsp[(23) - (24)].val12)->get_val());
	      delete (yyvsp[(23) - (24)].val12);
	    ;}
    break;

  case 231:

    { (yyval.val59) = new combinedDrillAndReamer(0, (yyvsp[(5) - (14)].val117), (yyvsp[(7) - (14)].val109), (yyvsp[(9) - (14)].val35), (yyvsp[(11) - (14)].val17), (yyvsp[(13) - (14)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val59)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (14)].val12)->get_val());
	      delete (yyvsp[(3) - (14)].val12);
	    ;}
    break;

  case 232:

    { (yyval.val60) = new completeCircularPath((yyvsp[(3) - (6)].val27), 0);
	      if ((yyvsp[(3) - (6)].val27))
		{
		  (yyval.val60)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val60)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (6)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (6)].val27)->get_id();
		  delete (yyvsp[(3) - (6)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val60)->radius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 233:

    { (yyval.val61) = new compositeCurve((yyvsp[(3) - (8)].sval), (yyvsp[(5) - (8)].val156), (yyvsp[(7) - (8)].val129)); ;}
    break;

  case 234:

    { (yyval.val62) = new compositeCurveSegment((yyvsp[(3) - (8)].val249), (yyvsp[(5) - (8)].val35), 0);
	      curve_refs.push_back(&((yyval.val62)->parentCurve));
	      curve_nums.push_back((yyvsp[(7) - (8)].val12)->get_val());
	      delete (yyvsp[(7) - (8)].val12);
	    ;}
    break;

  case 235:

    { (yyval.val63) = new std::list<compositeCurveSegment *>;
	      (yyval.val63)->push_back(0);
	      compositeCurveSegment_refs.push_back(&((yyval.val63)->back()));
	      compositeCurveSegment_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 236:

    { (yyval.val63) = (yyvsp[(1) - (3)].val63);
	      (yyval.val63)->push_back(0);
	      compositeCurveSegment_refs.push_back(&((yyval.val63)->back()));
	      compositeCurveSegment_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 237:

    { (yyval.val64) = new std::list<compoundFeatureSelect *>;
	      (yyval.val64)->push_back(0);
	      compoundFeatureSelect_refs.push_back(&((yyval.val64)->back()));
	      compoundFeatureSelect_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 238:

    { (yyval.val64) = (yyvsp[(1) - (3)].val64);
	      (yyval.val64)->push_back(0);
	      compoundFeatureSelect_refs.push_back(&((yyval.val64)->back()));
	      compoundFeatureSelect_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 239:

    { (yyval.val65) = new conicalHoleBottom((yyvsp[(3) - (6)].val17), (yyvsp[(5) - (6)].val236));
	      if ((yyvsp[(5) - (6)].val236))
		{
		  (yyval.val65)->set_tipRadius(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val65)->tipRadius));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (6)].val236)->get_id()->get_val());
		  delete (yyvsp[(5) - (6)].val236)->get_id();
		  delete (yyvsp[(5) - (6)].val236);
		}
	    ;}
    break;

  case 240:

    { (yyval.val66) = new connect(); ;}
    break;

  case 241:

    { (yyval.val67) = new contact(); ;}
    break;

  case 242:

    { (yyval.val68) = new continuous(); ;}
    break;

  case 243:

    { (yyval.val69) = new contSameGradient(); ;}
    break;

  case 244:

    { (yyval.val70) = new contSameGradientSameCurvature(); ;}
    break;

  case 245:

    { (yyval.val71) = new contourParallel((yyvsp[(3) - (10)].val17), (yyvsp[(5) - (10)].val35), (yyvsp[(7) - (10)].val208), (yyvsp[(9) - (10)].val77)); ;}
    break;

  case 246:

    { (yyval.val72) = new counterbore(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val72)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 247:

    { (yyval.val73) = new counterboreHole((yyvsp[(3) - (12)].sval), 0, (yyvsp[(7) - (12)].val160), 0, (yyvsp[(11) - (12)].val157));
	      workpiece_refs.push_back(&((yyval.val73)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (12)].val12)->get_val());
	      delete (yyvsp[(5) - (12)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val73)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (12)].val12)->get_val());
	      delete (yyvsp[(9) - (12)].val12);
	    ;}
    break;

  case 248:

    { (yyval.val74) = new countersink(0, (yyvsp[(5) - (14)].val117), (yyvsp[(7) - (14)].val109), (yyvsp[(9) - (14)].val35), (yyvsp[(11) - (14)].val17), (yyvsp[(13) - (14)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val74)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (14)].val12)->get_val());
	      delete (yyvsp[(3) - (14)].val12);
	    ;}
    break;

  case 249:

    { (yyval.val75) = new counterSinking((yyvsp[(3) - (30)].val239), (yyvsp[(5) - (30)].val233), (yyvsp[(7) - (30)].sval), (yyvsp[(9) - (30)].val17), (yyvsp[(11) - (30)].val46), 0, 0, 0, (yyvsp[(19) - (30)].val17), (yyvsp[(21) - (30)].val17), (yyvsp[(23) - (30)].val17), (yyvsp[(25) - (30)].val17), (yyvsp[(27) - (30)].val17), (yyvsp[(29) - (30)].val92));
	      if ((yyvsp[(3) - (30)].val239))
		{
		  (yyval.val75)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val75)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (30)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (30)].val239)->get_id();
		  delete (yyvsp[(3) - (30)].val239);
		}
	      if ((yyvsp[(5) - (30)].val233))
		{
		  (yyval.val75)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val75)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (30)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (30)].val233)->get_id();
		  delete (yyvsp[(5) - (30)].val233);
		}
	      if ((yyvsp[(11) - (30)].val46))
		{
		  (yyval.val75)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val75)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (30)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (30)].val46)->get_id();
		  delete (yyvsp[(11) - (30)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val75)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (30)].val12)->get_val());
	      delete (yyvsp[(13) - (30)].val12);
	      technology_refs.push_back(&((yyval.val75)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (30)].val12)->get_val());
	      delete (yyvsp[(15) - (30)].val12);
	      machineFunctions_refs.push_back(&((yyval.val75)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (30)].val12)->get_val());
	      delete (yyvsp[(17) - (30)].val12);
	      if ((yyvsp[(29) - (30)].val92))
		{
		  (yyval.val75)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val75)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (30)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (30)].val92)->get_id();
		  delete (yyvsp[(29) - (30)].val92);
		}
	    ;}
    break;

  case 250:

    { (yyval.val76) = new countersunkHole((yyvsp[(3) - (12)].sval), 0, (yyvsp[(7) - (12)].val160), 0, (yyvsp[(11) - (12)].val157));
	      workpiece_refs.push_back(&((yyval.val76)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (12)].val12)->get_val());
	      delete (yyvsp[(5) - (12)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val76)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (12)].val12)->get_val());
	      delete (yyvsp[(9) - (12)].val12);
	    ;}
    break;

  case 251:

    { (yyval.val77) = (yyvsp[(1) - (1)].val78); ;}
    break;

  case 252:

    { (yyval.val77) = (yyvsp[(1) - (1)].val79); ;}
    break;

  case 253:

    { (yyval.val78) = new cutmodeTypeClimb(); ;}
    break;

  case 254:

    { (yyval.val79) = new cutmodeTypeConventional(); ;}
    break;

  case 255:

    { (yyval.val80) = new cutterLocationTrajectory((yyvsp[(3) - (20)].val35), (yyvsp[(5) - (20)].val242), (yyvsp[(7) - (20)].val241), (yyvsp[(9) - (20)].val138), (yyvsp[(11) - (20)].val137), (yyvsp[(13) - (20)].val35), 0, (yyvsp[(17) - (20)].val61), (yyvsp[(19) - (20)].val61));
	      if ((yyvsp[(9) - (20)].val138))
		{
		  (yyval.val80)->set_itsTechnology(0);
		  technology_refs.push_back(&((yyval.val80)->itsTechnology));
		  technology_nums.push_back((yyvsp[(9) - (20)].val138)->get_id()->get_val());
		  delete (yyvsp[(9) - (20)].val138)->get_id();
		  delete (yyvsp[(9) - (20)].val138);
		}
	      if ((yyvsp[(11) - (20)].val137))
		{
		  (yyval.val80)->set_itsMachineFunctions(0);
		  machineFunctions_refs.push_back(&((yyval.val80)->itsMachineFunctions));
		  machineFunctions_nums.push_back((yyvsp[(11) - (20)].val137)->get_id()->get_val());
		  delete (yyvsp[(11) - (20)].val137)->get_id();
		  delete (yyvsp[(11) - (20)].val137);
		}
	      boundedCurve_refs.push_back(&((yyval.val80)->basiccurve));
	      boundedCurve_nums.push_back((yyvsp[(15) - (20)].val12)->get_val());
	      delete (yyvsp[(15) - (20)].val12);
	      if ((yyvsp[(17) - (20)].val61))
		{
		  (yyval.val80)->set_itsToolaxis(0);
		  boundedCurve_refs.push_back(&((yyval.val80)->itsToolaxis));
		  boundedCurve_nums.push_back((yyvsp[(17) - (20)].val61)->get_id()->get_val());
		  delete (yyvsp[(17) - (20)].val61)->get_id();
		  delete (yyvsp[(17) - (20)].val61);
		}
	      if ((yyvsp[(19) - (20)].val61))
		{
		  (yyval.val80)->set_surfaceNormal(0);
		  boundedCurve_refs.push_back(&((yyval.val80)->surfaceNormal));
		  boundedCurve_nums.push_back((yyvsp[(19) - (20)].val61)->get_id()->get_val());
		  delete (yyvsp[(19) - (20)].val61)->get_id();
		  delete (yyvsp[(19) - (20)].val61);
		}
	    ;}
    break;

  case 256:

    { (yyval.val81) = new cuttingComponent((yyvsp[(3) - (12)].rval), (yyvsp[(5) - (12)].val135), (yyvsp[(7) - (12)].val83), (yyvsp[(9) - (12)].val17), (yyvsp[(11) - (12)].val138));
	      if ((yyvsp[(5) - (12)].val135))
		{
		  (yyval.val81)->set_itsMaterial(0);
		  material_refs.push_back(&((yyval.val81)->itsMaterial));
		  material_nums.push_back((yyvsp[(5) - (12)].val135)->get_id()->get_val());
		  delete (yyvsp[(5) - (12)].val135)->get_id();
		  delete (yyvsp[(5) - (12)].val135);
		}
	      if ((yyvsp[(7) - (12)].val83))
		{
		  (yyval.val81)->set_technologicalData(0);
		  cuttingEdgeTechnologicalData_refs.push_back(&((yyval.val81)->technologicalData));
		  cuttingEdgeTechnologicalData_nums.push_back((yyvsp[(7) - (12)].val83)->get_id()->get_val());
		  delete (yyvsp[(7) - (12)].val83)->get_id();
		  delete (yyvsp[(7) - (12)].val83);
		}
	      if ((yyvsp[(11) - (12)].val138))
		{
		  (yyval.val81)->set_itsTechnology(0);
		  millingTechnology_refs.push_back(&((yyval.val81)->itsTechnology));
		  millingTechnology_nums.push_back((yyvsp[(11) - (12)].val138)->get_id()->get_val());
		  delete (yyvsp[(11) - (12)].val138)->get_id();
		  delete (yyvsp[(11) - (12)].val138);
		}
	    ;}
    break;

  case 257:

    { (yyval.val82) = new std::list<cuttingComponent *>;
	      (yyval.val82)->push_back(0);
	      cuttingComponent_refs.push_back(&((yyval.val82)->back()));
	      cuttingComponent_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 258:

    { (yyval.val82) = (yyvsp[(1) - (3)].val82);
	      (yyval.val82)->push_back(0);
	      cuttingComponent_refs.push_back(&((yyval.val82)->back()));
	      cuttingComponent_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 259:

    { (yyval.val83) = new cuttingEdgeTechnologicalData((yyvsp[(3) - (8)].val17), (yyvsp[(5) - (8)].val17), (yyvsp[(7) - (8)].val17)); ;}
    break;

  case 260:

    { (yyval.val84) = new dateAndTime(0, (yyvsp[(5) - (6)].sval));
	      date_refs.push_back(&((yyval.val84)->dateComponent));
	      date_nums.push_back((yyvsp[(3) - (6)].val12)->get_val());
	      delete (yyvsp[(3) - (6)].val12);
	    ;}
    break;

  case 261:

    { (yyval.val85) = new degouge(); ;}
    break;

  case 262:

    { (yyval.val86) = new descriptiveParameter((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval)); ;}
    break;

  case 263:

    { (yyval.val87) = new diameterTaper(0);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val87)->finalDiameter));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(3) - (4)].val12)->get_val());
	      delete (yyvsp[(3) - (4)].val12);
	    ;}
    break;

  case 264:

    { (yyval.val88) = new direction((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].val14)); ;}
    break;

  case 265:

    { (yyval.val89) = new discontinuous(); ;}
    break;

  case 266:

    { (yyval.val90) = new displayMessage((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval)); ;}
    break;

  case 267:

    { (yyval.val91) = new drilling((yyvsp[(3) - (30)].val239), (yyvsp[(5) - (30)].val233), (yyvsp[(7) - (30)].sval), (yyvsp[(9) - (30)].val17), (yyvsp[(11) - (30)].val46), 0, 0, 0, (yyvsp[(19) - (30)].val17), (yyvsp[(21) - (30)].val17), (yyvsp[(23) - (30)].val17), (yyvsp[(25) - (30)].val17), (yyvsp[(27) - (30)].val17), (yyvsp[(29) - (30)].val92));
	      if ((yyvsp[(3) - (30)].val239))
		{
		  (yyval.val91)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val91)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (30)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (30)].val239)->get_id();
		  delete (yyvsp[(3) - (30)].val239);
		}
	      if ((yyvsp[(5) - (30)].val233))
		{
		  (yyval.val91)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val91)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (30)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (30)].val233)->get_id();
		  delete (yyvsp[(5) - (30)].val233);
		}
	      if ((yyvsp[(11) - (30)].val46))
		{
		  (yyval.val91)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val91)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (30)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (30)].val46)->get_id();
		  delete (yyvsp[(11) - (30)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val91)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (30)].val12)->get_val());
	      delete (yyvsp[(13) - (30)].val12);
	      technology_refs.push_back(&((yyval.val91)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (30)].val12)->get_val());
	      delete (yyvsp[(15) - (30)].val12);
	      machineFunctions_refs.push_back(&((yyval.val91)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (30)].val12)->get_val());
	      delete (yyvsp[(17) - (30)].val12);
	      if ((yyvsp[(29) - (30)].val92))
		{
		  (yyval.val91)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val91)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (30)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (30)].val92)->get_id();
		  delete (yyvsp[(29) - (30)].val92);
		}
	    ;}
    break;

  case 268:

    { (yyval.val92) = new drillingTypeStrategy((yyvsp[(3) - (14)].val17), (yyvsp[(5) - (14)].val17), (yyvsp[(7) - (14)].val17), (yyvsp[(9) - (14)].val17), (yyvsp[(11) - (14)].val17), (yyvsp[(13) - (14)].val17)); ;}
    break;

  case 269:

    { (yyval.val93) = new edgeRound((yyvsp[(3) - (18)].sval), 0, (yyvsp[(7) - (18)].val160), 0, 0, 0, (yyvsp[(15) - (18)].val236), (yyvsp[(17) - (18)].val236));
	      workpiece_refs.push_back(&((yyval.val93)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (18)].val12)->get_val());
	      delete (yyvsp[(5) - (18)].val12);
	      machiningFeature_refs.push_back(&((yyval.val93)->firstFeature));
	      machiningFeature_nums.push_back((yyvsp[(9) - (18)].val12)->get_val());
	      delete (yyvsp[(9) - (18)].val12);
	      machiningFeature_refs.push_back(&((yyval.val93)->secondFeature));
	      machiningFeature_nums.push_back((yyvsp[(11) - (18)].val12)->get_val());
	      delete (yyvsp[(11) - (18)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val93)->radius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(13) - (18)].val12)->get_val());
	      delete (yyvsp[(13) - (18)].val12);
	      if ((yyvsp[(15) - (18)].val236))
		{
		  (yyval.val93)->set_firstOffsetAmount(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val93)->firstOffsetAmount));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(15) - (18)].val236)->get_id()->get_val());
		  delete (yyvsp[(15) - (18)].val236)->get_id();
		  delete (yyvsp[(15) - (18)].val236);
		}
	      if ((yyvsp[(17) - (18)].val236))
		{
		  (yyval.val93)->set_secondOffsetAmount(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val93)->secondOffsetAmount));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(17) - (18)].val236)->get_id()->get_val());
		  delete (yyvsp[(17) - (18)].val236)->get_id();
		  delete (yyvsp[(17) - (18)].val236);
		}
	    ;}
    break;

  case 270:

    { (yyval.val94) = new ellipse((yyvsp[(3) - (10)].sval), 0, (yyvsp[(7) - (10)].rval), (yyvsp[(9) - (10)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val94)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	    ;}
    break;

  case 271:

    { (yyval.val95) = new exchangePallet((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 272:

    { (yyval.val96) = new std::list<executable *>;
	      (yyval.val96)->push_back(0);
	      executable_refs.push_back(&((yyval.val96)->back()));
	      executable_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 273:

    { (yyval.val96) = (yyvsp[(1) - (3)].val96);
	      (yyval.val96)->push_back(0);
	      executable_refs.push_back(&((yyval.val96)->back()));
	      executable_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 274:

    { (yyval.val97) = new facemill(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val97)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 275:

    { (yyval.val98) = new feedstop((yyvsp[(3) - (14)].val35), (yyvsp[(5) - (14)].val242), (yyvsp[(7) - (14)].val241), (yyvsp[(9) - (14)].val138), (yyvsp[(11) - (14)].val137), (yyvsp[(13) - (14)].rval));
	      if ((yyvsp[(9) - (14)].val138))
		{
		  (yyval.val98)->set_itsTechnology(0);
		  technology_refs.push_back(&((yyval.val98)->itsTechnology));
		  technology_nums.push_back((yyvsp[(9) - (14)].val138)->get_id()->get_val());
		  delete (yyvsp[(9) - (14)].val138)->get_id();
		  delete (yyvsp[(9) - (14)].val138);
		}
	      if ((yyvsp[(11) - (14)].val137))
		{
		  (yyval.val98)->set_itsMachineFunctions(0);
		  machineFunctions_refs.push_back(&((yyval.val98)->itsMachineFunctions));
		  machineFunctions_nums.push_back((yyvsp[(11) - (14)].val137)->get_id()->get_val());
		  delete (yyvsp[(11) - (14)].val137)->get_id();
		  delete (yyvsp[(11) - (14)].val137);
		}
	    ;}
    break;

  case 276:

    { (yyval.val99) = (yyvsp[(1) - (1)].val101); ;}
    break;

  case 277:

    { (yyval.val99) = (yyvsp[(1) - (1)].val100); ;}
    break;

  case 278:

    { (yyval.val100) = new fittingTypeHole(); ;}
    break;

  case 279:

    { (yyval.val101) = new fittingTypeShaft(); ;}
    break;

  case 280:

    { (yyval.val102) = new flatHoleBottom(); ;}
    break;

  case 281:

    { (yyval.val103) = new flatSlotEndType(0, 0);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val103)->cornerRadius1));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(3) - (6)].val12)->get_val());
	      delete (yyvsp[(3) - (6)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val103)->cornerRadius2));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 282:

    { (yyval.val104) = new flatWithRadiusHoleBottom(0);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val104)->cornerRadius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(3) - (4)].val12)->get_val());
	      delete (yyvsp[(3) - (4)].val12);
	    ;}
    break;

  case 283:

    { (yyval.val105) = new freeformOperation((yyvsp[(3) - (26)].val239), (yyvsp[(5) - (26)].val233), (yyvsp[(7) - (26)].sval), (yyvsp[(9) - (26)].val17), (yyvsp[(11) - (26)].val46), 0, 0, 0, (yyvsp[(19) - (26)].val17), (yyvsp[(21) - (26)].val184), (yyvsp[(23) - (26)].val184), (yyvsp[(25) - (26)].val118));
	      if ((yyvsp[(3) - (26)].val239))
		{
		  (yyval.val105)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val105)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (26)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (26)].val239)->get_id();
		  delete (yyvsp[(3) - (26)].val239);
		}
	      if ((yyvsp[(5) - (26)].val233))
		{
		  (yyval.val105)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val105)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (26)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (26)].val233)->get_id();
		  delete (yyvsp[(5) - (26)].val233);
		}
	      if ((yyvsp[(11) - (26)].val46))
		{
		  (yyval.val105)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val105)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (26)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (26)].val46)->get_id();
		  delete (yyvsp[(11) - (26)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val105)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (26)].val12)->get_val());
	      delete (yyvsp[(13) - (26)].val12);
	      technology_refs.push_back(&((yyval.val105)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (26)].val12)->get_val());
	      delete (yyvsp[(15) - (26)].val12);
	      machineFunctions_refs.push_back(&((yyval.val105)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (26)].val12)->get_val());
	      delete (yyvsp[(17) - (26)].val12);
	      if ((yyvsp[(21) - (26)].val184))
		{
		  (yyval.val105)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val105)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (26)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (26)].val184)->get_id();
		  delete (yyvsp[(21) - (26)].val184);
		}
	      if ((yyvsp[(23) - (26)].val184))
		{
		  (yyval.val105)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val105)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (26)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (26)].val184)->get_id();
		  delete (yyvsp[(23) - (26)].val184);
		}
	      if ((yyvsp[(25) - (26)].val118))
		{
		  (yyval.val105)->set_itsMachiningStrategy(0);
		  freeformStrategy_refs.push_back(&((yyval.val105)->itsMachiningStrategy));
		  freeformStrategy_nums.push_back((yyvsp[(25) - (26)].val118)->get_id()->get_val());
		  delete (yyvsp[(25) - (26)].val118)->get_id();
		  delete (yyvsp[(25) - (26)].val118);
		}
	    ;}
    break;

  case 284:

    { (yyval.val106) = new generalPath((yyvsp[(3) - (6)].val27), 0);
	      if ((yyvsp[(3) - (6)].val27))
		{
		  (yyval.val106)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val106)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (6)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (6)].val27)->get_id();
		  delete (yyvsp[(3) - (6)].val27);
		}
	      boundedCurve_refs.push_back(&((yyval.val106)->sweptPath));
	      boundedCurve_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 285:

    { (yyval.val107) = new generalPattern((yyvsp[(3) - (14)].sval), 0, (yyvsp[(7) - (14)].val160), 0, 0, (yyvsp[(13) - (14)].val150));
	      workpiece_refs.push_back(&((yyval.val107)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (14)].val12)->get_val());
	      delete (yyvsp[(5) - (14)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val107)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (14)].val12)->get_val());
	      delete (yyvsp[(9) - (14)].val12);
	      two5DmanufacturingFeature_refs.push_back(&((yyval.val107)->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back((yyvsp[(11) - (14)].val12)->get_val());
	      delete (yyvsp[(11) - (14)].val12);
	    ;}
    break;

  case 286:

    { (yyval.val108) = new generalPocketBottomCondition(0);
	      region_refs.push_back(&((yyval.val108)->shape));
	      region_nums.push_back((yyvsp[(3) - (4)].val12)->get_val());
	      delete (yyvsp[(3) - (4)].val12);
	    ;}
    break;

  case 287:

    { (yyval.val109) = (yyvsp[(1) - (1)].val110); ;}
    break;

  case 288:

    { (yyval.val109) = (yyvsp[(1) - (1)].val111); ;}
    break;

  case 289:

    { (yyval.val110) = new handRight(); ;}
    break;

  case 290:

    { (yyval.val111) = new handLeft(); ;}
    break;

  case 291:

    { (yyval.val112) = new helix((yyvsp[(3) - (10)].sval), 0, (yyvsp[(7) - (10)].rval), (yyvsp[(9) - (10)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val112)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	    ;}
    break;

  case 292:

    { (yyval.val113) = new hyperbola((yyvsp[(3) - (10)].sval), 0, (yyvsp[(7) - (10)].rval), (yyvsp[(9) - (10)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val113)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	    ;}
    break;

  case 293:

    { (yyval.val114) = new indexPallet((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].ival)); ;}
    break;

  case 294:

    { (yyval.val115) = new indexTable((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].ival)); ;}
    break;

  case 295:

    { (yyval.val116) = new inProcessGeometry((yyvsp[(3) - (8)].val21), (yyvsp[(5) - (8)].val21), (yyvsp[(7) - (8)].val21)); ;}
    break;

  case 296:

    { (yyval.val117) = new integer((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 297:

    { (yyval.val118) = new leadingLineStrategy((yyvsp[(3) - (12)].val173), (yyvsp[(5) - (12)].val77), 0, (yyvsp[(9) - (12)].val17), 0);
	      tolerances_refs.push_back(&((yyval.val118)->itsMillingTolerances));
	      tolerances_nums.push_back((yyvsp[(7) - (12)].val12)->get_val());
	      delete (yyvsp[(7) - (12)].val12);
	      boundedCurve_refs.push_back(&((yyval.val118)->itsLine));
	      boundedCurve_nums.push_back((yyvsp[(11) - (12)].val12)->get_val());
	      delete (yyvsp[(11) - (12)].val12);
	    ;}
    break;

  case 298:

    { (yyval.val119) = (yyvsp[(1) - (1)].val120); ;}
    break;

  case 299:

    { (yyval.val119) = (yyvsp[(1) - (1)].val121); ;}
    break;

  case 300:

    { (yyval.val120) = new leftOrRightLeft(); ;}
    break;

  case 301:

    { (yyval.val121) = new leftOrRightRight(); ;}
    break;

  case 302:

    { (yyval.val122) = new lift(); ;}
    break;

  case 303:

    { (yyval.val123) = new liftShiftPlunge(); ;}
    break;

  case 304:

    { (yyval.val124) = new limitsAndFits((yyvsp[(3) - (8)].rval), (yyvsp[(5) - (8)].rval), (yyvsp[(7) - (8)].val99)); ;}
    break;

  case 305:

    { (yyval.val125) = new line((yyvsp[(3) - (8)].sval), 0, 0);
	      cartesianPoint_refs.push_back(&((yyval.val125)->pnt));
	      cartesianPoint_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	      vector_refs.push_back(&((yyval.val125)->dir));
	      vector_nums.push_back((yyvsp[(7) - (8)].val12)->get_val());
	      delete (yyvsp[(7) - (8)].val12);
	    ;}
    break;

  case 306:

    { (yyval.val126) = new linearPath((yyvsp[(3) - (8)].val27), 0, 0);
	      if ((yyvsp[(3) - (8)].val27))
		{
		  (yyval.val126)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val126)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (8)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (8)].val27)->get_id();
		  delete (yyvsp[(3) - (8)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val126)->distance));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	      direction_refs.push_back(&((yyval.val126)->itsDirection));
	      direction_nums.push_back((yyvsp[(7) - (8)].val12)->get_val());
	      delete (yyvsp[(7) - (8)].val12);
	    ;}
    break;

  case 307:

    { (yyval.val127) = new linearProfile((yyvsp[(3) - (6)].val27), 0);
	      if ((yyvsp[(3) - (6)].val27))
		{
		  (yyval.val127)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val127)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (6)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (6)].val27)->get_id();
		  delete (yyvsp[(3) - (6)].val27);
		}
	      numericParameter_refs.push_back(&((yyval.val127)->profileLength));
	      numericParameter_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 308:

    { (yyval.val128) = new loadTool((yyvsp[(3) - (6)].sval), 0);
	      machiningTool_refs.push_back(&((yyval.val128)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 309:

    { (yyval.val129) = (yyvsp[(1) - (1)].val36); ;}
    break;

  case 310:

    { (yyval.val129) = (yyvsp[(1) - (1)].val37); ;}
    break;

  case 311:

    { (yyval.val129) = (yyvsp[(1) - (1)].val130); ;}
    break;

  case 312:

    { (yyval.val130) = new logicalUnknown(); ;}
    break;

  case 313:

    { (yyval.val131) = new loopBack(); ;}
    break;

  case 314:

    { (yyval.val132) = new loopSlotEndType(); ;}
    break;

  case 315:

    { (yyval.val133) = new std::list<machiningOperation *>;
	      (yyval.val133)->push_back(0);
	      machiningOperation_refs.push_back(&((yyval.val133)->back()));
	      machiningOperation_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 316:

    { (yyval.val133) = (yyvsp[(1) - (3)].val133);
	      (yyval.val133)->push_back(0);
	      machiningOperation_refs.push_back(&((yyval.val133)->back()));
	      machiningOperation_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 317:

    { (yyval.val134) = new machiningWorkingstep((yyvsp[(3) - (12)].sval), 0, 0, 0, (yyvsp[(11) - (12)].val116));
	      elementarySurface_refs.push_back(&((yyval.val134)->itsSecplane));
	      elementarySurface_nums.push_back((yyvsp[(5) - (12)].val12)->get_val());
	      delete (yyvsp[(5) - (12)].val12);
	      manufacturingFeature_refs.push_back(&((yyval.val134)->itsFeature));
	      manufacturingFeature_nums.push_back((yyvsp[(7) - (12)].val12)->get_val());
	      delete (yyvsp[(7) - (12)].val12);
	      machiningOperation_refs.push_back(&((yyval.val134)->itsOperation));
	      machiningOperation_nums.push_back((yyvsp[(9) - (12)].val12)->get_val());
	      delete (yyvsp[(9) - (12)].val12);
	    ;}
    break;

  case 318:

    { (yyval.val135) = new material((yyvsp[(3) - (8)].sval), (yyvsp[(5) - (8)].sval), (yyvsp[(7) - (8)].val163)); ;}
    break;

  case 319:

    { (yyval.val136) = new millingCuttingTool((yyvsp[(3) - (14)].sval), 0, (yyvsp[(7) - (14)].val158), (yyvsp[(9) - (14)].val17), (yyvsp[(11) - (14)].val88), (yyvsp[(13) - (14)].val17));
	      toolBody_refs.push_back(&((yyval.val136)->itsToolBody));
	      toolBody_nums.push_back((yyvsp[(5) - (14)].val12)->get_val());
	      delete (yyvsp[(5) - (14)].val12);
	      if ((yyvsp[(11) - (14)].val88))
		{
		  (yyval.val136)->set_directionForSpindleOrientation(0);
		  direction_refs.push_back(&((yyval.val136)->directionForSpindleOrientation));
		  direction_nums.push_back((yyvsp[(11) - (14)].val88)->get_id()->get_val());
		  delete (yyvsp[(11) - (14)].val88)->get_id();
		  delete (yyvsp[(11) - (14)].val88);
		}
	    ;}
    break;

  case 320:

    { (yyval.val137) = new millingMachineFunctions((yyvsp[(3) - (22)].val35), (yyvsp[(5) - (22)].val17), (yyvsp[(7) - (22)].val35), (yyvsp[(9) - (22)].val35), (yyvsp[(11) - (22)].val17), (yyvsp[(13) - (22)].val15), (yyvsp[(15) - (22)].val35), (yyvsp[(17) - (22)].val88), (yyvsp[(19) - (22)].val191), (yyvsp[(21) - (22)].val163));
	      if ((yyvsp[(17) - (22)].val88))
		{
		  (yyval.val137)->set_orientedSpindleStop(0);
		  direction_refs.push_back(&((yyval.val137)->orientedSpindleStop));
		  direction_nums.push_back((yyvsp[(17) - (22)].val88)->get_id()->get_val());
		  delete (yyvsp[(17) - (22)].val88)->get_id();
		  delete (yyvsp[(17) - (22)].val88);
		}
	      if ((yyvsp[(19) - (22)].val191))
		{
		  (yyval.val137)->set_itsProcessModel(0);
		  processModelList_refs.push_back(&((yyval.val137)->itsProcessModel));
		  processModelList_nums.push_back((yyvsp[(19) - (22)].val191)->get_id()->get_val());
		  delete (yyvsp[(19) - (22)].val191)->get_id();
		  delete (yyvsp[(19) - (22)].val191);
		}
	    ;}
    break;

  case 321:

    { (yyval.val138) = new millingTechnology((yyvsp[(3) - (20)].val17), (yyvsp[(5) - (20)].val244), (yyvsp[(7) - (20)].val17), (yyvsp[(9) - (20)].val17), (yyvsp[(11) - (20)].val17), (yyvsp[(13) - (20)].val35), (yyvsp[(15) - (20)].val35), (yyvsp[(17) - (20)].val35), (yyvsp[(19) - (20)].val35)); ;}
    break;

  case 322:

    { (yyval.val139) = new millingToolDimension((yyvsp[(3) - (16)].rval), (yyvsp[(5) - (16)].val17), (yyvsp[(7) - (16)].val17), (yyvsp[(9) - (16)].val17), (yyvsp[(11) - (16)].val17), (yyvsp[(13) - (16)].val17), (yyvsp[(15) - (16)].val17)); ;}
    break;

  case 323:

    { (yyval.val140) = new multistepDrilling((yyvsp[(3) - (38)].val239), (yyvsp[(5) - (38)].val233), (yyvsp[(7) - (38)].sval), (yyvsp[(9) - (38)].val17), (yyvsp[(11) - (38)].val46), 0, 0, 0, (yyvsp[(19) - (38)].val17), (yyvsp[(21) - (38)].val17), (yyvsp[(23) - (38)].val17), (yyvsp[(25) - (38)].val17), (yyvsp[(27) - (38)].val17), (yyvsp[(29) - (38)].val92), (yyvsp[(31) - (38)].rval), (yyvsp[(33) - (38)].rval), (yyvsp[(35) - (38)].rval), (yyvsp[(37) - (38)].val17));
	      if ((yyvsp[(3) - (38)].val239))
		{
		  (yyval.val140)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val140)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (38)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (38)].val239)->get_id();
		  delete (yyvsp[(3) - (38)].val239);
		}
	      if ((yyvsp[(5) - (38)].val233))
		{
		  (yyval.val140)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val140)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (38)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (38)].val233)->get_id();
		  delete (yyvsp[(5) - (38)].val233);
		}
	      if ((yyvsp[(11) - (38)].val46))
		{
		  (yyval.val140)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val140)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (38)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (38)].val46)->get_id();
		  delete (yyvsp[(11) - (38)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val140)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (38)].val12)->get_val());
	      delete (yyvsp[(13) - (38)].val12);
	      technology_refs.push_back(&((yyval.val140)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (38)].val12)->get_val());
	      delete (yyvsp[(15) - (38)].val12);
	      machineFunctions_refs.push_back(&((yyval.val140)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (38)].val12)->get_val());
	      delete (yyvsp[(17) - (38)].val12);
	      if ((yyvsp[(29) - (38)].val92))
		{
		  (yyval.val140)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val140)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (38)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (38)].val92)->get_id();
		  delete (yyvsp[(29) - (38)].val92);
		}
	    ;}
    break;

  case 324:

    { (yyval.val141) = new ncVariable((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].val17)); ;}
    break;

  case 325:

    { (yyval.val142) = new std::list<ncVariable *>;
	      (yyval.val142)->push_back(0);
	      ncVariable_refs.push_back(&((yyval.val142)->back()));
	      ncVariable_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 326:

    { (yyval.val142) = (yyvsp[(1) - (3)].val142);
	      (yyval.val142)->push_back(0);
	      ncVariable_refs.push_back(&((yyval.val142)->back()));
	      ncVariable_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 327:

    { (yyval.val143) = new nonContact(); ;}
    break;

  case 328:

    { (yyval.val144) = new numericParameter((yyvsp[(3) - (8)].sval), (yyvsp[(5) - (8)].rval), (yyvsp[(7) - (8)].sval)); ;}
    break;

  case 329:

    { (yyval.val145) = new offsetVector((yyvsp[(3) - (6)].val161), (yyvsp[(5) - (6)].val161)); ;}
    break;

  case 330:

    { (yyval.val146) = new openSlotEndType(); ;}
    break;

  case 331:

    { (yyval.val21) = (yyvsp[(1) - (1)].val21) ;}
    break;

  case 332:

    { (yyval.val21) = 0; ;}
    break;

  case 333:

    { (yyval.val184) = new plungeHelix(0,0,0);
	      (yyval.val184)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 334:

    { (yyval.val184) = 0; ;}
    break;

  case 335:

    { (yyval.val24) = new approval(0,0);
	      (yyval.val24)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 336:

    { (yyval.val24) = 0; ;}
    break;

  case 337:

    { (yyval.val27) = new axis2placement3d(0,0,0,0);
	      (yyval.val27)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 338:

    { (yyval.val27) = 0; ;}
    break;

  case 339:

    { (yyval.val35) = (yyvsp[(1) - (1)].val35) ;}
    break;

  case 340:

    { (yyval.val35) = 0; ;}
    break;

  case 341:

    { (yyval.val61) = new compositeCurve(0,0,0);
	      (yyval.val61)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 342:

    { (yyval.val61) = 0; ;}
    break;

  case 343:

    { (yyval.val34) = new block(0,0,0,0,0);
	      (yyval.val34)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 344:

    { (yyval.val34) = 0; ;}
    break;

  case 345:

    { (yyval.val46) = new cartesianPoint(0,0);
	      (yyval.val46)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 346:

    { (yyval.val46) = 0; ;}
    break;

  case 347:

    { (yyval.val51) = new channel(0);
	      (yyval.val51)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 348:

    { (yyval.val51) = 0; ;}
    break;

  case 349:

    { (yyval.val200) = new rectangularClosedProfile(0,0,0);
	      (yyval.val200)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 350:

    { (yyval.val200) = 0; ;}
    break;

  case 351:

    { (yyval.val77) = (yyvsp[(1) - (1)].val77) ;}
    break;

  case 352:

    { (yyval.val77) = 0; ;}
    break;

  case 353:

    { (yyval.val83) = new cuttingEdgeTechnologicalData(0,0,0);
	      (yyval.val83)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 354:

    { (yyval.val83) = 0; ;}
    break;

  case 355:

    { (yyval.val84) = new dateAndTime(0,0);
	      (yyval.val84)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 356:

    { (yyval.val84) = 0; ;}
    break;

  case 357:

    { (yyval.val88) = new direction(0,0);
	      (yyval.val88)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 358:

    { (yyval.val88) = 0; ;}
    break;

  case 359:

    { (yyval.val92) = new drillingTypeStrategy(0,0,0,0,0,0);
	      (yyval.val92)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 360:

    { (yyval.val92) = 0; ;}
    break;

  case 361:

    { (yyval.val99) = (yyvsp[(1) - (1)].val99) ;}
    break;

  case 362:

    { (yyval.val99) = 0; ;}
    break;

  case 363:

    { (yyval.val118) = new leadingLineStrategy(0,0,0,0,0);
	      (yyval.val118)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 364:

    { (yyval.val118) = 0; ;}
    break;

  case 365:

    { (yyval.val109) = (yyvsp[(1) - (1)].val109) ;}
    break;

  case 366:

    { (yyval.val109) = 0; ;}
    break;

  case 367:

    { (yyval.val116) = (yyvsp[(1) - (1)].val116) ;}
    break;

  case 368:

    { (yyval.val116) = 0; ;}
    break;

  case 369:

    { (yyval.val117) = (yyvsp[(1) - (1)].val117) ;}
    break;

  case 370:

    { (yyval.val117) = 0; ;}
    break;

  case 371:

    { (yyval.val147) = new optionalStop((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 372:

    { (yyval.val119) = (yyvsp[(1) - (1)].val119) ;}
    break;

  case 373:

    { (yyval.val119) = 0; ;}
    break;

  case 374:

    { (yyval.val137) = new millingMachineFunctions(0,0,0,0,0,0,0,0,0,0);
	      (yyval.val137)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 375:

    { (yyval.val137) = 0; ;}
    break;

  case 376:

    { (yyval.val136) = new millingCuttingTool(0,0,0,0,0,0);
	      (yyval.val136)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 377:

    { (yyval.val136) = 0; ;}
    break;

  case 378:

    { (yyval.val135) = new material(0,0,0);
	      (yyval.val135)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 379:

    { (yyval.val135) = 0; ;}
    break;

  case 380:

    { (yyval.val138) = new millingTechnology(0,0,0,0,0,0,0,0,0);
	      (yyval.val138)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 381:

    { (yyval.val138) = 0; ;}
    break;

  case 382:

    { (yyval.val145) = (yyvsp[(1) - (1)].val145) ;}
    break;

  case 383:

    { (yyval.val145) = 0; ;}
    break;

  case 384:

    { (yyval.val161) = (yyvsp[(1) - (1)].val161) ;}
    break;

  case 385:

    { (yyval.val161) = 0; ;}
    break;

  case 386:

    { (yyval.val176) = new personAndAddress(0,0);
	      (yyval.val176)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 387:

    { (yyval.val176) = 0; ;}
    break;

  case 388:

    { (yyval.val191) = new processModelList(0);
	      (yyval.val191)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 389:

    { (yyval.val191) = 0; ;}
    break;

  case 390:

    { (yyval.val34) = new block(0,0,0,0,0);
	      (yyval.val34)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 391:

    { (yyval.val34) = 0; ;}
    break;

  case 392:

    { (yyval.val214) = new setup(0,0,0,0);
	      (yyval.val214)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 393:

    { (yyval.val214) = 0; ;}
    break;

  case 394:

    { (yyval.val228) = (yyvsp[(1) - (1)].val228) ;}
    break;

  case 395:

    { (yyval.val228) = 0; ;}
    break;

  case 396:

    { (yyval.val22) = new angleTaper(0);
	      (yyval.val22)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 397:

    { (yyval.val22) = 0; ;}
    break;

  case 398:

    { (yyval.val138) = new millingTechnology(0,0,0,0,0,0,0,0,0);
	      (yyval.val138)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 399:

    { (yyval.val138) = 0; ;}
    break;

  case 400:

    { (yyval.val236) = new tolerancedLengthMeasure(0,0);
	      (yyval.val236)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 401:

    { (yyval.val236) = 0; ;}
    break;

  case 402:

    { (yyval.val233) = new threeAxes();
	      (yyval.val233)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 403:

    { (yyval.val233) = 0; ;}
    break;

  case 404:

    { (yyval.val239) = new toolpathList(0);
	      (yyval.val239)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 405:

    { (yyval.val239) = 0; ;}
    break;

  case 406:

    { (yyval.val241) = (yyvsp[(1) - (1)].val241) ;}
    break;

  case 407:

    { (yyval.val241) = 0; ;}
    break;

  case 408:

    { (yyval.val33) = new bidirectionalMilling(0,0,0,0,0);
	      (yyval.val33)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 409:

    { (yyval.val33) = 0; ;}
    break;

  case 410:

    { (yyval.val260) = new veeProfile(0,0,0,0);
	      (yyval.val260)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 411:

    { (yyval.val260) = 0; ;}
    break;

  case 412:

    { (yyval.val263) = new workpiece(0,0,0,0,0,0,0);
	      (yyval.val263)->set_id((yyvsp[(1) - (1)].val12));
	    ;}
    break;

  case 413:

    { (yyval.val263) = 0; ;}
    break;

  case 414:

    { (yyval.val148) = new parabola((yyvsp[(3) - (8)].sval), 0, (yyvsp[(7) - (8)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val148)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	    ;}
    break;

  case 415:

    { (yyval.val149) = new parameter(); ;}
    break;

  case 416:

    { (yyval.val150) = new parenAxis2placement3dListFull((yyvsp[(2) - (3)].val28)); ;}
    break;

  case 417:

    { (yyval.val151) = new parenBossList((yyvsp[(2) - (3)].val40)); ;}
    break;

  case 418:

    { (yyval.val151) = new parenBossList(new std::list<boss *>); ;}
    break;

  case 419:

    { (yyval.val152) = new parenCartesianPointList((yyvsp[(2) - (3)].val47)); ;}
    break;

  case 420:

    { (yyval.val152) = new parenCartesianPointList(new std::list<cartesianPoint *>); ;}
    break;

  case 421:

    { (yyval.val153) = new parenCartesianPointListFull((yyvsp[(2) - (3)].val47)); ;}
    break;

  case 422:

    { (yyval.val154) = new parenCircularOffsetList((yyvsp[(2) - (3)].val55)); ;}
    break;

  case 423:

    { (yyval.val154) = new parenCircularOffsetList(new std::list<circularOffset *>); ;}
    break;

  case 424:

    { (yyval.val155) = new parenCircularOmitList((yyvsp[(2) - (3)].val56)); ;}
    break;

  case 425:

    { (yyval.val155) = new parenCircularOmitList(new std::list<circularOmit *>); ;}
    break;

  case 426:

    { (yyval.val156) = new parenCompositeCurveSegmentListFull((yyvsp[(2) - (3)].val63)); ;}
    break;

  case 427:

    { (yyval.val157) = new parenCompoundFeatureSelectListFull((yyvsp[(2) - (3)].val64)); ;}
    break;

  case 428:

    { (yyval.val158) = new parenCuttingComponentListFull((yyvsp[(2) - (3)].val82)); ;}
    break;

  case 429:

    { (yyval.val159) = new parenExecutableList((yyvsp[(2) - (3)].val96)); ;}
    break;

  case 430:

    { (yyval.val159) = new parenExecutableList(new std::list<executable *>); ;}
    break;

  case 431:

    { (yyval.val160) = new parenMachiningOperationList((yyvsp[(2) - (3)].val133)); ;}
    break;

  case 432:

    { (yyval.val160) = new parenMachiningOperationList(new std::list<machiningOperation *>); ;}
    break;

  case 433:

    { (yyval.val161) = new parenNcVariableListFull((yyvsp[(2) - (3)].val142)); ;}
    break;

  case 434:

    { (yyval.val162) = new parenProcessModelLiszt((yyvsp[(2) - (3)].val192)); ;}
    break;

  case 435:

    { (yyval.val163) = new parenPropertyParameterList((yyvsp[(2) - (3)].val195)); ;}
    break;

  case 436:

    { (yyval.val163) = new parenPropertyParameterList(new std::list<propertyParameter *>); ;}
    break;

  case 437:

    { (yyval.val164) = new parenRectangularOffsetList((yyvsp[(2) - (3)].val202)); ;}
    break;

  case 438:

    { (yyval.val164) = new parenRectangularOffsetList(new std::list<rectangularOffset *>); ;}
    break;

  case 439:

    { (yyval.val165) = new parenRectangularOmitList((yyvsp[(2) - (3)].val204)); ;}
    break;

  case 440:

    { (yyval.val165) = new parenRectangularOmitList(new std::list<rectangularOmit *>); ;}
    break;

  case 441:

    { (yyval.val166) = new parenSetupInstructionList((yyvsp[(2) - (3)].val216)); ;}
    break;

  case 442:

    { (yyval.val166) = new parenSetupInstructionList(new std::list<setupInstruction *>); ;}
    break;

  case 443:

    { (yyval.val167) = new parenSlotEndTypeList((yyvsp[(2) - (3)].val220)); ;}
    break;

  case 444:

    { (yyval.val167) = new parenSlotEndTypeList(new std::list<slotEndType *>); ;}
    break;

  case 445:

    { (yyval.val168) = new parenToolpathLisztFull((yyvsp[(2) - (3)].val240)); ;}
    break;

  case 446:

    { (yyval.val169) = new parenTrimmingSelectListFull((yyvsp[(2) - (3)].val252)); ;}
    break;

  case 447:

    { (yyval.val170) = new parenWorkpieceList((yyvsp[(2) - (3)].val265)); ;}
    break;

  case 448:

    { (yyval.val170) = new parenWorkpieceList(new std::list<workpiece *>); ;}
    break;

  case 449:

    { (yyval.val171) = new parenWorkpieceSetupList((yyvsp[(2) - (3)].val268)); ;}
    break;

  case 450:

    { (yyval.val171) = new parenWorkpieceSetupList(new std::list<workpieceSetup *>); ;}
    break;

  case 451:

    { (yyval.val172) = new partialCircularPath((yyvsp[(3) - (8)].val27), 0, (yyvsp[(7) - (8)].rval));
	      if ((yyvsp[(3) - (8)].val27))
		{
		  (yyval.val172)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val172)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (8)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (8)].val27)->get_id();
		  delete (yyvsp[(3) - (8)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val172)->radius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	    ;}
    break;

  case 452:

    { (yyval.val173) = (yyvsp[(1) - (1)].val174); ;}
    break;

  case 453:

    { (yyval.val173) = (yyvsp[(1) - (1)].val175); ;}
    break;

  case 454:

    { (yyval.val174) = new pathmodeTypeForward(); ;}
    break;

  case 455:

    { (yyval.val175) = new pathmodeTypeZigzag(); ;}
    break;

  case 456:

    { (yyval.val176) = new personAndAddress((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval)); ;}
    break;

  case 457:

    { (yyval.val177) = new planarFace((yyvsp[(3) - (20)].sval), 0, (yyvsp[(7) - (20)].val160), 0, 0, 0, 0, (yyvsp[(17) - (20)].val200), (yyvsp[(19) - (20)].val151));
	      workpiece_refs.push_back(&((yyval.val177)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (20)].val12)->get_val());
	      delete (yyvsp[(5) - (20)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val177)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (20)].val12)->get_val());
	      delete (yyvsp[(9) - (20)].val12);
	      elementarySurface_refs.push_back(&((yyval.val177)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (20)].val12)->get_val());
	      delete (yyvsp[(11) - (20)].val12);
	      linearPath_refs.push_back(&((yyval.val177)->courseOfTravel));
	      linearPath_nums.push_back((yyvsp[(13) - (20)].val12)->get_val());
	      delete (yyvsp[(13) - (20)].val12);
	      linearProfile_refs.push_back(&((yyval.val177)->removalBoundary));
	      linearProfile_nums.push_back((yyvsp[(15) - (20)].val12)->get_val());
	      delete (yyvsp[(15) - (20)].val12);
	      if ((yyvsp[(17) - (20)].val200))
		{
		  (yyval.val177)->set_faceBoundary(0);
		  closedProfile_refs.push_back(&((yyval.val177)->faceBoundary));
		  closedProfile_nums.push_back((yyvsp[(17) - (20)].val200)->get_id()->get_val());
		  delete (yyvsp[(17) - (20)].val200)->get_id();
		  delete (yyvsp[(17) - (20)].val200);
		}
	    ;}
    break;

  case 458:

    { (yyval.val178) = new planarPocketBottomCondition(); ;}
    break;

  case 459:

    { (yyval.val179) = new plane((yyvsp[(3) - (6)].sval), 0);
	      axis2placement3d_refs.push_back(&((yyval.val179)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 460:

    { (yyval.val180) = new planeCcStrategy((yyvsp[(3) - (12)].val173), (yyvsp[(5) - (12)].val77), 0, (yyvsp[(9) - (12)].val17), 0);
	      tolerances_refs.push_back(&((yyval.val180)->itsMillingTolerances));
	      tolerances_nums.push_back((yyvsp[(7) - (12)].val12)->get_val());
	      delete (yyvsp[(7) - (12)].val12);
	      direction_refs.push_back(&((yyval.val180)->itsPlaneNormal));
	      direction_nums.push_back((yyvsp[(11) - (12)].val12)->get_val());
	      delete (yyvsp[(11) - (12)].val12);
	    ;}
    break;

  case 461:

    { (yyval.val181) = new planeClStrategy((yyvsp[(3) - (12)].val173), (yyvsp[(5) - (12)].val77), 0, (yyvsp[(9) - (12)].val17), 0);
	      tolerances_refs.push_back(&((yyval.val181)->itsMillingTolerances));
	      tolerances_nums.push_back((yyvsp[(7) - (12)].val12)->get_val());
	      delete (yyvsp[(7) - (12)].val12);
	      direction_refs.push_back(&((yyval.val181)->itsPlaneNormal));
	      direction_nums.push_back((yyvsp[(11) - (12)].val12)->get_val());
	      delete (yyvsp[(11) - (12)].val12);
	    ;}
    break;

  case 462:

    { (yyval.val182) = new planeFinishMilling((yyvsp[(3) - (30)].val239), (yyvsp[(5) - (30)].val233), (yyvsp[(7) - (30)].sval), (yyvsp[(9) - (30)].val17), (yyvsp[(11) - (30)].val46), 0, 0, 0, (yyvsp[(19) - (30)].val17), (yyvsp[(21) - (30)].val184), (yyvsp[(23) - (30)].val184), (yyvsp[(25) - (30)].val33), (yyvsp[(27) - (30)].val17), (yyvsp[(29) - (30)].val17));
	      if ((yyvsp[(3) - (30)].val239))
		{
		  (yyval.val182)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val182)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (30)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (30)].val239)->get_id();
		  delete (yyvsp[(3) - (30)].val239);
		}
	      if ((yyvsp[(5) - (30)].val233))
		{
		  (yyval.val182)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val182)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (30)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (30)].val233)->get_id();
		  delete (yyvsp[(5) - (30)].val233);
		}
	      if ((yyvsp[(11) - (30)].val46))
		{
		  (yyval.val182)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val182)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (30)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (30)].val46)->get_id();
		  delete (yyvsp[(11) - (30)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val182)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (30)].val12)->get_val());
	      delete (yyvsp[(13) - (30)].val12);
	      technology_refs.push_back(&((yyval.val182)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (30)].val12)->get_val());
	      delete (yyvsp[(15) - (30)].val12);
	      machineFunctions_refs.push_back(&((yyval.val182)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (30)].val12)->get_val());
	      delete (yyvsp[(17) - (30)].val12);
	      if ((yyvsp[(21) - (30)].val184))
		{
		  (yyval.val182)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val182)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (30)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (30)].val184)->get_id();
		  delete (yyvsp[(21) - (30)].val184);
		}
	      if ((yyvsp[(23) - (30)].val184))
		{
		  (yyval.val182)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val182)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (30)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (30)].val184)->get_id();
		  delete (yyvsp[(23) - (30)].val184);
		}
	      if ((yyvsp[(25) - (30)].val33))
		{
		  (yyval.val182)->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&((yyval.val182)->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back((yyvsp[(25) - (30)].val33)->get_id()->get_val());
		  delete (yyvsp[(25) - (30)].val33)->get_id();
		  delete (yyvsp[(25) - (30)].val33);
		}
	    ;}
    break;

  case 463:

    { (yyval.val183) = new planeRoughMilling((yyvsp[(3) - (30)].val239), (yyvsp[(5) - (30)].val233), (yyvsp[(7) - (30)].sval), (yyvsp[(9) - (30)].val17), (yyvsp[(11) - (30)].val46), 0, 0, 0, (yyvsp[(19) - (30)].val17), (yyvsp[(21) - (30)].val184), (yyvsp[(23) - (30)].val184), (yyvsp[(25) - (30)].val33), (yyvsp[(27) - (30)].val17), (yyvsp[(29) - (30)].val17));
	      if ((yyvsp[(3) - (30)].val239))
		{
		  (yyval.val183)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val183)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (30)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (30)].val239)->get_id();
		  delete (yyvsp[(3) - (30)].val239);
		}
	      if ((yyvsp[(5) - (30)].val233))
		{
		  (yyval.val183)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val183)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (30)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (30)].val233)->get_id();
		  delete (yyvsp[(5) - (30)].val233);
		}
	      if ((yyvsp[(11) - (30)].val46))
		{
		  (yyval.val183)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val183)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (30)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (30)].val46)->get_id();
		  delete (yyvsp[(11) - (30)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val183)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (30)].val12)->get_val());
	      delete (yyvsp[(13) - (30)].val12);
	      technology_refs.push_back(&((yyval.val183)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (30)].val12)->get_val());
	      delete (yyvsp[(15) - (30)].val12);
	      machineFunctions_refs.push_back(&((yyval.val183)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (30)].val12)->get_val());
	      delete (yyvsp[(17) - (30)].val12);
	      if ((yyvsp[(21) - (30)].val184))
		{
		  (yyval.val183)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val183)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (30)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (30)].val184)->get_id();
		  delete (yyvsp[(21) - (30)].val184);
		}
	      if ((yyvsp[(23) - (30)].val184))
		{
		  (yyval.val183)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val183)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (30)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (30)].val184)->get_id();
		  delete (yyvsp[(23) - (30)].val184);
		}
	      if ((yyvsp[(25) - (30)].val33))
		{
		  (yyval.val183)->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&((yyval.val183)->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back((yyvsp[(25) - (30)].val33)->get_id()->get_val());
		  delete (yyvsp[(25) - (30)].val33)->get_id();
		  delete (yyvsp[(25) - (30)].val33);
		}
	    ;}
    break;

  case 464:

    { (yyval.val184) = new plungeHelix((yyvsp[(3) - (8)].val88), (yyvsp[(5) - (8)].rval), (yyvsp[(7) - (8)].rval));
	      if ((yyvsp[(3) - (8)].val88))
		{
		  (yyval.val184)->set_toolOrientation(0);
		  direction_refs.push_back(&((yyval.val184)->toolOrientation));
		  direction_nums.push_back((yyvsp[(3) - (8)].val88)->get_id()->get_val());
		  delete (yyvsp[(3) - (8)].val88)->get_id();
		  delete (yyvsp[(3) - (8)].val88);
		}
	    ;}
    break;

  case 465:

    { (yyval.val185) = new plungeRamp((yyvsp[(3) - (6)].val88), (yyvsp[(5) - (6)].rval));
	      if ((yyvsp[(3) - (6)].val88))
		{
		  (yyval.val185)->set_toolOrientation(0);
		  direction_refs.push_back(&((yyval.val185)->toolOrientation));
		  direction_nums.push_back((yyvsp[(3) - (6)].val88)->get_id()->get_val());
		  delete (yyvsp[(3) - (6)].val88)->get_id();
		  delete (yyvsp[(3) - (6)].val88);
		}
	    ;}
    break;

  case 466:

    { (yyval.val186) = new plungeToolaxis((yyvsp[(3) - (4)].val88));
	      if ((yyvsp[(3) - (4)].val88))
		{
		  (yyval.val186)->set_toolOrientation(0);
		  direction_refs.push_back(&((yyval.val186)->toolOrientation));
		  direction_nums.push_back((yyvsp[(3) - (4)].val88)->get_id()->get_val());
		  delete (yyvsp[(3) - (4)].val88)->get_id();
		  delete (yyvsp[(3) - (4)].val88);
		}
	    ;}
    break;

  case 467:

    { (yyval.val187) = new plungeZigzag((yyvsp[(3) - (8)].val88), (yyvsp[(5) - (8)].rval), (yyvsp[(7) - (8)].rval));
	      if ((yyvsp[(3) - (8)].val88))
		{
		  (yyval.val187)->set_toolOrientation(0);
		  direction_refs.push_back(&((yyval.val187)->toolOrientation));
		  direction_nums.push_back((yyvsp[(3) - (8)].val88)->get_id()->get_val());
		  delete (yyvsp[(3) - (8)].val88)->get_id();
		  delete (yyvsp[(3) - (8)].val88);
		}
	    ;}
    break;

  case 468:

    { (yyval.val188) = new plusMinusValue((yyvsp[(3) - (8)].rval), (yyvsp[(5) - (8)].rval), (yyvsp[(7) - (8)].ival)); ;}
    break;

  case 469:

    { (yyval.val189) = new polyline((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].val153)); ;}
    break;

  case 470:

    { (yyval.val190) = new processModel((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval)); ;}
    break;

  case 471:

    { (yyval.val191) = new processModelList((yyvsp[(3) - (4)].val162)); ;}
    break;

  case 472:

    { (yyval.val192) = new std::list<processModel *>;
	      (yyval.val192)->push_back(0);
	      processModel_refs.push_back(&((yyval.val192)->back()));
	      processModel_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 473:

    { (yyval.val192) = (yyvsp[(1) - (3)].val192);
	      (yyval.val192)->push_back(0);
	      processModel_refs.push_back(&((yyval.val192)->back()));
	      processModel_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 474:

    { (yyval.val193) = new programStop((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 475:

    { (yyval.val194) = new project((yyvsp[(3) - (14)].sval), 0, (yyvsp[(7) - (14)].val170), (yyvsp[(9) - (14)].val176), (yyvsp[(11) - (14)].val84), (yyvsp[(13) - (14)].val24));
	      workplan_refs.push_back(&((yyval.val194)->mainWorkplan));
	      workplan_nums.push_back((yyvsp[(5) - (14)].val12)->get_val());
	      delete (yyvsp[(5) - (14)].val12);
	      if ((yyvsp[(9) - (14)].val176))
		{
		  (yyval.val194)->set_itsOwner(0);
		  personAndAddress_refs.push_back(&((yyval.val194)->itsOwner));
		  personAndAddress_nums.push_back((yyvsp[(9) - (14)].val176)->get_id()->get_val());
		  delete (yyvsp[(9) - (14)].val176)->get_id();
		  delete (yyvsp[(9) - (14)].val176);
		}
	      if ((yyvsp[(11) - (14)].val84))
		{
		  (yyval.val194)->set_itsRelease(0);
		  dateAndTime_refs.push_back(&((yyval.val194)->itsRelease));
		  dateAndTime_nums.push_back((yyvsp[(11) - (14)].val84)->get_id()->get_val());
		  delete (yyvsp[(11) - (14)].val84)->get_id();
		  delete (yyvsp[(11) - (14)].val84);
		}
	      if ((yyvsp[(13) - (14)].val24))
		{
		  (yyval.val194)->set_itsStatus(0);
		  approval_refs.push_back(&((yyval.val194)->itsStatus));
		  approval_nums.push_back((yyvsp[(13) - (14)].val24)->get_id()->get_val());
		  delete (yyvsp[(13) - (14)].val24)->get_id();
		  delete (yyvsp[(13) - (14)].val24);
		}
	    ;}
    break;

  case 476:

    { (yyval.val195) = new std::list<propertyParameter *>;
	      (yyval.val195)->push_back(0);
	      propertyParameter_refs.push_back(&((yyval.val195)->back()));
	      propertyParameter_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 477:

    { (yyval.val195) = (yyvsp[(1) - (3)].val195);
	      (yyval.val195)->push_back(0);
	      propertyParameter_refs.push_back(&((yyval.val195)->back()));
	      propertyParameter_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 478:

    { (yyval.val196) = new radiusedPocketBottomCondition(0, 0);
	      cartesianPoint_refs.push_back(&((yyval.val196)->floorRadiusCenter));
	      cartesianPoint_nums.push_back((yyvsp[(3) - (6)].val12)->get_val());
	      delete (yyvsp[(3) - (6)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val196)->floorRadius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 479:

    { (yyval.val197) = new radiusedSlotEndType(); ;}
    break;

  case 480:

    { (yyval.val198) = new rapidMovement((yyvsp[(3) - (10)].sval), 0, (yyvsp[(7) - (10)].val239), (yyvsp[(9) - (10)].val233));
	      elementarySurface_refs.push_back(&((yyval.val198)->itsSecplane));
	      elementarySurface_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	      if ((yyvsp[(7) - (10)].val239))
		{
		  (yyval.val198)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val198)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(7) - (10)].val239)->get_id()->get_val());
		  delete (yyvsp[(7) - (10)].val239)->get_id();
		  delete (yyvsp[(7) - (10)].val239);
		}
	      if ((yyvsp[(9) - (10)].val233))
		{
		  (yyval.val198)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val198)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(9) - (10)].val233)->get_id()->get_val());
		  delete (yyvsp[(9) - (10)].val233)->get_id();
		  delete (yyvsp[(9) - (10)].val233);
		}
	    ;}
    break;

  case 481:

    { (yyval.val199) = new reaming((yyvsp[(3) - (36)].val239), (yyvsp[(5) - (36)].val233), (yyvsp[(7) - (36)].sval), (yyvsp[(9) - (36)].val17), (yyvsp[(11) - (36)].val46), 0, 0, 0, (yyvsp[(19) - (36)].val17), (yyvsp[(21) - (36)].val17), (yyvsp[(23) - (36)].val17), (yyvsp[(25) - (36)].val17), (yyvsp[(27) - (36)].val17), (yyvsp[(29) - (36)].val92), (yyvsp[(31) - (36)].val35), (yyvsp[(33) - (36)].val17), (yyvsp[(35) - (36)].val46));
	      if ((yyvsp[(3) - (36)].val239))
		{
		  (yyval.val199)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val199)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (36)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (36)].val239)->get_id();
		  delete (yyvsp[(3) - (36)].val239);
		}
	      if ((yyvsp[(5) - (36)].val233))
		{
		  (yyval.val199)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val199)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (36)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (36)].val233)->get_id();
		  delete (yyvsp[(5) - (36)].val233);
		}
	      if ((yyvsp[(11) - (36)].val46))
		{
		  (yyval.val199)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val199)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (36)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (36)].val46)->get_id();
		  delete (yyvsp[(11) - (36)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val199)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (36)].val12)->get_val());
	      delete (yyvsp[(13) - (36)].val12);
	      technology_refs.push_back(&((yyval.val199)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (36)].val12)->get_val());
	      delete (yyvsp[(15) - (36)].val12);
	      machineFunctions_refs.push_back(&((yyval.val199)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (36)].val12)->get_val());
	      delete (yyvsp[(17) - (36)].val12);
	      if ((yyvsp[(29) - (36)].val92))
		{
		  (yyval.val199)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val199)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (36)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (36)].val92)->get_id();
		  delete (yyvsp[(29) - (36)].val92);
		}
	      if ((yyvsp[(35) - (36)].val46))
		{
		  (yyval.val199)->set_waitingPosition(0);
		  cartesianPoint_refs.push_back(&((yyval.val199)->waitingPosition));
		  cartesianPoint_nums.push_back((yyvsp[(35) - (36)].val46)->get_id()->get_val());
		  delete (yyvsp[(35) - (36)].val46)->get_id();
		  delete (yyvsp[(35) - (36)].val46);
		}
	    ;}
    break;

  case 482:

    { (yyval.val200) = new rectangularClosedProfile((yyvsp[(3) - (8)].val27), 0, 0);
	      if ((yyvsp[(3) - (8)].val27))
		{
		  (yyval.val200)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val200)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (8)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (8)].val27)->get_id();
		  delete (yyvsp[(3) - (8)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val200)->profileWidth));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val200)->profileLength));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(7) - (8)].val12)->get_val());
	      delete (yyvsp[(7) - (8)].val12);
	    ;}
    break;

  case 483:

    { (yyval.val201) = new rectangularOffset(0, (yyvsp[(5) - (10)].rval), (yyvsp[(7) - (10)].ival), (yyvsp[(9) - (10)].ival));
	      direction_refs.push_back(&((yyval.val201)->offsetDirection));
	      direction_nums.push_back((yyvsp[(3) - (10)].val12)->get_val());
	      delete (yyvsp[(3) - (10)].val12);
	    ;}
    break;

  case 484:

    { (yyval.val202) = new std::list<rectangularOffset *>;
	      (yyval.val202)->push_back(0);
	      rectangularOffset_refs.push_back(&((yyval.val202)->back()));
	      rectangularOffset_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 485:

    { (yyval.val202) = (yyvsp[(1) - (3)].val202);
	      (yyval.val202)->push_back(0);
	      rectangularOffset_refs.push_back(&((yyval.val202)->back()));
	      rectangularOffset_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 486:

    { (yyval.val203) = new rectangularOmit((yyvsp[(3) - (6)].ival), (yyvsp[(5) - (6)].ival)); ;}
    break;

  case 487:

    { (yyval.val204) = new std::list<rectangularOmit *>;
	      (yyval.val204)->push_back(0);
	      rectangularOmit_refs.push_back(&((yyval.val204)->back()));
	      rectangularOmit_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 488:

    { (yyval.val204) = (yyvsp[(1) - (3)].val204);
	      (yyval.val204)->push_back(0);
	      rectangularOmit_refs.push_back(&((yyval.val204)->back()));
	      rectangularOmit_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 489:

    { (yyval.val205) = new rectangularPattern((yyvsp[(3) - (27)].sval), 0, (yyvsp[(7) - (27)].val160), 0, 0, 0, 0, (yyvsp[(16) - (27)].val117), (yyvsp[(18) - (27)].ival), (yyvsp[(20) - (27)].val236), (yyvsp[(22) - (27)].val88), (yyvsp[(24) - (27)].val164), (yyvsp[(26) - (27)].val165));
	      workpiece_refs.push_back(&((yyval.val205)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (27)].val12)->get_val());
	      delete (yyvsp[(5) - (27)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val205)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (27)].val12)->get_val());
	      delete (yyvsp[(9) - (27)].val12);
	      two5DmanufacturingFeature_refs.push_back(&((yyval.val205)->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back((yyvsp[(11) - (27)].val12)->get_val());
	      delete (yyvsp[(11) - (27)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val205)->spacing));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(12) - (27)].val12)->get_val());
	      delete (yyvsp[(12) - (27)].val12);
	      direction_refs.push_back(&((yyval.val205)->itsDirection));
	      direction_nums.push_back((yyvsp[(14) - (27)].val12)->get_val());
	      delete (yyvsp[(14) - (27)].val12);
	      if ((yyvsp[(20) - (27)].val236))
		{
		  (yyval.val205)->set_rowSpacing(0);
		  tolerancedLengthMeasure_refs.push_back(&((yyval.val205)->rowSpacing));
		  tolerancedLengthMeasure_nums.push_back((yyvsp[(20) - (27)].val236)->get_id()->get_val());
		  delete (yyvsp[(20) - (27)].val236)->get_id();
		  delete (yyvsp[(20) - (27)].val236);
		}
	      if ((yyvsp[(22) - (27)].val88))
		{
		  (yyval.val205)->set_rowLayoutDirection(0);
		  direction_refs.push_back(&((yyval.val205)->rowLayoutDirection));
		  direction_nums.push_back((yyvsp[(22) - (27)].val88)->get_id()->get_val());
		  delete (yyvsp[(22) - (27)].val88)->get_id();
		  delete (yyvsp[(22) - (27)].val88);
		}
	    ;}
    break;

  case 490:

    { (yyval.val206) = new regionProjection((yyvsp[(3) - (16)].sval), 0, (yyvsp[(7) - (16)].val160), (yyvsp[(9) - (16)].val27), 0, 0, 0);
	      workpiece_refs.push_back(&((yyval.val206)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (16)].val12)->get_val());
	      delete (yyvsp[(5) - (16)].val12);
	      if ((yyvsp[(9) - (16)].val27))
		{
		  (yyval.val206)->set_featurePlacement(0);
		  axis2placement3d_refs.push_back(&((yyval.val206)->featurePlacement));
		  axis2placement3d_nums.push_back((yyvsp[(9) - (16)].val27)->get_id()->get_val());
		  delete (yyvsp[(9) - (16)].val27)->get_id();
		  delete (yyvsp[(9) - (16)].val27);
		}
	      boundedCurve_refs.push_back(&((yyval.val206)->projCurve));
	      boundedCurve_nums.push_back((yyvsp[(11) - (16)].val12)->get_val());
	      delete (yyvsp[(11) - (16)].val12);
	      direction_refs.push_back(&((yyval.val206)->projDir));
	      direction_nums.push_back((yyvsp[(13) - (16)].val12)->get_val());
	      delete (yyvsp[(13) - (16)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val206)->depth));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(15) - (16)].val12)->get_val());
	      delete (yyvsp[(15) - (16)].val12);
	    ;}
    break;

  case 491:

    { (yyval.val207) = new rightCircularCylinder((yyvsp[(3) - (10)].sval), 0, (yyvsp[(7) - (10)].rval), (yyvsp[(9) - (10)].rval));
	      axis1placement_refs.push_back(&((yyval.val207)->position));
	      axis1placement_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	    ;}
    break;

  case 492:

    { (yyval.val208) = (yyvsp[(1) - (1)].val209); ;}
    break;

  case 493:

    { (yyval.val208) = (yyvsp[(1) - (1)].val210); ;}
    break;

  case 494:

    { (yyval.val209) = new rotDirectionCw(); ;}
    break;

  case 495:

    { (yyval.val210) = new rotDirectionCcw(); ;}
    break;

  case 496:

    { (yyval.val211) = new roundedUProfile((yyvsp[(3) - (6)].val27), 0);
	      if ((yyvsp[(3) - (6)].val27))
		{
		  (yyval.val211)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val211)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (6)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (6)].val27)->get_id();
		  delete (yyvsp[(3) - (6)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val211)->width));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 497:

    { (yyval.val212) = new roundHole((yyvsp[(3) - (18)].sval), 0, (yyvsp[(7) - (18)].val160), 0, 0, 0, (yyvsp[(15) - (18)].val22), 0);
	      workpiece_refs.push_back(&((yyval.val212)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (18)].val12)->get_val());
	      delete (yyvsp[(5) - (18)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val212)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (18)].val12)->get_val());
	      delete (yyvsp[(9) - (18)].val12);
	      elementarySurface_refs.push_back(&((yyval.val212)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (18)].val12)->get_val());
	      delete (yyvsp[(11) - (18)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val212)->diameter));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(13) - (18)].val12)->get_val());
	      delete (yyvsp[(13) - (18)].val12);
	      if ((yyvsp[(15) - (18)].val22))
		{
		  (yyval.val212)->set_changeInDiameter(0);
		  taperSelect_refs.push_back(&((yyval.val212)->changeInDiameter));
		  taperSelect_nums.push_back((yyvsp[(15) - (18)].val22)->get_id()->get_val());
		  delete (yyvsp[(15) - (18)].val22)->get_id();
		  delete (yyvsp[(15) - (18)].val22);
		}
	      holeBottomCondition_refs.push_back(&((yyval.val212)->bottomCondition));
	      holeBottomCondition_nums.push_back((yyvsp[(17) - (18)].val12)->get_val());
	      delete (yyvsp[(17) - (18)].val12);
	    ;}
    break;

  case 498:

    { (yyval.val213) = new setMark((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 499:

    { (yyval.val214) = new setup((yyvsp[(3) - (10)].sval), (yyvsp[(5) - (10)].val27), 0, (yyvsp[(9) - (10)].val171));
	      if ((yyvsp[(5) - (10)].val27))
		{
		  (yyval.val214)->set_itsOrigin(0);
		  axis2placement3d_refs.push_back(&((yyval.val214)->itsOrigin));
		  axis2placement3d_nums.push_back((yyvsp[(5) - (10)].val27)->get_id()->get_val());
		  delete (yyvsp[(5) - (10)].val27)->get_id();
		  delete (yyvsp[(5) - (10)].val27);
		}
	      elementarySurface_refs.push_back(&((yyval.val214)->itsSecplane));
	      elementarySurface_nums.push_back((yyvsp[(7) - (10)].val12)->get_val());
	      delete (yyvsp[(7) - (10)].val12);
	    ;}
    break;

  case 500:

    { (yyval.val215) = new setupInstruction((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval)); ;}
    break;

  case 501:

    { (yyval.val216) = new std::list<setupInstruction *>;
	      (yyval.val216)->push_back(0);
	      setupInstruction_refs.push_back(&((yyval.val216)->back()));
	      setupInstruction_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 502:

    { (yyval.val216) = (yyvsp[(1) - (3)].val216);
	      (yyval.val216)->push_back(0);
	      setupInstruction_refs.push_back(&((yyval.val216)->back()));
	      setupInstruction_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 503:

    { (yyval.val217) = new sideFinishMilling((yyvsp[(3) - (32)].val239), (yyvsp[(5) - (32)].val233), (yyvsp[(7) - (32)].sval), (yyvsp[(9) - (32)].val17), (yyvsp[(11) - (32)].val46), 0, 0, 0, (yyvsp[(19) - (32)].val17), (yyvsp[(21) - (32)].val184), (yyvsp[(23) - (32)].val184), (yyvsp[(25) - (32)].val33), (yyvsp[(27) - (32)].val17), (yyvsp[(29) - (32)].val17), (yyvsp[(31) - (32)].val17));
	      if ((yyvsp[(3) - (32)].val239))
		{
		  (yyval.val217)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val217)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (32)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (32)].val239)->get_id();
		  delete (yyvsp[(3) - (32)].val239);
		}
	      if ((yyvsp[(5) - (32)].val233))
		{
		  (yyval.val217)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val217)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (32)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (32)].val233)->get_id();
		  delete (yyvsp[(5) - (32)].val233);
		}
	      if ((yyvsp[(11) - (32)].val46))
		{
		  (yyval.val217)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val217)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (32)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (32)].val46)->get_id();
		  delete (yyvsp[(11) - (32)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val217)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (32)].val12)->get_val());
	      delete (yyvsp[(13) - (32)].val12);
	      technology_refs.push_back(&((yyval.val217)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (32)].val12)->get_val());
	      delete (yyvsp[(15) - (32)].val12);
	      machineFunctions_refs.push_back(&((yyval.val217)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (32)].val12)->get_val());
	      delete (yyvsp[(17) - (32)].val12);
	      if ((yyvsp[(21) - (32)].val184))
		{
		  (yyval.val217)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val217)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (32)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (32)].val184)->get_id();
		  delete (yyvsp[(21) - (32)].val184);
		}
	      if ((yyvsp[(23) - (32)].val184))
		{
		  (yyval.val217)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val217)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (32)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (32)].val184)->get_id();
		  delete (yyvsp[(23) - (32)].val184);
		}
	      if ((yyvsp[(25) - (32)].val33))
		{
		  (yyval.val217)->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&((yyval.val217)->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back((yyvsp[(25) - (32)].val33)->get_id()->get_val());
		  delete (yyvsp[(25) - (32)].val33)->get_id();
		  delete (yyvsp[(25) - (32)].val33);
		}
	    ;}
    break;

  case 504:

    { (yyval.val218) = new sideRoughMilling((yyvsp[(3) - (32)].val239), (yyvsp[(5) - (32)].val233), (yyvsp[(7) - (32)].sval), (yyvsp[(9) - (32)].val17), (yyvsp[(11) - (32)].val46), 0, 0, 0, (yyvsp[(19) - (32)].val17), (yyvsp[(21) - (32)].val184), (yyvsp[(23) - (32)].val184), (yyvsp[(25) - (32)].val33), (yyvsp[(27) - (32)].val17), (yyvsp[(29) - (32)].val17), (yyvsp[(31) - (32)].val17));
	      if ((yyvsp[(3) - (32)].val239))
		{
		  (yyval.val218)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val218)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (32)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (32)].val239)->get_id();
		  delete (yyvsp[(3) - (32)].val239);
		}
	      if ((yyvsp[(5) - (32)].val233))
		{
		  (yyval.val218)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val218)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (32)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (32)].val233)->get_id();
		  delete (yyvsp[(5) - (32)].val233);
		}
	      if ((yyvsp[(11) - (32)].val46))
		{
		  (yyval.val218)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val218)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (32)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (32)].val46)->get_id();
		  delete (yyvsp[(11) - (32)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val218)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (32)].val12)->get_val());
	      delete (yyvsp[(13) - (32)].val12);
	      technology_refs.push_back(&((yyval.val218)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (32)].val12)->get_val());
	      delete (yyvsp[(15) - (32)].val12);
	      machineFunctions_refs.push_back(&((yyval.val218)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (32)].val12)->get_val());
	      delete (yyvsp[(17) - (32)].val12);
	      if ((yyvsp[(21) - (32)].val184))
		{
		  (yyval.val218)->set_approach(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val218)->approach));
		  approachRetractStrategy_nums.push_back((yyvsp[(21) - (32)].val184)->get_id()->get_val());
		  delete (yyvsp[(21) - (32)].val184)->get_id();
		  delete (yyvsp[(21) - (32)].val184);
		}
	      if ((yyvsp[(23) - (32)].val184))
		{
		  (yyval.val218)->set_retract(0);
		  approachRetractStrategy_refs.push_back(&((yyval.val218)->retract));
		  approachRetractStrategy_nums.push_back((yyvsp[(23) - (32)].val184)->get_id()->get_val());
		  delete (yyvsp[(23) - (32)].val184)->get_id();
		  delete (yyvsp[(23) - (32)].val184);
		}
	      if ((yyvsp[(25) - (32)].val33))
		{
		  (yyval.val218)->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&((yyval.val218)->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back((yyvsp[(25) - (32)].val33)->get_id()->get_val());
		  delete (yyvsp[(25) - (32)].val33)->get_id();
		  delete (yyvsp[(25) - (32)].val33);
		}
	    ;}
    break;

  case 505:

    { (yyval.val219) = new slot((yyvsp[(3) - (18)].sval), 0, (yyvsp[(7) - (18)].val160), 0, 0, 0, 0, (yyvsp[(17) - (18)].val167));
	      workpiece_refs.push_back(&((yyval.val219)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (18)].val12)->get_val());
	      delete (yyvsp[(5) - (18)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val219)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (18)].val12)->get_val());
	      delete (yyvsp[(9) - (18)].val12);
	      elementarySurface_refs.push_back(&((yyval.val219)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (18)].val12)->get_val());
	      delete (yyvsp[(11) - (18)].val12);
	      travelPath_refs.push_back(&((yyval.val219)->courseOfTravel));
	      travelPath_nums.push_back((yyvsp[(13) - (18)].val12)->get_val());
	      delete (yyvsp[(13) - (18)].val12);
	      openProfile_refs.push_back(&((yyval.val219)->sweptShape));
	      openProfile_nums.push_back((yyvsp[(15) - (18)].val12)->get_val());
	      delete (yyvsp[(15) - (18)].val12);
	    ;}
    break;

  case 506:

    { (yyval.val220) = new std::list<slotEndType *>;
	      (yyval.val220)->push_back(0);
	      slotEndType_refs.push_back(&((yyval.val220)->back()));
	      slotEndType_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 507:

    { (yyval.val220) = (yyvsp[(1) - (3)].val220);
	      (yyval.val220)->push_back(0);
	      slotEndType_refs.push_back(&((yyval.val220)->back()));
	      slotEndType_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 508:

    { (yyval.val221) = new speedName(); ;}
    break;

  case 509:

    { (yyval.val222) = new sphericalCap((yyvsp[(3) - (16)].sval), 0, (yyvsp[(7) - (16)].val160), 0, 0, 0, 0);
	      workpiece_refs.push_back(&((yyval.val222)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (16)].val12)->get_val());
	      delete (yyvsp[(5) - (16)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val222)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (16)].val12)->get_val());
	      delete (yyvsp[(9) - (16)].val12);
	      elementarySurface_refs.push_back(&((yyval.val222)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (16)].val12)->get_val());
	      delete (yyvsp[(11) - (16)].val12);
	      numericParameter_refs.push_back(&((yyval.val222)->internalAngle));
	      numericParameter_nums.push_back((yyvsp[(13) - (16)].val12)->get_val());
	      delete (yyvsp[(13) - (16)].val12);
	      numericParameter_refs.push_back(&((yyval.val222)->radius));
	      numericParameter_nums.push_back((yyvsp[(15) - (16)].val12)->get_val());
	      delete (yyvsp[(15) - (16)].val12);
	    ;}
    break;

  case 510:

    { (yyval.val223) = new sphericalHoleBottom(0);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val223)->radius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(3) - (4)].val12)->get_val());
	      delete (yyvsp[(3) - (4)].val12);
	    ;}
    break;

  case 511:

    { (yyval.val224) = new sphericalSurface((yyvsp[(3) - (8)].sval), 0, (yyvsp[(7) - (8)].rval));
	      axis2placement3d_refs.push_back(&((yyval.val224)->position));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	    ;}
    break;

  case 512:

    { (yyval.val225) = new squareUProfile((yyvsp[(3) - (14)].val27), 0, 0, (yyvsp[(9) - (14)].rval), 0, (yyvsp[(13) - (14)].rval));
	      if ((yyvsp[(3) - (14)].val27))
		{
		  (yyval.val225)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val225)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (14)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (14)].val27)->get_id();
		  delete (yyvsp[(3) - (14)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val225)->width));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (14)].val12)->get_val());
	      delete (yyvsp[(5) - (14)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val225)->firstRadius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(7) - (14)].val12)->get_val());
	      delete (yyvsp[(7) - (14)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val225)->secondRadius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(11) - (14)].val12)->get_val());
	      delete (yyvsp[(11) - (14)].val12);
	    ;}
    break;

  case 513:

    { (yyval.val226) = new step((yyvsp[(3) - (18)].sval), 0, (yyvsp[(7) - (18)].val160), 0, 0, 0, (yyvsp[(15) - (18)].val260), (yyvsp[(17) - (18)].val151));
	      workpiece_refs.push_back(&((yyval.val226)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (18)].val12)->get_val());
	      delete (yyvsp[(5) - (18)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val226)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (18)].val12)->get_val());
	      delete (yyvsp[(9) - (18)].val12);
	      elementarySurface_refs.push_back(&((yyval.val226)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (18)].val12)->get_val());
	      delete (yyvsp[(11) - (18)].val12);
	      linearPath_refs.push_back(&((yyval.val226)->openBoundary));
	      linearPath_nums.push_back((yyvsp[(13) - (18)].val12)->get_val());
	      delete (yyvsp[(13) - (18)].val12);
	      if ((yyvsp[(15) - (18)].val260))
		{
		  (yyval.val226)->set_wallBoundary(0);
		  veeProfile_refs.push_back(&((yyval.val226)->wallBoundary));
		  veeProfile_nums.push_back((yyvsp[(15) - (18)].val260)->get_id()->get_val());
		  delete (yyvsp[(15) - (18)].val260)->get_id();
		  delete (yyvsp[(15) - (18)].val260);
		}
	    ;}
    break;

  case 514:

    { (yyval.val227) = new straightline(); ;}
    break;

  case 515:

    { (yyval.val228) = (yyvsp[(1) - (1)].val227); ;}
    break;

  case 516:

    { (yyval.val228) = (yyvsp[(1) - (1)].val123); ;}
    break;

  case 517:

    { (yyval.val228) = (yyvsp[(1) - (1)].val85); ;}
    break;

  case 518:

    { (yyval.val228) = (yyvsp[(1) - (1)].val131); ;}
    break;

  case 519:

    { (yyval.val229) = new taperedEndmill(0, (yyvsp[(5) - (14)].val117), (yyvsp[(7) - (14)].val109), (yyvsp[(9) - (14)].val35), (yyvsp[(11) - (14)].val17), (yyvsp[(13) - (14)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val229)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (14)].val12)->get_val());
	      delete (yyvsp[(3) - (14)].val12);
	    ;}
    break;

  case 520:

    { (yyval.val230) = new taperedReamer(0, (yyvsp[(5) - (14)].val117), (yyvsp[(7) - (14)].val109), (yyvsp[(9) - (14)].val35), (yyvsp[(11) - (14)].val17), (yyvsp[(13) - (14)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val230)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (14)].val12)->get_val());
	      delete (yyvsp[(3) - (14)].val12);
	    ;}
    break;

  case 521:

    { (yyval.val231) = new tapping((yyvsp[(3) - (31)].val239), (yyvsp[(5) - (31)].val233), (yyvsp[(7) - (31)].sval), (yyvsp[(9) - (31)].val17), (yyvsp[(11) - (31)].val46), 0, 0, 0, (yyvsp[(19) - (31)].val17), (yyvsp[(21) - (31)].val17), (yyvsp[(23) - (31)].val17), (yyvsp[(25) - (31)].val17), (yyvsp[(27) - (31)].val17), (yyvsp[(29) - (31)].val92), (yyvsp[(30) - (31)].val35));
	      if ((yyvsp[(3) - (31)].val239))
		{
		  (yyval.val231)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val231)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (31)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (31)].val239)->get_id();
		  delete (yyvsp[(3) - (31)].val239);
		}
	      if ((yyvsp[(5) - (31)].val233))
		{
		  (yyval.val231)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val231)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (31)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (31)].val233)->get_id();
		  delete (yyvsp[(5) - (31)].val233);
		}
	      if ((yyvsp[(11) - (31)].val46))
		{
		  (yyval.val231)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val231)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (31)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (31)].val46)->get_id();
		  delete (yyvsp[(11) - (31)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val231)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (31)].val12)->get_val());
	      delete (yyvsp[(13) - (31)].val12);
	      technology_refs.push_back(&((yyval.val231)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (31)].val12)->get_val());
	      delete (yyvsp[(15) - (31)].val12);
	      machineFunctions_refs.push_back(&((yyval.val231)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (31)].val12)->get_val());
	      delete (yyvsp[(17) - (31)].val12);
	      if ((yyvsp[(29) - (31)].val92))
		{
		  (yyval.val231)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val231)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (31)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (31)].val92)->get_id();
		  delete (yyvsp[(29) - (31)].val92);
		}
	    ;}
    break;

  case 522:

    { (yyval.val232) = new threadDrilling((yyvsp[(3) - (31)].val239), (yyvsp[(5) - (31)].val233), (yyvsp[(7) - (31)].sval), (yyvsp[(9) - (31)].val17), (yyvsp[(11) - (31)].val46), 0, 0, 0, (yyvsp[(19) - (31)].val17), (yyvsp[(21) - (31)].val17), (yyvsp[(23) - (31)].val17), (yyvsp[(25) - (31)].val17), (yyvsp[(27) - (31)].val17), (yyvsp[(29) - (31)].val92), (yyvsp[(30) - (31)].val35));
	      if ((yyvsp[(3) - (31)].val239))
		{
		  (yyval.val232)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val232)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(3) - (31)].val239)->get_id()->get_val());
		  delete (yyvsp[(3) - (31)].val239)->get_id();
		  delete (yyvsp[(3) - (31)].val239);
		}
	      if ((yyvsp[(5) - (31)].val233))
		{
		  (yyval.val232)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val232)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(5) - (31)].val233)->get_id()->get_val());
		  delete (yyvsp[(5) - (31)].val233)->get_id();
		  delete (yyvsp[(5) - (31)].val233);
		}
	      if ((yyvsp[(11) - (31)].val46))
		{
		  (yyval.val232)->set_startPoint(0);
		  cartesianPoint_refs.push_back(&((yyval.val232)->startPoint));
		  cartesianPoint_nums.push_back((yyvsp[(11) - (31)].val46)->get_id()->get_val());
		  delete (yyvsp[(11) - (31)].val46)->get_id();
		  delete (yyvsp[(11) - (31)].val46);
		}
	      machiningTool_refs.push_back(&((yyval.val232)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(13) - (31)].val12)->get_val());
	      delete (yyvsp[(13) - (31)].val12);
	      technology_refs.push_back(&((yyval.val232)->itsTechnology));
	      technology_nums.push_back((yyvsp[(15) - (31)].val12)->get_val());
	      delete (yyvsp[(15) - (31)].val12);
	      machineFunctions_refs.push_back(&((yyval.val232)->itsMachineFunctions));
	      machineFunctions_nums.push_back((yyvsp[(17) - (31)].val12)->get_val());
	      delete (yyvsp[(17) - (31)].val12);
	      if ((yyvsp[(29) - (31)].val92))
		{
		  (yyval.val232)->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&((yyval.val232)->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back((yyvsp[(29) - (31)].val92)->get_id()->get_val());
		  delete (yyvsp[(29) - (31)].val92)->get_id();
		  delete (yyvsp[(29) - (31)].val92);
		}
	    ;}
    break;

  case 523:

    { (yyval.val233) = new threeAxes(); ;}
    break;

  case 524:

    { (yyval.val234) = new throughBottomCondition(); ;}
    break;

  case 525:

    { (yyval.val235) = new throughPocketBottomCondition(); ;}
    break;

  case 526:

    { (yyval.val236) = new tolerancedLengthMeasure((yyvsp[(3) - (6)].rval), 0);
	      plusMinusValue_refs.push_back(&((yyval.val236)->implicitTolerance));
	      plusMinusValue_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 527:

    { (yyval.val237) = new tolerances((yyvsp[(3) - (6)].rval), (yyvsp[(5) - (6)].rval)); ;}
    break;

  case 528:

    { (yyval.val238) = new toolpathFeature((yyvsp[(3) - (12)].sval), 0, (yyvsp[(7) - (12)].val160), 0, 0);
	      workpiece_refs.push_back(&((yyval.val238)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(5) - (12)].val12)->get_val());
	      delete (yyvsp[(5) - (12)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val238)->featurePlacement));
	      axis2placement3d_nums.push_back((yyvsp[(9) - (12)].val12)->get_val());
	      delete (yyvsp[(9) - (12)].val12);
	      elementarySurface_refs.push_back(&((yyval.val238)->depth));
	      elementarySurface_nums.push_back((yyvsp[(11) - (12)].val12)->get_val());
	      delete (yyvsp[(11) - (12)].val12);
	    ;}
    break;

  case 529:

    { (yyval.val239) = new toolpathList((yyvsp[(3) - (4)].val168)); ;}
    break;

  case 530:

    { (yyval.val240) = new std::list<toolpath *>;
	      (yyval.val240)->push_back(0);
	      toolpath_refs.push_back(&((yyval.val240)->back()));
	      toolpath_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 531:

    { (yyval.val240) = (yyvsp[(1) - (3)].val240);
	      (yyval.val240)->push_back(0);
	      toolpath_refs.push_back(&((yyval.val240)->back()));
	      toolpath_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 532:

    { (yyval.val241) = (yyvsp[(1) - (1)].val17); ;}
    break;

  case 533:

    { (yyval.val241) = (yyvsp[(1) - (1)].val221); ;}
    break;

  case 534:

    { (yyval.val242) = (yyvsp[(1) - (1)].val23); ;}
    break;

  case 535:

    { (yyval.val242) = (yyvsp[(1) - (1)].val122); ;}
    break;

  case 536:

    { (yyval.val242) = (yyvsp[(1) - (1)].val66); ;}
    break;

  case 537:

    { (yyval.val242) = (yyvsp[(1) - (1)].val143); ;}
    break;

  case 538:

    { (yyval.val242) = (yyvsp[(1) - (1)].val67); ;}
    break;

  case 539:

    { (yyval.val242) = (yyvsp[(1) - (1)].val248); ;}
    break;

  case 540:

    { (yyval.val243) = new toolProbing((yyvsp[(3) - (18)].sval), 0, (yyvsp[(7) - (18)].val239), (yyvsp[(9) - (18)].val233), 0, 0, (yyvsp[(15) - (18)].rval), 0);
	      elementarySurface_refs.push_back(&((yyval.val243)->itsSecplane));
	      elementarySurface_nums.push_back((yyvsp[(5) - (18)].val12)->get_val());
	      delete (yyvsp[(5) - (18)].val12);
	      if ((yyvsp[(7) - (18)].val239))
		{
		  (yyval.val243)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val243)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(7) - (18)].val239)->get_id()->get_val());
		  delete (yyvsp[(7) - (18)].val239)->get_id();
		  delete (yyvsp[(7) - (18)].val239);
		}
	      if ((yyvsp[(9) - (18)].val233))
		{
		  (yyval.val243)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val243)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(9) - (18)].val233)->get_id()->get_val());
		  delete (yyvsp[(9) - (18)].val233)->get_id();
		  delete (yyvsp[(9) - (18)].val233);
		}
	      ncVariable_refs.push_back(&((yyval.val243)->measuredOffset));
	      ncVariable_nums.push_back((yyvsp[(11) - (18)].val12)->get_val());
	      delete (yyvsp[(11) - (18)].val12);
	      cartesianPoint_refs.push_back(&((yyval.val243)->offset));
	      cartesianPoint_nums.push_back((yyvsp[(13) - (18)].val12)->get_val());
	      delete (yyvsp[(13) - (18)].val12);
	      machiningTool_refs.push_back(&((yyval.val243)->itsTool));
	      machiningTool_nums.push_back((yyvsp[(17) - (18)].val12)->get_val());
	      delete (yyvsp[(17) - (18)].val12);
	    ;}
    break;

  case 541:

    { (yyval.val244) = (yyvsp[(1) - (1)].val245); ;}
    break;

  case 542:

    { (yyval.val244) = (yyvsp[(1) - (1)].val246); ;}
    break;

  case 543:

    { (yyval.val245) = new toolReferencePointCcp(); ;}
    break;

  case 544:

    { (yyval.val246) = new toolReferencePointTcp(); ;}
    break;

  case 545:

    { (yyval.val247) = new touchProbe((yyvsp[(3) - (4)].sval)); ;}
    break;

  case 546:

    { (yyval.val248) = new trajectoryPath(); ;}
    break;

  case 547:

    { (yyval.val249) = (yyvsp[(1) - (1)].val89); ;}
    break;

  case 548:

    { (yyval.val249) = (yyvsp[(1) - (1)].val68); ;}
    break;

  case 549:

    { (yyval.val249) = (yyvsp[(1) - (1)].val69); ;}
    break;

  case 550:

    { (yyval.val249) = (yyvsp[(1) - (1)].val70); ;}
    break;

  case 551:

    { (yyval.val250) = new trimmedCurve((yyvsp[(3) - (14)].sval), 0, (yyvsp[(7) - (14)].val169), (yyvsp[(9) - (14)].val169), (yyvsp[(11) - (14)].val35), (yyvsp[(13) - (14)].val251));
	      curve_refs.push_back(&((yyval.val250)->basisCurve));
	      curve_nums.push_back((yyvsp[(5) - (14)].val12)->get_val());
	      delete (yyvsp[(5) - (14)].val12);
	    ;}
    break;

  case 552:

    { (yyval.val251) = (yyvsp[(1) - (1)].val45); ;}
    break;

  case 553:

    { (yyval.val251) = (yyvsp[(1) - (1)].val149); ;}
    break;

  case 554:

    { (yyval.val251) = (yyvsp[(1) - (1)].val257); ;}
    break;

  case 555:

    { (yyval.val252) = new std::list<trimmingSelect *>;
	      (yyval.val252)->push_back(0);
	      trimmingSelect_refs.push_back(&((yyval.val252)->back()));
	      trimmingSelect_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 556:

    { (yyval.val252) = (yyvsp[(1) - (3)].val252);
	      (yyval.val252)->push_back(0);
	      trimmingSelect_refs.push_back(&((yyval.val252)->back()));
	      trimmingSelect_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 557:

    { (yyval.val253) = new twistDrill(0, (yyvsp[(5) - (12)].val117), (yyvsp[(7) - (12)].val109), (yyvsp[(9) - (12)].val35), (yyvsp[(11) - (12)].val17));
	      millingToolDimension_refs.push_back(&((yyval.val253)->dimension));
	      millingToolDimension_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	    ;}
    break;

  case 558:

    { (yyval.val254) = new twoAxes(); ;}
    break;

  case 559:

    { (yyval.val255) = new unidirectionalMilling((yyvsp[(3) - (10)].val17), (yyvsp[(5) - (10)].val35), (yyvsp[(7) - (10)].val88), (yyvsp[(9) - (10)].val77));
	      if ((yyvsp[(7) - (10)].val88))
		{
		  (yyval.val255)->set_feedDirection(0);
		  direction_refs.push_back(&((yyval.val255)->feedDirection));
		  direction_nums.push_back((yyvsp[(7) - (10)].val88)->get_id()->get_val());
		  delete (yyvsp[(7) - (10)].val88)->get_id();
		  delete (yyvsp[(7) - (10)].val88);
		}
	    ;}
    break;

  case 560:

    { (yyval.val256) = new unloadTool((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].val136));
	      if ((yyvsp[(5) - (6)].val136))
		{
		  (yyval.val256)->set_itsTool(0);
		  machiningTool_refs.push_back(&((yyval.val256)->itsTool));
		  machiningTool_nums.push_back((yyvsp[(5) - (6)].val136)->get_id()->get_val());
		  delete (yyvsp[(5) - (6)].val136)->get_id();
		  delete (yyvsp[(5) - (6)].val136);
		}
	    ;}
    break;

  case 561:

    { (yyval.val257) = new unspecified(); ;}
    break;

  case 562:

    { (yyval.val258) = new uvStrategy((yyvsp[(3) - (14)].val173), (yyvsp[(5) - (14)].val77), 0, (yyvsp[(9) - (14)].val17), 0, 0);
	      tolerances_refs.push_back(&((yyval.val258)->itsMillingTolerances));
	      tolerances_nums.push_back((yyvsp[(7) - (14)].val12)->get_val());
	      delete (yyvsp[(7) - (14)].val12);
	      direction_refs.push_back(&((yyval.val258)->forwardDirection));
	      direction_nums.push_back((yyvsp[(11) - (14)].val12)->get_val());
	      delete (yyvsp[(11) - (14)].val12);
	      direction_refs.push_back(&((yyval.val258)->sidewardDirection));
	      direction_nums.push_back((yyvsp[(13) - (14)].val12)->get_val());
	      delete (yyvsp[(13) - (14)].val12);
	    ;}
    break;

  case 563:

    { (yyval.val259) = new vector((yyvsp[(3) - (8)].sval), 0, (yyvsp[(7) - (8)].rval));
	      direction_refs.push_back(&((yyval.val259)->orientation));
	      direction_nums.push_back((yyvsp[(5) - (8)].val12)->get_val());
	      delete (yyvsp[(5) - (8)].val12);
	    ;}
    break;

  case 564:

    { (yyval.val260) = new veeProfile((yyvsp[(3) - (10)].val27), 0, (yyvsp[(7) - (10)].rval), (yyvsp[(9) - (10)].rval));
	      if ((yyvsp[(3) - (10)].val27))
		{
		  (yyval.val260)->set_placement(0);
		  axis2placement3d_refs.push_back(&((yyval.val260)->placement));
		  axis2placement3d_nums.push_back((yyvsp[(3) - (10)].val27)->get_id()->get_val());
		  delete (yyvsp[(3) - (10)].val27)->get_id();
		  delete (yyvsp[(3) - (10)].val27);
		}
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val260)->profileRadius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(5) - (10)].val12)->get_val());
	      delete (yyvsp[(5) - (10)].val12);
	    ;}
    break;

  case 565:

    { (yyval.val261) = new waitForMark((yyvsp[(3) - (6)].sval), 0);
	      channel_refs.push_back(&((yyval.val261)->itsChannel));
	      channel_nums.push_back((yyvsp[(5) - (6)].val12)->get_val());
	      delete (yyvsp[(5) - (6)].val12);
	    ;}
    break;

  case 566:

    { (yyval.val262) = new woodruffSlotEndType(0);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val262)->radius));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(3) - (4)].val12)->get_val());
	      delete (yyvsp[(3) - (4)].val12);
	    ;}
    break;

  case 567:

    { (yyval.val263) = new workpiece((yyvsp[(3) - (16)].sval), (yyvsp[(5) - (16)].val135), (yyvsp[(7) - (16)].val17), (yyvsp[(9) - (16)].val263), (yyvsp[(11) - (16)].val21), (yyvsp[(13) - (16)].val34), (yyvsp[(15) - (16)].val152));
	      if ((yyvsp[(5) - (16)].val135))
		{
		  (yyval.val263)->set_itsMaterial(0);
		  material_refs.push_back(&((yyval.val263)->itsMaterial));
		  material_nums.push_back((yyvsp[(5) - (16)].val135)->get_id()->get_val());
		  delete (yyvsp[(5) - (16)].val135)->get_id();
		  delete (yyvsp[(5) - (16)].val135);
		}
	      if ((yyvsp[(9) - (16)].val263))
		{
		  (yyval.val263)->set_itsRawpiece(0);
		  workpiece_refs.push_back(&((yyval.val263)->itsRawpiece));
		  workpiece_nums.push_back((yyvsp[(9) - (16)].val263)->get_id()->get_val());
		  delete (yyvsp[(9) - (16)].val263)->get_id();
		  delete (yyvsp[(9) - (16)].val263);
		}
	      if ((yyvsp[(13) - (16)].val34))
		{
		  (yyval.val263)->set_itsBoundingGeometry(0);
		  boundingGeometrySelect_refs.push_back(&((yyval.val263)->itsBoundingGeometry));
		  boundingGeometrySelect_nums.push_back((yyvsp[(13) - (16)].val34)->get_id()->get_val());
		  delete (yyvsp[(13) - (16)].val34)->get_id();
		  delete (yyvsp[(13) - (16)].val34);
		}
	    ;}
    break;

  case 568:

    { (yyval.val264) = new workpieceCompleteProbing((yyvsp[(3) - (20)].sval), 0, (yyvsp[(7) - (20)].val239), (yyvsp[(9) - (20)].val233), 0, 0, 0, 0, (yyvsp[(19) - (20)].val145));
	      elementarySurface_refs.push_back(&((yyval.val264)->itsSecplane));
	      elementarySurface_nums.push_back((yyvsp[(5) - (20)].val12)->get_val());
	      delete (yyvsp[(5) - (20)].val12);
	      if ((yyvsp[(7) - (20)].val239))
		{
		  (yyval.val264)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val264)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(7) - (20)].val239)->get_id()->get_val());
		  delete (yyvsp[(7) - (20)].val239)->get_id();
		  delete (yyvsp[(7) - (20)].val239);
		}
	      if ((yyvsp[(9) - (20)].val233))
		{
		  (yyval.val264)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val264)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(9) - (20)].val233)->get_id()->get_val());
		  delete (yyvsp[(9) - (20)].val233)->get_id();
		  delete (yyvsp[(9) - (20)].val233);
		}
	      ncVariable_refs.push_back(&((yyval.val264)->measuredOffset));
	      ncVariable_nums.push_back((yyvsp[(11) - (20)].val12)->get_val());
	      delete (yyvsp[(11) - (20)].val12);
	      workpiece_refs.push_back(&((yyval.val264)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(13) - (20)].val12)->get_val());
	      delete (yyvsp[(13) - (20)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val264)->probingDistance));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(15) - (20)].val12)->get_val());
	      delete (yyvsp[(15) - (20)].val12);
	      touchProbe_refs.push_back(&((yyval.val264)->itsProbe));
	      touchProbe_nums.push_back((yyvsp[(17) - (20)].val12)->get_val());
	      delete (yyvsp[(17) - (20)].val12);
	    ;}
    break;

  case 569:

    { (yyval.val265) = new std::list<workpiece *>;
	      (yyval.val265)->push_back(0);
	      workpiece_refs.push_back(&((yyval.val265)->back()));
	      workpiece_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 570:

    { (yyval.val265) = (yyvsp[(1) - (3)].val265);
	      (yyval.val265)->push_back(0);
	      workpiece_refs.push_back(&((yyval.val265)->back()));
	      workpiece_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 571:

    { (yyval.val266) = new workpieceProbing((yyvsp[(3) - (22)].sval), 0, (yyvsp[(7) - (22)].val239), (yyvsp[(9) - (22)].val233), 0, 0, 0, 0, 0, 0);
	      elementarySurface_refs.push_back(&((yyval.val266)->itsSecplane));
	      elementarySurface_nums.push_back((yyvsp[(5) - (22)].val12)->get_val());
	      delete (yyvsp[(5) - (22)].val12);
	      if ((yyvsp[(7) - (22)].val239))
		{
		  (yyval.val266)->set_itsToolpath(0);
		  toolpathList_refs.push_back(&((yyval.val266)->itsToolpath));
		  toolpathList_nums.push_back((yyvsp[(7) - (22)].val239)->get_id()->get_val());
		  delete (yyvsp[(7) - (22)].val239)->get_id();
		  delete (yyvsp[(7) - (22)].val239);
		}
	      if ((yyvsp[(9) - (22)].val233))
		{
		  (yyval.val266)->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&((yyval.val266)->itsToolDirection));
		  toolDirection_nums.push_back((yyvsp[(9) - (22)].val233)->get_id()->get_val());
		  delete (yyvsp[(9) - (22)].val233)->get_id();
		  delete (yyvsp[(9) - (22)].val233);
		}
	      ncVariable_refs.push_back(&((yyval.val266)->measuredOffset));
	      ncVariable_nums.push_back((yyvsp[(11) - (22)].val12)->get_val());
	      delete (yyvsp[(11) - (22)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val266)->startPosition));
	      axis2placement3d_nums.push_back((yyvsp[(13) - (22)].val12)->get_val());
	      delete (yyvsp[(13) - (22)].val12);
	      workpiece_refs.push_back(&((yyval.val266)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(15) - (22)].val12)->get_val());
	      delete (yyvsp[(15) - (22)].val12);
	      direction_refs.push_back(&((yyval.val266)->itsDirection));
	      direction_nums.push_back((yyvsp[(17) - (22)].val12)->get_val());
	      delete (yyvsp[(17) - (22)].val12);
	      tolerancedLengthMeasure_refs.push_back(&((yyval.val266)->expectedValue));
	      tolerancedLengthMeasure_nums.push_back((yyvsp[(19) - (22)].val12)->get_val());
	      delete (yyvsp[(19) - (22)].val12);
	      touchProbe_refs.push_back(&((yyval.val266)->itsProbe));
	      touchProbe_nums.push_back((yyvsp[(21) - (22)].val12)->get_val());
	      delete (yyvsp[(21) - (22)].val12);
	    ;}
    break;

  case 572:

    { (yyval.val267) = new workpieceSetup(0, 0, (yyvsp[(7) - (12)].val145), (yyvsp[(9) - (12)].val34), (yyvsp[(11) - (12)].val166));
	      workpiece_refs.push_back(&((yyval.val267)->itsWorkpiece));
	      workpiece_nums.push_back((yyvsp[(3) - (12)].val12)->get_val());
	      delete (yyvsp[(3) - (12)].val12);
	      axis2placement3d_refs.push_back(&((yyval.val267)->itsOrigin));
	      axis2placement3d_nums.push_back((yyvsp[(5) - (12)].val12)->get_val());
	      delete (yyvsp[(5) - (12)].val12);
	      if ((yyvsp[(9) - (12)].val34))
		{
		  (yyval.val267)->set_itsRestrictedArea(0);
		  restrictedAreaSelect_refs.push_back(&((yyval.val267)->itsRestrictedArea));
		  restrictedAreaSelect_nums.push_back((yyvsp[(9) - (12)].val34)->get_id()->get_val());
		  delete (yyvsp[(9) - (12)].val34)->get_id();
		  delete (yyvsp[(9) - (12)].val34);
		}
	    ;}
    break;

  case 573:

    { (yyval.val268) = new std::list<workpieceSetup *>;
	      (yyval.val268)->push_back(0);
	      workpieceSetup_refs.push_back(&((yyval.val268)->back()));
	      workpieceSetup_nums.push_back((yyvsp[(1) - (1)].val12)->get_val());
	    ;}
    break;

  case 574:

    { (yyval.val268) = (yyvsp[(1) - (3)].val268);
	      (yyval.val268)->push_back(0);
	      workpieceSetup_refs.push_back(&((yyval.val268)->back()));
	      workpieceSetup_nums.push_back((yyvsp[(3) - (3)].val12)->get_val());
	    ;}
    break;

  case 575:

    { (yyval.val269) = new workplan((yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].val159), (yyvsp[(7) - (12)].val51), (yyvsp[(9) - (12)].val214), (yyvsp[(11) - (12)].val116));
	      if ((yyvsp[(7) - (12)].val51))
		{
		  (yyval.val269)->set_itsChannel(0);
		  channel_refs.push_back(&((yyval.val269)->itsChannel));
		  channel_nums.push_back((yyvsp[(7) - (12)].val51)->get_id()->get_val());
		  delete (yyvsp[(7) - (12)].val51)->get_id();
		  delete (yyvsp[(7) - (12)].val51);
		}
	      if ((yyvsp[(9) - (12)].val214))
		{
		  (yyval.val269)->set_itsSetup(0);
		  setup_refs.push_back(&((yyval.val269)->itsSetup));
		  setup_nums.push_back((yyvsp[(9) - (12)].val214)->get_id()->get_val());
		  delete (yyvsp[(9) - (12)].val214)->get_id();
		  delete (yyvsp[(9) - (12)].val214);
		}
	    ;}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





