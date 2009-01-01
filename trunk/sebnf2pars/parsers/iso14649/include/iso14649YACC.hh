/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1489 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

