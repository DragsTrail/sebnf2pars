%{

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

%}

%union {
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

%type <val1> inputFile
%type <val2> dataSection
%type <val3> dataStarter
%type <val4> endSection
%type <val5> fileDescription
%type <val6> fileEnd
%type <val7> fileName
%type <val8> fileSchema
%type <val9> fileStart
%type <val10> headerSection
%type <val11> headerStarter
%type <val12> instanceId
%type <val13> instanceList
%type <val14> parenRealListFull
%type <val15> parenStringList
%type <val16> parenStringListFull
%type <val17> real
%type <val17> optReal
%type <val18> realList
%type <val19> stringList
%type <val20> instance
%type <val20> instancePlus
%type <val21> advancedBrepShapeRepresentation
%type <val21> optAdvancedBrepShapeRepresentation
%type <val22> angleTaper
%type <val22> optTaperSelect
%type <val23> approach
%type <val24> approval
%type <val24> optApproval
%type <val25> approvalStatus
%type <val26> axis1placement
%type <val27> axis2placement3d
%type <val27> optAxis2placement3d
%type <val28> axis2placement3dList
%type <val29> backBoring
%type <val30> backsideCounterbore
%type <val31> backsideCountersink
%type <val32> ballEndmill
%type <val33> bidirectionalMilling
%type <val33> optTwo5DmillingStrategy
%type <val34> block
%type <val34> optBoundingGeometrySelect
%type <val34> optRestrictedAreaSelect
%type <val35> boolean
%type <val35> optBoolean
%type <val36> booleanTrue
%type <val37> booleanFalse
%type <val38> boring
%type <val39> boss
%type <val40> bossList
%type <val41> bottomAndSideFinishMilling
%type <val42> bottomAndSideRoughMilling
%type <val43> bullnoseEndmill
%type <val44> calendarDate
%type <val45> cartesian
%type <val46> cartesianPoint
%type <val46> optCartesianPoint
%type <val47> cartesianPointList
%type <val48> centerDrill
%type <val49> centerDrilling
%type <val50> chamfer
%type <val51> channel
%type <val51> optChannel
%type <val52> circle
%type <val53> circularOffset
%type <val54> circularOmit
%type <val55> circularOffsetList
%type <val56> circularOmitList
%type <val57> circularPattern
%type <val58> closedPocket
%type <val59> combinedDrillAndReamer
%type <val60> completeCircularPath
%type <val61> compositeCurve
%type <val61> optBoundedCurve
%type <val62> compositeCurveSegment
%type <val63> compositeCurveSegmentList
%type <val64> compoundFeatureSelectList
%type <val65> conicalHoleBottom
%type <val66> connect
%type <val67> contact
%type <val68> continuous
%type <val69> contSameGradient
%type <val70> contSameGradientSameCurvature
%type <val71> contourParallel
%type <val72> counterbore
%type <val73> counterboreHole
%type <val74> countersink
%type <val75> counterSinking
%type <val76> countersunkHole
%type <val77> cutmodeType
%type <val77> optCutmodeType
%type <val78> cutmodeTypeClimb
%type <val79> cutmodeTypeConventional
%type <val80> cutterLocationTrajectory
%type <val81> cuttingComponent
%type <val82> cuttingComponentList
%type <val83> cuttingEdgeTechnologicalData
%type <val83> optCuttingEdgeTechnologicalData
%type <val84> dateAndTime
%type <val84> optDateAndTime
%type <val85> degouge
%type <val86> descriptiveParameter
%type <val87> diameterTaper
%type <val88> direction
%type <val88> optDirection
%type <val89> discontinuous
%type <val90> displayMessage
%type <val91> drilling
%type <val92> drillingTypeStrategy
%type <val92> optDrillingTypeStrategy
%type <val93> edgeRound
%type <val94> ellipse
%type <val95> exchangePallet
%type <val96> executableList
%type <val97> facemill
%type <val98> feedstop
%type <val99> fittingType
%type <val99> optFittingType
%type <val100> fittingTypeHole
%type <val101> fittingTypeShaft
%type <val102> flatHoleBottom
%type <val103> flatSlotEndType
%type <val104> flatWithRadiusHoleBottom
%type <val105> freeformOperation
%type <val106> generalPath
%type <val107> generalPattern
%type <val108> generalPocketBottomCondition
%type <val109> hand
%type <val109> optHand
%type <val110> handRight
%type <val111> handLeft
%type <val112> helix
%type <val113> hyperbola
%type <val114> indexPallet
%type <val115> indexTable
%type <val116> inProcessGeometry
%type <val116> optInProcessGeometry
%type <val117> integer
%type <val117> optInteger
%type <val118> leadingLineStrategy
%type <val118> optFreeformStrategy
%type <val119> leftOrRight
%type <val119> optLeftOrRight
%type <val120> leftOrRightLeft
%type <val121> leftOrRightRight
%type <val122> lift
%type <val123> liftShiftPlunge
%type <val124> limitsAndFits
%type <val125> line
%type <val126> linearPath
%type <val127> linearProfile
%type <val128> loadTool
%type <val129> logical
%type <val130> logicalUnknown
%type <val131> loopBack
%type <val132> loopSlotEndType
%type <val133> machiningOperationList
%type <val134> machiningWorkingstep
%type <val135> material
%type <val135> optMaterial
%type <val136> millingCuttingTool
%type <val136> optMachiningTool
%type <val137> millingMachineFunctions
%type <val137> optMachineFunctions
%type <val138> millingTechnology
%type <val138> optMillingTechnology
%type <val138> optTechnology
%type <val139> millingToolDimension
%type <val140> multistepDrilling
%type <val141> ncVariable
%type <val142> ncVariableList
%type <val143> nonContact
%type <val144> numericParameter
%type <val145> offsetVector
%type <val145> optOffsetVector
%type <val146> openSlotEndType
%type <val147> optionalStop
%type <val148> parabola
%type <val149> parameter
%type <val150> parenAxis2placement3dListFull
%type <val151> parenBossList
%type <val152> parenCartesianPointList
%type <val153> parenCartesianPointListFull
%type <val154> parenCircularOffsetList
%type <val155> parenCircularOmitList
%type <val156> parenCompositeCurveSegmentListFull
%type <val157> parenCompoundFeatureSelectListFull
%type <val158> parenCuttingComponentListFull
%type <val159> parenExecutableList
%type <val160> parenMachiningOperationList
%type <val161> parenNcVariableListFull
%type <val161> optParenNcVariableListFull
%type <val162> parenProcessModelLiszt
%type <val163> parenPropertyParameterList
%type <val164> parenRectangularOffsetList
%type <val165> parenRectangularOmitList
%type <val166> parenSetupInstructionList
%type <val167> parenSlotEndTypeList
%type <val168> parenToolpathLisztFull
%type <val169> parenTrimmingSelectListFull
%type <val170> parenWorkpieceList
%type <val171> parenWorkpieceSetupList
%type <val172> partialCircularPath
%type <val173> pathmodeType
%type <val174> pathmodeTypeForward
%type <val175> pathmodeTypeZigzag
%type <val176> personAndAddress
%type <val176> optPersonAndAddress
%type <val177> planarFace
%type <val178> planarPocketBottomCondition
%type <val179> plane
%type <val180> planeCcStrategy
%type <val181> planeClStrategy
%type <val182> planeFinishMilling
%type <val183> planeRoughMilling
%type <val184> plungeHelix
%type <val184> optApproachRetractStrategy
%type <val185> plungeRamp
%type <val186> plungeToolaxis
%type <val187> plungeZigzag
%type <val188> plusMinusValue
%type <val189> polyline
%type <val190> processModel
%type <val191> processModelList
%type <val191> optProcessModelList
%type <val192> processModelLiszt
%type <val193> programStop
%type <val194> project
%type <val195> propertyParameterList
%type <val196> radiusedPocketBottomCondition
%type <val197> radiusedSlotEndType
%type <val198> rapidMovement
%type <val199> reaming
%type <val200> rectangularClosedProfile
%type <val200> optClosedProfile
%type <val201> rectangularOffset
%type <val202> rectangularOffsetList
%type <val203> rectangularOmit
%type <val204> rectangularOmitList
%type <val205> rectangularPattern
%type <val206> regionProjection
%type <val207> rightCircularCylinder
%type <val208> rotDirection
%type <val209> rotDirectionCw
%type <val210> rotDirectionCcw
%type <val211> roundedUProfile
%type <val212> roundHole
%type <val213> setMark
%type <val214> setup
%type <val214> optSetup
%type <val215> setupInstruction
%type <val216> setupInstructionList
%type <val217> sideFinishMilling
%type <val218> sideRoughMilling
%type <val219> slot
%type <val220> slotEndTypeList
%type <val221> speedName
%type <val222> sphericalCap
%type <val223> sphericalHoleBottom
%type <val224> sphericalSurface
%type <val225> squareUProfile
%type <val226> step
%type <val227> straightline
%type <val228> strokeConnectionStrategy
%type <val228> optStrokeConnectionStrategy
%type <val229> taperedEndmill
%type <val230> taperedReamer
%type <val231> tapping
%type <val232> threadDrilling
%type <val233> threeAxes
%type <val233> optToolDirection
%type <val234> throughBottomCondition
%type <val235> throughPocketBottomCondition
%type <val236> tolerancedLengthMeasure
%type <val236> optTolerancedLengthMeasure
%type <val237> tolerances
%type <val238> toolpathFeature
%type <val239> toolpathList
%type <val239> optToolpathList
%type <val240> toolpathLiszt
%type <val241> toolpathSpeedprofile
%type <val241> optToolpathSpeedprofile
%type <val242> toolpathType
%type <val243> toolProbing
%type <val244> toolReferencePoint
%type <val245> toolReferencePointCcp
%type <val246> toolReferencePointTcp
%type <val247> touchProbe
%type <val248> trajectoryPath
%type <val249> transitionCode
%type <val250> trimmedCurve
%type <val251> trimmingPreference
%type <val252> trimmingSelectList
%type <val253> twistDrill
%type <val254> twoAxes
%type <val255> unidirectionalMilling
%type <val256> unloadTool
%type <val257> unspecified
%type <val258> uvStrategy
%type <val259> vector
%type <val260> veeProfile
%type <val260> optVeeProfile
%type <val261> waitForMark
%type <val262> woodruffSlotEndType
%type <val263> workpiece
%type <val263> optWorkpiece
%type <val264> workpieceCompleteProbing
%type <val265> workpieceList
%type <val266> workpieceProbing
%type <val267> workpieceSetup
%type <val268> workpieceSetupList
%type <val269> workplan

%token ADVANCEDBREPSHAPEREPRESENTATION
%token ANGLETAPER
%token APPROACH
%token APPROVAL
%token APPROVALSTATUS
%token AXIS1PLACEMENT
%token AXIS2PLACEMENT3D
%token BACKBORING
%token BACKSIDECOUNTERBORE
%token BACKSIDECOUNTERSINK
%token BALLENDMILL
%token BIDIRECTIONALMILLING
%token BLOCK
%token BORING
%token BOSS
%token BOTTOMANDSIDEFINISHMILLING
%token BOTTOMANDSIDEROUGHMILLING
%token BULLNOSEENDMILL
%token C
%token CALENDARDATE
%token CARTESIAN
%token CARTESIANPOINT
%token CCP
%token CCW
%token CENTERDRILL
%token CENTERDRILLING
%token CHAMFER
%token CHANNEL
%token CIRCLE
%token CIRCULAROFFSET
%token CIRCULAROMIT
%token CIRCULARPATTERN
%token CLIMB
%token CLOSEDPOCKET
%token COMBINEDDRILLANDREAMER
%token COMPLETECIRCULARPATH
%token COMPOSITECURVE
%token COMPOSITECURVESEGMENT
%token CONICALHOLEBOTTOM
%token CONNECT
%token CONTACT
%token CONTINUOUS
%token CONTOURPARALLEL
%token CONTSAMEGRADIENT
%token CONTSAMEGRADIENTSAMECURVATURE
%token CONVENTIONAL
%token COUNTERBORE
%token COUNTERBOREHOLE
%token COUNTERSINK
%token COUNTERSINKING
%token COUNTERSUNKHOLE
%token CUTTERLOCATIONTRAJECTORY
%token CUTTINGCOMPONENT
%token CUTTINGEDGETECHNOLOGICALDATA
%token CW
%token DATA
%token DATEANDTIME
%token DEGOUGE
%token DESCRIPTIVEPARAMETER
%token DIAMETERTAPER
%token DIRECTION
%token DISCONTINUOUS
%token DISPLAYMESSAGE
%token DRILLING
%token DRILLINGTYPESTRATEGY
%token EDGEROUND
%token ELLIPSE
%token ENDSEC
%token EXCHANGEPALLET
%token FACEMILL
%token FALSE
%token FEEDSTOP
%token FILEDESCRIPTION
%token FILEEND
%token FILENAME
%token FILESCHEMA
%token FILESTART
%token FLATHOLEBOTTOM
%token FLATSLOTENDTYPE
%token FLATWITHRADIUSHOLEBOTTOM
%token FORWARD
%token FREEFORMOPERATION
%token GENERALPATH
%token GENERALPATTERN
%token GENERALPOCKETBOTTOMCONDITION
%token HEADER
%token HELIX
%token HOLE
%token HYPERBOLA
%token INDEXPALLET
%token INDEXTABLE
%token INPROCESSGEOMETRY
%token LEADINGLINESTRATEGY
%token LEFT
%token LIFT
%token LIFTSHIFTPLUNGE
%token LIMITSANDFITS
%token LINE
%token LINEARPATH
%token LINEARPROFILE
%token LOADTOOL
%token LOOPBACK
%token LOOPSLOTENDTYPE
%token MACHININGWORKINGSTEP
%token MATERIAL
%token MILLINGCUTTINGTOOL
%token MILLINGMACHINEFUNCTIONS
%token MILLINGTECHNOLOGY
%token MILLINGTOOLDIMENSION
%token MULTISTEPDRILLING
%token NCVARIABLE
%token NONCONTACT
%token NUMERICPARAMETER
%token OFFSETVECTOR
%token OPENSLOTENDTYPE
%token OPTIONALSTOP
%token PARABOLA
%token PARAMETER
%token PARTIALCIRCULARPATH
%token PERSONANDADDRESS
%token PLANARFACE
%token PLANARPOCKETBOTTOMCONDITION
%token PLANE
%token PLANECCSTRATEGY
%token PLANECLSTRATEGY
%token PLANEFINISHMILLING
%token PLANEROUGHMILLING
%token PLUNGEHELIX
%token PLUNGERAMP
%token PLUNGETOOLAXIS
%token PLUNGEZIGZAG
%token PLUSMINUSVALUE
%token POLYLINE
%token PROCESSMODEL
%token PROCESSMODELLIST
%token PROGRAMSTOP
%token PROJECT
%token RADIUSEDPOCKETBOTTOMCONDITION
%token RADIUSEDSLOTENDTYPE
%token RAPID
%token RAPIDMOVEMENT
%token REAMING
%token RECTANGULARCLOSEDPROFILE
%token RECTANGULAROFFSET
%token RECTANGULAROMIT
%token RECTANGULARPATTERN
%token REGIONPROJECTION
%token RIGHT
%token RIGHTCIRCULARCYLINDER
%token ROUNDEDUPROFILE
%token ROUNDHOLE
%token SETMARK
%token SETUP
%token SETUPINSTRUCTION
%token SHAFT
%token SIDEFINISHMILLING
%token SIDEROUGHMILLING
%token SLOT
%token SPHERICALCAP
%token SPHERICALHOLEBOTTOM
%token SPHERICALSURFACE
%token SQUAREUPROFILE
%token STEP
%token STRAIGHTLINE
%token TAPEREDENDMILL
%token TAPEREDREAMER
%token TAPPING
%token TCP
%token THREADDRILLING
%token THREEAXES
%token THROUGHBOTTOMCONDITION
%token THROUGHPOCKETBOTTOMCONDITION
%token TOLERANCEDLENGTHMEASURE
%token TOLERANCES
%token TOOLPATHFEATURE
%token TOOLPATHLIST
%token TOOLPROBING
%token TOUCHPROBE
%token TRAJECTORYPATH
%token TRIMMEDCURVE
%token TRUE
%token TWISTDRILL
%token TWOAXES
%token UNIDIRECTIONALMILLING
%token UNKNOWN
%token UNLOADTOOL
%token UNSPECIFIED
%token UVSTRATEGY
%token VECTOR
%token VEEPROFILE
%token WAITFORMARK
%token WOODRUFFSLOTENDTYPE
%token WORKPIECE
%token WORKPIECECOMPLETEPROBING
%token WORKPIECEPROBING
%token WORKPIECESETUP
%token WORKPLAN
%token ZIGZAG
%token <sval> CHARSTRING
%token <ival> INTSTRING
%token <rval> REALSTRING

%token BAD
%token COLON
%token DOLLAR
%token EQUALS
%token LBOX
%token LPAREN
%token RBOX
%token RPAREN
%token SEMICOLON
%token SHARP
%token SLASH

%start inputFile

%%

inputFile :
	  fileStart headerSection dataSection fileEnd
	    { $$ = new inputFile($1, $2, $3, $4);
	      tree = $$; }
	;

dataSection :
	  dataStarter instanceList endSection
	    { $$ = new dataSection($1, $2, $3); }
	;

dataStarter :
	  DATA SEMICOLON
	    { $$ = new dataStarter(); }
	;

endSection :
	  ENDSEC SEMICOLON
	    { $$ = new endSection(); }
	;

fileDescription :
	  FILEDESCRIPTION LPAREN parenStringListFull C CHARSTRING RPAREN SEMICOLON
	    { $$ = new fileDescription($3, $5); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileEnd :
	  FILEEND SEMICOLON
	    { $$ = new fileEnd(); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileName :
	  FILENAME LPAREN CHARSTRING C CHARSTRING C parenStringListFull C parenStringListFull C CHARSTRING C CHARSTRING C CHARSTRING RPAREN SEMICOLON
	    { $$ = new fileName($3, $5, $7, $9, $11, $13, $15); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileSchema :
	  FILESCHEMA LPAREN parenStringList RPAREN SEMICOLON
	    { $$ = new fileSchema($3); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileStart :
	  FILESTART SEMICOLON
	    { $$ = new fileStart(); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

headerSection :
	  headerStarter fileDescription fileName fileSchema endSection
	    { $$ = new headerSection($1, $2, $3, $4, $5); }
	;

headerStarter :
	  HEADER SEMICOLON
	    { $$ = new headerStarter(); }
	;

instanceId :
	  SHARP INTSTRING
	    { $$ = new instanceId($2); }
	;

instanceList :
	  instancePlus
	    { $$ = new std::list<instance *>;
	      $$->push_back($1); }
	| instanceList instancePlus
	    { $$ = $1;
	      $$->push_back($2); }
	;

instancePlus :
	  instanceId EQUALS instance SEMICOLON
	    { int n;
	      $$ = $3;
	      $3->set_id($1);
	      n = $1->get_val();
	      if (n < INSTANCEMAX)
		{
		  if (instances[n])
		    {
		      fprintf(report, "instance id %d reused\n", n);
		      numErrors++;
		    }
		  else
		    instances[n] = $$;
		}
	      else
		{
		  fprintf(report, "instance id %d is too large\n", n);
		  numErrors++;
		}
	    }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

optReal :
	  real
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

parenRealListFull :
	  LPAREN realList RPAREN
	    { $$ = new parenRealListFull($2); }
	;

parenStringList :
	  LPAREN stringList RPAREN
	    { $$ = new parenStringList($2); }
	| LPAREN RPAREN
	    { $$ = new parenStringList(new std::list<char *>); }
	;

parenStringListFull :
	  LPAREN stringList RPAREN
	    { $$ = new parenStringListFull($2); }
	;

real :
	  REALSTRING
	    { $$ = new real($1); }
	;

realList :
	  real
	    { $$ = new std::list<real *>;
	      $$->push_back($1); }
	| realList C real
	    { $$ = $1;
	      $$->push_back($3); }
	;

stringList :
	  CHARSTRING
	    { $$ = new std::list<char *>;
	      $$->push_back($1); }
	| stringList C CHARSTRING
	    { $$ = $1;
	      $$->push_back($3); }
	;

instance :
	  angleTaper
	    { $$ = $1; }
	| approval
	    { $$ = $1; }
	| approvalStatus
	    { $$ = $1; }
	| axis1placement
	    { $$ = $1; }
	| axis2placement3d
	    { $$ = $1; }
	| backBoring
	    { $$ = $1; }
	| backsideCounterbore
	    { $$ = $1; }
	| backsideCountersink
	    { $$ = $1; }
	| ballEndmill
	    { $$ = $1; }
	| bidirectionalMilling
	    { $$ = $1; }
	| block
	    { $$ = $1; }
	| boring
	    { $$ = $1; }
	| boss
	    { $$ = $1; }
	| bottomAndSideFinishMilling
	    { $$ = $1; }
	| bottomAndSideRoughMilling
	    { $$ = $1; }
	| bullnoseEndmill
	    { $$ = $1; }
	| calendarDate
	    { $$ = $1; }
	| cartesianPoint
	    { $$ = $1; }
	| centerDrill
	    { $$ = $1; }
	| centerDrilling
	    { $$ = $1; }
	| chamfer
	    { $$ = $1; }
	| channel
	    { $$ = $1; }
	| circle
	    { $$ = $1; }
	| circularOffset
	    { $$ = $1; }
	| circularOmit
	    { $$ = $1; }
	| circularPattern
	    { $$ = $1; }
	| closedPocket
	    { $$ = $1; }
	| combinedDrillAndReamer
	    { $$ = $1; }
	| completeCircularPath
	    { $$ = $1; }
	| compositeCurve
	    { $$ = $1; }
	| compositeCurveSegment
	    { $$ = $1; }
	| conicalHoleBottom
	    { $$ = $1; }
	| contourParallel
	    { $$ = $1; }
	| counterbore
	    { $$ = $1; }
	| counterboreHole
	    { $$ = $1; }
	| countersink
	    { $$ = $1; }
	| counterSinking
	    { $$ = $1; }
	| countersunkHole
	    { $$ = $1; }
	| cutterLocationTrajectory
	    { $$ = $1; }
	| cuttingComponent
	    { $$ = $1; }
	| cuttingEdgeTechnologicalData
	    { $$ = $1; }
	| dateAndTime
	    { $$ = $1; }
	| descriptiveParameter
	    { $$ = $1; }
	| diameterTaper
	    { $$ = $1; }
	| displayMessage
	    { $$ = $1; }
	| drilling
	    { $$ = $1; }
	| drillingTypeStrategy
	    { $$ = $1; }
	| direction
	    { $$ = $1; }
	| edgeRound
	    { $$ = $1; }
	| ellipse
	    { $$ = $1; }
	| exchangePallet
	    { $$ = $1; }
	| feedstop
	    { $$ = $1; }
	| facemill
	    { $$ = $1; }
	| flatHoleBottom
	    { $$ = $1; }
	| flatSlotEndType
	    { $$ = $1; }
	| flatWithRadiusHoleBottom
	    { $$ = $1; }
	| freeformOperation
	    { $$ = $1; }
	| generalPath
	    { $$ = $1; }
	| generalPattern
	    { $$ = $1; }
	| generalPocketBottomCondition
	    { $$ = $1; }
	| helix
	    { $$ = $1; }
	| hyperbola
	    { $$ = $1; }
	| indexPallet
	    { $$ = $1; }
	| indexTable
	    { $$ = $1; }
	| leadingLineStrategy
	    { $$ = $1; }
	| limitsAndFits
	    { $$ = $1; }
	| line
	    { $$ = $1; }
	| linearPath
	    { $$ = $1; }
	| linearProfile
	    { $$ = $1; }
	| loadTool
	    { $$ = $1; }
	| loopSlotEndType
	    { $$ = $1; }
	| machiningWorkingstep
	    { $$ = $1; }
	| material
	    { $$ = $1; }
	| millingCuttingTool
	    { $$ = $1; }
	| millingMachineFunctions
	    { $$ = $1; }
	| millingTechnology
	    { $$ = $1; }
	| millingToolDimension
	    { $$ = $1; }
	| multistepDrilling
	    { $$ = $1; }
	| ncVariable
	    { $$ = $1; }
	| numericParameter
	    { $$ = $1; }
	| openSlotEndType
	    { $$ = $1; }
	| optionalStop
	    { $$ = $1; }
	| parabola
	    { $$ = $1; }
	| partialCircularPath
	    { $$ = $1; }
	| personAndAddress
	    { $$ = $1; }
	| planarFace
	    { $$ = $1; }
	| planarPocketBottomCondition
	    { $$ = $1; }
	| plane
	    { $$ = $1; }
	| planeCcStrategy
	    { $$ = $1; }
	| planeClStrategy
	    { $$ = $1; }
	| planeFinishMilling
	    { $$ = $1; }
	| planeRoughMilling
	    { $$ = $1; }
	| plungeHelix
	    { $$ = $1; }
	| plungeRamp
	    { $$ = $1; }
	| plungeToolaxis
	    { $$ = $1; }
	| plungeZigzag
	    { $$ = $1; }
	| plusMinusValue
	    { $$ = $1; }
	| polyline
	    { $$ = $1; }
	| processModel
	    { $$ = $1; }
	| processModelList
	    { $$ = $1; }
	| programStop
	    { $$ = $1; }
	| project
	    { $$ = $1; }
	| radiusedPocketBottomCondition
	    { $$ = $1; }
	| radiusedSlotEndType
	    { $$ = $1; }
	| rapidMovement
	    { $$ = $1; }
	| reaming
	    { $$ = $1; }
	| rectangularClosedProfile
	    { $$ = $1; }
	| rectangularPattern
	    { $$ = $1; }
	| rectangularOffset
	    { $$ = $1; }
	| rectangularOmit
	    { $$ = $1; }
	| regionProjection
	    { $$ = $1; }
	| rightCircularCylinder
	    { $$ = $1; }
	| roundedUProfile
	    { $$ = $1; }
	| roundHole
	    { $$ = $1; }
	| setMark
	    { $$ = $1; }
	| setup
	    { $$ = $1; }
	| setupInstruction
	    { $$ = $1; }
	| sideFinishMilling
	    { $$ = $1; }
	| sideRoughMilling
	    { $$ = $1; }
	| slot
	    { $$ = $1; }
	| sphericalCap
	    { $$ = $1; }
	| sphericalHoleBottom
	    { $$ = $1; }
	| sphericalSurface
	    { $$ = $1; }
	| squareUProfile
	    { $$ = $1; }
	| step
	    { $$ = $1; }
	| taperedEndmill
	    { $$ = $1; }
	| taperedReamer
	    { $$ = $1; }
	| tapping
	    { $$ = $1; }
	| threadDrilling
	    { $$ = $1; }
	| threeAxes
	    { $$ = $1; }
	| throughBottomCondition
	    { $$ = $1; }
	| throughPocketBottomCondition
	    { $$ = $1; }
	| tolerancedLengthMeasure
	    { $$ = $1; }
	| tolerances
	    { $$ = $1; }
	| toolpathFeature
	    { $$ = $1; }
	| toolpathList
	    { $$ = $1; }
	| toolProbing
	    { $$ = $1; }
	| touchProbe
	    { $$ = $1; }
	| trimmedCurve
	    { $$ = $1; }
	| twistDrill
	    { $$ = $1; }
	| twoAxes
	    { $$ = $1; }
	| unidirectionalMilling
	    { $$ = $1; }
	| unloadTool
	    { $$ = $1; }
	| uvStrategy
	    { $$ = $1; }
	| vector
	    { $$ = $1; }
	| veeProfile
	    { $$ = $1; }
	| waitForMark
	    { $$ = $1; }
	| woodruffSlotEndType
	    { $$ = $1; }
	| workpiece
	    { $$ = $1; }
	| workpieceCompleteProbing
	    { $$ = $1; }
	| workpieceProbing
	    { $$ = $1; }
	| workpieceSetup
	    { $$ = $1; }
	| workplan
	    { $$ = $1; }
	;

advancedBrepShapeRepresentation :
	  ADVANCEDBREPSHAPEREPRESENTATION LPAREN RPAREN
	    { $$ = new advancedBrepShapeRepresentation(); }
	;

angleTaper :
	  ANGLETAPER LPAREN real RPAREN
	    { $$ = new angleTaper($3); }
	;

approach :
	  APPROACH
	    { $$ = new approach(); }
	;

approval :
	  APPROVAL LPAREN instanceId C CHARSTRING RPAREN
	    { $$ = new approval(0, $5);
	      approvalStatus_refs.push_back(&($$->status));
	      approvalStatus_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

approvalStatus :
	  APPROVALSTATUS LPAREN CHARSTRING RPAREN
	    { $$ = new approvalStatus($3); }
	;

axis1placement :
	  AXIS1PLACEMENT LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new axis1placement($3, 0, 0);
	      cartesianPoint_refs.push_back(&($$->location));
	      cartesianPoint_nums.push_back($5->get_val());
	      delete $5;
	      direction_refs.push_back(&($$->axis));
	      direction_nums.push_back($7->get_val());
	      delete $7;
	    }
	;

axis2placement3d :
	  AXIS2PLACEMENT3D LPAREN CHARSTRING C instanceId C instanceId C optDirection RPAREN
	    { $$ = new axis2placement3d($3, 0, 0, $9);
	      cartesianPoint_refs.push_back(&($$->location));
	      cartesianPoint_nums.push_back($5->get_val());
	      delete $5;
	      direction_refs.push_back(&($$->axis));
	      direction_nums.push_back($7->get_val());
	      delete $7;
	      if ($9)
		{
		  $$->set_refDirection(0);
		  direction_refs.push_back(&($$->refDirection));
		  direction_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	    }
	;

axis2placement3dList :
	  instanceId
	    { $$ = new std::list<axis2placement3d *>;
	      $$->push_back(0);
	      axis2placement3d_refs.push_back(&($$->back()));
	      axis2placement3d_nums.push_back($1->get_val());
	    }
	| axis2placement3dList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      axis2placement3d_refs.push_back(&($$->back()));
	      axis2placement3d_nums.push_back($3->get_val());
	    }
	;

backBoring :
	  BACKBORING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new backBoring($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

backsideCounterbore :
	  BACKSIDECOUNTERBORE LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new backsideCounterbore(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

backsideCountersink :
	  BACKSIDECOUNTERSINK LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new backsideCountersink(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

ballEndmill :
	  BALLENDMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new ballEndmill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

bidirectionalMilling :
	  BIDIRECTIONALMILLING LPAREN optReal C optBoolean C optDirection C optLeftOrRight C optStrokeConnectionStrategy RPAREN
	    { $$ = new bidirectionalMilling($3, $5, $7, $9, $11);
	      if ($7)
		{
		  $$->set_feedDirection(0);
		  direction_refs.push_back(&($$->feedDirection));
		  direction_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	    }
	;

block :
	  BLOCK LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING C REALSTRING RPAREN
	    { $$ = new block($3, 0, $7, $9, $11);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

boolean :
	  booleanTrue
	    { $$ = $1; }
	| booleanFalse
	    { $$ = $1; }
	;

booleanTrue :
	  TRUE
	    { $$ = new booleanTrue(); }
	;

booleanFalse :
	  FALSE
	    { $$ = new booleanFalse(); }
	;

boring :
	  BORING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy C boolean C optReal C optCartesianPoint RPAREN
	    { $$ = new boring($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33, $35);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	      if ($35)
		{
		  $$->set_waitingPosition(0);
		  cartesianPoint_refs.push_back(&($$->waitingPosition));
		  cartesianPoint_nums.push_back($35->get_id()->get_val());
		  delete $35->get_id();
		  delete $35;
		}
	    }
	;

boss :
	  BOSS LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optReal RPAREN
	    { $$ = new boss($3, 0, $7, 0, 0, 0, $15);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      closedProfile_refs.push_back(&($$->itsBoundary));
	      closedProfile_nums.push_back($13->get_val());
	      delete $13;
	    }
	;

bossList :
	  instanceId
	    { $$ = new std::list<boss *>;
	      $$->push_back(0);
	      boss_refs.push_back(&($$->back()));
	      boss_nums.push_back($1->get_val());
	    }
	| bossList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      boss_refs.push_back(&($$->back()));
	      boss_nums.push_back($3->get_val());
	    }
	;

bottomAndSideFinishMilling :
	  BOTTOMANDSIDEFINISHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new bottomAndSideFinishMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

bottomAndSideRoughMilling :
	  BOTTOMANDSIDEROUGHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new bottomAndSideRoughMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

bullnoseEndmill :
	  BULLNOSEENDMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new bullnoseEndmill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

calendarDate :
	  CALENDARDATE LPAREN INTSTRING C INTSTRING C INTSTRING RPAREN
	    { $$ = new calendarDate($3, $5, $7); }
	;

cartesian :
	  CARTESIAN
	    { $$ = new cartesian(); }
	;

cartesianPoint :
	  CARTESIANPOINT LPAREN CHARSTRING C parenRealListFull RPAREN
	    { $$ = new cartesianPoint($3, $5); }
	;

cartesianPointList :
	  instanceId
	    { $$ = new std::list<cartesianPoint *>;
	      $$->push_back(0);
	      cartesianPoint_refs.push_back(&($$->back()));
	      cartesianPoint_nums.push_back($1->get_val());
	    }
	| cartesianPointList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      cartesianPoint_refs.push_back(&($$->back()));
	      cartesianPoint_nums.push_back($3->get_val());
	    }
	;

centerDrill :
	  CENTERDRILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new centerDrill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

centerDrilling :
	  CENTERDRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new centerDrilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

chamfer :
	  CHAMFER LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C REALSTRING C instanceId RPAREN
	    { $$ = new chamfer($3, 0, $7, 0, 0, $13, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      machiningFeature_refs.push_back(&($$->firstFeature));
	      machiningFeature_nums.push_back($9->get_val());
	      delete $9;
	      machiningFeature_refs.push_back(&($$->secondFeature));
	      machiningFeature_nums.push_back($11->get_val());
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->firstOffsetAmount));
	      tolerancedLengthMeasure_nums.push_back($15->get_val());
	      delete $15;
	    }
	;

channel :
	  CHANNEL LPAREN CHARSTRING RPAREN
	    { $$ = new channel($3); }
	;

circle :
	  CIRCLE LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new circle($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

circularOffset :
	  CIRCULAROFFSET LPAREN REALSTRING C INTSTRING RPAREN
	    { $$ = new circularOffset($3, $5); }
	;

circularOmit :
	  CIRCULAROMIT LPAREN INTSTRING RPAREN
	    { $$ = new circularOmit($3); }
	;

circularOffsetList :
	  instanceId
	    { $$ = new std::list<circularOffset *>;
	      $$->push_back(0);
	      circularOffset_refs.push_back(&($$->back()));
	      circularOffset_nums.push_back($1->get_val());
	    }
	| circularOffsetList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      circularOffset_refs.push_back(&($$->back()));
	      circularOffset_nums.push_back($3->get_val());
	    }
	;

circularOmitList :
	  instanceId
	    { $$ = new std::list<circularOmit *>;
	      $$->push_back(0);
	      circularOmit_refs.push_back(&($$->back()));
	      circularOmit_nums.push_back($1->get_val());
	    }
	| circularOmitList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      circularOmit_refs.push_back(&($$->back()));
	      circularOmit_nums.push_back($3->get_val());
	    }
	;

circularPattern :
	  CIRCULARPATTERN LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C REALSTRING C INTSTRING C parenCircularOffsetList C parenCircularOmitList C optTolerancedLengthMeasure C REALSTRING RPAREN
	    { $$ = new circularPattern($3, 0, $7, 0, 0, $13, $15, $17, $19, $21, $23);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      two5DmanufacturingFeature_refs.push_back(&($$->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back($11->get_val());
	      delete $11;
	      if ($21)
		{
		  $$->set_baseFeatureDiameter(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->baseFeatureDiameter));
		  tolerancedLengthMeasure_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	    }
	;

closedPocket :
	  CLOSEDPOCKET LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C parenBossList C optReal C instanceId C optTolerancedLengthMeasure C optTolerancedLengthMeasure C instanceId RPAREN
	    { $$ = new closedPocket($3, 0, $7, 0, 0, $13, $15, 0, $19, $21, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      pocketBottomCondition_refs.push_back(&($$->bottomCondition));
	      pocketBottomCondition_nums.push_back($17->get_val());
	      delete $17;
	      if ($19)
		{
		  $$->set_planarRadius(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->planarRadius));
		  tolerancedLengthMeasure_nums.push_back($19->get_id()->get_val());
		  delete $19->get_id();
		  delete $19;
		}
	      if ($21)
		{
		  $$->set_orthogonalRadius(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->orthogonalRadius));
		  tolerancedLengthMeasure_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      closedProfile_refs.push_back(&($$->featureBoundary));
	      closedProfile_nums.push_back($23->get_val());
	      delete $23;
	    }
	;

combinedDrillAndReamer :
	  COMBINEDDRILLANDREAMER LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new combinedDrillAndReamer(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

completeCircularPath :
	  COMPLETECIRCULARPATH LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new completeCircularPath($3, 0);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

compositeCurve :
	  COMPOSITECURVE LPAREN CHARSTRING C parenCompositeCurveSegmentListFull C logical RPAREN
	    { $$ = new compositeCurve($3, $5, $7); }
	;

compositeCurveSegment :
	  COMPOSITECURVESEGMENT LPAREN transitionCode C boolean C instanceId RPAREN
	    { $$ = new compositeCurveSegment($3, $5, 0);
	      curve_refs.push_back(&($$->parentCurve));
	      curve_nums.push_back($7->get_val());
	      delete $7;
	    }
	;

compositeCurveSegmentList :
	  instanceId
	    { $$ = new std::list<compositeCurveSegment *>;
	      $$->push_back(0);
	      compositeCurveSegment_refs.push_back(&($$->back()));
	      compositeCurveSegment_nums.push_back($1->get_val());
	    }
	| compositeCurveSegmentList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      compositeCurveSegment_refs.push_back(&($$->back()));
	      compositeCurveSegment_nums.push_back($3->get_val());
	    }
	;

compoundFeatureSelectList :
	  instanceId
	    { $$ = new std::list<compoundFeatureSelect *>;
	      $$->push_back(0);
	      compoundFeatureSelect_refs.push_back(&($$->back()));
	      compoundFeatureSelect_nums.push_back($1->get_val());
	    }
	| compoundFeatureSelectList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      compoundFeatureSelect_refs.push_back(&($$->back()));
	      compoundFeatureSelect_nums.push_back($3->get_val());
	    }
	;

conicalHoleBottom :
	  CONICALHOLEBOTTOM LPAREN real C optTolerancedLengthMeasure RPAREN
	    { $$ = new conicalHoleBottom($3, $5);
	      if ($5)
		{
		  $$->set_tipRadius(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->tipRadius));
		  tolerancedLengthMeasure_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	    }
	;

connect :
	  CONNECT
	    { $$ = new connect(); }
	;

contact :
	  CONTACT
	    { $$ = new contact(); }
	;

continuous :
	  CONTINUOUS
	    { $$ = new continuous(); }
	;

contSameGradient :
	  CONTSAMEGRADIENT
	    { $$ = new contSameGradient(); }
	;

contSameGradientSameCurvature :
	  CONTSAMEGRADIENTSAMECURVATURE
	    { $$ = new contSameGradientSameCurvature(); }
	;

contourParallel :
	  CONTOURPARALLEL LPAREN optReal C optBoolean C rotDirection C optCutmodeType RPAREN
	    { $$ = new contourParallel($3, $5, $7, $9); }
	;

counterbore :
	  COUNTERBORE LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new counterbore(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

counterboreHole :
	  COUNTERBOREHOLE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C parenCompoundFeatureSelectListFull RPAREN
	    { $$ = new counterboreHole($3, 0, $7, 0, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	    }
	;

countersink :
	  COUNTERSINK LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new countersink(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

counterSinking :
	  COUNTERSINKING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new counterSinking($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

countersunkHole :
	  COUNTERSUNKHOLE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C parenCompoundFeatureSelectListFull RPAREN
	    { $$ = new countersunkHole($3, 0, $7, 0, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	    }
	;

cutmodeType :
	  cutmodeTypeClimb
	    { $$ = $1; }
	| cutmodeTypeConventional
	    { $$ = $1; }
	;

cutmodeTypeClimb :
	  CLIMB
	    { $$ = new cutmodeTypeClimb(); }
	;

cutmodeTypeConventional :
	  CONVENTIONAL
	    { $$ = new cutmodeTypeConventional(); }
	;

cutterLocationTrajectory :
	  CUTTERLOCATIONTRAJECTORY LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C optBoolean C instanceId C optBoundedCurve C optBoundedCurve RPAREN
	    { $$ = new cutterLocationTrajectory($3, $5, $7, $9, $11, $13, 0, $17, $19);
	      if ($9)
		{
		  $$->set_itsTechnology(0);
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      if ($11)
		{
		  $$->set_itsMachineFunctions(0);
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      boundedCurve_refs.push_back(&($$->basiccurve));
	      boundedCurve_nums.push_back($15->get_val());
	      delete $15;
	      if ($17)
		{
		  $$->set_itsToolaxis(0);
		  boundedCurve_refs.push_back(&($$->itsToolaxis));
		  boundedCurve_nums.push_back($17->get_id()->get_val());
		  delete $17->get_id();
		  delete $17;
		}
	      if ($19)
		{
		  $$->set_surfaceNormal(0);
		  boundedCurve_refs.push_back(&($$->surfaceNormal));
		  boundedCurve_nums.push_back($19->get_id()->get_val());
		  delete $19->get_id();
		  delete $19;
		}
	    }
	;

cuttingComponent :
	  CUTTINGCOMPONENT LPAREN REALSTRING C optMaterial C optCuttingEdgeTechnologicalData C optReal C optMillingTechnology RPAREN
	    { $$ = new cuttingComponent($3, $5, $7, $9, $11);
	      if ($5)
		{
		  $$->set_itsMaterial(0);
		  material_refs.push_back(&($$->itsMaterial));
		  material_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($7)
		{
		  $$->set_technologicalData(0);
		  cuttingEdgeTechnologicalData_refs.push_back(&($$->technologicalData));
		  cuttingEdgeTechnologicalData_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	      if ($11)
		{
		  $$->set_itsTechnology(0);
		  millingTechnology_refs.push_back(&($$->itsTechnology));
		  millingTechnology_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	    }
	;

cuttingComponentList :
	  instanceId
	    { $$ = new std::list<cuttingComponent *>;
	      $$->push_back(0);
	      cuttingComponent_refs.push_back(&($$->back()));
	      cuttingComponent_nums.push_back($1->get_val());
	    }
	| cuttingComponentList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      cuttingComponent_refs.push_back(&($$->back()));
	      cuttingComponent_nums.push_back($3->get_val());
	    }
	;

cuttingEdgeTechnologicalData :
	  CUTTINGEDGETECHNOLOGICALDATA LPAREN optReal C optReal C optReal RPAREN
	    { $$ = new cuttingEdgeTechnologicalData($3, $5, $7); }
	;

dateAndTime :
	  DATEANDTIME LPAREN instanceId C CHARSTRING RPAREN
	    { $$ = new dateAndTime(0, $5);
	      date_refs.push_back(&($$->dateComponent));
	      date_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

degouge :
	  DEGOUGE
	    { $$ = new degouge(); }
	;

descriptiveParameter :
	  DESCRIPTIVEPARAMETER LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new descriptiveParameter($3, $5); }
	;

diameterTaper :
	  DIAMETERTAPER LPAREN instanceId RPAREN
	    { $$ = new diameterTaper(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->finalDiameter));
	      tolerancedLengthMeasure_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

direction :
	  DIRECTION LPAREN CHARSTRING C parenRealListFull RPAREN
	    { $$ = new direction($3, $5); }
	;

discontinuous :
	  DISCONTINUOUS
	    { $$ = new discontinuous(); }
	;

displayMessage :
	  DISPLAYMESSAGE LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new displayMessage($3, $5); }
	;

drilling :
	  DRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new drilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

drillingTypeStrategy :
	  DRILLINGTYPESTRATEGY LPAREN optReal C optReal C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new drillingTypeStrategy($3, $5, $7, $9, $11, $13); }
	;

edgeRound :
	  EDGEROUND LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optTolerancedLengthMeasure C optTolerancedLengthMeasure RPAREN
	    { $$ = new edgeRound($3, 0, $7, 0, 0, 0, $15, $17);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      machiningFeature_refs.push_back(&($$->firstFeature));
	      machiningFeature_nums.push_back($9->get_val());
	      delete $9;
	      machiningFeature_refs.push_back(&($$->secondFeature));
	      machiningFeature_nums.push_back($11->get_val());
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($13->get_val());
	      delete $13;
	      if ($15)
		{
		  $$->set_firstOffsetAmount(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->firstOffsetAmount));
		  tolerancedLengthMeasure_nums.push_back($15->get_id()->get_val());
		  delete $15->get_id();
		  delete $15;
		}
	      if ($17)
		{
		  $$->set_secondOffsetAmount(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->secondOffsetAmount));
		  tolerancedLengthMeasure_nums.push_back($17->get_id()->get_val());
		  delete $17->get_id();
		  delete $17;
		}
	    }
	;

ellipse :
	  ELLIPSE LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new ellipse($3, 0, $7, $9);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

exchangePallet :
	  EXCHANGEPALLET LPAREN CHARSTRING RPAREN
	    { $$ = new exchangePallet($3); }
	;

executableList :
	  instanceId
	    { $$ = new std::list<executable *>;
	      $$->push_back(0);
	      executable_refs.push_back(&($$->back()));
	      executable_nums.push_back($1->get_val());
	    }
	| executableList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      executable_refs.push_back(&($$->back()));
	      executable_nums.push_back($3->get_val());
	    }
	;

facemill :
	  FACEMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new facemill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

feedstop :
	  FEEDSTOP LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C REALSTRING RPAREN
	    { $$ = new feedstop($3, $5, $7, $9, $11, $13);
	      if ($9)
		{
		  $$->set_itsTechnology(0);
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      if ($11)
		{
		  $$->set_itsMachineFunctions(0);
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	    }
	;

fittingType :
	  fittingTypeShaft
	    { $$ = $1; }
	| fittingTypeHole
	    { $$ = $1; }
	;

fittingTypeHole :
	  HOLE
	    { $$ = new fittingTypeHole(); }
	;

fittingTypeShaft :
	  SHAFT
	    { $$ = new fittingTypeShaft(); }
	;

flatHoleBottom :
	  FLATHOLEBOTTOM LPAREN RPAREN
	    { $$ = new flatHoleBottom(); }
	;

flatSlotEndType :
	  FLATSLOTENDTYPE LPAREN instanceId C instanceId RPAREN
	    { $$ = new flatSlotEndType(0, 0);
	      tolerancedLengthMeasure_refs.push_back(&($$->cornerRadius1));
	      tolerancedLengthMeasure_nums.push_back($3->get_val());
	      delete $3;
	      tolerancedLengthMeasure_refs.push_back(&($$->cornerRadius2));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

flatWithRadiusHoleBottom :
	  FLATWITHRADIUSHOLEBOTTOM LPAREN instanceId RPAREN
	    { $$ = new flatWithRadiusHoleBottom(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->cornerRadius));
	      tolerancedLengthMeasure_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

freeformOperation :
	  FREEFORMOPERATION LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optFreeformStrategy RPAREN
	    { $$ = new freeformOperation($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  freeformStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  freeformStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

generalPath :
	  GENERALPATH LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new generalPath($3, 0);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      boundedCurve_refs.push_back(&($$->sweptPath));
	      boundedCurve_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

generalPattern :
	  GENERALPATTERN LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C parenAxis2placement3dListFull RPAREN
	    { $$ = new generalPattern($3, 0, $7, 0, 0, $13);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      two5DmanufacturingFeature_refs.push_back(&($$->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back($11->get_val());
	      delete $11;
	    }
	;

generalPocketBottomCondition :
	  GENERALPOCKETBOTTOMCONDITION LPAREN instanceId RPAREN
	    { $$ = new generalPocketBottomCondition(0);
	      region_refs.push_back(&($$->shape));
	      region_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

hand :
	  handRight
	    { $$ = $1; }
	| handLeft
	    { $$ = $1; }
	;

handRight :
	  RIGHT
	    { $$ = new handRight(); }
	;

handLeft :
	  LEFT
	    { $$ = new handLeft(); }
	;

helix :
	  HELIX LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new helix($3, 0, $7, $9);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

hyperbola :
	  HYPERBOLA LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new hyperbola($3, 0, $7, $9);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

indexPallet :
	  INDEXPALLET LPAREN CHARSTRING C INTSTRING RPAREN
	    { $$ = new indexPallet($3, $5); }
	;

indexTable :
	  INDEXTABLE LPAREN CHARSTRING C INTSTRING RPAREN
	    { $$ = new indexTable($3, $5); }
	;

inProcessGeometry :
	  INPROCESSGEOMETRY LPAREN optAdvancedBrepShapeRepresentation C optAdvancedBrepShapeRepresentation C optAdvancedBrepShapeRepresentation RPAREN
	    { $$ = new inProcessGeometry($3, $5, $7); }
	;

integer :
	  INTSTRING
	    { $$ = new integer($1); }
	;

leadingLineStrategy :
	  LEADINGLINESTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId RPAREN
	    { $$ = new leadingLineStrategy($3, $5, 0, $9, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->get_val());
	      delete $7;
	      boundedCurve_refs.push_back(&($$->itsLine));
	      boundedCurve_nums.push_back($11->get_val());
	      delete $11;
	    }
	;

leftOrRight :
	  leftOrRightLeft
	    { $$ = $1; }
	| leftOrRightRight
	    { $$ = $1; }
	;

leftOrRightLeft :
	  LEFT
	    { $$ = new leftOrRightLeft(); }
	;

leftOrRightRight :
	  RIGHT
	    { $$ = new leftOrRightRight(); }
	;

lift :
	  LIFT
	    { $$ = new lift(); }
	;

liftShiftPlunge :
	  LIFTSHIFTPLUNGE
	    { $$ = new liftShiftPlunge(); }
	;

limitsAndFits :
	  LIMITSANDFITS LPAREN REALSTRING C REALSTRING C optFittingType RPAREN
	    { $$ = new limitsAndFits($3, $5, $7); }
	;

line :
	  LINE LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new line($3, 0, 0);
	      cartesianPoint_refs.push_back(&($$->pnt));
	      cartesianPoint_nums.push_back($5->get_val());
	      delete $5;
	      vector_refs.push_back(&($$->dir));
	      vector_nums.push_back($7->get_val());
	      delete $7;
	    }
	;

linearPath :
	  LINEARPATH LPAREN optAxis2placement3d C instanceId C instanceId RPAREN
	    { $$ = new linearPath($3, 0, 0);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->distance));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	      direction_refs.push_back(&($$->itsDirection));
	      direction_nums.push_back($7->get_val());
	      delete $7;
	    }
	;

linearProfile :
	  LINEARPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new linearProfile($3, 0);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      numericParameter_refs.push_back(&($$->profileLength));
	      numericParameter_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

loadTool :
	  LOADTOOL LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new loadTool($3, 0);
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

logical :
	  booleanTrue
	    { $$ = $1; }
	| booleanFalse
	    { $$ = $1; }
	| logicalUnknown
	    { $$ = $1; }
	;

logicalUnknown :
	  UNKNOWN
	    { $$ = new logicalUnknown(); }
	;

loopBack :
	  LOOPBACK
	    { $$ = new loopBack(); }
	;

loopSlotEndType :
	  LOOPSLOTENDTYPE LPAREN RPAREN
	    { $$ = new loopSlotEndType(); }
	;

machiningOperationList :
	  instanceId
	    { $$ = new std::list<machiningOperation *>;
	      $$->push_back(0);
	      machiningOperation_refs.push_back(&($$->back()));
	      machiningOperation_nums.push_back($1->get_val());
	    }
	| machiningOperationList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      machiningOperation_refs.push_back(&($$->back()));
	      machiningOperation_nums.push_back($3->get_val());
	    }
	;

machiningWorkingstep :
	  MACHININGWORKINGSTEP LPAREN CHARSTRING C instanceId C instanceId C instanceId C optInProcessGeometry RPAREN
	    { $$ = new machiningWorkingstep($3, 0, 0, 0, $11);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->get_val());
	      delete $5;
	      manufacturingFeature_refs.push_back(&($$->itsFeature));
	      manufacturingFeature_nums.push_back($7->get_val());
	      delete $7;
	      machiningOperation_refs.push_back(&($$->itsOperation));
	      machiningOperation_nums.push_back($9->get_val());
	      delete $9;
	    }
	;

material :
	  MATERIAL LPAREN CHARSTRING C CHARSTRING C parenPropertyParameterList RPAREN
	    { $$ = new material($3, $5, $7); }
	;

millingCuttingTool :
	  MILLINGCUTTINGTOOL LPAREN CHARSTRING C instanceId C parenCuttingComponentListFull C optReal C optDirection C optReal RPAREN
	    { $$ = new millingCuttingTool($3, 0, $7, $9, $11, $13);
	      toolBody_refs.push_back(&($$->itsToolBody));
	      toolBody_nums.push_back($5->get_val());
	      delete $5;
	      if ($11)
		{
		  $$->set_directionForSpindleOrientation(0);
		  direction_refs.push_back(&($$->directionForSpindleOrientation));
		  direction_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	    }
	;

millingMachineFunctions :
	  MILLINGMACHINEFUNCTIONS LPAREN boolean C optReal C optBoolean C boolean C optReal C parenStringList C boolean C optDirection C optProcessModelList C parenPropertyParameterList RPAREN
	    { $$ = new millingMachineFunctions($3, $5, $7, $9, $11, $13, $15, $17, $19, $21);
	      if ($17)
		{
		  $$->set_orientedSpindleStop(0);
		  direction_refs.push_back(&($$->orientedSpindleStop));
		  direction_nums.push_back($17->get_id()->get_val());
		  delete $17->get_id();
		  delete $17;
		}
	      if ($19)
		{
		  $$->set_itsProcessModel(0);
		  processModelList_refs.push_back(&($$->itsProcessModel));
		  processModelList_nums.push_back($19->get_id()->get_val());
		  delete $19->get_id();
		  delete $19;
		}
	    }
	;

millingTechnology :
	  MILLINGTECHNOLOGY LPAREN optReal C toolReferencePoint C optReal C optReal C optReal C boolean C boolean C boolean C optBoolean RPAREN
	    { $$ = new millingTechnology($3, $5, $7, $9, $11, $13, $15, $17, $19); }
	;

millingToolDimension :
	  MILLINGTOOLDIMENSION LPAREN REALSTRING C optReal C optReal C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new millingToolDimension($3, $5, $7, $9, $11, $13, $15); }
	;

multistepDrilling :
	  MULTISTEPDRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy C REALSTRING C REALSTRING C REALSTRING C optReal RPAREN
	    { $$ = new multistepDrilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33, $35, $37);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

ncVariable :
	  NCVARIABLE LPAREN CHARSTRING C optReal RPAREN
	    { $$ = new ncVariable($3, $5); }
	;

ncVariableList :
	  instanceId
	    { $$ = new std::list<ncVariable *>;
	      $$->push_back(0);
	      ncVariable_refs.push_back(&($$->back()));
	      ncVariable_nums.push_back($1->get_val());
	    }
	| ncVariableList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      ncVariable_refs.push_back(&($$->back()));
	      ncVariable_nums.push_back($3->get_val());
	    }
	;

nonContact :
	  NONCONTACT
	    { $$ = new nonContact(); }
	;

numericParameter :
	  NUMERICPARAMETER LPAREN CHARSTRING C REALSTRING C CHARSTRING RPAREN
	    { $$ = new numericParameter($3, $5, $7); }
	;

offsetVector :
	  OFFSETVECTOR LPAREN parenNcVariableListFull C optParenNcVariableListFull RPAREN
	    { $$ = new offsetVector($3, $5); }
	;

openSlotEndType :
	  OPENSLOTENDTYPE LPAREN RPAREN
	    { $$ = new openSlotEndType(); }
	;

optAdvancedBrepShapeRepresentation :
	  advancedBrepShapeRepresentation
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optApproachRetractStrategy :
	  instanceId
	    { $$ = new plungeHelix(0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optApproval :
	  instanceId
	    { $$ = new approval(0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optAxis2placement3d :
	  instanceId
	    { $$ = new axis2placement3d(0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optBoolean :
	  boolean
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optBoundedCurve :
	  instanceId
	    { $$ = new compositeCurve(0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optBoundingGeometrySelect :
	  instanceId
	    { $$ = new block(0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optCartesianPoint :
	  instanceId
	    { $$ = new cartesianPoint(0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optChannel :
	  instanceId
	    { $$ = new channel(0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optClosedProfile :
	  instanceId
	    { $$ = new rectangularClosedProfile(0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optCutmodeType :
	  cutmodeType
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optCuttingEdgeTechnologicalData :
	  instanceId
	    { $$ = new cuttingEdgeTechnologicalData(0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDateAndTime :
	  instanceId
	    { $$ = new dateAndTime(0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDirection :
	  instanceId
	    { $$ = new direction(0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDrillingTypeStrategy :
	  instanceId
	    { $$ = new drillingTypeStrategy(0,0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optFittingType :
	  fittingType
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optFreeformStrategy :
	  instanceId
	    { $$ = new leadingLineStrategy(0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optHand :
	  hand
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optInProcessGeometry :
	  inProcessGeometry
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optInteger :
	  integer
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optionalStop :
	  OPTIONALSTOP LPAREN CHARSTRING RPAREN
	    { $$ = new optionalStop($3); }
	;

optLeftOrRight :
	  leftOrRight
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optMachineFunctions :
	  instanceId
	    { $$ = new millingMachineFunctions(0,0,0,0,0,0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optMachiningTool :
	  instanceId
	    { $$ = new millingCuttingTool(0,0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optMaterial :
	  instanceId
	    { $$ = new material(0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optMillingTechnology :
	  instanceId
	    { $$ = new millingTechnology(0,0,0,0,0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optOffsetVector :
	  offsetVector
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optParenNcVariableListFull :
	  parenNcVariableListFull
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optPersonAndAddress :
	  instanceId
	    { $$ = new personAndAddress(0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optProcessModelList :
	  instanceId
	    { $$ = new processModelList(0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optRestrictedAreaSelect :
	  instanceId
	    { $$ = new block(0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optSetup :
	  instanceId
	    { $$ = new setup(0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optStrokeConnectionStrategy :
	  strokeConnectionStrategy
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optTaperSelect :
	  instanceId
	    { $$ = new angleTaper(0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optTechnology :
	  instanceId
	    { $$ = new millingTechnology(0,0,0,0,0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optTolerancedLengthMeasure :
	  instanceId
	    { $$ = new tolerancedLengthMeasure(0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optToolDirection :
	  instanceId
	    { $$ = new threeAxes();
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optToolpathList :
	  instanceId
	    { $$ = new toolpathList(0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optToolpathSpeedprofile :
	  toolpathSpeedprofile
	    { $$ = $1 }
	| DOLLAR
	    { $$ = 0; }
	;

optTwo5DmillingStrategy :
	  instanceId
	    { $$ = new bidirectionalMilling(0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optVeeProfile :
	  instanceId
	    { $$ = new veeProfile(0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optWorkpiece :
	  instanceId
	    { $$ = new workpiece(0,0,0,0,0,0,0);
	      $$->set_id($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

parabola :
	  PARABOLA LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new parabola($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

parameter :
	  PARAMETER
	    { $$ = new parameter(); }
	;

parenAxis2placement3dListFull :
	  LPAREN axis2placement3dList RPAREN
	    { $$ = new parenAxis2placement3dListFull($2); }
	;

parenBossList :
	  LPAREN bossList RPAREN
	    { $$ = new parenBossList($2); }
	| LPAREN RPAREN
	    { $$ = new parenBossList(new std::list<boss *>); }
	;

parenCartesianPointList :
	  LPAREN cartesianPointList RPAREN
	    { $$ = new parenCartesianPointList($2); }
	| LPAREN RPAREN
	    { $$ = new parenCartesianPointList(new std::list<cartesianPoint *>); }
	;

parenCartesianPointListFull :
	  LPAREN cartesianPointList RPAREN
	    { $$ = new parenCartesianPointListFull($2); }
	;

parenCircularOffsetList :
	  LPAREN circularOffsetList RPAREN
	    { $$ = new parenCircularOffsetList($2); }
	| LPAREN RPAREN
	    { $$ = new parenCircularOffsetList(new std::list<circularOffset *>); }
	;

parenCircularOmitList :
	  LPAREN circularOmitList RPAREN
	    { $$ = new parenCircularOmitList($2); }
	| LPAREN RPAREN
	    { $$ = new parenCircularOmitList(new std::list<circularOmit *>); }
	;

parenCompositeCurveSegmentListFull :
	  LPAREN compositeCurveSegmentList RPAREN
	    { $$ = new parenCompositeCurveSegmentListFull($2); }
	;

parenCompoundFeatureSelectListFull :
	  LPAREN compoundFeatureSelectList RPAREN
	    { $$ = new parenCompoundFeatureSelectListFull($2); }
	;

parenCuttingComponentListFull :
	  LPAREN cuttingComponentList RPAREN
	    { $$ = new parenCuttingComponentListFull($2); }
	;

parenExecutableList :
	  LPAREN executableList RPAREN
	    { $$ = new parenExecutableList($2); }
	| LPAREN RPAREN
	    { $$ = new parenExecutableList(new std::list<executable *>); }
	;

parenMachiningOperationList :
	  LPAREN machiningOperationList RPAREN
	    { $$ = new parenMachiningOperationList($2); }
	| LPAREN RPAREN
	    { $$ = new parenMachiningOperationList(new std::list<machiningOperation *>); }
	;

parenNcVariableListFull :
	  LPAREN ncVariableList RPAREN
	    { $$ = new parenNcVariableListFull($2); }
	;

parenProcessModelLiszt :
	  LPAREN processModelLiszt RPAREN
	    { $$ = new parenProcessModelLiszt($2); }
	;

parenPropertyParameterList :
	  LPAREN propertyParameterList RPAREN
	    { $$ = new parenPropertyParameterList($2); }
	| LPAREN RPAREN
	    { $$ = new parenPropertyParameterList(new std::list<propertyParameter *>); }
	;

parenRectangularOffsetList :
	  LPAREN rectangularOffsetList RPAREN
	    { $$ = new parenRectangularOffsetList($2); }
	| LPAREN RPAREN
	    { $$ = new parenRectangularOffsetList(new std::list<rectangularOffset *>); }
	;

parenRectangularOmitList :
	  LPAREN rectangularOmitList RPAREN
	    { $$ = new parenRectangularOmitList($2); }
	| LPAREN RPAREN
	    { $$ = new parenRectangularOmitList(new std::list<rectangularOmit *>); }
	;

parenSetupInstructionList :
	  LPAREN setupInstructionList RPAREN
	    { $$ = new parenSetupInstructionList($2); }
	| LPAREN RPAREN
	    { $$ = new parenSetupInstructionList(new std::list<setupInstruction *>); }
	;

parenSlotEndTypeList :
	  LPAREN slotEndTypeList RPAREN
	    { $$ = new parenSlotEndTypeList($2); }
	| LPAREN RPAREN
	    { $$ = new parenSlotEndTypeList(new std::list<slotEndType *>); }
	;

parenToolpathLisztFull :
	  LPAREN toolpathLiszt RPAREN
	    { $$ = new parenToolpathLisztFull($2); }
	;

parenTrimmingSelectListFull :
	  LPAREN trimmingSelectList RPAREN
	    { $$ = new parenTrimmingSelectListFull($2); }
	;

parenWorkpieceList :
	  LPAREN workpieceList RPAREN
	    { $$ = new parenWorkpieceList($2); }
	| LPAREN RPAREN
	    { $$ = new parenWorkpieceList(new std::list<workpiece *>); }
	;

parenWorkpieceSetupList :
	  LPAREN workpieceSetupList RPAREN
	    { $$ = new parenWorkpieceSetupList($2); }
	| LPAREN RPAREN
	    { $$ = new parenWorkpieceSetupList(new std::list<workpieceSetup *>); }
	;

partialCircularPath :
	  PARTIALCIRCULARPATH LPAREN optAxis2placement3d C instanceId C REALSTRING RPAREN
	    { $$ = new partialCircularPath($3, 0, $7);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

pathmodeType :
	  pathmodeTypeForward
	    { $$ = $1; }
	| pathmodeTypeZigzag
	    { $$ = $1; }
	;

pathmodeTypeForward :
	  FORWARD
	    { $$ = new pathmodeTypeForward(); }
	;

pathmodeTypeZigzag :
	  ZIGZAG
	    { $$ = new pathmodeTypeZigzag(); }
	;

personAndAddress :
	  PERSONANDADDRESS LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new personAndAddress($3, $5); }
	;

planarFace :
	  PLANARFACE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C optClosedProfile C parenBossList RPAREN
	    { $$ = new planarFace($3, 0, $7, 0, 0, 0, 0, $17, $19);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      linearPath_refs.push_back(&($$->courseOfTravel));
	      linearPath_nums.push_back($13->get_val());
	      delete $13;
	      linearProfile_refs.push_back(&($$->removalBoundary));
	      linearProfile_nums.push_back($15->get_val());
	      delete $15;
	      if ($17)
		{
		  $$->set_faceBoundary(0);
		  closedProfile_refs.push_back(&($$->faceBoundary));
		  closedProfile_nums.push_back($17->get_id()->get_val());
		  delete $17->get_id();
		  delete $17;
		}
	    }
	;

planarPocketBottomCondition :
	  PLANARPOCKETBOTTOMCONDITION LPAREN RPAREN
	    { $$ = new planarPocketBottomCondition(); }
	;

plane :
	  PLANE LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new plane($3, 0);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

planeCcStrategy :
	  PLANECCSTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId RPAREN
	    { $$ = new planeCcStrategy($3, $5, 0, $9, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->get_val());
	      delete $7;
	      direction_refs.push_back(&($$->itsPlaneNormal));
	      direction_nums.push_back($11->get_val());
	      delete $11;
	    }
	;

planeClStrategy :
	  PLANECLSTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId RPAREN
	    { $$ = new planeClStrategy($3, $5, 0, $9, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->get_val());
	      delete $7;
	      direction_refs.push_back(&($$->itsPlaneNormal));
	      direction_nums.push_back($11->get_val());
	      delete $11;
	    }
	;

planeFinishMilling :
	  PLANEFINISHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal RPAREN
	    { $$ = new planeFinishMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

planeRoughMilling :
	  PLANEROUGHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal RPAREN
	    { $$ = new planeRoughMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

plungeHelix :
	  PLUNGEHELIX LPAREN optDirection C REALSTRING C REALSTRING RPAREN
	    { $$ = new plungeHelix($3, $5, $7);
	      if ($3)
		{
		  $$->set_toolOrientation(0);
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	    }
	;

plungeRamp :
	  PLUNGERAMP LPAREN optDirection C REALSTRING RPAREN
	    { $$ = new plungeRamp($3, $5);
	      if ($3)
		{
		  $$->set_toolOrientation(0);
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	    }
	;

plungeToolaxis :
	  PLUNGETOOLAXIS LPAREN optDirection RPAREN
	    { $$ = new plungeToolaxis($3);
	      if ($3)
		{
		  $$->set_toolOrientation(0);
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	    }
	;

plungeZigzag :
	  PLUNGEZIGZAG LPAREN optDirection C REALSTRING C REALSTRING RPAREN
	    { $$ = new plungeZigzag($3, $5, $7);
	      if ($3)
		{
		  $$->set_toolOrientation(0);
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	    }
	;

plusMinusValue :
	  PLUSMINUSVALUE LPAREN REALSTRING C REALSTRING C INTSTRING RPAREN
	    { $$ = new plusMinusValue($3, $5, $7); }
	;

polyline :
	  POLYLINE LPAREN CHARSTRING C parenCartesianPointListFull RPAREN
	    { $$ = new polyline($3, $5); }
	;

processModel :
	  PROCESSMODEL LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new processModel($3, $5); }
	;

processModelList :
	  PROCESSMODELLIST LPAREN parenProcessModelLiszt RPAREN
	    { $$ = new processModelList($3); }
	;

processModelLiszt :
	  instanceId
	    { $$ = new std::list<processModel *>;
	      $$->push_back(0);
	      processModel_refs.push_back(&($$->back()));
	      processModel_nums.push_back($1->get_val());
	    }
	| processModelLiszt C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      processModel_refs.push_back(&($$->back()));
	      processModel_nums.push_back($3->get_val());
	    }
	;

programStop :
	  PROGRAMSTOP LPAREN CHARSTRING RPAREN
	    { $$ = new programStop($3); }
	;

project :
	  PROJECT LPAREN CHARSTRING C instanceId C parenWorkpieceList C optPersonAndAddress C optDateAndTime C optApproval RPAREN
	    { $$ = new project($3, 0, $7, $9, $11, $13);
	      workplan_refs.push_back(&($$->mainWorkplan));
	      workplan_nums.push_back($5->get_val());
	      delete $5;
	      if ($9)
		{
		  $$->set_itsOwner(0);
		  personAndAddress_refs.push_back(&($$->itsOwner));
		  personAndAddress_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      if ($11)
		{
		  $$->set_itsRelease(0);
		  dateAndTime_refs.push_back(&($$->itsRelease));
		  dateAndTime_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      if ($13)
		{
		  $$->set_itsStatus(0);
		  approval_refs.push_back(&($$->itsStatus));
		  approval_nums.push_back($13->get_id()->get_val());
		  delete $13->get_id();
		  delete $13;
		}
	    }
	;

propertyParameterList :
	  instanceId
	    { $$ = new std::list<propertyParameter *>;
	      $$->push_back(0);
	      propertyParameter_refs.push_back(&($$->back()));
	      propertyParameter_nums.push_back($1->get_val());
	    }
	| propertyParameterList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      propertyParameter_refs.push_back(&($$->back()));
	      propertyParameter_nums.push_back($3->get_val());
	    }
	;

radiusedPocketBottomCondition :
	  RADIUSEDPOCKETBOTTOMCONDITION LPAREN instanceId C instanceId RPAREN
	    { $$ = new radiusedPocketBottomCondition(0, 0);
	      cartesianPoint_refs.push_back(&($$->floorRadiusCenter));
	      cartesianPoint_nums.push_back($3->get_val());
	      delete $3;
	      tolerancedLengthMeasure_refs.push_back(&($$->floorRadius));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

radiusedSlotEndType :
	  RADIUSEDSLOTENDTYPE LPAREN RPAREN
	    { $$ = new radiusedSlotEndType(); }
	;

rapidMovement :
	  RAPIDMOVEMENT LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection RPAREN
	    { $$ = new rapidMovement($3, 0, $7, $9);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->get_val());
	      delete $5;
	      if ($7)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	      if ($9)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	    }
	;

reaming :
	  REAMING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy C boolean C optReal C optCartesianPoint RPAREN
	    { $$ = new reaming($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33, $35);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	      if ($35)
		{
		  $$->set_waitingPosition(0);
		  cartesianPoint_refs.push_back(&($$->waitingPosition));
		  cartesianPoint_nums.push_back($35->get_id()->get_val());
		  delete $35->get_id();
		  delete $35;
		}
	    }
	;

rectangularClosedProfile :
	  RECTANGULARCLOSEDPROFILE LPAREN optAxis2placement3d C instanceId C instanceId RPAREN
	    { $$ = new rectangularClosedProfile($3, 0, 0);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->profileWidth));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	      tolerancedLengthMeasure_refs.push_back(&($$->profileLength));
	      tolerancedLengthMeasure_nums.push_back($7->get_val());
	      delete $7;
	    }
	;

rectangularOffset :
	  RECTANGULAROFFSET LPAREN instanceId C REALSTRING C INTSTRING C INTSTRING RPAREN
	    { $$ = new rectangularOffset(0, $5, $7, $9);
	      direction_refs.push_back(&($$->offsetDirection));
	      direction_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

rectangularOffsetList :
	  instanceId
	    { $$ = new std::list<rectangularOffset *>;
	      $$->push_back(0);
	      rectangularOffset_refs.push_back(&($$->back()));
	      rectangularOffset_nums.push_back($1->get_val());
	    }
	| rectangularOffsetList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      rectangularOffset_refs.push_back(&($$->back()));
	      rectangularOffset_nums.push_back($3->get_val());
	    }
	;

rectangularOmit :
	  RECTANGULAROMIT LPAREN INTSTRING C INTSTRING RPAREN
	    { $$ = new rectangularOmit($3, $5); }
	;

rectangularOmitList :
	  instanceId
	    { $$ = new std::list<rectangularOmit *>;
	      $$->push_back(0);
	      rectangularOmit_refs.push_back(&($$->back()));
	      rectangularOmit_nums.push_back($1->get_val());
	    }
	| rectangularOmitList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      rectangularOmit_refs.push_back(&($$->back()));
	      rectangularOmit_nums.push_back($3->get_val());
	    }
	;

rectangularPattern :
	  RECTANGULARPATTERN LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId instanceId C instanceId C optInteger C INTSTRING C optTolerancedLengthMeasure C optDirection C parenRectangularOffsetList C parenRectangularOmitList RPAREN
	    { $$ = new rectangularPattern($3, 0, $7, 0, 0, 0, 0, $16, $18, $20, $22, $24, $26);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      two5DmanufacturingFeature_refs.push_back(&($$->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back($11->get_val());
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->spacing));
	      tolerancedLengthMeasure_nums.push_back($12->get_val());
	      delete $12;
	      direction_refs.push_back(&($$->itsDirection));
	      direction_nums.push_back($14->get_val());
	      delete $14;
	      if ($20)
		{
		  $$->set_rowSpacing(0);
		  tolerancedLengthMeasure_refs.push_back(&($$->rowSpacing));
		  tolerancedLengthMeasure_nums.push_back($20->get_id()->get_val());
		  delete $20->get_id();
		  delete $20;
		}
	      if ($22)
		{
		  $$->set_rowLayoutDirection(0);
		  direction_refs.push_back(&($$->rowLayoutDirection));
		  direction_nums.push_back($22->get_id()->get_val());
		  delete $22->get_id();
		  delete $22;
		}
	    }
	;

regionProjection :
	  REGIONPROJECTION LPAREN CHARSTRING C instanceId C parenMachiningOperationList C optAxis2placement3d C instanceId C instanceId C instanceId RPAREN
	    { $$ = new regionProjection($3, 0, $7, $9, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      if ($9)
		{
		  $$->set_featurePlacement(0);
		  axis2placement3d_refs.push_back(&($$->featurePlacement));
		  axis2placement3d_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      boundedCurve_refs.push_back(&($$->projCurve));
	      boundedCurve_nums.push_back($11->get_val());
	      delete $11;
	      direction_refs.push_back(&($$->projDir));
	      direction_nums.push_back($13->get_val());
	      delete $13;
	      tolerancedLengthMeasure_refs.push_back(&($$->depth));
	      tolerancedLengthMeasure_nums.push_back($15->get_val());
	      delete $15;
	    }
	;

rightCircularCylinder :
	  RIGHTCIRCULARCYLINDER LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new rightCircularCylinder($3, 0, $7, $9);
	      axis1placement_refs.push_back(&($$->position));
	      axis1placement_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

rotDirection :
	  rotDirectionCw
	    { $$ = $1; }
	| rotDirectionCcw
	    { $$ = $1; }
	;

rotDirectionCw :
	  CW
	    { $$ = new rotDirectionCw(); }
	;

rotDirectionCcw :
	  CCW
	    { $$ = new rotDirectionCcw(); }
	;

roundedUProfile :
	  ROUNDEDUPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new roundedUProfile($3, 0);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->width));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

roundHole :
	  ROUNDHOLE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optTaperSelect C instanceId RPAREN
	    { $$ = new roundHole($3, 0, $7, 0, 0, 0, $15, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->diameter));
	      tolerancedLengthMeasure_nums.push_back($13->get_val());
	      delete $13;
	      if ($15)
		{
		  $$->set_changeInDiameter(0);
		  taperSelect_refs.push_back(&($$->changeInDiameter));
		  taperSelect_nums.push_back($15->get_id()->get_val());
		  delete $15->get_id();
		  delete $15;
		}
	      holeBottomCondition_refs.push_back(&($$->bottomCondition));
	      holeBottomCondition_nums.push_back($17->get_val());
	      delete $17;
	    }
	;

setMark :
	  SETMARK LPAREN CHARSTRING RPAREN
	    { $$ = new setMark($3); }
	;

setup :
	  SETUP LPAREN CHARSTRING C optAxis2placement3d C instanceId C parenWorkpieceSetupList RPAREN
	    { $$ = new setup($3, $5, 0, $9);
	      if ($5)
		{
		  $$->set_itsOrigin(0);
		  axis2placement3d_refs.push_back(&($$->itsOrigin));
		  axis2placement3d_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($7->get_val());
	      delete $7;
	    }
	;

setupInstruction :
	  SETUPINSTRUCTION LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new setupInstruction($3, $5); }
	;

setupInstructionList :
	  instanceId
	    { $$ = new std::list<setupInstruction *>;
	      $$->push_back(0);
	      setupInstruction_refs.push_back(&($$->back()));
	      setupInstruction_nums.push_back($1->get_val());
	    }
	| setupInstructionList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      setupInstruction_refs.push_back(&($$->back()));
	      setupInstruction_nums.push_back($3->get_val());
	    }
	;

sideFinishMilling :
	  SIDEFINISHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal RPAREN
	    { $$ = new sideFinishMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

sideRoughMilling :
	  SIDEROUGHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal RPAREN
	    { $$ = new sideRoughMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($21)
		{
		  $$->set_approach(0);
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->get_id()->get_val());
		  delete $21->get_id();
		  delete $21;
		}
	      if ($23)
		{
		  $$->set_retract(0);
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->get_id()->get_val());
		  delete $23->get_id();
		  delete $23;
		}
	      if ($25)
		{
		  $$->set_itsMachiningStrategy(0);
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->get_id()->get_val());
		  delete $25->get_id();
		  delete $25;
		}
	    }
	;

slot :
	  SLOT LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C parenSlotEndTypeList RPAREN
	    { $$ = new slot($3, 0, $7, 0, 0, 0, 0, $17);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      travelPath_refs.push_back(&($$->courseOfTravel));
	      travelPath_nums.push_back($13->get_val());
	      delete $13;
	      openProfile_refs.push_back(&($$->sweptShape));
	      openProfile_nums.push_back($15->get_val());
	      delete $15;
	    }
	;

slotEndTypeList :
	  instanceId
	    { $$ = new std::list<slotEndType *>;
	      $$->push_back(0);
	      slotEndType_refs.push_back(&($$->back()));
	      slotEndType_nums.push_back($1->get_val());
	    }
	| slotEndTypeList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      slotEndType_refs.push_back(&($$->back()));
	      slotEndType_nums.push_back($3->get_val());
	    }
	;

speedName :
	  RAPID
	    { $$ = new speedName(); }
	;

sphericalCap :
	  SPHERICALCAP LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new sphericalCap($3, 0, $7, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      numericParameter_refs.push_back(&($$->internalAngle));
	      numericParameter_nums.push_back($13->get_val());
	      delete $13;
	      numericParameter_refs.push_back(&($$->radius));
	      numericParameter_nums.push_back($15->get_val());
	      delete $15;
	    }
	;

sphericalHoleBottom :
	  SPHERICALHOLEBOTTOM LPAREN instanceId RPAREN
	    { $$ = new sphericalHoleBottom(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

sphericalSurface :
	  SPHERICALSURFACE LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new sphericalSurface($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

squareUProfile :
	  SQUAREUPROFILE LPAREN optAxis2placement3d C instanceId C instanceId C REALSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new squareUProfile($3, 0, 0, $9, 0, $13);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->width));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	      tolerancedLengthMeasure_refs.push_back(&($$->firstRadius));
	      tolerancedLengthMeasure_nums.push_back($7->get_val());
	      delete $7;
	      tolerancedLengthMeasure_refs.push_back(&($$->secondRadius));
	      tolerancedLengthMeasure_nums.push_back($11->get_val());
	      delete $11;
	    }
	;

step :
	  STEP LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optVeeProfile C parenBossList RPAREN
	    { $$ = new step($3, 0, $7, 0, 0, 0, $15, $17);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	      linearPath_refs.push_back(&($$->openBoundary));
	      linearPath_nums.push_back($13->get_val());
	      delete $13;
	      if ($15)
		{
		  $$->set_wallBoundary(0);
		  veeProfile_refs.push_back(&($$->wallBoundary));
		  veeProfile_nums.push_back($15->get_id()->get_val());
		  delete $15->get_id();
		  delete $15;
		}
	    }
	;

straightline :
	  STRAIGHTLINE
	    { $$ = new straightline(); }
	;

strokeConnectionStrategy :
	  straightline
	    { $$ = $1; }
	| liftShiftPlunge
	    { $$ = $1; }
	| degouge
	    { $$ = $1; }
	| loopBack
	    { $$ = $1; }
	;

taperedEndmill :
	  TAPEREDENDMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new taperedEndmill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

taperedReamer :
	  TAPEREDREAMER LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new taperedReamer(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

tapping :
	  TAPPING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy boolean RPAREN
	    { $$ = new tapping($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $30);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

threadDrilling :
	  THREADDRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy boolean RPAREN
	    { $$ = new threadDrilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $30);
	      if ($3)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      if ($5)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($11)
		{
		  $$->set_startPoint(0);
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->get_id()->get_val());
		  delete $11->get_id();
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->get_val());
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->get_val());
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->get_val());
	      delete $17;
	      if ($29)
		{
		  $$->set_itsMachiningStrategy(0);
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->get_id()->get_val());
		  delete $29->get_id();
		  delete $29;
		}
	    }
	;

threeAxes :
	  THREEAXES LPAREN RPAREN
	    { $$ = new threeAxes(); }
	;

throughBottomCondition :
	  THROUGHBOTTOMCONDITION LPAREN RPAREN
	    { $$ = new throughBottomCondition(); }
	;

throughPocketBottomCondition :
	  THROUGHPOCKETBOTTOMCONDITION LPAREN RPAREN
	    { $$ = new throughPocketBottomCondition(); }
	;

tolerancedLengthMeasure :
	  TOLERANCEDLENGTHMEASURE LPAREN REALSTRING C instanceId RPAREN
	    { $$ = new tolerancedLengthMeasure($3, 0);
	      plusMinusValue_refs.push_back(&($$->implicitTolerance));
	      plusMinusValue_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

tolerances :
	  TOLERANCES LPAREN REALSTRING C REALSTRING RPAREN
	    { $$ = new tolerances($3, $5); }
	;

toolpathFeature :
	  TOOLPATHFEATURE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId RPAREN
	    { $$ = new toolpathFeature($3, 0, $7, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->get_val());
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->get_val());
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->get_val());
	      delete $11;
	    }
	;

toolpathList :
	  TOOLPATHLIST LPAREN parenToolpathLisztFull RPAREN
	    { $$ = new toolpathList($3); }
	;

toolpathLiszt :
	  instanceId
	    { $$ = new std::list<toolpath *>;
	      $$->push_back(0);
	      toolpath_refs.push_back(&($$->back()));
	      toolpath_nums.push_back($1->get_val());
	    }
	| toolpathLiszt C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      toolpath_refs.push_back(&($$->back()));
	      toolpath_nums.push_back($3->get_val());
	    }
	;

toolpathSpeedprofile :
	  real
	    { $$ = $1; }
	| speedName
	    { $$ = $1; }
	;

toolpathType :
	  approach
	    { $$ = $1; }
	| lift
	    { $$ = $1; }
	| connect
	    { $$ = $1; }
	| nonContact
	    { $$ = $1; }
	| contact
	    { $$ = $1; }
	| trajectoryPath
	    { $$ = $1; }
	;

toolProbing :
	  TOOLPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C REALSTRING C instanceId RPAREN
	    { $$ = new toolProbing($3, 0, $7, $9, 0, 0, $15, 0);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->get_val());
	      delete $5;
	      if ($7)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	      if ($9)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->get_val());
	      delete $11;
	      cartesianPoint_refs.push_back(&($$->offset));
	      cartesianPoint_nums.push_back($13->get_val());
	      delete $13;
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($17->get_val());
	      delete $17;
	    }
	;

toolReferencePoint :
	  toolReferencePointCcp
	    { $$ = $1; }
	| toolReferencePointTcp
	    { $$ = $1; }
	;

toolReferencePointCcp :
	  CCP
	    { $$ = new toolReferencePointCcp(); }
	;

toolReferencePointTcp :
	  TCP
	    { $$ = new toolReferencePointTcp(); }
	;

touchProbe :
	  TOUCHPROBE LPAREN CHARSTRING RPAREN
	    { $$ = new touchProbe($3); }
	;

trajectoryPath :
	  TRAJECTORYPATH
	    { $$ = new trajectoryPath(); }
	;

transitionCode :
	  discontinuous
	    { $$ = $1; }
	| continuous
	    { $$ = $1; }
	| contSameGradient
	    { $$ = $1; }
	| contSameGradientSameCurvature
	    { $$ = $1; }
	;

trimmedCurve :
	  TRIMMEDCURVE LPAREN CHARSTRING C instanceId C parenTrimmingSelectListFull C parenTrimmingSelectListFull C boolean C trimmingPreference RPAREN
	    { $$ = new trimmedCurve($3, 0, $7, $9, $11, $13);
	      curve_refs.push_back(&($$->basisCurve));
	      curve_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

trimmingPreference :
	  cartesian
	    { $$ = $1; }
	| parameter
	    { $$ = $1; }
	| unspecified
	    { $$ = $1; }
	;

trimmingSelectList :
	  instanceId
	    { $$ = new std::list<trimmingSelect *>;
	      $$->push_back(0);
	      trimmingSelect_refs.push_back(&($$->back()));
	      trimmingSelect_nums.push_back($1->get_val());
	    }
	| trimmingSelectList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      trimmingSelect_refs.push_back(&($$->back()));
	      trimmingSelect_nums.push_back($3->get_val());
	    }
	;

twistDrill :
	  TWISTDRILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new twistDrill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

twoAxes :
	  TWOAXES LPAREN RPAREN
	    { $$ = new twoAxes(); }
	;

unidirectionalMilling :
	  UNIDIRECTIONALMILLING LPAREN optReal C optBoolean C optDirection C optCutmodeType RPAREN
	    { $$ = new unidirectionalMilling($3, $5, $7, $9);
	      if ($7)
		{
		  $$->set_feedDirection(0);
		  direction_refs.push_back(&($$->feedDirection));
		  direction_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	    }
	;

unloadTool :
	  UNLOADTOOL LPAREN CHARSTRING C optMachiningTool RPAREN
	    { $$ = new unloadTool($3, $5);
	      if ($5)
		{
		  $$->set_itsTool(0);
		  machiningTool_refs.push_back(&($$->itsTool));
		  machiningTool_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	    }
	;

unspecified :
	  UNSPECIFIED
	    { $$ = new unspecified(); }
	;

uvStrategy :
	  UVSTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId C instanceId RPAREN
	    { $$ = new uvStrategy($3, $5, 0, $9, 0, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->get_val());
	      delete $7;
	      direction_refs.push_back(&($$->forwardDirection));
	      direction_nums.push_back($11->get_val());
	      delete $11;
	      direction_refs.push_back(&($$->sidewardDirection));
	      direction_nums.push_back($13->get_val());
	      delete $13;
	    }
	;

vector :
	  VECTOR LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new vector($3, 0, $7);
	      direction_refs.push_back(&($$->orientation));
	      direction_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

veeProfile :
	  VEEPROFILE LPAREN optAxis2placement3d C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new veeProfile($3, 0, $7, $9);
	      if ($3)
		{
		  $$->set_placement(0);
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->get_id()->get_val());
		  delete $3->get_id();
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->profileRadius));
	      tolerancedLengthMeasure_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

waitForMark :
	  WAITFORMARK LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new waitForMark($3, 0);
	      channel_refs.push_back(&($$->itsChannel));
	      channel_nums.push_back($5->get_val());
	      delete $5;
	    }
	;

woodruffSlotEndType :
	  WOODRUFFSLOTENDTYPE LPAREN instanceId RPAREN
	    { $$ = new woodruffSlotEndType(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($3->get_val());
	      delete $3;
	    }
	;

workpiece :
	  WORKPIECE LPAREN CHARSTRING C optMaterial C optReal C optWorkpiece C optAdvancedBrepShapeRepresentation C optBoundingGeometrySelect C parenCartesianPointList RPAREN
	    { $$ = new workpiece($3, $5, $7, $9, $11, $13, $15);
	      if ($5)
		{
		  $$->set_itsMaterial(0);
		  material_refs.push_back(&($$->itsMaterial));
		  material_nums.push_back($5->get_id()->get_val());
		  delete $5->get_id();
		  delete $5;
		}
	      if ($9)
		{
		  $$->set_itsRawpiece(0);
		  workpiece_refs.push_back(&($$->itsRawpiece));
		  workpiece_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      if ($13)
		{
		  $$->set_itsBoundingGeometry(0);
		  boundingGeometrySelect_refs.push_back(&($$->itsBoundingGeometry));
		  boundingGeometrySelect_nums.push_back($13->get_id()->get_val());
		  delete $13->get_id();
		  delete $13;
		}
	    }
	;

workpieceCompleteProbing :
	  WORKPIECECOMPLETEPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C instanceId C instanceId C offsetVector RPAREN
	    { $$ = new workpieceCompleteProbing($3, 0, $7, $9, 0, 0, 0, 0, $19);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->get_val());
	      delete $5;
	      if ($7)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	      if ($9)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->get_val());
	      delete $11;
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($13->get_val());
	      delete $13;
	      tolerancedLengthMeasure_refs.push_back(&($$->probingDistance));
	      tolerancedLengthMeasure_nums.push_back($15->get_val());
	      delete $15;
	      touchProbe_refs.push_back(&($$->itsProbe));
	      touchProbe_nums.push_back($17->get_val());
	      delete $17;
	    }
	;

workpieceList :
	  instanceId
	    { $$ = new std::list<workpiece *>;
	      $$->push_back(0);
	      workpiece_refs.push_back(&($$->back()));
	      workpiece_nums.push_back($1->get_val());
	    }
	| workpieceList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      workpiece_refs.push_back(&($$->back()));
	      workpiece_nums.push_back($3->get_val());
	    }
	;

workpieceProbing :
	  WORKPIECEPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new workpieceProbing($3, 0, $7, $9, 0, 0, 0, 0, 0, 0);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->get_val());
	      delete $5;
	      if ($7)
		{
		  $$->set_itsToolpath(0);
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	      if ($9)
		{
		  $$->set_itsToolDirection(0);
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->get_val());
	      delete $11;
	      axis2placement3d_refs.push_back(&($$->startPosition));
	      axis2placement3d_nums.push_back($13->get_val());
	      delete $13;
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($15->get_val());
	      delete $15;
	      direction_refs.push_back(&($$->itsDirection));
	      direction_nums.push_back($17->get_val());
	      delete $17;
	      tolerancedLengthMeasure_refs.push_back(&($$->expectedValue));
	      tolerancedLengthMeasure_nums.push_back($19->get_val());
	      delete $19;
	      touchProbe_refs.push_back(&($$->itsProbe));
	      touchProbe_nums.push_back($21->get_val());
	      delete $21;
	    }
	;

workpieceSetup :
	  WORKPIECESETUP LPAREN instanceId C instanceId C optOffsetVector C optRestrictedAreaSelect C parenSetupInstructionList RPAREN
	    { $$ = new workpieceSetup(0, 0, $7, $9, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($3->get_val());
	      delete $3;
	      axis2placement3d_refs.push_back(&($$->itsOrigin));
	      axis2placement3d_nums.push_back($5->get_val());
	      delete $5;
	      if ($9)
		{
		  $$->set_itsRestrictedArea(0);
		  restrictedAreaSelect_refs.push_back(&($$->itsRestrictedArea));
		  restrictedAreaSelect_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	    }
	;

workpieceSetupList :
	  instanceId
	    { $$ = new std::list<workpieceSetup *>;
	      $$->push_back(0);
	      workpieceSetup_refs.push_back(&($$->back()));
	      workpieceSetup_nums.push_back($1->get_val());
	    }
	| workpieceSetupList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      workpieceSetup_refs.push_back(&($$->back()));
	      workpieceSetup_nums.push_back($3->get_val());
	    }
	;

workplan :
	  WORKPLAN LPAREN CHARSTRING C parenExecutableList C optChannel C optSetup C optInProcessGeometry RPAREN
	    { $$ = new workplan($3, $5, $7, $9, $11);
	      if ($7)
		{
		  $$->set_itsChannel(0);
		  channel_refs.push_back(&($$->itsChannel));
		  channel_nums.push_back($7->get_id()->get_val());
		  delete $7->get_id();
		  delete $7;
		}
	      if ($9)
		{
		  $$->set_itsSetup(0);
		  setup_refs.push_back(&($$->itsSetup));
		  setup_nums.push_back($9->get_id()->get_val());
		  delete $9->get_id();
		  delete $9;
		}
	    }
	;

%%
