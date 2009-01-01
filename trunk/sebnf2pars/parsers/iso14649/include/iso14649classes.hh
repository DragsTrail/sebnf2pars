
/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

/*

This file defines classes used to represent data in Part 21 files.
The meaning of each class definition is documented. In the
documentation, punctuation marks and special characters that should
appear in program files are enclosed in quotes.

A class is defined for each production in the EBNF file that does not
define a list or give the spelling of a token and is not an optional
parent.

Each expression from the EBNF definition for a production that
corresponds to an attribute in the EXPRESS model used by the EBNF file
is represented by a data member of the class. The name of the data
member is the EXPRESS attribute name given in the comments at the end
of the EBNF file. Each represented item is either a list or a class,
and they are represented as follows.

   Each list data member is represented by a pointer to a C++ standard
   library list of pointers to the class for the item of which the list
   is composed. For example, std::list<cartesianPoint *> * theList

   Every other data member is represented by a pointer to the class for
   that item. 

Classes are not defined for optional parents. If there is an optional
attribute, its value is a pointer to the optional child, but the
pointer may be NULL. No pointer to a non-optional attribute may be NULL.

For each data member of a C++ class, there is a method to get the data
member, and a method to set it. The name of each method is the name of the
data member preceded by either "get_" or "set_". The get method
has no arguments and returns the type of data in the data member. The set
method has an argument whose type is the type of the data member and
returns nothing.

Each class from which no other class is derived has two constructors
and a destructor. One of the constructors takes no arguments, and sets
nothing. The other constructor takes as many arguments as there are
data members and sets all the data members.

*/

#include <list>

class advancedBrepShapeRepresentation;
class angleTaper;
class approach;
class approachRetractStrategy;
class approval;
class approvalStatus;
class axis1placement;
class axis2placement3d;
class backBoring;
class backsideCounterbore;
class backsideCountersink;
class ballEndmill;
class bidirectionalMilling;
class blindBottomCondition;
class block;
class boolean;
class booleanFalse;
class booleanTrue;
class boring;
class boringOperation;
class boss;
class bottomAndSideFinishMilling;
class bottomAndSideMilling;
class bottomAndSideRoughMilling;
class boundedCurve;
class boundingGeometrySelect;
class bullnoseEndmill;
class calendarDate;
class cartesian;
class cartesianPoint;
class centerDrill;
class centerDrilling;
class chamfer;
class channel;
class circle;
class circularOffset;
class circularOmit;
class circularPath;
class circularPattern;
class closedPocket;
class closedProfile;
class combinedDrillAndReamer;
class completeCircularPath;
class compositeCurve;
class compositeCurveSegment;
class compoundFeature;
class compoundFeatureSelect;
class conic;
class conicalHoleBottom;
class connect;
class contSameGradient;
class contSameGradientSameCurvature;
class contact;
class continuous;
class contourParallel;
class counterSinking;
class counterbore;
class counterboreHole;
class counterboreParent;
class countersink;
class countersinkParent;
class countersunkHole;
class curve;
class cutmodeType;
class cutmodeTypeClimb;
class cutmodeTypeConventional;
class cutterLocationTrajectory;
class cuttingComponent;
class cuttingEdgeTechnologicalData;
class cuttingTool;
class dataSection;
class dataStarter;
class date;
class dateAndTime;
class degouge;
class descriptiveParameter;
class diameterTaper;
class direction;
class discontinuous;
class displayMessage;
class drill;
class drilling;
class drillingOperation;
class drillingTypeOperation;
class drillingTypeStrategy;
class edgeRound;
class elementarySurface;
class ellipse;
class endSection;
class endmill;
class exchangePallet;
class executable;
class facemill;
class feedstop;
class fileDescription;
class fileEnd;
class fileName;
class fileSchema;
class fileStart;
class fittingType;
class fittingTypeHole;
class fittingTypeShaft;
class flatHoleBottom;
class flatSlotEndType;
class flatWithRadiusHoleBottom;
class freeformOperation;
class freeformStrategy;
class generalPath;
class generalPattern;
class generalPocketBottomCondition;
class hand;
class handLeft;
class handRight;
class headerSection;
class headerStarter;
class helix;
class holeBottomCondition;
class hyperbola;
class inProcessGeometry;
class indexPallet;
class indexTable;
class inputFile;
class instance;
class instanceId;
class integer;
class leadingLineStrategy;
class leftOrRight;
class leftOrRightLeft;
class leftOrRightRight;
class lift;
class liftShiftPlunge;
class limitsAndFits;
class line;
class linearPath;
class linearProfile;
class loadTool;
class logical;
class logicalUnknown;
class loopBack;
class loopSlotEndType;
class machineFunctions;
class machiningFeature;
class machiningOperation;
class machiningTool;
class machiningWorkingstep;
class manufacturingFeature;
class material;
class millingCutter;
class millingCuttingTool;
class millingMachineFunctions;
class millingMachiningOperation;
class millingTechnology;
class millingToolBody;
class millingToolDimension;
class millingTypeOperation;
class multistepDrilling;
class ncFunction;
class ncVariable;
class nonContact;
class numericParameter;
class offsetVector;
class openProfile;
class openSlotEndType;
class operation;
class optionalStop;
class parabola;
class parameter;
class parenAxis2placement3dListFull;
class parenBossList;
class parenCartesianPointList;
class parenCartesianPointListFull;
class parenCircularOffsetList;
class parenCircularOmitList;
class parenCompositeCurveSegmentListFull;
class parenCompoundFeatureSelectListFull;
class parenCuttingComponentListFull;
class parenExecutableList;
class parenMachiningOperationList;
class parenNcVariableListFull;
class parenProcessModelLiszt;
class parenPropertyParameterList;
class parenRealListFull;
class parenRectangularOffsetList;
class parenRectangularOmitList;
class parenSetupInstructionList;
class parenSlotEndTypeList;
class parenStringList;
class parenStringListFull;
class parenToolpathLisztFull;
class parenTrimmingSelectListFull;
class parenWorkpieceList;
class parenWorkpieceSetupList;
class partialCircularPath;
class pathmodeType;
class pathmodeTypeForward;
class pathmodeTypeZigzag;
class personAndAddress;
class placement;
class planarFace;
class planarPocketBottomCondition;
class plane;
class planeCcStrategy;
class planeClStrategy;
class planeFinishMilling;
class planeMilling;
class planeRoughMilling;
class plungeHelix;
class plungeRamp;
class plungeStrategy;
class plungeToolaxis;
class plungeZigzag;
class plusMinusValue;
class pocket;
class pocketBottomCondition;
class polyline;
class processModel;
class processModelList;
class profile;
class programStop;
class programStructure;
class project;
class propertyParameter;
class radiusedPocketBottomCondition;
class radiusedSlotEndType;
class rapidMovement;
class real;
class reamer;
class reaming;
class rectangularClosedProfile;
class rectangularOffset;
class rectangularOmit;
class rectangularPattern;
class region;
class regionProjection;
class replicateFeature;
class representationItem;
class restrictedAreaSelect;
class rightCircularCylinder;
class rotDirection;
class rotDirectionCcw;
class rotDirectionCw;
class roundHole;
class roundedUProfile;
class setMark;
class setup;
class setupInstruction;
class sideFinishMilling;
class sideMilling;
class sideRoughMilling;
class slot;
class slotEndType;
class speedName;
class sphericalCap;
class sphericalHoleBottom;
class sphericalSurface;
class squareUProfile;
class step;
class straightline;
class strokeConnectionStrategy;
class taperSelect;
class taperedEndmill;
class taperedReamer;
class tapping;
class technology;
class threadDrilling;
class threeAxes;
class throughBottomCondition;
class throughPocketBottomCondition;
class toleranceSelect;
class tolerancedLengthMeasure;
class tolerances;
class toolBody;
class toolDirection;
class toolProbing;
class toolReferencePoint;
class toolReferencePointCcp;
class toolReferencePointTcp;
class toolpath;
class toolpathFeature;
class toolpathList;
class toolpathSpeedprofile;
class toolpathType;
class touchProbe;
class touchProbing;
class trajectory;
class trajectoryPath;
class transitionCode;
class transitionFeature;
class travelPath;
class trimmedCurve;
class trimmingPreference;
class trimmingSelect;
class twistDrill;
class two5DmanufacturingFeature;
class two5DmillingOperation;
class two5DmillingStrategy;
class twoAxes;
class unidirectionalMilling;
class unloadTool;
class unspecified;
class uvStrategy;
class vector;
class veeProfile;
class waitForMark;
class woodruffSlotEndType;
class workingstep;
class workpiece;
class workpieceCompleteProbing;
class workpieceProbing;
class workpieceSetup;
class workplan;
class iso14649CppBase;

/********************************************************************/

enum iso14649ClassEName {
advancedBrepShapeRepresentation_E,
angleTaper_E,
approach_E,
approachRetractStrategy_E,
approval_E,
approvalStatus_E,
axis1placement_E,
axis2placement3d_E,
backBoring_E,
backsideCounterbore_E,
backsideCountersink_E,
ballEndmill_E,
bidirectionalMilling_E,
blindBottomCondition_E,
block_E,
boolean_E,
booleanFalse_E,
booleanTrue_E,
boring_E,
boringOperation_E,
boss_E,
bottomAndSideFinishMilling_E,
bottomAndSideMilling_E,
bottomAndSideRoughMilling_E,
boundedCurve_E,
boundingGeometrySelect_E,
bullnoseEndmill_E,
calendarDate_E,
cartesian_E,
cartesianPoint_E,
centerDrill_E,
centerDrilling_E,
chamfer_E,
channel_E,
circle_E,
circularOffset_E,
circularOmit_E,
circularPath_E,
circularPattern_E,
closedPocket_E,
closedProfile_E,
combinedDrillAndReamer_E,
completeCircularPath_E,
compositeCurve_E,
compositeCurveSegment_E,
compoundFeature_E,
compoundFeatureSelect_E,
conic_E,
conicalHoleBottom_E,
connect_E,
contSameGradient_E,
contSameGradientSameCurvature_E,
contact_E,
continuous_E,
contourParallel_E,
counterSinking_E,
counterbore_E,
counterboreHole_E,
counterboreParent_E,
countersink_E,
countersinkParent_E,
countersunkHole_E,
curve_E,
cutmodeType_E,
cutmodeTypeClimb_E,
cutmodeTypeConventional_E,
cutterLocationTrajectory_E,
cuttingComponent_E,
cuttingEdgeTechnologicalData_E,
cuttingTool_E,
dataSection_E,
dataStarter_E,
date_E,
dateAndTime_E,
degouge_E,
descriptiveParameter_E,
diameterTaper_E,
direction_E,
discontinuous_E,
displayMessage_E,
drill_E,
drilling_E,
drillingOperation_E,
drillingTypeOperation_E,
drillingTypeStrategy_E,
edgeRound_E,
elementarySurface_E,
ellipse_E,
endSection_E,
endmill_E,
exchangePallet_E,
executable_E,
facemill_E,
feedstop_E,
fileDescription_E,
fileEnd_E,
fileName_E,
fileSchema_E,
fileStart_E,
fittingType_E,
fittingTypeHole_E,
fittingTypeShaft_E,
flatHoleBottom_E,
flatSlotEndType_E,
flatWithRadiusHoleBottom_E,
freeformOperation_E,
freeformStrategy_E,
generalPath_E,
generalPattern_E,
generalPocketBottomCondition_E,
hand_E,
handLeft_E,
handRight_E,
headerSection_E,
headerStarter_E,
helix_E,
holeBottomCondition_E,
hyperbola_E,
inProcessGeometry_E,
indexPallet_E,
indexTable_E,
inputFile_E,
instance_E,
instanceId_E,
integer_E,
leadingLineStrategy_E,
leftOrRight_E,
leftOrRightLeft_E,
leftOrRightRight_E,
lift_E,
liftShiftPlunge_E,
limitsAndFits_E,
line_E,
linearPath_E,
linearProfile_E,
loadTool_E,
logical_E,
logicalUnknown_E,
loopBack_E,
loopSlotEndType_E,
machineFunctions_E,
machiningFeature_E,
machiningOperation_E,
machiningTool_E,
machiningWorkingstep_E,
manufacturingFeature_E,
material_E,
millingCutter_E,
millingCuttingTool_E,
millingMachineFunctions_E,
millingMachiningOperation_E,
millingTechnology_E,
millingToolBody_E,
millingToolDimension_E,
millingTypeOperation_E,
multistepDrilling_E,
ncFunction_E,
ncVariable_E,
nonContact_E,
numericParameter_E,
offsetVector_E,
openProfile_E,
openSlotEndType_E,
operation_E,
optionalStop_E,
parabola_E,
parameter_E,
parenAxis2placement3dListFull_E,
parenBossList_E,
parenCartesianPointList_E,
parenCartesianPointListFull_E,
parenCircularOffsetList_E,
parenCircularOmitList_E,
parenCompositeCurveSegmentListFull_E,
parenCompoundFeatureSelectListFull_E,
parenCuttingComponentListFull_E,
parenExecutableList_E,
parenMachiningOperationList_E,
parenNcVariableListFull_E,
parenProcessModelLiszt_E,
parenPropertyParameterList_E,
parenRealListFull_E,
parenRectangularOffsetList_E,
parenRectangularOmitList_E,
parenSetupInstructionList_E,
parenSlotEndTypeList_E,
parenStringList_E,
parenStringListFull_E,
parenToolpathLisztFull_E,
parenTrimmingSelectListFull_E,
parenWorkpieceList_E,
parenWorkpieceSetupList_E,
partialCircularPath_E,
pathmodeType_E,
pathmodeTypeForward_E,
pathmodeTypeZigzag_E,
personAndAddress_E,
placement_E,
planarFace_E,
planarPocketBottomCondition_E,
plane_E,
planeCcStrategy_E,
planeClStrategy_E,
planeFinishMilling_E,
planeMilling_E,
planeRoughMilling_E,
plungeHelix_E,
plungeRamp_E,
plungeStrategy_E,
plungeToolaxis_E,
plungeZigzag_E,
plusMinusValue_E,
pocket_E,
pocketBottomCondition_E,
polyline_E,
processModel_E,
processModelList_E,
profile_E,
programStop_E,
programStructure_E,
project_E,
propertyParameter_E,
radiusedPocketBottomCondition_E,
radiusedSlotEndType_E,
rapidMovement_E,
real_E,
reamer_E,
reaming_E,
rectangularClosedProfile_E,
rectangularOffset_E,
rectangularOmit_E,
rectangularPattern_E,
region_E,
regionProjection_E,
replicateFeature_E,
representationItem_E,
restrictedAreaSelect_E,
rightCircularCylinder_E,
rotDirection_E,
rotDirectionCcw_E,
rotDirectionCw_E,
roundHole_E,
roundedUProfile_E,
setMark_E,
setup_E,
setupInstruction_E,
sideFinishMilling_E,
sideMilling_E,
sideRoughMilling_E,
slot_E,
slotEndType_E,
speedName_E,
sphericalCap_E,
sphericalHoleBottom_E,
sphericalSurface_E,
squareUProfile_E,
step_E,
straightline_E,
strokeConnectionStrategy_E,
taperSelect_E,
taperedEndmill_E,
taperedReamer_E,
tapping_E,
technology_E,
threadDrilling_E,
threeAxes_E,
throughBottomCondition_E,
throughPocketBottomCondition_E,
toleranceSelect_E,
tolerancedLengthMeasure_E,
tolerances_E,
toolBody_E,
toolDirection_E,
toolProbing_E,
toolReferencePoint_E,
toolReferencePointCcp_E,
toolReferencePointTcp_E,
toolpath_E,
toolpathFeature_E,
toolpathList_E,
toolpathSpeedprofile_E,
toolpathType_E,
touchProbe_E,
touchProbing_E,
trajectory_E,
trajectoryPath_E,
transitionCode_E,
transitionFeature_E,
travelPath_E,
trimmedCurve_E,
trimmingPreference_E,
trimmingSelect_E,
twistDrill_E,
two5DmanufacturingFeature_E,
two5DmillingOperation_E,
two5DmillingStrategy_E,
twoAxes_E,
unidirectionalMilling_E,
unloadTool_E,
unspecified_E,
uvStrategy_E,
vector_E,
veeProfile_E,
waitForMark_E,
woodruffSlotEndType_E,
workingstep_E,
workpiece_E,
workpieceCompleteProbing_E,
workpieceProbing_E,
workpieceSetup_E,
workplan_E,
iso14649CppBase_E};

/********************************************************************/

/* iso14649CppBase

This is the base class for all other classes. It has virtual
functions printSelf and isA.

*/

class iso14649CppBase
{
public:
  iso14649CppBase(){}
  virtual ~iso14649CppBase(){}
  virtual void printSelf() = 0;
  virtual int isA(int aType) = 0;
};

/********************************************************************/

/* inputFile

This is a class for the single definition of inputFile.
It represents the following items:

fileStart headerSection dataSection fileEnd

*/

class inputFile :
  public iso14649CppBase
{
public:
  inputFile(){}
  inputFile(
    fileStart * inputStartIn,
    headerSection * inputHeaderIn,
    dataSection * inputDataIn,
    fileEnd * inputEndIn)
    {
      inputStart = inputStartIn;
      inputHeader = inputHeaderIn;
      inputData = inputDataIn;
      inputEnd = inputEndIn;
    }
  ~inputFile();
  int isA(int aType)
    { return (aType == inputFile_E); }
  void printSelf();
  fileStart * get_inputStart()
    {return inputStart;}
  void set_inputStart(fileStart * inputStartIn)
    {inputStart = inputStartIn;}
  headerSection * get_inputHeader()
    {return inputHeader;}
  void set_inputHeader(headerSection * inputHeaderIn)
    {inputHeader = inputHeaderIn;}
  dataSection * get_inputData()
    {return inputData;}
  void set_inputData(dataSection * inputDataIn)
    {inputData = inputDataIn;}
  fileEnd * get_inputEnd()
    {return inputEnd;}
  void set_inputEnd(fileEnd * inputEndIn)
    {inputEnd = inputEndIn;}
private:
  fileStart * inputStart;
  headerSection * inputHeader;
  dataSection * inputData;
  fileEnd * inputEnd;
};

/********************************************************************/

/* dataSection

This is a class for the single definition of dataSection.
It represents the following items:

dataStarter instanceList endSection

*/

class dataSection :
  public iso14649CppBase
{
public:
  dataSection(){}
  dataSection(
    dataStarter * dataStartIn,
    std::list<instance *> * itemsIn,
    endSection * sectionEndIn)
    {
      dataStart = dataStartIn;
      items = itemsIn;
      sectionEnd = sectionEndIn;
    }
  ~dataSection();
  int isA(int aType)
    { return (aType == dataSection_E); }
  void printSelf();
  dataStarter * get_dataStart()
    {return dataStart;}
  void set_dataStart(dataStarter * dataStartIn)
    {dataStart = dataStartIn;}
  std::list<instance *> * get_items()
    {return items;}
  void set_items(std::list<instance *> * itemsIn)
    {items = itemsIn;}
  endSection * get_sectionEnd()
    {return sectionEnd;}
  void set_sectionEnd(endSection * sectionEndIn)
    {sectionEnd = sectionEndIn;}
private:
  dataStarter * dataStart;
  std::list<instance *> * items;
  endSection * sectionEnd;
};

/********************************************************************/

/* dataStarter

This is a class for the single definition of dataStarter.
It represents the following items:

DATA ';'

*/

class dataStarter :
  public iso14649CppBase
{
public:
  dataStarter(){}
  ~dataStarter();
  int isA(int aType)
    { return (aType == dataStarter_E); }
  void printSelf();
};

/********************************************************************/

/* endSection

This is a class for the single definition of endSection.
It represents the following items:

ENDSEC ';'

*/

class endSection :
  public iso14649CppBase
{
public:
  endSection(){}
  ~endSection();
  int isA(int aType)
    { return (aType == endSection_E); }
  void printSelf();
};

/********************************************************************/

/* fileDescription

This is a class for the single definition of fileDescription.
It represents the following items:

FILEDESCRIPTION '(' parenStringListFull ',' CHARSTRING ')' ';'

*/

class fileDescription :
  public iso14649CppBase
{
public:
  fileDescription(){}
  fileDescription(
    parenStringListFull * descriptionIn,
    char * implementationLevelIn)
    {
      description = descriptionIn;
      implementationLevel = implementationLevelIn;
    }
  ~fileDescription();
  int isA(int aType)
    { return (aType == fileDescription_E); }
  void printSelf();
  parenStringListFull * get_description()
    {return description;}
  void set_description(parenStringListFull * descriptionIn)
    {description = descriptionIn;}
  char * get_implementationLevel()
    {return implementationLevel;}
  void set_implementationLevel(char * implementationLevelIn)
    {implementationLevel = implementationLevelIn;}
private:
  parenStringListFull * description;
  char * implementationLevel;
};

/********************************************************************/

/* fileEnd

This is a class for the single definition of fileEnd.
It represents the following items:

FILEEND ';'

*/

class fileEnd :
  public iso14649CppBase
{
public:
  fileEnd(){}
  ~fileEnd();
  int isA(int aType)
    { return (aType == fileEnd_E); }
  void printSelf();
};

/********************************************************************/

/* fileName

This is a class for the single definition of fileName.
It represents the following items:

FILENAME '(' CHARSTRING ',' CHARSTRING ',' parenStringListFull ',' parenStringListFull ',' CHARSTRING ',' CHARSTRING ',' CHARSTRING ')' ';'

*/

class fileName :
  public iso14649CppBase
{
public:
  fileName(){}
  fileName(
    char * nameIn,
    char * timeStampIn,
    parenStringListFull * authorIn,
    parenStringListFull * organizationIn,
    char * preprocessorVersionIn,
    char * originatingSystemIn,
    char * authorizationIn)
    {
      name = nameIn;
      timeStamp = timeStampIn;
      author = authorIn;
      organization = organizationIn;
      preprocessorVersion = preprocessorVersionIn;
      originatingSystem = originatingSystemIn;
      authorization = authorizationIn;
    }
  ~fileName();
  int isA(int aType)
    { return (aType == fileName_E); }
  void printSelf();
  char * get_name()
    {return name;}
  void set_name(char * nameIn)
    {name = nameIn;}
  char * get_timeStamp()
    {return timeStamp;}
  void set_timeStamp(char * timeStampIn)
    {timeStamp = timeStampIn;}
  parenStringListFull * get_author()
    {return author;}
  void set_author(parenStringListFull * authorIn)
    {author = authorIn;}
  parenStringListFull * get_organization()
    {return organization;}
  void set_organization(parenStringListFull * organizationIn)
    {organization = organizationIn;}
  char * get_preprocessorVersion()
    {return preprocessorVersion;}
  void set_preprocessorVersion(char * preprocessorVersionIn)
    {preprocessorVersion = preprocessorVersionIn;}
  char * get_originatingSystem()
    {return originatingSystem;}
  void set_originatingSystem(char * originatingSystemIn)
    {originatingSystem = originatingSystemIn;}
  char * get_authorization()
    {return authorization;}
  void set_authorization(char * authorizationIn)
    {authorization = authorizationIn;}
private:
  char * name;
  char * timeStamp;
  parenStringListFull * author;
  parenStringListFull * organization;
  char * preprocessorVersion;
  char * originatingSystem;
  char * authorization;
};

/********************************************************************/

/* fileSchema

This is a class for the single definition of fileSchema.
It represents the following items:

FILESCHEMA '(' parenStringList ')' ';'

*/

class fileSchema :
  public iso14649CppBase
{
public:
  fileSchema(){}
  fileSchema(
    parenStringList * schemaIdentifiersIn)
    {
      schemaIdentifiers = schemaIdentifiersIn;
    }
  ~fileSchema();
  int isA(int aType)
    { return (aType == fileSchema_E); }
  void printSelf();
  parenStringList * get_schemaIdentifiers()
    {return schemaIdentifiers;}
  void set_schemaIdentifiers(parenStringList * schemaIdentifiersIn)
    {schemaIdentifiers = schemaIdentifiersIn;}
private:
  parenStringList * schemaIdentifiers;
};

/********************************************************************/

/* fileStart

This is a class for the single definition of fileStart.
It represents the following items:

FILESTART ';'

*/

class fileStart :
  public iso14649CppBase
{
public:
  fileStart(){}
  ~fileStart();
  int isA(int aType)
    { return (aType == fileStart_E); }
  void printSelf();
};

/********************************************************************/

/* headerSection

This is a class for the single definition of headerSection.
It represents the following items:

headerStarter fileDescription fileName fileSchema endSection

*/

class headerSection :
  public iso14649CppBase
{
public:
  headerSection(){}
  headerSection(
    headerStarter * headerStartIn,
    fileDescription * headerDescriptionIn,
    fileName * headerNameIn,
    fileSchema * headerSchemaIn,
    endSection * sectionEndIn)
    {
      headerStart = headerStartIn;
      headerDescription = headerDescriptionIn;
      headerName = headerNameIn;
      headerSchema = headerSchemaIn;
      sectionEnd = sectionEndIn;
    }
  ~headerSection();
  int isA(int aType)
    { return (aType == headerSection_E); }
  void printSelf();
  headerStarter * get_headerStart()
    {return headerStart;}
  void set_headerStart(headerStarter * headerStartIn)
    {headerStart = headerStartIn;}
  fileDescription * get_headerDescription()
    {return headerDescription;}
  void set_headerDescription(fileDescription * headerDescriptionIn)
    {headerDescription = headerDescriptionIn;}
  fileName * get_headerName()
    {return headerName;}
  void set_headerName(fileName * headerNameIn)
    {headerName = headerNameIn;}
  fileSchema * get_headerSchema()
    {return headerSchema;}
  void set_headerSchema(fileSchema * headerSchemaIn)
    {headerSchema = headerSchemaIn;}
  endSection * get_sectionEnd()
    {return sectionEnd;}
  void set_sectionEnd(endSection * sectionEndIn)
    {sectionEnd = sectionEndIn;}
private:
  headerStarter * headerStart;
  fileDescription * headerDescription;
  fileName * headerName;
  fileSchema * headerSchema;
  endSection * sectionEnd;
};

/********************************************************************/

/* headerStarter

This is a class for the single definition of headerStarter.
It represents the following items:

HEADER ';'

*/

class headerStarter :
  public iso14649CppBase
{
public:
  headerStarter(){}
  ~headerStarter();
  int isA(int aType)
    { return (aType == headerStarter_E); }
  void printSelf();
};

/********************************************************************/

/* instanceId

This is a class for the single definition of instanceId.
It represents the following items:

'#' INTSTRING

*/

class instanceId :
  public iso14649CppBase
{
public:
  instanceId(){}
  instanceId(
    int valIn)
    {
      val = valIn;
    }
  ~instanceId();
  int isA(int aType)
    { return (aType == instanceId_E); }
  void printSelf();
  int get_val()
    {return val;}
  void set_val(int valIn)
    {val = valIn;}
private:
  int val;
};

/********************************************************************/

/* parenRealListFull

This is a class for the single definition of parenRealListFull.
It represents the following items:

'(' realList ')'

*/

class parenRealListFull :
  public iso14649CppBase
{
public:
  parenRealListFull(){}
  parenRealListFull(
    std::list<real *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenRealListFull();
  int isA(int aType)
    { return (aType == parenRealListFull_E); }
  void printSelf();
  std::list<real *> * get_theList()
    {return theList;}
  void set_theList(std::list<real *> * theListIn)
    {theList = theListIn;}
private:
  std::list<real *> * theList;
};

/********************************************************************/

/* parenStringList

This is a class for the list parenStringList.
It represents the following items:

'(' stringList ')'
  or
'(' ')'

*/

class parenStringList :
  public iso14649CppBase
{
public:
  parenStringList(){}
  parenStringList(
    std::list<char *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenStringList();
  int isA(int aType)
    { return (aType == parenStringList_E); }
  void printSelf();
  std::list<char *> * get_theList()
    {return theList;}
  void set_theList(std::list<char *> * theListIn)
    {theList = theListIn;}
private:
  std::list<char *> * theList;
};

/********************************************************************/

/* parenStringListFull

This is a class for the single definition of parenStringListFull.
It represents the following items:

'(' stringList ')'

*/

class parenStringListFull :
  public iso14649CppBase
{
public:
  parenStringListFull(){}
  parenStringListFull(
    std::list<char *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenStringListFull();
  int isA(int aType)
    { return (aType == parenStringListFull_E); }
  void printSelf();
  std::list<char *> * get_theList()
    {return theList;}
  void set_theList(std::list<char *> * theListIn)
    {theList = theListIn;}
private:
  std::list<char *> * theList;
};

/********************************************************************/

/* instance

This is the instance class.

*/

class instance :
  public iso14649CppBase
{
public:
  instance(){}
  instance(instanceId * idIn)
  {
    id = idIn;
  }
  ~instance(){}
  int isA(int aType) = 0;
  void printSelf() = 0;
  instanceId * get_id(){return id;}
  void set_id(instanceId * idIn){id = idIn;}
private:
  instanceId * id;
};

/********************************************************************/

/* approachRetractStrategy

This is a parent class.

*/

class approachRetractStrategy :
  public iso14649CppBase
{
  friend int yyparse();
public:
  approachRetractStrategy(){}
  approachRetractStrategy(
    direction * toolOrientationIn)
    {
      toolOrientation = toolOrientationIn;
    }
  ~approachRetractStrategy(){}
  int isA(int aType)
    { return (aType == approachRetractStrategy_E); }
  void printSelf() = 0;
  direction * get_toolOrientation()
    {return toolOrientation;}
  void set_toolOrientation(direction * toolOrientationIn)
    {toolOrientation = toolOrientationIn;}
private:
  direction * toolOrientation;
};

/********************************************************************/

/* approval

This is a class for the single definition of approval.
It represents the following items:

APPROVAL '(' approvalStatus ',' CHARSTRING ')'

*/

class approval :
  public instance
{
  friend int yyparse();
public:
  approval(){}
  approval(
    approvalStatus * statusIn,
    char * levelIn)
    {
      status = statusIn;
      level = levelIn;
    }
  ~approval();
  int isA(int aType)
    { return (aType == approval_E); }
  void printSelf();
  approvalStatus * get_status()
    {return status;}
  void set_status(approvalStatus * statusIn)
    {status = statusIn;}
  char * get_level()
    {return level;}
  void set_level(char * levelIn)
    {level = levelIn;}
private:
  approvalStatus * status;
  char * level;
};

/********************************************************************/

/* approvalStatus

This is a class for the single definition of approvalStatus.
It represents the following items:

APPROVALSTATUS '(' CHARSTRING ')'

*/

class approvalStatus :
  public instance
{
  friend int yyparse();
public:
  approvalStatus(){}
  approvalStatus(
    char * nameIn)
    {
      name = nameIn;
    }
  ~approvalStatus();
  int isA(int aType)
    { return (aType == approvalStatus_E); }
  void printSelf();
  char * get_name()
    {return name;}
  void set_name(char * nameIn)
    {name = nameIn;}
private:
  char * name;
};

/********************************************************************/

/* boolean

This is a parent class.

*/

class boolean :
  public iso14649CppBase
{
public:
  boolean(){}
  ~boolean(){}
  int isA(int aType)
    { return (aType == boolean_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* channel

This is a class for the single definition of channel.
It represents the following items:

CHANNEL '(' CHARSTRING ')'

*/

class channel :
  public instance
{
  friend int yyparse();
public:
  channel(){}
  channel(
    char * itsIdIn)
    {
      itsId = itsIdIn;
    }
  ~channel();
  int isA(int aType)
    { return (aType == channel_E); }
  void printSelf();
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
private:
  char * itsId;
};

/********************************************************************/

/* circularOffset

This is a class for the single definition of circularOffset.
It represents the following items:

CIRCULAROFFSET '(' REALSTRING ',' INTSTRING ')'

*/

class circularOffset :
  public instance
{
  friend int yyparse();
public:
  circularOffset(){}
  circularOffset(
    double angularOffsetIn,
    int indexIn)
    {
      angularOffset = angularOffsetIn;
      index = indexIn;
    }
  ~circularOffset();
  int isA(int aType)
    { return (aType == circularOffset_E); }
  void printSelf();
  double get_angularOffset()
    {return angularOffset;}
  void set_angularOffset(double angularOffsetIn)
    {angularOffset = angularOffsetIn;}
  int get_index()
    {return index;}
  void set_index(int indexIn)
    {index = indexIn;}
private:
  double angularOffset;
  int index;
};

/********************************************************************/

/* circularOmit

This is a class for the single definition of circularOmit.
It represents the following items:

CIRCULAROMIT '(' INTSTRING ')'

*/

class circularOmit :
  public instance
{
  friend int yyparse();
public:
  circularOmit(){}
  circularOmit(
    int indexIn)
    {
      index = indexIn;
    }
  ~circularOmit();
  int isA(int aType)
    { return (aType == circularOmit_E); }
  void printSelf();
  int get_index()
    {return index;}
  void set_index(int indexIn)
    {index = indexIn;}
private:
  int index;
};

/********************************************************************/

/* compositeCurveSegment

This is a class for the single definition of compositeCurveSegment.
It represents the following items:

COMPOSITECURVESEGMENT '(' transitionCode ',' boolean ',' curve ')'

*/

class compositeCurveSegment :
  public instance
{
  friend int yyparse();
public:
  compositeCurveSegment(){}
  compositeCurveSegment(
    transitionCode * transitionIn,
    boolean * sameSenseIn,
    curve * parentCurveIn)
    {
      transition = transitionIn;
      sameSense = sameSenseIn;
      parentCurve = parentCurveIn;
    }
  ~compositeCurveSegment();
  int isA(int aType)
    { return (aType == compositeCurveSegment_E); }
  void printSelf();
  transitionCode * get_transition()
    {return transition;}
  void set_transition(transitionCode * transitionIn)
    {transition = transitionIn;}
  boolean * get_sameSense()
    {return sameSense;}
  void set_sameSense(boolean * sameSenseIn)
    {sameSense = sameSenseIn;}
  curve * get_parentCurve()
    {return parentCurve;}
  void set_parentCurve(curve * parentCurveIn)
    {parentCurve = parentCurveIn;}
private:
  transitionCode * transition;
  boolean * sameSense;
  curve * parentCurve;
};

/********************************************************************/

/* compoundFeatureSelect

This is a parent class.

*/

class compoundFeatureSelect :
  public iso14649CppBase
{
  friend int yyparse();
public:
  compoundFeatureSelect(){}
  ~compoundFeatureSelect(){}
  int isA(int aType)
    { return (aType == compoundFeatureSelect_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* cutmodeType

This is a parent class.

*/

class cutmodeType :
  public iso14649CppBase
{
public:
  cutmodeType(){}
  ~cutmodeType(){}
  int isA(int aType)
    { return (aType == cutmodeType_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* cutmodeTypeClimb

This is a class for the single definition of cutmodeTypeClimb.
It represents the following items:

CLIMB

*/

class cutmodeTypeClimb :
  public cutmodeType
{
public:
  cutmodeTypeClimb(){}
  ~cutmodeTypeClimb();
  int isA(int aType)
    { return ((aType == cutmodeTypeClimb_E) ||
	      (aType == cutmodeType_E));
    }
  void printSelf();
};

/********************************************************************/

/* cutmodeTypeConventional

This is a class for the single definition of cutmodeTypeConventional.
It represents the following items:

CONVENTIONAL

*/

class cutmodeTypeConventional :
  public cutmodeType
{
public:
  cutmodeTypeConventional(){}
  ~cutmodeTypeConventional();
  int isA(int aType)
    { return ((aType == cutmodeTypeConventional_E) ||
	      (aType == cutmodeType_E));
    }
  void printSelf();
};

/********************************************************************/

/* cuttingComponent

This is a class for the single definition of cuttingComponent.
It represents the following items:

CUTTINGCOMPONENT '(' REALSTRING ',' optMaterial ',' optCuttingEdgeTechnologicalData ',' optReal ',' optMillingTechnology ')'

*/

class cuttingComponent :
  public instance
{
  friend int yyparse();
public:
  cuttingComponent(){}
  cuttingComponent(
    double toolOffsetLengthIn,
    material * itsMaterialIn,
    cuttingEdgeTechnologicalData * technologicalDataIn,
    real * expectedToolLifeIn,
    millingTechnology * itsTechnologyIn)
    {
      toolOffsetLength = toolOffsetLengthIn;
      itsMaterial = itsMaterialIn;
      technologicalData = technologicalDataIn;
      expectedToolLife = expectedToolLifeIn;
      itsTechnology = itsTechnologyIn;
    }
  ~cuttingComponent();
  int isA(int aType)
    { return (aType == cuttingComponent_E); }
  void printSelf();
  double get_toolOffsetLength()
    {return toolOffsetLength;}
  void set_toolOffsetLength(double toolOffsetLengthIn)
    {toolOffsetLength = toolOffsetLengthIn;}
  material * get_itsMaterial()
    {return itsMaterial;}
  void set_itsMaterial(material * itsMaterialIn)
    {itsMaterial = itsMaterialIn;}
  cuttingEdgeTechnologicalData * get_technologicalData()
    {return technologicalData;}
  void set_technologicalData(cuttingEdgeTechnologicalData * technologicalDataIn)
    {technologicalData = technologicalDataIn;}
  real * get_expectedToolLife()
    {return expectedToolLife;}
  void set_expectedToolLife(real * expectedToolLifeIn)
    {expectedToolLife = expectedToolLifeIn;}
  millingTechnology * get_itsTechnology()
    {return itsTechnology;}
  void set_itsTechnology(millingTechnology * itsTechnologyIn)
    {itsTechnology = itsTechnologyIn;}
private:
  double toolOffsetLength;
  material * itsMaterial;
  cuttingEdgeTechnologicalData * technologicalData;
  real * expectedToolLife;
  millingTechnology * itsTechnology;
};

/********************************************************************/

/* cuttingEdgeTechnologicalData

This is a class for the single definition of cuttingEdgeTechnologicalData.
It represents the following items:

CUTTINGEDGETECHNOLOGICALDATA '(' optReal ',' optReal ',' optReal ')'

*/

class cuttingEdgeTechnologicalData :
  public instance
{
  friend int yyparse();
public:
  cuttingEdgeTechnologicalData(){}
  cuttingEdgeTechnologicalData(
    real * cuttingAngleIn,
    real * freeAngleIn,
    real * auxAngleIn)
    {
      cuttingAngle = cuttingAngleIn;
      freeAngle = freeAngleIn;
      auxAngle = auxAngleIn;
    }
  ~cuttingEdgeTechnologicalData();
  int isA(int aType)
    { return (aType == cuttingEdgeTechnologicalData_E); }
  void printSelf();
  real * get_cuttingAngle()
    {return cuttingAngle;}
  void set_cuttingAngle(real * cuttingAngleIn)
    {cuttingAngle = cuttingAngleIn;}
  real * get_freeAngle()
    {return freeAngle;}
  void set_freeAngle(real * freeAngleIn)
    {freeAngle = freeAngleIn;}
  real * get_auxAngle()
    {return auxAngle;}
  void set_auxAngle(real * auxAngleIn)
    {auxAngle = auxAngleIn;}
private:
  real * cuttingAngle;
  real * freeAngle;
  real * auxAngle;
};

/********************************************************************/

/* date

This is a parent class.

*/

class date :
  public iso14649CppBase
{
  friend int yyparse();
public:
  date(){}
  ~date(){}
  int isA(int aType)
    { return (aType == date_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* dateAndTime

This is a class for the single definition of dateAndTime.
It represents the following items:

DATEANDTIME '(' date ',' CHARSTRING ')'

*/

class dateAndTime :
  public instance
{
  friend int yyparse();
public:
  dateAndTime(){}
  dateAndTime(
    date * dateComponentIn,
    char * timeComponentIn)
    {
      dateComponent = dateComponentIn;
      timeComponent = timeComponentIn;
    }
  ~dateAndTime();
  int isA(int aType)
    { return (aType == dateAndTime_E); }
  void printSelf();
  date * get_dateComponent()
    {return dateComponent;}
  void set_dateComponent(date * dateComponentIn)
    {dateComponent = dateComponentIn;}
  char * get_timeComponent()
    {return timeComponent;}
  void set_timeComponent(char * timeComponentIn)
    {timeComponent = timeComponentIn;}
private:
  date * dateComponent;
  char * timeComponent;
};

/********************************************************************/

/* drillingTypeStrategy

This is a class for the single definition of drillingTypeStrategy.
It represents the following items:

DRILLINGTYPESTRATEGY '(' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class drillingTypeStrategy :
  public instance
{
  friend int yyparse();
public:
  drillingTypeStrategy(){}
  drillingTypeStrategy(
    real * reducedCutAtStartIn,
    real * reducedFeedAtStartIn,
    real * depthOfStartIn,
    real * reducedCutAtEndIn,
    real * reducedFeedAtEndIn,
    real * depthOfEndIn)
    {
      reducedCutAtStart = reducedCutAtStartIn;
      reducedFeedAtStart = reducedFeedAtStartIn;
      depthOfStart = depthOfStartIn;
      reducedCutAtEnd = reducedCutAtEndIn;
      reducedFeedAtEnd = reducedFeedAtEndIn;
      depthOfEnd = depthOfEndIn;
    }
  ~drillingTypeStrategy();
  int isA(int aType)
    { return (aType == drillingTypeStrategy_E); }
  void printSelf();
  real * get_reducedCutAtStart()
    {return reducedCutAtStart;}
  void set_reducedCutAtStart(real * reducedCutAtStartIn)
    {reducedCutAtStart = reducedCutAtStartIn;}
  real * get_reducedFeedAtStart()
    {return reducedFeedAtStart;}
  void set_reducedFeedAtStart(real * reducedFeedAtStartIn)
    {reducedFeedAtStart = reducedFeedAtStartIn;}
  real * get_depthOfStart()
    {return depthOfStart;}
  void set_depthOfStart(real * depthOfStartIn)
    {depthOfStart = depthOfStartIn;}
  real * get_reducedCutAtEnd()
    {return reducedCutAtEnd;}
  void set_reducedCutAtEnd(real * reducedCutAtEndIn)
    {reducedCutAtEnd = reducedCutAtEndIn;}
  real * get_reducedFeedAtEnd()
    {return reducedFeedAtEnd;}
  void set_reducedFeedAtEnd(real * reducedFeedAtEndIn)
    {reducedFeedAtEnd = reducedFeedAtEndIn;}
  real * get_depthOfEnd()
    {return depthOfEnd;}
  void set_depthOfEnd(real * depthOfEndIn)
    {depthOfEnd = depthOfEndIn;}
private:
  real * reducedCutAtStart;
  real * reducedFeedAtStart;
  real * depthOfStart;
  real * reducedCutAtEnd;
  real * reducedFeedAtEnd;
  real * depthOfEnd;
};

/********************************************************************/

/* executable

This is a parent class.

*/

class executable :
  public iso14649CppBase
{
  friend int yyparse();
public:
  executable(){}
  executable(
    char * itsIdIn)
    {
      itsId = itsIdIn;
    }
  ~executable(){}
  int isA(int aType)
    { return (aType == executable_E); }
  void printSelf() = 0;
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
private:
  char * itsId;
};

/********************************************************************/

/* fittingType

This is a parent class.

*/

class fittingType :
  public iso14649CppBase
{
public:
  fittingType(){}
  ~fittingType(){}
  int isA(int aType)
    { return (aType == fittingType_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* fittingTypeHole

This is a class for the single definition of fittingTypeHole.
It represents the following items:

HOLE

*/

class fittingTypeHole :
  public fittingType
{
public:
  fittingTypeHole(){}
  ~fittingTypeHole();
  int isA(int aType)
    { return ((aType == fittingTypeHole_E) ||
	      (aType == fittingType_E));
    }
  void printSelf();
};

/********************************************************************/

/* fittingTypeShaft

This is a class for the single definition of fittingTypeShaft.
It represents the following items:

SHAFT

*/

class fittingTypeShaft :
  public fittingType
{
public:
  fittingTypeShaft(){}
  ~fittingTypeShaft();
  int isA(int aType)
    { return ((aType == fittingTypeShaft_E) ||
	      (aType == fittingType_E));
    }
  void printSelf();
};

/********************************************************************/

/* freeformStrategy

This is a parent class.

*/

class freeformStrategy :
  public iso14649CppBase
{
  friend int yyparse();
public:
  freeformStrategy(){}
  freeformStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn)
    {
      pathmode = pathmodeIn;
      cutmode = cutmodeIn;
      itsMillingTolerances = itsMillingTolerancesIn;
      stepover = stepoverIn;
    }
  ~freeformStrategy(){}
  int isA(int aType)
    { return (aType == freeformStrategy_E); }
  void printSelf() = 0;
  pathmodeType * get_pathmode()
    {return pathmode;}
  void set_pathmode(pathmodeType * pathmodeIn)
    {pathmode = pathmodeIn;}
  cutmodeType * get_cutmode()
    {return cutmode;}
  void set_cutmode(cutmodeType * cutmodeIn)
    {cutmode = cutmodeIn;}
  tolerances * get_itsMillingTolerances()
    {return itsMillingTolerances;}
  void set_itsMillingTolerances(tolerances * itsMillingTolerancesIn)
    {itsMillingTolerances = itsMillingTolerancesIn;}
  real * get_stepover()
    {return stepover;}
  void set_stepover(real * stepoverIn)
    {stepover = stepoverIn;}
private:
  pathmodeType * pathmode;
  cutmodeType * cutmode;
  tolerances * itsMillingTolerances;
  real * stepover;
};

/********************************************************************/

/* hand

This is a parent class.

*/

class hand :
  public iso14649CppBase
{
public:
  hand(){}
  ~hand(){}
  int isA(int aType)
    { return (aType == hand_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* handRight

This is a class for the single definition of handRight.
It represents the following items:

RIGHT

*/

class handRight :
  public hand
{
public:
  handRight(){}
  ~handRight();
  int isA(int aType)
    { return ((aType == handRight_E) ||
	      (aType == hand_E));
    }
  void printSelf();
};

/********************************************************************/

/* handLeft

This is a class for the single definition of handLeft.
It represents the following items:

LEFT

*/

class handLeft :
  public hand
{
public:
  handLeft(){}
  ~handLeft();
  int isA(int aType)
    { return ((aType == handLeft_E) ||
	      (aType == hand_E));
    }
  void printSelf();
};

/********************************************************************/

/* holeBottomCondition

This is a parent class.

*/

class holeBottomCondition :
  public iso14649CppBase
{
  friend int yyparse();
public:
  holeBottomCondition(){}
  ~holeBottomCondition(){}
  int isA(int aType)
    { return (aType == holeBottomCondition_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* inProcessGeometry

This is a class for the single definition of inProcessGeometry.
It represents the following items:

INPROCESSGEOMETRY '(' optAdvancedBrepShapeRepresentation ',' optAdvancedBrepShapeRepresentation ',' optAdvancedBrepShapeRepresentation ')'

*/

class inProcessGeometry :
  public iso14649CppBase
{
public:
  inProcessGeometry(){}
  inProcessGeometry(
    advancedBrepShapeRepresentation * asIsIn,
    advancedBrepShapeRepresentation * toBeIn,
    advancedBrepShapeRepresentation * removalIn)
    {
      asIs = asIsIn;
      toBe = toBeIn;
      removal = removalIn;
    }
  ~inProcessGeometry();
  int isA(int aType)
    { return (aType == inProcessGeometry_E); }
  void printSelf();
  advancedBrepShapeRepresentation * get_asIs()
    {return asIs;}
  void set_asIs(advancedBrepShapeRepresentation * asIsIn)
    {asIs = asIsIn;}
  advancedBrepShapeRepresentation * get_toBe()
    {return toBe;}
  void set_toBe(advancedBrepShapeRepresentation * toBeIn)
    {toBe = toBeIn;}
  advancedBrepShapeRepresentation * get_removal()
    {return removal;}
  void set_removal(advancedBrepShapeRepresentation * removalIn)
    {removal = removalIn;}
private:
  advancedBrepShapeRepresentation * asIs;
  advancedBrepShapeRepresentation * toBe;
  advancedBrepShapeRepresentation * removal;
};

/********************************************************************/

/* integer

This is a class for the single definition of integer.
It represents the following items:

INTSTRING

*/

class integer :
  public iso14649CppBase
{
public:
  integer(){}
  integer(
    int valIn)
    {
      val = valIn;
    }
  ~integer();
  int isA(int aType)
    { return (aType == integer_E); }
  void printSelf();
  int get_val()
    {return val;}
  void set_val(int valIn)
    {val = valIn;}
private:
  int val;
};

/********************************************************************/

/* leadingLineStrategy

This is a class for the single definition of leadingLineStrategy.
It represents the following items:

LEADINGLINESTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' boundedCurve ')'

*/

class leadingLineStrategy :
  public instance,
  public freeformStrategy
{
  friend int yyparse();
public:
  leadingLineStrategy(){}
  leadingLineStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    boundedCurve * itsLineIn) :
      freeformStrategy(
        pathmodeIn,
        cutmodeIn,
        itsMillingTolerancesIn,
        stepoverIn)
    {
      itsLine = itsLineIn;
    }
  ~leadingLineStrategy();
  int isA(int aType)
    { return ((aType == leadingLineStrategy_E) ||
	      (aType == freeformStrategy_E));
    }
  void printSelf();
  boundedCurve * get_itsLine()
    {return itsLine;}
  void set_itsLine(boundedCurve * itsLineIn)
    {itsLine = itsLineIn;}
private:
  boundedCurve * itsLine;
};

/********************************************************************/

/* leftOrRight

This is a parent class.

*/

class leftOrRight :
  public iso14649CppBase
{
public:
  leftOrRight(){}
  ~leftOrRight(){}
  int isA(int aType)
    { return (aType == leftOrRight_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* leftOrRightLeft

This is a class for the single definition of leftOrRightLeft.
It represents the following items:

LEFT

*/

class leftOrRightLeft :
  public leftOrRight
{
public:
  leftOrRightLeft(){}
  ~leftOrRightLeft();
  int isA(int aType)
    { return ((aType == leftOrRightLeft_E) ||
	      (aType == leftOrRight_E));
    }
  void printSelf();
};

/********************************************************************/

/* leftOrRightRight

This is a class for the single definition of leftOrRightRight.
It represents the following items:

RIGHT

*/

class leftOrRightRight :
  public leftOrRight
{
public:
  leftOrRightRight(){}
  ~leftOrRightRight();
  int isA(int aType)
    { return ((aType == leftOrRightRight_E) ||
	      (aType == leftOrRight_E));
    }
  void printSelf();
};

/********************************************************************/

/* logical

This is a parent class.

*/

class logical :
  public iso14649CppBase
{
public:
  logical(){}
  ~logical(){}
  int isA(int aType)
    { return (aType == logical_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* logicalUnknown

This is a class for the single definition of logicalUnknown.
It represents the following items:

UNKNOWN

*/

class logicalUnknown :
  public logical
{
public:
  logicalUnknown(){}
  ~logicalUnknown();
  int isA(int aType)
    { return ((aType == logicalUnknown_E) ||
	      (aType == logical_E));
    }
  void printSelf();
};

/********************************************************************/

/* machineFunctions

This is a parent class.

*/

class machineFunctions :
  public iso14649CppBase
{
  friend int yyparse();
public:
  machineFunctions(){}
  ~machineFunctions(){}
  int isA(int aType)
    { return (aType == machineFunctions_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* machiningTool

This is a parent class.

*/

class machiningTool :
  public iso14649CppBase
{
  friend int yyparse();
public:
  machiningTool(){}
  machiningTool(
    char * itsIdIn)
    {
      itsId = itsIdIn;
    }
  ~machiningTool(){}
  int isA(int aType)
    { return (aType == machiningTool_E); }
  void printSelf() = 0;
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
private:
  char * itsId;
};

/********************************************************************/

/* manufacturingFeature

This is a parent class.

*/

class manufacturingFeature :
  public iso14649CppBase
{
  friend int yyparse();
public:
  manufacturingFeature(){}
  manufacturingFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn)
    {
      itsId = itsIdIn;
      itsWorkpiece = itsWorkpieceIn;
      itsOperations = itsOperationsIn;
    }
  ~manufacturingFeature(){}
  int isA(int aType)
    { return (aType == manufacturingFeature_E); }
  void printSelf() = 0;
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
  workpiece * get_itsWorkpiece()
    {return itsWorkpiece;}
  void set_itsWorkpiece(workpiece * itsWorkpieceIn)
    {itsWorkpiece = itsWorkpieceIn;}
  parenMachiningOperationList * get_itsOperations()
    {return itsOperations;}
  void set_itsOperations(parenMachiningOperationList * itsOperationsIn)
    {itsOperations = itsOperationsIn;}
private:
  char * itsId;
  workpiece * itsWorkpiece;
  parenMachiningOperationList * itsOperations;
};

/********************************************************************/

/* material

This is a class for the single definition of material.
It represents the following items:

MATERIAL '(' CHARSTRING ',' CHARSTRING ',' parenPropertyParameterList ')'

*/

class material :
  public instance
{
  friend int yyparse();
public:
  material(){}
  material(
    char * standardIdentifierIn,
    char * materialIdentifierIn,
    parenPropertyParameterList * materialPropertyIn)
    {
      standardIdentifier = standardIdentifierIn;
      materialIdentifier = materialIdentifierIn;
      materialProperty = materialPropertyIn;
    }
  ~material();
  int isA(int aType)
    { return (aType == material_E); }
  void printSelf();
  char * get_standardIdentifier()
    {return standardIdentifier;}
  void set_standardIdentifier(char * standardIdentifierIn)
    {standardIdentifier = standardIdentifierIn;}
  char * get_materialIdentifier()
    {return materialIdentifier;}
  void set_materialIdentifier(char * materialIdentifierIn)
    {materialIdentifier = materialIdentifierIn;}
  parenPropertyParameterList * get_materialProperty()
    {return materialProperty;}
  void set_materialProperty(parenPropertyParameterList * materialPropertyIn)
    {materialProperty = materialPropertyIn;}
private:
  char * standardIdentifier;
  char * materialIdentifier;
  parenPropertyParameterList * materialProperty;
};

/********************************************************************/

/* millingMachineFunctions

This is a class for the single definition of millingMachineFunctions.
It represents the following items:

MILLINGMACHINEFUNCTIONS '(' boolean ',' optReal ',' optBoolean ',' boolean ',' optReal ',' parenStringList ',' boolean ',' optDirection ',' optProcessModelList ',' parenPropertyParameterList ')'

*/

class millingMachineFunctions :
  public instance,
  public machineFunctions
{
  friend int yyparse();
public:
  millingMachineFunctions(){}
  millingMachineFunctions(
    boolean * coolantIn,
    real * coolantPressureIn,
    boolean * mistIn,
    boolean * throughSpindleCoolantIn,
    real * throughPressureIn,
    parenStringList * axisClampingIn,
    boolean * chipRemovalIn,
    direction * orientedSpindleStopIn,
    processModelList * itsProcessModelIn,
    parenPropertyParameterList * otherFunctionsIn)
    {
      coolant = coolantIn;
      coolantPressure = coolantPressureIn;
      mist = mistIn;
      throughSpindleCoolant = throughSpindleCoolantIn;
      throughPressure = throughPressureIn;
      axisClamping = axisClampingIn;
      chipRemoval = chipRemovalIn;
      orientedSpindleStop = orientedSpindleStopIn;
      itsProcessModel = itsProcessModelIn;
      otherFunctions = otherFunctionsIn;
    }
  ~millingMachineFunctions();
  int isA(int aType)
    { return ((aType == millingMachineFunctions_E) ||
	      (aType == machineFunctions_E));
    }
  void printSelf();
  boolean * get_coolant()
    {return coolant;}
  void set_coolant(boolean * coolantIn)
    {coolant = coolantIn;}
  real * get_coolantPressure()
    {return coolantPressure;}
  void set_coolantPressure(real * coolantPressureIn)
    {coolantPressure = coolantPressureIn;}
  boolean * get_mist()
    {return mist;}
  void set_mist(boolean * mistIn)
    {mist = mistIn;}
  boolean * get_throughSpindleCoolant()
    {return throughSpindleCoolant;}
  void set_throughSpindleCoolant(boolean * throughSpindleCoolantIn)
    {throughSpindleCoolant = throughSpindleCoolantIn;}
  real * get_throughPressure()
    {return throughPressure;}
  void set_throughPressure(real * throughPressureIn)
    {throughPressure = throughPressureIn;}
  parenStringList * get_axisClamping()
    {return axisClamping;}
  void set_axisClamping(parenStringList * axisClampingIn)
    {axisClamping = axisClampingIn;}
  boolean * get_chipRemoval()
    {return chipRemoval;}
  void set_chipRemoval(boolean * chipRemovalIn)
    {chipRemoval = chipRemovalIn;}
  direction * get_orientedSpindleStop()
    {return orientedSpindleStop;}
  void set_orientedSpindleStop(direction * orientedSpindleStopIn)
    {orientedSpindleStop = orientedSpindleStopIn;}
  processModelList * get_itsProcessModel()
    {return itsProcessModel;}
  void set_itsProcessModel(processModelList * itsProcessModelIn)
    {itsProcessModel = itsProcessModelIn;}
  parenPropertyParameterList * get_otherFunctions()
    {return otherFunctions;}
  void set_otherFunctions(parenPropertyParameterList * otherFunctionsIn)
    {otherFunctions = otherFunctionsIn;}
private:
  boolean * coolant;
  real * coolantPressure;
  boolean * mist;
  boolean * throughSpindleCoolant;
  real * throughPressure;
  parenStringList * axisClamping;
  boolean * chipRemoval;
  direction * orientedSpindleStop;
  processModelList * itsProcessModel;
  parenPropertyParameterList * otherFunctions;
};

/********************************************************************/

/* millingToolDimension

This is a class for the single definition of millingToolDimension.
It represents the following items:

MILLINGTOOLDIMENSION '(' REALSTRING ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class millingToolDimension :
  public instance
{
  friend int yyparse();
public:
  millingToolDimension(){}
  millingToolDimension(
    double diameterIn,
    real * toolTopAngleIn,
    real * toolCircumferenceAngleIn,
    real * cuttingEdgeLengthIn,
    real * edgeRadiusIn,
    real * edgeCenterVerticalIn,
    real * edgeCenterHorizontalIn)
    {
      diameter = diameterIn;
      toolTopAngle = toolTopAngleIn;
      toolCircumferenceAngle = toolCircumferenceAngleIn;
      cuttingEdgeLength = cuttingEdgeLengthIn;
      edgeRadius = edgeRadiusIn;
      edgeCenterVertical = edgeCenterVerticalIn;
      edgeCenterHorizontal = edgeCenterHorizontalIn;
    }
  ~millingToolDimension();
  int isA(int aType)
    { return (aType == millingToolDimension_E); }
  void printSelf();
  double get_diameter()
    {return diameter;}
  void set_diameter(double diameterIn)
    {diameter = diameterIn;}
  real * get_toolTopAngle()
    {return toolTopAngle;}
  void set_toolTopAngle(real * toolTopAngleIn)
    {toolTopAngle = toolTopAngleIn;}
  real * get_toolCircumferenceAngle()
    {return toolCircumferenceAngle;}
  void set_toolCircumferenceAngle(real * toolCircumferenceAngleIn)
    {toolCircumferenceAngle = toolCircumferenceAngleIn;}
  real * get_cuttingEdgeLength()
    {return cuttingEdgeLength;}
  void set_cuttingEdgeLength(real * cuttingEdgeLengthIn)
    {cuttingEdgeLength = cuttingEdgeLengthIn;}
  real * get_edgeRadius()
    {return edgeRadius;}
  void set_edgeRadius(real * edgeRadiusIn)
    {edgeRadius = edgeRadiusIn;}
  real * get_edgeCenterVertical()
    {return edgeCenterVertical;}
  void set_edgeCenterVertical(real * edgeCenterVerticalIn)
    {edgeCenterVertical = edgeCenterVerticalIn;}
  real * get_edgeCenterHorizontal()
    {return edgeCenterHorizontal;}
  void set_edgeCenterHorizontal(real * edgeCenterHorizontalIn)
    {edgeCenterHorizontal = edgeCenterHorizontalIn;}
private:
  double diameter;
  real * toolTopAngle;
  real * toolCircumferenceAngle;
  real * cuttingEdgeLength;
  real * edgeRadius;
  real * edgeCenterVertical;
  real * edgeCenterHorizontal;
};

/********************************************************************/

/* ncFunction

This is a parent class.

*/

class ncFunction :
  public executable
{
  friend int yyparse();
public:
  ncFunction(){}
  ncFunction(
    char * itsIdIn) :
      executable(
        itsIdIn)
    {}
  ~ncFunction(){}
  int isA(int aType)
    { return ((aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* ncVariable

This is a class for the single definition of ncVariable.
It represents the following items:

NCVARIABLE '(' CHARSTRING ',' optReal ')'

*/

class ncVariable :
  public instance
{
  friend int yyparse();
public:
  ncVariable(){}
  ncVariable(
    char * itsNameIn,
    real * initialValueIn)
    {
      itsName = itsNameIn;
      initialValue = initialValueIn;
    }
  ~ncVariable();
  int isA(int aType)
    { return (aType == ncVariable_E); }
  void printSelf();
  char * get_itsName()
    {return itsName;}
  void set_itsName(char * itsNameIn)
    {itsName = itsNameIn;}
  real * get_initialValue()
    {return initialValue;}
  void set_initialValue(real * initialValueIn)
    {initialValue = initialValueIn;}
private:
  char * itsName;
  real * initialValue;
};

/********************************************************************/

/* offsetVector

This is a class for the single definition of offsetVector.
It represents the following items:

OFFSETVECTOR '(' parenNcVariableListFull ',' optParenNcVariableListFull ')'

*/

class offsetVector :
  public iso14649CppBase
{
public:
  offsetVector(){}
  offsetVector(
    parenNcVariableListFull * translateIn,
    parenNcVariableListFull * rotateIn)
    {
      translate = translateIn;
      rotate = rotateIn;
    }
  ~offsetVector();
  int isA(int aType)
    { return (aType == offsetVector_E); }
  void printSelf();
  parenNcVariableListFull * get_translate()
    {return translate;}
  void set_translate(parenNcVariableListFull * translateIn)
    {translate = translateIn;}
  parenNcVariableListFull * get_rotate()
    {return rotate;}
  void set_rotate(parenNcVariableListFull * rotateIn)
    {rotate = rotateIn;}
private:
  parenNcVariableListFull * translate;
  parenNcVariableListFull * rotate;
};

/********************************************************************/

/* operation

This is a parent class.

*/

class operation :
  public iso14649CppBase
{
  friend int yyparse();
public:
  operation(){}
  operation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn)
    {
      itsToolpath = itsToolpathIn;
      itsToolDirection = itsToolDirectionIn;
    }
  ~operation(){}
  int isA(int aType)
    { return (aType == operation_E); }
  void printSelf() = 0;
  toolpathList * get_itsToolpath()
    {return itsToolpath;}
  void set_itsToolpath(toolpathList * itsToolpathIn)
    {itsToolpath = itsToolpathIn;}
  toolDirection * get_itsToolDirection()
    {return itsToolDirection;}
  void set_itsToolDirection(toolDirection * itsToolDirectionIn)
    {itsToolDirection = itsToolDirectionIn;}
private:
  toolpathList * itsToolpath;
  toolDirection * itsToolDirection;
};

/********************************************************************/

/* optionalStop

This is a class for the single definition of optionalStop.
It represents the following items:

OPTIONALSTOP '(' CHARSTRING ')'

*/

class optionalStop :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  optionalStop(){}
  optionalStop(
    char * itsIdIn) :
      ncFunction(
        itsIdIn)
    {}
  ~optionalStop();
  int isA(int aType)
    { return ((aType == optionalStop_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
};

/********************************************************************/

/* parenAxis2placement3dListFull

This is a class for the single definition of parenAxis2placement3dListFull.
It represents the following items:

'(' axis2placement3dList ')'

*/

class parenAxis2placement3dListFull :
  public iso14649CppBase
{
public:
  parenAxis2placement3dListFull(){}
  parenAxis2placement3dListFull(
    std::list<axis2placement3d *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenAxis2placement3dListFull();
  int isA(int aType)
    { return (aType == parenAxis2placement3dListFull_E); }
  void printSelf();
  std::list<axis2placement3d *> * get_theList()
    {return theList;}
  void set_theList(std::list<axis2placement3d *> * theListIn)
    {theList = theListIn;}
private:
  std::list<axis2placement3d *> * theList;
};

/********************************************************************/

/* parenBossList

This is a class for the list parenBossList.
It represents the following items:

'(' bossList ')'
  or
'(' ')'

*/

class parenBossList :
  public iso14649CppBase
{
public:
  parenBossList(){}
  parenBossList(
    std::list<boss *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenBossList();
  int isA(int aType)
    { return (aType == parenBossList_E); }
  void printSelf();
  std::list<boss *> * get_theList()
    {return theList;}
  void set_theList(std::list<boss *> * theListIn)
    {theList = theListIn;}
private:
  std::list<boss *> * theList;
};

/********************************************************************/

/* parenCartesianPointList

This is a class for the list parenCartesianPointList.
It represents the following items:

'(' cartesianPointList ')'
  or
'(' ')'

*/

class parenCartesianPointList :
  public iso14649CppBase
{
public:
  parenCartesianPointList(){}
  parenCartesianPointList(
    std::list<cartesianPoint *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCartesianPointList();
  int isA(int aType)
    { return (aType == parenCartesianPointList_E); }
  void printSelf();
  std::list<cartesianPoint *> * get_theList()
    {return theList;}
  void set_theList(std::list<cartesianPoint *> * theListIn)
    {theList = theListIn;}
private:
  std::list<cartesianPoint *> * theList;
};

/********************************************************************/

/* parenCartesianPointListFull

This is a class for the single definition of parenCartesianPointListFull.
It represents the following items:

'(' cartesianPointList ')'

*/

class parenCartesianPointListFull :
  public iso14649CppBase
{
public:
  parenCartesianPointListFull(){}
  parenCartesianPointListFull(
    std::list<cartesianPoint *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCartesianPointListFull();
  int isA(int aType)
    { return (aType == parenCartesianPointListFull_E); }
  void printSelf();
  std::list<cartesianPoint *> * get_theList()
    {return theList;}
  void set_theList(std::list<cartesianPoint *> * theListIn)
    {theList = theListIn;}
private:
  std::list<cartesianPoint *> * theList;
};

/********************************************************************/

/* parenCircularOffsetList

This is a class for the list parenCircularOffsetList.
It represents the following items:

'(' circularOffsetList ')'
  or
'(' ')'

*/

class parenCircularOffsetList :
  public iso14649CppBase
{
public:
  parenCircularOffsetList(){}
  parenCircularOffsetList(
    std::list<circularOffset *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCircularOffsetList();
  int isA(int aType)
    { return (aType == parenCircularOffsetList_E); }
  void printSelf();
  std::list<circularOffset *> * get_theList()
    {return theList;}
  void set_theList(std::list<circularOffset *> * theListIn)
    {theList = theListIn;}
private:
  std::list<circularOffset *> * theList;
};

/********************************************************************/

/* parenCircularOmitList

This is a class for the list parenCircularOmitList.
It represents the following items:

'(' circularOmitList ')'
  or
'(' ')'

*/

class parenCircularOmitList :
  public iso14649CppBase
{
public:
  parenCircularOmitList(){}
  parenCircularOmitList(
    std::list<circularOmit *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCircularOmitList();
  int isA(int aType)
    { return (aType == parenCircularOmitList_E); }
  void printSelf();
  std::list<circularOmit *> * get_theList()
    {return theList;}
  void set_theList(std::list<circularOmit *> * theListIn)
    {theList = theListIn;}
private:
  std::list<circularOmit *> * theList;
};

/********************************************************************/

/* parenCompositeCurveSegmentListFull

This is a class for the single definition of parenCompositeCurveSegmentListFull.
It represents the following items:

'(' compositeCurveSegmentList ')'

*/

class parenCompositeCurveSegmentListFull :
  public iso14649CppBase
{
public:
  parenCompositeCurveSegmentListFull(){}
  parenCompositeCurveSegmentListFull(
    std::list<compositeCurveSegment *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCompositeCurveSegmentListFull();
  int isA(int aType)
    { return (aType == parenCompositeCurveSegmentListFull_E); }
  void printSelf();
  std::list<compositeCurveSegment *> * get_theList()
    {return theList;}
  void set_theList(std::list<compositeCurveSegment *> * theListIn)
    {theList = theListIn;}
private:
  std::list<compositeCurveSegment *> * theList;
};

/********************************************************************/

/* parenCompoundFeatureSelectListFull

This is a class for the single definition of parenCompoundFeatureSelectListFull.
It represents the following items:

'(' compoundFeatureSelectList ')'

*/

class parenCompoundFeatureSelectListFull :
  public iso14649CppBase
{
public:
  parenCompoundFeatureSelectListFull(){}
  parenCompoundFeatureSelectListFull(
    std::list<compoundFeatureSelect *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCompoundFeatureSelectListFull();
  int isA(int aType)
    { return (aType == parenCompoundFeatureSelectListFull_E); }
  void printSelf();
  std::list<compoundFeatureSelect *> * get_theList()
    {return theList;}
  void set_theList(std::list<compoundFeatureSelect *> * theListIn)
    {theList = theListIn;}
private:
  std::list<compoundFeatureSelect *> * theList;
};

/********************************************************************/

/* parenCuttingComponentListFull

This is a class for the single definition of parenCuttingComponentListFull.
It represents the following items:

'(' cuttingComponentList ')'

*/

class parenCuttingComponentListFull :
  public iso14649CppBase
{
public:
  parenCuttingComponentListFull(){}
  parenCuttingComponentListFull(
    std::list<cuttingComponent *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenCuttingComponentListFull();
  int isA(int aType)
    { return (aType == parenCuttingComponentListFull_E); }
  void printSelf();
  std::list<cuttingComponent *> * get_theList()
    {return theList;}
  void set_theList(std::list<cuttingComponent *> * theListIn)
    {theList = theListIn;}
private:
  std::list<cuttingComponent *> * theList;
};

/********************************************************************/

/* parenExecutableList

This is a class for the list parenExecutableList.
It represents the following items:

'(' executableList ')'
  or
'(' ')'

*/

class parenExecutableList :
  public iso14649CppBase
{
public:
  parenExecutableList(){}
  parenExecutableList(
    std::list<executable *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenExecutableList();
  int isA(int aType)
    { return (aType == parenExecutableList_E); }
  void printSelf();
  std::list<executable *> * get_theList()
    {return theList;}
  void set_theList(std::list<executable *> * theListIn)
    {theList = theListIn;}
private:
  std::list<executable *> * theList;
};

/********************************************************************/

/* parenMachiningOperationList

This is a class for the list parenMachiningOperationList.
It represents the following items:

'(' machiningOperationList ')'
  or
'(' ')'

*/

class parenMachiningOperationList :
  public iso14649CppBase
{
public:
  parenMachiningOperationList(){}
  parenMachiningOperationList(
    std::list<machiningOperation *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenMachiningOperationList();
  int isA(int aType)
    { return (aType == parenMachiningOperationList_E); }
  void printSelf();
  std::list<machiningOperation *> * get_theList()
    {return theList;}
  void set_theList(std::list<machiningOperation *> * theListIn)
    {theList = theListIn;}
private:
  std::list<machiningOperation *> * theList;
};

/********************************************************************/

/* parenNcVariableListFull

This is a class for the single definition of parenNcVariableListFull.
It represents the following items:

'(' ncVariableList ')'

*/

class parenNcVariableListFull :
  public iso14649CppBase
{
public:
  parenNcVariableListFull(){}
  parenNcVariableListFull(
    std::list<ncVariable *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenNcVariableListFull();
  int isA(int aType)
    { return (aType == parenNcVariableListFull_E); }
  void printSelf();
  std::list<ncVariable *> * get_theList()
    {return theList;}
  void set_theList(std::list<ncVariable *> * theListIn)
    {theList = theListIn;}
private:
  std::list<ncVariable *> * theList;
};

/********************************************************************/

/* parenProcessModelLiszt

This is a class for the single definition of parenProcessModelLiszt.
It represents the following items:

'(' processModelLiszt ')'

*/

class parenProcessModelLiszt :
  public iso14649CppBase
{
public:
  parenProcessModelLiszt(){}
  parenProcessModelLiszt(
    std::list<processModel *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenProcessModelLiszt();
  int isA(int aType)
    { return (aType == parenProcessModelLiszt_E); }
  void printSelf();
  std::list<processModel *> * get_theList()
    {return theList;}
  void set_theList(std::list<processModel *> * theListIn)
    {theList = theListIn;}
private:
  std::list<processModel *> * theList;
};

/********************************************************************/

/* parenPropertyParameterList

This is a class for the list parenPropertyParameterList.
It represents the following items:

'(' propertyParameterList ')'
  or
'(' ')'

*/

class parenPropertyParameterList :
  public iso14649CppBase
{
public:
  parenPropertyParameterList(){}
  parenPropertyParameterList(
    std::list<propertyParameter *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenPropertyParameterList();
  int isA(int aType)
    { return (aType == parenPropertyParameterList_E); }
  void printSelf();
  std::list<propertyParameter *> * get_theList()
    {return theList;}
  void set_theList(std::list<propertyParameter *> * theListIn)
    {theList = theListIn;}
private:
  std::list<propertyParameter *> * theList;
};

/********************************************************************/

/* parenRectangularOffsetList

This is a class for the list parenRectangularOffsetList.
It represents the following items:

'(' rectangularOffsetList ')'
  or
'(' ')'

*/

class parenRectangularOffsetList :
  public iso14649CppBase
{
public:
  parenRectangularOffsetList(){}
  parenRectangularOffsetList(
    std::list<rectangularOffset *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenRectangularOffsetList();
  int isA(int aType)
    { return (aType == parenRectangularOffsetList_E); }
  void printSelf();
  std::list<rectangularOffset *> * get_theList()
    {return theList;}
  void set_theList(std::list<rectangularOffset *> * theListIn)
    {theList = theListIn;}
private:
  std::list<rectangularOffset *> * theList;
};

/********************************************************************/

/* parenRectangularOmitList

This is a class for the list parenRectangularOmitList.
It represents the following items:

'(' rectangularOmitList ')'
  or
'(' ')'

*/

class parenRectangularOmitList :
  public iso14649CppBase
{
public:
  parenRectangularOmitList(){}
  parenRectangularOmitList(
    std::list<rectangularOmit *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenRectangularOmitList();
  int isA(int aType)
    { return (aType == parenRectangularOmitList_E); }
  void printSelf();
  std::list<rectangularOmit *> * get_theList()
    {return theList;}
  void set_theList(std::list<rectangularOmit *> * theListIn)
    {theList = theListIn;}
private:
  std::list<rectangularOmit *> * theList;
};

/********************************************************************/

/* parenSetupInstructionList

This is a class for the list parenSetupInstructionList.
It represents the following items:

'(' setupInstructionList ')'
  or
'(' ')'

*/

class parenSetupInstructionList :
  public iso14649CppBase
{
public:
  parenSetupInstructionList(){}
  parenSetupInstructionList(
    std::list<setupInstruction *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenSetupInstructionList();
  int isA(int aType)
    { return (aType == parenSetupInstructionList_E); }
  void printSelf();
  std::list<setupInstruction *> * get_theList()
    {return theList;}
  void set_theList(std::list<setupInstruction *> * theListIn)
    {theList = theListIn;}
private:
  std::list<setupInstruction *> * theList;
};

/********************************************************************/

/* parenSlotEndTypeList

This is a class for the list parenSlotEndTypeList.
It represents the following items:

'(' slotEndTypeList ')'
  or
'(' ')'

*/

class parenSlotEndTypeList :
  public iso14649CppBase
{
public:
  parenSlotEndTypeList(){}
  parenSlotEndTypeList(
    std::list<slotEndType *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenSlotEndTypeList();
  int isA(int aType)
    { return (aType == parenSlotEndTypeList_E); }
  void printSelf();
  std::list<slotEndType *> * get_theList()
    {return theList;}
  void set_theList(std::list<slotEndType *> * theListIn)
    {theList = theListIn;}
private:
  std::list<slotEndType *> * theList;
};

/********************************************************************/

/* parenToolpathLisztFull

This is a class for the single definition of parenToolpathLisztFull.
It represents the following items:

'(' toolpathLiszt ')'

*/

class parenToolpathLisztFull :
  public iso14649CppBase
{
public:
  parenToolpathLisztFull(){}
  parenToolpathLisztFull(
    std::list<toolpath *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenToolpathLisztFull();
  int isA(int aType)
    { return (aType == parenToolpathLisztFull_E); }
  void printSelf();
  std::list<toolpath *> * get_theList()
    {return theList;}
  void set_theList(std::list<toolpath *> * theListIn)
    {theList = theListIn;}
private:
  std::list<toolpath *> * theList;
};

/********************************************************************/

/* parenTrimmingSelectListFull

This is a class for the single definition of parenTrimmingSelectListFull.
It represents the following items:

'(' trimmingSelectList ')'

*/

class parenTrimmingSelectListFull :
  public iso14649CppBase
{
public:
  parenTrimmingSelectListFull(){}
  parenTrimmingSelectListFull(
    std::list<trimmingSelect *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenTrimmingSelectListFull();
  int isA(int aType)
    { return (aType == parenTrimmingSelectListFull_E); }
  void printSelf();
  std::list<trimmingSelect *> * get_theList()
    {return theList;}
  void set_theList(std::list<trimmingSelect *> * theListIn)
    {theList = theListIn;}
private:
  std::list<trimmingSelect *> * theList;
};

/********************************************************************/

/* parenWorkpieceList

This is a class for the list parenWorkpieceList.
It represents the following items:

'(' workpieceList ')'
  or
'(' ')'

*/

class parenWorkpieceList :
  public iso14649CppBase
{
public:
  parenWorkpieceList(){}
  parenWorkpieceList(
    std::list<workpiece *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenWorkpieceList();
  int isA(int aType)
    { return (aType == parenWorkpieceList_E); }
  void printSelf();
  std::list<workpiece *> * get_theList()
    {return theList;}
  void set_theList(std::list<workpiece *> * theListIn)
    {theList = theListIn;}
private:
  std::list<workpiece *> * theList;
};

/********************************************************************/

/* parenWorkpieceSetupList

This is a class for the list parenWorkpieceSetupList.
It represents the following items:

'(' workpieceSetupList ')'
  or
'(' ')'

*/

class parenWorkpieceSetupList :
  public iso14649CppBase
{
public:
  parenWorkpieceSetupList(){}
  parenWorkpieceSetupList(
    std::list<workpieceSetup *> * theListIn)
    {
      theList = theListIn;
    }
  ~parenWorkpieceSetupList();
  int isA(int aType)
    { return (aType == parenWorkpieceSetupList_E); }
  void printSelf();
  std::list<workpieceSetup *> * get_theList()
    {return theList;}
  void set_theList(std::list<workpieceSetup *> * theListIn)
    {theList = theListIn;}
private:
  std::list<workpieceSetup *> * theList;
};

/********************************************************************/

/* pathmodeType

This is a parent class.

*/

class pathmodeType :
  public iso14649CppBase
{
public:
  pathmodeType(){}
  ~pathmodeType(){}
  int isA(int aType)
    { return (aType == pathmodeType_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* pathmodeTypeForward

This is a class for the single definition of pathmodeTypeForward.
It represents the following items:

FORWARD

*/

class pathmodeTypeForward :
  public pathmodeType
{
public:
  pathmodeTypeForward(){}
  ~pathmodeTypeForward();
  int isA(int aType)
    { return ((aType == pathmodeTypeForward_E) ||
	      (aType == pathmodeType_E));
    }
  void printSelf();
};

/********************************************************************/

/* pathmodeTypeZigzag

This is a class for the single definition of pathmodeTypeZigzag.
It represents the following items:

ZIGZAG

*/

class pathmodeTypeZigzag :
  public pathmodeType
{
public:
  pathmodeTypeZigzag(){}
  ~pathmodeTypeZigzag();
  int isA(int aType)
    { return ((aType == pathmodeTypeZigzag_E) ||
	      (aType == pathmodeType_E));
    }
  void printSelf();
};

/********************************************************************/

/* personAndAddress

This is a class for the single definition of personAndAddress.
It represents the following items:

PERSONANDADDRESS '(' CHARSTRING ',' CHARSTRING ')'

*/

class personAndAddress :
  public instance
{
  friend int yyparse();
public:
  personAndAddress(){}
  personAndAddress(
    char * itsPersonIn,
    char * itsAddressIn)
    {
      itsPerson = itsPersonIn;
      itsAddress = itsAddressIn;
    }
  ~personAndAddress();
  int isA(int aType)
    { return (aType == personAndAddress_E); }
  void printSelf();
  char * get_itsPerson()
    {return itsPerson;}
  void set_itsPerson(char * itsPersonIn)
    {itsPerson = itsPersonIn;}
  char * get_itsAddress()
    {return itsAddress;}
  void set_itsAddress(char * itsAddressIn)
    {itsAddress = itsAddressIn;}
private:
  char * itsPerson;
  char * itsAddress;
};

/********************************************************************/

/* planeCcStrategy

This is a class for the single definition of planeCcStrategy.
It represents the following items:

PLANECCSTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' direction ')'

*/

class planeCcStrategy :
  public instance,
  public freeformStrategy
{
  friend int yyparse();
public:
  planeCcStrategy(){}
  planeCcStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    direction * itsPlaneNormalIn) :
      freeformStrategy(
        pathmodeIn,
        cutmodeIn,
        itsMillingTolerancesIn,
        stepoverIn)
    {
      itsPlaneNormal = itsPlaneNormalIn;
    }
  ~planeCcStrategy();
  int isA(int aType)
    { return ((aType == planeCcStrategy_E) ||
	      (aType == freeformStrategy_E));
    }
  void printSelf();
  direction * get_itsPlaneNormal()
    {return itsPlaneNormal;}
  void set_itsPlaneNormal(direction * itsPlaneNormalIn)
    {itsPlaneNormal = itsPlaneNormalIn;}
private:
  direction * itsPlaneNormal;
};

/********************************************************************/

/* planeClStrategy

This is a class for the single definition of planeClStrategy.
It represents the following items:

PLANECLSTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' direction ')'

*/

class planeClStrategy :
  public instance,
  public freeformStrategy
{
  friend int yyparse();
public:
  planeClStrategy(){}
  planeClStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    direction * itsPlaneNormalIn) :
      freeformStrategy(
        pathmodeIn,
        cutmodeIn,
        itsMillingTolerancesIn,
        stepoverIn)
    {
      itsPlaneNormal = itsPlaneNormalIn;
    }
  ~planeClStrategy();
  int isA(int aType)
    { return ((aType == planeClStrategy_E) ||
	      (aType == freeformStrategy_E));
    }
  void printSelf();
  direction * get_itsPlaneNormal()
    {return itsPlaneNormal;}
  void set_itsPlaneNormal(direction * itsPlaneNormalIn)
    {itsPlaneNormal = itsPlaneNormalIn;}
private:
  direction * itsPlaneNormal;
};

/********************************************************************/

/* plungeStrategy

This is a parent class.

*/

class plungeStrategy :
  public approachRetractStrategy
{
  friend int yyparse();
public:
  plungeStrategy(){}
  plungeStrategy(
    direction * toolOrientationIn) :
      approachRetractStrategy(
        toolOrientationIn)
    {}
  ~plungeStrategy(){}
  int isA(int aType)
    { return ((aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* plungeHelix

This is a class for the single definition of plungeHelix.
It represents the following items:

PLUNGEHELIX '(' optDirection ',' REALSTRING ',' REALSTRING ')'

*/

class plungeHelix :
  public instance,
  public plungeStrategy
{
  friend int yyparse();
public:
  plungeHelix(){}
  plungeHelix(
    direction * toolOrientationIn,
    double radiusIn,
    double angleIn) :
      plungeStrategy(
        toolOrientationIn)
    {
      radius = radiusIn;
      angle = angleIn;
    }
  ~plungeHelix();
  int isA(int aType)
    { return ((aType == plungeHelix_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }
  void printSelf();
  double get_radius()
    {return radius;}
  void set_radius(double radiusIn)
    {radius = radiusIn;}
  double get_angle()
    {return angle;}
  void set_angle(double angleIn)
    {angle = angleIn;}
private:
  double radius;
  double angle;
};

/********************************************************************/

/* plungeRamp

This is a class for the single definition of plungeRamp.
It represents the following items:

PLUNGERAMP '(' optDirection ',' REALSTRING ')'

*/

class plungeRamp :
  public instance,
  public plungeStrategy
{
  friend int yyparse();
public:
  plungeRamp(){}
  plungeRamp(
    direction * toolOrientationIn,
    double angleIn) :
      plungeStrategy(
        toolOrientationIn)
    {
      angle = angleIn;
    }
  ~plungeRamp();
  int isA(int aType)
    { return ((aType == plungeRamp_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }
  void printSelf();
  double get_angle()
    {return angle;}
  void set_angle(double angleIn)
    {angle = angleIn;}
private:
  double angle;
};

/********************************************************************/

/* plungeToolaxis

This is a class for the single definition of plungeToolaxis.
It represents the following items:

PLUNGETOOLAXIS '(' optDirection ')'

*/

class plungeToolaxis :
  public instance,
  public plungeStrategy
{
  friend int yyparse();
public:
  plungeToolaxis(){}
  plungeToolaxis(
    direction * toolOrientationIn) :
      plungeStrategy(
        toolOrientationIn)
    {}
  ~plungeToolaxis();
  int isA(int aType)
    { return ((aType == plungeToolaxis_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }
  void printSelf();
};

/********************************************************************/

/* plungeZigzag

This is a class for the single definition of plungeZigzag.
It represents the following items:

PLUNGEZIGZAG '(' optDirection ',' REALSTRING ',' REALSTRING ')'

*/

class plungeZigzag :
  public instance,
  public plungeStrategy
{
  friend int yyparse();
public:
  plungeZigzag(){}
  plungeZigzag(
    direction * toolOrientationIn,
    double angleIn,
    double widthIn) :
      plungeStrategy(
        toolOrientationIn)
    {
      angle = angleIn;
      width = widthIn;
    }
  ~plungeZigzag();
  int isA(int aType)
    { return ((aType == plungeZigzag_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }
  void printSelf();
  double get_angle()
    {return angle;}
  void set_angle(double angleIn)
    {angle = angleIn;}
  double get_width()
    {return width;}
  void set_width(double widthIn)
    {width = widthIn;}
private:
  double angle;
  double width;
};

/********************************************************************/

/* pocketBottomCondition

This is a parent class.

*/

class pocketBottomCondition :
  public iso14649CppBase
{
  friend int yyparse();
public:
  pocketBottomCondition(){}
  ~pocketBottomCondition(){}
  int isA(int aType)
    { return (aType == pocketBottomCondition_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* processModel

This is a class for the single definition of processModel.
It represents the following items:

PROCESSMODEL '(' CHARSTRING ',' CHARSTRING ')'

*/

class processModel :
  public instance
{
  friend int yyparse();
public:
  processModel(){}
  processModel(
    char * iniDataFileIn,
    char * itsTypeIn)
    {
      iniDataFile = iniDataFileIn;
      itsType = itsTypeIn;
    }
  ~processModel();
  int isA(int aType)
    { return (aType == processModel_E); }
  void printSelf();
  char * get_iniDataFile()
    {return iniDataFile;}
  void set_iniDataFile(char * iniDataFileIn)
    {iniDataFile = iniDataFileIn;}
  char * get_itsType()
    {return itsType;}
  void set_itsType(char * itsTypeIn)
    {itsType = itsTypeIn;}
private:
  char * iniDataFile;
  char * itsType;
};

/********************************************************************/

/* processModelList

This is a class for the single definition of processModelList.
It represents the following items:

PROCESSMODELLIST '(' parenProcessModelLiszt ')'

*/

class processModelList :
  public instance
{
  friend int yyparse();
public:
  processModelList(){}
  processModelList(
    parenProcessModelLiszt * itsListIn)
    {
      itsList = itsListIn;
    }
  ~processModelList();
  int isA(int aType)
    { return (aType == processModelList_E); }
  void printSelf();
  parenProcessModelLiszt * get_itsList()
    {return itsList;}
  void set_itsList(parenProcessModelLiszt * itsListIn)
    {itsList = itsListIn;}
private:
  parenProcessModelLiszt * itsList;
};

/********************************************************************/

/* profile

This is a parent class.

*/

class profile :
  public iso14649CppBase
{
  friend int yyparse();
public:
  profile(){}
  profile(
    axis2placement3d * placementIn)
    {
      placement = placementIn;
    }
  ~profile(){}
  int isA(int aType)
    { return (aType == profile_E); }
  void printSelf() = 0;
  axis2placement3d * get_placement()
    {return placement;}
  void set_placement(axis2placement3d * placementIn)
    {placement = placementIn;}
private:
  axis2placement3d * placement;
};

/********************************************************************/

/* programStructure

This is a parent class.

*/

class programStructure :
  public executable
{
  friend int yyparse();
public:
  programStructure(){}
  programStructure(
    char * itsIdIn) :
      executable(
        itsIdIn)
    {}
  ~programStructure(){}
  int isA(int aType)
    { return ((aType == programStructure_E) ||
	      (aType == executable_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* programStop

This is a class for the single definition of programStop.
It represents the following items:

PROGRAMSTOP '(' CHARSTRING ')'

*/

class programStop :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  programStop(){}
  programStop(
    char * itsIdIn) :
      ncFunction(
        itsIdIn)
    {}
  ~programStop();
  int isA(int aType)
    { return ((aType == programStop_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
};

/********************************************************************/

/* project

This is a class for the single definition of project.
It represents the following items:

PROJECT '(' CHARSTRING ',' workplan ',' parenWorkpieceList ',' optPersonAndAddress ',' optDateAndTime ',' optApproval ')'

*/

class project :
  public instance
{
  friend int yyparse();
public:
  project(){}
  project(
    char * itsIdIn,
    workplan * mainWorkplanIn,
    parenWorkpieceList * itsWorkpiecesIn,
    personAndAddress * itsOwnerIn,
    dateAndTime * itsReleaseIn,
    approval * itsStatusIn)
    {
      itsId = itsIdIn;
      mainWorkplan = mainWorkplanIn;
      itsWorkpieces = itsWorkpiecesIn;
      itsOwner = itsOwnerIn;
      itsRelease = itsReleaseIn;
      itsStatus = itsStatusIn;
    }
  ~project();
  int isA(int aType)
    { return (aType == project_E); }
  void printSelf();
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
  workplan * get_mainWorkplan()
    {return mainWorkplan;}
  void set_mainWorkplan(workplan * mainWorkplanIn)
    {mainWorkplan = mainWorkplanIn;}
  parenWorkpieceList * get_itsWorkpieces()
    {return itsWorkpieces;}
  void set_itsWorkpieces(parenWorkpieceList * itsWorkpiecesIn)
    {itsWorkpieces = itsWorkpiecesIn;}
  personAndAddress * get_itsOwner()
    {return itsOwner;}
  void set_itsOwner(personAndAddress * itsOwnerIn)
    {itsOwner = itsOwnerIn;}
  dateAndTime * get_itsRelease()
    {return itsRelease;}
  void set_itsRelease(dateAndTime * itsReleaseIn)
    {itsRelease = itsReleaseIn;}
  approval * get_itsStatus()
    {return itsStatus;}
  void set_itsStatus(approval * itsStatusIn)
    {itsStatus = itsStatusIn;}
private:
  char * itsId;
  workplan * mainWorkplan;
  parenWorkpieceList * itsWorkpieces;
  personAndAddress * itsOwner;
  dateAndTime * itsRelease;
  approval * itsStatus;
};

/********************************************************************/

/* propertyParameter

This is a parent class.

*/

class propertyParameter :
  public iso14649CppBase
{
  friend int yyparse();
public:
  propertyParameter(){}
  propertyParameter(
    char * parameterNameIn)
    {
      parameterName = parameterNameIn;
    }
  ~propertyParameter(){}
  int isA(int aType)
    { return (aType == propertyParameter_E); }
  void printSelf() = 0;
  char * get_parameterName()
    {return parameterName;}
  void set_parameterName(char * parameterNameIn)
    {parameterName = parameterNameIn;}
private:
  char * parameterName;
};

/********************************************************************/

/* radiusedPocketBottomCondition

This is a class for the single definition of radiusedPocketBottomCondition.
It represents the following items:

RADIUSEDPOCKETBOTTOMCONDITION '(' cartesianPoint ',' tolerancedLengthMeasure ')'

*/

class radiusedPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
  friend int yyparse();
public:
  radiusedPocketBottomCondition(){}
  radiusedPocketBottomCondition(
    cartesianPoint * floorRadiusCenterIn,
    tolerancedLengthMeasure * floorRadiusIn)
    {
      floorRadiusCenter = floorRadiusCenterIn;
      floorRadius = floorRadiusIn;
    }
  ~radiusedPocketBottomCondition();
  int isA(int aType)
    { return ((aType == radiusedPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }
  void printSelf();
  cartesianPoint * get_floorRadiusCenter()
    {return floorRadiusCenter;}
  void set_floorRadiusCenter(cartesianPoint * floorRadiusCenterIn)
    {floorRadiusCenter = floorRadiusCenterIn;}
  tolerancedLengthMeasure * get_floorRadius()
    {return floorRadius;}
  void set_floorRadius(tolerancedLengthMeasure * floorRadiusIn)
    {floorRadius = floorRadiusIn;}
private:
  cartesianPoint * floorRadiusCenter;
  tolerancedLengthMeasure * floorRadius;
};

/********************************************************************/

/* rectangularOffset

This is a class for the single definition of rectangularOffset.
It represents the following items:

RECTANGULAROFFSET '(' direction ',' REALSTRING ',' INTSTRING ',' INTSTRING ')'

*/

class rectangularOffset :
  public instance
{
  friend int yyparse();
public:
  rectangularOffset(){}
  rectangularOffset(
    direction * offsetDirectionIn,
    double offsetDistanceIn,
    int rowIndexIn,
    int columnIndexIn)
    {
      offsetDirection = offsetDirectionIn;
      offsetDistance = offsetDistanceIn;
      rowIndex = rowIndexIn;
      columnIndex = columnIndexIn;
    }
  ~rectangularOffset();
  int isA(int aType)
    { return (aType == rectangularOffset_E); }
  void printSelf();
  direction * get_offsetDirection()
    {return offsetDirection;}
  void set_offsetDirection(direction * offsetDirectionIn)
    {offsetDirection = offsetDirectionIn;}
  double get_offsetDistance()
    {return offsetDistance;}
  void set_offsetDistance(double offsetDistanceIn)
    {offsetDistance = offsetDistanceIn;}
  int get_rowIndex()
    {return rowIndex;}
  void set_rowIndex(int rowIndexIn)
    {rowIndex = rowIndexIn;}
  int get_columnIndex()
    {return columnIndex;}
  void set_columnIndex(int columnIndexIn)
    {columnIndex = columnIndexIn;}
private:
  direction * offsetDirection;
  double offsetDistance;
  int rowIndex;
  int columnIndex;
};

/********************************************************************/

/* rectangularOmit

This is a class for the single definition of rectangularOmit.
It represents the following items:

RECTANGULAROMIT '(' INTSTRING ',' INTSTRING ')'

*/

class rectangularOmit :
  public instance
{
  friend int yyparse();
public:
  rectangularOmit(){}
  rectangularOmit(
    int rowIndexIn,
    int columnIndexIn)
    {
      rowIndex = rowIndexIn;
      columnIndex = columnIndexIn;
    }
  ~rectangularOmit();
  int isA(int aType)
    { return (aType == rectangularOmit_E); }
  void printSelf();
  int get_rowIndex()
    {return rowIndex;}
  void set_rowIndex(int rowIndexIn)
    {rowIndex = rowIndexIn;}
  int get_columnIndex()
    {return columnIndex;}
  void set_columnIndex(int columnIndexIn)
    {columnIndex = columnIndexIn;}
private:
  int rowIndex;
  int columnIndex;
};

/********************************************************************/

/* region

This is a parent class.

*/

class region :
  public manufacturingFeature
{
  friend int yyparse();
public:
  region(){}
  region(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn) :
      manufacturingFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn)
    {
      featurePlacement = featurePlacementIn;
    }
  ~region(){}
  int isA(int aType)
    { return ((aType == region_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  axis2placement3d * get_featurePlacement()
    {return featurePlacement;}
  void set_featurePlacement(axis2placement3d * featurePlacementIn)
    {featurePlacement = featurePlacementIn;}
private:
  axis2placement3d * featurePlacement;
};

/********************************************************************/

/* regionProjection

This is a class for the single definition of regionProjection.
It represents the following items:

REGIONPROJECTION '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' optAxis2placement3d ',' boundedCurve ',' direction ',' tolerancedLengthMeasure ')'

*/

class regionProjection :
  public instance,
  public region
{
  friend int yyparse();
public:
  regionProjection(){}
  regionProjection(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    boundedCurve * projCurveIn,
    direction * projDirIn,
    tolerancedLengthMeasure * depthIn) :
      region(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn)
    {
      projCurve = projCurveIn;
      projDir = projDirIn;
      depth = depthIn;
    }
  ~regionProjection();
  int isA(int aType)
    { return ((aType == regionProjection_E) ||
	      (aType == region_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  boundedCurve * get_projCurve()
    {return projCurve;}
  void set_projCurve(boundedCurve * projCurveIn)
    {projCurve = projCurveIn;}
  direction * get_projDir()
    {return projDir;}
  void set_projDir(direction * projDirIn)
    {projDir = projDirIn;}
  tolerancedLengthMeasure * get_depth()
    {return depth;}
  void set_depth(tolerancedLengthMeasure * depthIn)
    {depth = depthIn;}
private:
  boundedCurve * projCurve;
  direction * projDir;
  tolerancedLengthMeasure * depth;
};

/********************************************************************/

/* representationItem

This is a parent class.

*/

class representationItem :
  public iso14649CppBase
{
  friend int yyparse();
public:
  representationItem(){}
  representationItem(
    char * nameIn)
    {
      name = nameIn;
    }
  ~representationItem(){}
  int isA(int aType)
    { return (aType == representationItem_E); }
  void printSelf() = 0;
  char * get_name()
    {return name;}
  void set_name(char * nameIn)
    {name = nameIn;}
private:
  char * name;
};

/********************************************************************/

/* restrictedAreaSelect

This is a parent class.

*/

class restrictedAreaSelect :
  public iso14649CppBase
{
  friend int yyparse();
public:
  restrictedAreaSelect(){}
  ~restrictedAreaSelect(){}
  int isA(int aType)
    { return (aType == restrictedAreaSelect_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* rotDirection

This is a parent class.

*/

class rotDirection :
  public iso14649CppBase
{
public:
  rotDirection(){}
  ~rotDirection(){}
  int isA(int aType)
    { return (aType == rotDirection_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* rotDirectionCw

This is a class for the single definition of rotDirectionCw.
It represents the following items:

CW

*/

class rotDirectionCw :
  public rotDirection
{
public:
  rotDirectionCw(){}
  ~rotDirectionCw();
  int isA(int aType)
    { return ((aType == rotDirectionCw_E) ||
	      (aType == rotDirection_E));
    }
  void printSelf();
};

/********************************************************************/

/* rotDirectionCcw

This is a class for the single definition of rotDirectionCcw.
It represents the following items:

CCW

*/

class rotDirectionCcw :
  public rotDirection
{
public:
  rotDirectionCcw(){}
  ~rotDirectionCcw();
  int isA(int aType)
    { return ((aType == rotDirectionCcw_E) ||
	      (aType == rotDirection_E));
    }
  void printSelf();
};

/********************************************************************/

/* setMark

This is a class for the single definition of setMark.
It represents the following items:

SETMARK '(' CHARSTRING ')'

*/

class setMark :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  setMark(){}
  setMark(
    char * itsIdIn) :
      ncFunction(
        itsIdIn)
    {}
  ~setMark();
  int isA(int aType)
    { return ((aType == setMark_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
};

/********************************************************************/

/* setup

This is a class for the single definition of setup.
It represents the following items:

SETUP '(' CHARSTRING ',' optAxis2placement3d ',' elementarySurface ',' parenWorkpieceSetupList ')'

*/

class setup :
  public instance
{
  friend int yyparse();
public:
  setup(){}
  setup(
    char * itsIdIn,
    axis2placement3d * itsOriginIn,
    elementarySurface * itsSecplaneIn,
    parenWorkpieceSetupList * itsWorkpieceSetupIn)
    {
      itsId = itsIdIn;
      itsOrigin = itsOriginIn;
      itsSecplane = itsSecplaneIn;
      itsWorkpieceSetup = itsWorkpieceSetupIn;
    }
  ~setup();
  int isA(int aType)
    { return (aType == setup_E); }
  void printSelf();
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
  axis2placement3d * get_itsOrigin()
    {return itsOrigin;}
  void set_itsOrigin(axis2placement3d * itsOriginIn)
    {itsOrigin = itsOriginIn;}
  elementarySurface * get_itsSecplane()
    {return itsSecplane;}
  void set_itsSecplane(elementarySurface * itsSecplaneIn)
    {itsSecplane = itsSecplaneIn;}
  parenWorkpieceSetupList * get_itsWorkpieceSetup()
    {return itsWorkpieceSetup;}
  void set_itsWorkpieceSetup(parenWorkpieceSetupList * itsWorkpieceSetupIn)
    {itsWorkpieceSetup = itsWorkpieceSetupIn;}
private:
  char * itsId;
  axis2placement3d * itsOrigin;
  elementarySurface * itsSecplane;
  parenWorkpieceSetupList * itsWorkpieceSetup;
};

/********************************************************************/

/* setupInstruction

This is a class for the single definition of setupInstruction.
It represents the following items:

SETUPINSTRUCTION '(' CHARSTRING ',' CHARSTRING ')'

*/

class setupInstruction :
  public instance
{
  friend int yyparse();
public:
  setupInstruction(){}
  setupInstruction(
    char * descriptionIn,
    char * externalDocumentIn)
    {
      description = descriptionIn;
      externalDocument = externalDocumentIn;
    }
  ~setupInstruction();
  int isA(int aType)
    { return (aType == setupInstruction_E); }
  void printSelf();
  char * get_description()
    {return description;}
  void set_description(char * descriptionIn)
    {description = descriptionIn;}
  char * get_externalDocument()
    {return externalDocument;}
  void set_externalDocument(char * externalDocumentIn)
    {externalDocument = externalDocumentIn;}
private:
  char * description;
  char * externalDocument;
};

/********************************************************************/

/* slotEndType

This is a parent class.

*/

class slotEndType :
  public iso14649CppBase
{
  friend int yyparse();
public:
  slotEndType(){}
  ~slotEndType(){}
  int isA(int aType)
    { return (aType == slotEndType_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* strokeConnectionStrategy

This is a parent class.

*/

class strokeConnectionStrategy :
  public iso14649CppBase
{
public:
  strokeConnectionStrategy(){}
  ~strokeConnectionStrategy(){}
  int isA(int aType)
    { return (aType == strokeConnectionStrategy_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* taperSelect

This is a parent class.

*/

class taperSelect :
  public iso14649CppBase
{
  friend int yyparse();
public:
  taperSelect(){}
  ~taperSelect(){}
  int isA(int aType)
    { return (aType == taperSelect_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* technology

This is a parent class.

*/

class technology :
  public iso14649CppBase
{
  friend int yyparse();
public:
  technology(){}
  technology(
    real * feedrateIn,
    toolReferencePoint * feedrateReferenceIn)
    {
      feedrate = feedrateIn;
      feedrateReference = feedrateReferenceIn;
    }
  ~technology(){}
  int isA(int aType)
    { return (aType == technology_E); }
  void printSelf() = 0;
  real * get_feedrate()
    {return feedrate;}
  void set_feedrate(real * feedrateIn)
    {feedrate = feedrateIn;}
  toolReferencePoint * get_feedrateReference()
    {return feedrateReference;}
  void set_feedrateReference(toolReferencePoint * feedrateReferenceIn)
    {feedrateReference = feedrateReferenceIn;}
private:
  real * feedrate;
  toolReferencePoint * feedrateReference;
};

/********************************************************************/

/* throughBottomCondition

This is a class for the single definition of throughBottomCondition.
It represents the following items:

THROUGHBOTTOMCONDITION '(' ')'

*/

class throughBottomCondition :
  public instance,
  public holeBottomCondition
{
  friend int yyparse();
public:
  throughBottomCondition(){}
  ~throughBottomCondition();
  int isA(int aType)
    { return ((aType == throughBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }
  void printSelf();
};

/********************************************************************/

/* throughPocketBottomCondition

This is a class for the single definition of throughPocketBottomCondition.
It represents the following items:

THROUGHPOCKETBOTTOMCONDITION '(' ')'

*/

class throughPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
  friend int yyparse();
public:
  throughPocketBottomCondition(){}
  ~throughPocketBottomCondition();
  int isA(int aType)
    { return ((aType == throughPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }
  void printSelf();
};

/********************************************************************/

/* tolerancedLengthMeasure

This is a class for the single definition of tolerancedLengthMeasure.
It represents the following items:

TOLERANCEDLENGTHMEASURE '(' REALSTRING ',' plusMinusValue ')'

*/

class tolerancedLengthMeasure :
  public instance
{
  friend int yyparse();
public:
  tolerancedLengthMeasure(){}
  tolerancedLengthMeasure(
    double theoreticalSizeIn,
    plusMinusValue * implicitToleranceIn)
    {
      theoreticalSize = theoreticalSizeIn;
      implicitTolerance = implicitToleranceIn;
    }
  ~tolerancedLengthMeasure();
  int isA(int aType)
    { return (aType == tolerancedLengthMeasure_E); }
  void printSelf();
  double get_theoreticalSize()
    {return theoreticalSize;}
  void set_theoreticalSize(double theoreticalSizeIn)
    {theoreticalSize = theoreticalSizeIn;}
  plusMinusValue * get_implicitTolerance()
    {return implicitTolerance;}
  void set_implicitTolerance(plusMinusValue * implicitToleranceIn)
    {implicitTolerance = implicitToleranceIn;}
private:
  double theoreticalSize;
  plusMinusValue * implicitTolerance;
};

/********************************************************************/

/* tolerances

This is a class for the single definition of tolerances.
It represents the following items:

TOLERANCES '(' REALSTRING ',' REALSTRING ')'

*/

class tolerances :
  public instance
{
  friend int yyparse();
public:
  tolerances(){}
  tolerances(
    double chordalToleranceIn,
    double scallopHeightIn)
    {
      chordalTolerance = chordalToleranceIn;
      scallopHeight = scallopHeightIn;
    }
  ~tolerances();
  int isA(int aType)
    { return (aType == tolerances_E); }
  void printSelf();
  double get_chordalTolerance()
    {return chordalTolerance;}
  void set_chordalTolerance(double chordalToleranceIn)
    {chordalTolerance = chordalToleranceIn;}
  double get_scallopHeight()
    {return scallopHeight;}
  void set_scallopHeight(double scallopHeightIn)
    {scallopHeight = scallopHeightIn;}
private:
  double chordalTolerance;
  double scallopHeight;
};

/********************************************************************/

/* toleranceSelect

This is a parent class.

*/

class toleranceSelect :
  public iso14649CppBase
{
  friend int yyparse();
public:
  toleranceSelect(){}
  ~toleranceSelect(){}
  int isA(int aType)
    { return (aType == toleranceSelect_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* toolBody

This is a parent class.

*/

class toolBody :
  public iso14649CppBase
{
  friend int yyparse();
public:
  toolBody(){}
  ~toolBody(){}
  int isA(int aType)
    { return (aType == toolBody_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* toolDirection

This is a parent class.

*/

class toolDirection :
  public iso14649CppBase
{
  friend int yyparse();
public:
  toolDirection(){}
  ~toolDirection(){}
  int isA(int aType)
    { return (aType == toolDirection_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* toolpath

This is a parent class.

*/

class toolpath :
  public iso14649CppBase
{
  friend int yyparse();
public:
  toolpath(){}
  toolpath(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn)
    {
      itsPriority = itsPriorityIn;
      itsType = itsTypeIn;
      itsSpeed = itsSpeedIn;
      itsTechnology = itsTechnologyIn;
      itsMachineFunctions = itsMachineFunctionsIn;
    }
  ~toolpath(){}
  int isA(int aType)
    { return (aType == toolpath_E); }
  void printSelf() = 0;
  boolean * get_itsPriority()
    {return itsPriority;}
  void set_itsPriority(boolean * itsPriorityIn)
    {itsPriority = itsPriorityIn;}
  toolpathType * get_itsType()
    {return itsType;}
  void set_itsType(toolpathType * itsTypeIn)
    {itsType = itsTypeIn;}
  toolpathSpeedprofile * get_itsSpeed()
    {return itsSpeed;}
  void set_itsSpeed(toolpathSpeedprofile * itsSpeedIn)
    {itsSpeed = itsSpeedIn;}
  technology * get_itsTechnology()
    {return itsTechnology;}
  void set_itsTechnology(technology * itsTechnologyIn)
    {itsTechnology = itsTechnologyIn;}
  machineFunctions * get_itsMachineFunctions()
    {return itsMachineFunctions;}
  void set_itsMachineFunctions(machineFunctions * itsMachineFunctionsIn)
    {itsMachineFunctions = itsMachineFunctionsIn;}
private:
  boolean * itsPriority;
  toolpathType * itsType;
  toolpathSpeedprofile * itsSpeed;
  technology * itsTechnology;
  machineFunctions * itsMachineFunctions;
};

/********************************************************************/

/* toolpathList

This is a class for the single definition of toolpathList.
It represents the following items:

TOOLPATHLIST '(' parenToolpathLisztFull ')'

*/

class toolpathList :
  public instance
{
  friend int yyparse();
public:
  toolpathList(){}
  toolpathList(
    parenToolpathLisztFull * itsListIn)
    {
      itsList = itsListIn;
    }
  ~toolpathList();
  int isA(int aType)
    { return (aType == toolpathList_E); }
  void printSelf();
  parenToolpathLisztFull * get_itsList()
    {return itsList;}
  void set_itsList(parenToolpathLisztFull * itsListIn)
    {itsList = itsListIn;}
private:
  parenToolpathLisztFull * itsList;
};

/********************************************************************/

/* toolpathSpeedprofile

This is a parent class.

*/

class toolpathSpeedprofile :
  public iso14649CppBase
{
public:
  toolpathSpeedprofile(){}
  ~toolpathSpeedprofile(){}
  int isA(int aType)
    { return (aType == toolpathSpeedprofile_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* toolpathType

This is a parent class.

*/

class toolpathType :
  public iso14649CppBase
{
public:
  toolpathType(){}
  ~toolpathType(){}
  int isA(int aType)
    { return (aType == toolpathType_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* toolReferencePoint

This is a parent class.

*/

class toolReferencePoint :
  public iso14649CppBase
{
public:
  toolReferencePoint(){}
  ~toolReferencePoint(){}
  int isA(int aType)
    { return (aType == toolReferencePoint_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* toolReferencePointCcp

This is a class for the single definition of toolReferencePointCcp.
It represents the following items:

CCP

*/

class toolReferencePointCcp :
  public toolReferencePoint
{
public:
  toolReferencePointCcp(){}
  ~toolReferencePointCcp();
  int isA(int aType)
    { return ((aType == toolReferencePointCcp_E) ||
	      (aType == toolReferencePoint_E));
    }
  void printSelf();
};

/********************************************************************/

/* toolReferencePointTcp

This is a class for the single definition of toolReferencePointTcp.
It represents the following items:

TCP

*/

class toolReferencePointTcp :
  public toolReferencePoint
{
public:
  toolReferencePointTcp(){}
  ~toolReferencePointTcp();
  int isA(int aType)
    { return ((aType == toolReferencePointTcp_E) ||
	      (aType == toolReferencePoint_E));
    }
  void printSelf();
};

/********************************************************************/

/* touchProbe

This is a class for the single definition of touchProbe.
It represents the following items:

TOUCHPROBE '(' CHARSTRING ')'

*/

class touchProbe :
  public instance
{
  friend int yyparse();
public:
  touchProbe(){}
  touchProbe(
    char * itsIdIn)
    {
      itsId = itsIdIn;
    }
  ~touchProbe();
  int isA(int aType)
    { return (aType == touchProbe_E); }
  void printSelf();
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
private:
  char * itsId;
};

/********************************************************************/

/* trajectory

This is a parent class.

*/

class trajectory :
  public toolpath
{
  friend int yyparse();
public:
  trajectory(){}
  trajectory(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    boolean * itsDirectionIn) :
      toolpath(
        itsPriorityIn,
        itsTypeIn,
        itsSpeedIn,
        itsTechnologyIn,
        itsMachineFunctionsIn)
    {
      itsDirection = itsDirectionIn;
    }
  ~trajectory(){}
  int isA(int aType)
    { return ((aType == trajectory_E) ||
	      (aType == toolpath_E));
    }
  void printSelf() = 0;
  boolean * get_itsDirection()
    {return itsDirection;}
  void set_itsDirection(boolean * itsDirectionIn)
    {itsDirection = itsDirectionIn;}
private:
  boolean * itsDirection;
};

/********************************************************************/

/* trajectoryPath

This is a class for the single definition of trajectoryPath.
It represents the following items:

TRAJECTORYPATH

*/

class trajectoryPath :
  public toolpathType
{
public:
  trajectoryPath(){}
  ~trajectoryPath();
  int isA(int aType)
    { return ((aType == trajectoryPath_E) ||
	      (aType == toolpathType_E));
    }
  void printSelf();
};

/********************************************************************/

/* transitionCode

This is a parent class.

*/

class transitionCode :
  public iso14649CppBase
{
public:
  transitionCode(){}
  ~transitionCode(){}
  int isA(int aType)
    { return (aType == transitionCode_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* transitionFeature

This is a parent class.

*/

class transitionFeature :
  public compoundFeatureSelect,
  public manufacturingFeature
{
  friend int yyparse();
public:
  transitionFeature(){}
  transitionFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    machiningFeature * firstFeatureIn,
    machiningFeature * secondFeatureIn) :
      manufacturingFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn)
    {
      firstFeature = firstFeatureIn;
      secondFeature = secondFeatureIn;
    }
  ~transitionFeature(){}
  int isA(int aType)
    { return ((aType == transitionFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  machiningFeature * get_firstFeature()
    {return firstFeature;}
  void set_firstFeature(machiningFeature * firstFeatureIn)
    {firstFeature = firstFeatureIn;}
  machiningFeature * get_secondFeature()
    {return secondFeature;}
  void set_secondFeature(machiningFeature * secondFeatureIn)
    {secondFeature = secondFeatureIn;}
private:
  machiningFeature * firstFeature;
  machiningFeature * secondFeature;
};

/********************************************************************/

/* travelPath

This is a parent class.

*/

class travelPath :
  public iso14649CppBase
{
  friend int yyparse();
public:
  travelPath(){}
  travelPath(
    axis2placement3d * placementIn)
    {
      placement = placementIn;
    }
  ~travelPath(){}
  int isA(int aType)
    { return (aType == travelPath_E); }
  void printSelf() = 0;
  axis2placement3d * get_placement()
    {return placement;}
  void set_placement(axis2placement3d * placementIn)
    {placement = placementIn;}
private:
  axis2placement3d * placement;
};

/********************************************************************/

/* trimmingPreference

This is a parent class.

*/

class trimmingPreference :
  public iso14649CppBase
{
public:
  trimmingPreference(){}
  ~trimmingPreference(){}
  int isA(int aType)
    { return (aType == trimmingPreference_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* trimmingSelect

This is a parent class.

*/

class trimmingSelect :
  public iso14649CppBase
{
  friend int yyparse();
public:
  trimmingSelect(){}
  ~trimmingSelect(){}
  int isA(int aType)
    { return (aType == trimmingSelect_E); }
  void printSelf() = 0;
};

/********************************************************************/

/* twoAxes

This is a class for the single definition of twoAxes.
It represents the following items:

TWOAXES '(' ')'

*/

class twoAxes :
  public instance,
  public toolDirection
{
  friend int yyparse();
public:
  twoAxes(){}
  ~twoAxes();
  int isA(int aType)
    { return ((aType == twoAxes_E) ||
	      (aType == toolDirection_E));
    }
  void printSelf();
};

/********************************************************************/

/* two5DmanufacturingFeature

This is a parent class.

*/

class two5DmanufacturingFeature :
  public manufacturingFeature
{
  friend int yyparse();
public:
  two5DmanufacturingFeature(){}
  two5DmanufacturingFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn) :
      manufacturingFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn)
    {
      featurePlacement = featurePlacementIn;
    }
  ~two5DmanufacturingFeature(){}
  int isA(int aType)
    { return ((aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  axis2placement3d * get_featurePlacement()
    {return featurePlacement;}
  void set_featurePlacement(axis2placement3d * featurePlacementIn)
    {featurePlacement = featurePlacementIn;}
private:
  axis2placement3d * featurePlacement;
};

/********************************************************************/

/* two5DmillingStrategy

This is a parent class.

*/

class two5DmillingStrategy :
  public iso14649CppBase
{
  friend int yyparse();
public:
  two5DmillingStrategy(){}
  two5DmillingStrategy(
    real * overlapIn,
    boolean * allowMultiplePassesIn)
    {
      overlap = overlapIn;
      allowMultiplePasses = allowMultiplePassesIn;
    }
  ~two5DmillingStrategy(){}
  int isA(int aType)
    { return (aType == two5DmillingStrategy_E); }
  void printSelf() = 0;
  real * get_overlap()
    {return overlap;}
  void set_overlap(real * overlapIn)
    {overlap = overlapIn;}
  boolean * get_allowMultiplePasses()
    {return allowMultiplePasses;}
  void set_allowMultiplePasses(boolean * allowMultiplePassesIn)
    {allowMultiplePasses = allowMultiplePassesIn;}
private:
  real * overlap;
  boolean * allowMultiplePasses;
};

/********************************************************************/

/* unidirectionalMilling

This is a class for the single definition of unidirectionalMilling.
It represents the following items:

UNIDIRECTIONALMILLING '(' optReal ',' optBoolean ',' optDirection ',' optCutmodeType ')'

*/

class unidirectionalMilling :
  public instance,
  public two5DmillingStrategy
{
  friend int yyparse();
public:
  unidirectionalMilling(){}
  unidirectionalMilling(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    direction * feedDirectionIn,
    cutmodeType * cutmodeIn) :
      two5DmillingStrategy(
        overlapIn,
        allowMultiplePassesIn)
    {
      feedDirection = feedDirectionIn;
      cutmode = cutmodeIn;
    }
  ~unidirectionalMilling();
  int isA(int aType)
    { return ((aType == unidirectionalMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }
  void printSelf();
  direction * get_feedDirection()
    {return feedDirection;}
  void set_feedDirection(direction * feedDirectionIn)
    {feedDirection = feedDirectionIn;}
  cutmodeType * get_cutmode()
    {return cutmode;}
  void set_cutmode(cutmodeType * cutmodeIn)
    {cutmode = cutmodeIn;}
private:
  direction * feedDirection;
  cutmodeType * cutmode;
};

/********************************************************************/

/* unloadTool

This is a class for the single definition of unloadTool.
It represents the following items:

UNLOADTOOL '(' CHARSTRING ',' optMachiningTool ')'

*/

class unloadTool :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  unloadTool(){}
  unloadTool(
    char * itsIdIn,
    machiningTool * itsToolIn) :
      ncFunction(
        itsIdIn)
    {
      itsTool = itsToolIn;
    }
  ~unloadTool();
  int isA(int aType)
    { return ((aType == unloadTool_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  machiningTool * get_itsTool()
    {return itsTool;}
  void set_itsTool(machiningTool * itsToolIn)
    {itsTool = itsToolIn;}
private:
  machiningTool * itsTool;
};

/********************************************************************/

/* unspecified

This is a class for the single definition of unspecified.
It represents the following items:

UNSPECIFIED

*/

class unspecified :
  public trimmingPreference
{
public:
  unspecified(){}
  ~unspecified();
  int isA(int aType)
    { return ((aType == unspecified_E) ||
	      (aType == trimmingPreference_E));
    }
  void printSelf();
};

/********************************************************************/

/* uvStrategy

This is a class for the single definition of uvStrategy.
It represents the following items:

UVSTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' direction ',' direction ')'

*/

class uvStrategy :
  public instance,
  public freeformStrategy
{
  friend int yyparse();
public:
  uvStrategy(){}
  uvStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    direction * forwardDirectionIn,
    direction * sidewardDirectionIn) :
      freeformStrategy(
        pathmodeIn,
        cutmodeIn,
        itsMillingTolerancesIn,
        stepoverIn)
    {
      forwardDirection = forwardDirectionIn;
      sidewardDirection = sidewardDirectionIn;
    }
  ~uvStrategy();
  int isA(int aType)
    { return ((aType == uvStrategy_E) ||
	      (aType == freeformStrategy_E));
    }
  void printSelf();
  direction * get_forwardDirection()
    {return forwardDirection;}
  void set_forwardDirection(direction * forwardDirectionIn)
    {forwardDirection = forwardDirectionIn;}
  direction * get_sidewardDirection()
    {return sidewardDirection;}
  void set_sidewardDirection(direction * sidewardDirectionIn)
    {sidewardDirection = sidewardDirectionIn;}
private:
  direction * forwardDirection;
  direction * sidewardDirection;
};

/********************************************************************/

/* vector

This is a class for the single definition of vector.
It represents the following items:

VECTOR '(' CHARSTRING ',' direction ',' REALSTRING ')'

*/

class vector :
  public instance,
  public representationItem
{
  friend int yyparse();
public:
  vector(){}
  vector(
    char * nameIn,
    direction * orientationIn,
    double magnitudeIn) :
      representationItem(
        nameIn)
    {
      orientation = orientationIn;
      magnitude = magnitudeIn;
    }
  ~vector();
  int isA(int aType)
    { return ((aType == vector_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  direction * get_orientation()
    {return orientation;}
  void set_orientation(direction * orientationIn)
    {orientation = orientationIn;}
  double get_magnitude()
    {return magnitude;}
  void set_magnitude(double magnitudeIn)
    {magnitude = magnitudeIn;}
private:
  direction * orientation;
  double magnitude;
};

/********************************************************************/

/* waitForMark

This is a class for the single definition of waitForMark.
It represents the following items:

WAITFORMARK '(' CHARSTRING ',' channel ')'

*/

class waitForMark :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  waitForMark(){}
  waitForMark(
    char * itsIdIn,
    channel * itsChannelIn) :
      ncFunction(
        itsIdIn)
    {
      itsChannel = itsChannelIn;
    }
  ~waitForMark();
  int isA(int aType)
    { return ((aType == waitForMark_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  channel * get_itsChannel()
    {return itsChannel;}
  void set_itsChannel(channel * itsChannelIn)
    {itsChannel = itsChannelIn;}
private:
  channel * itsChannel;
};

/********************************************************************/

/* woodruffSlotEndType

This is a class for the single definition of woodruffSlotEndType.
It represents the following items:

WOODRUFFSLOTENDTYPE '(' tolerancedLengthMeasure ')'

*/

class woodruffSlotEndType :
  public instance,
  public slotEndType
{
  friend int yyparse();
public:
  woodruffSlotEndType(){}
  woodruffSlotEndType(
    tolerancedLengthMeasure * radiusIn)
    {
      radius = radiusIn;
    }
  ~woodruffSlotEndType();
  int isA(int aType)
    { return ((aType == woodruffSlotEndType_E) ||
	      (aType == slotEndType_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_radius()
    {return radius;}
  void set_radius(tolerancedLengthMeasure * radiusIn)
    {radius = radiusIn;}
private:
  tolerancedLengthMeasure * radius;
};

/********************************************************************/

/* workingstep

This is a parent class.

*/

class workingstep :
  public executable
{
  friend int yyparse();
public:
  workingstep(){}
  workingstep(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn) :
      executable(
        itsIdIn)
    {
      itsSecplane = itsSecplaneIn;
    }
  ~workingstep(){}
  int isA(int aType)
    { return ((aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf() = 0;
  elementarySurface * get_itsSecplane()
    {return itsSecplane;}
  void set_itsSecplane(elementarySurface * itsSecplaneIn)
    {itsSecplane = itsSecplaneIn;}
private:
  elementarySurface * itsSecplane;
};

/********************************************************************/

/* workpiece

This is a class for the single definition of workpiece.
It represents the following items:

WORKPIECE '(' CHARSTRING ',' optMaterial ',' optReal ',' optWorkpiece ',' optAdvancedBrepShapeRepresentation ',' optBoundingGeometrySelect ',' parenCartesianPointList ')'

*/

class workpiece :
  public instance
{
  friend int yyparse();
public:
  workpiece(){}
  workpiece(
    char * itsIdIn,
    material * itsMaterialIn,
    real * globalToleranceIn,
    workpiece * itsRawpieceIn,
    advancedBrepShapeRepresentation * itsGeometryIn,
    boundingGeometrySelect * itsBoundingGeometryIn,
    parenCartesianPointList * clampingPositionsIn)
    {
      itsId = itsIdIn;
      itsMaterial = itsMaterialIn;
      globalTolerance = globalToleranceIn;
      itsRawpiece = itsRawpieceIn;
      itsGeometry = itsGeometryIn;
      itsBoundingGeometry = itsBoundingGeometryIn;
      clampingPositions = clampingPositionsIn;
    }
  ~workpiece();
  int isA(int aType)
    { return (aType == workpiece_E); }
  void printSelf();
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
  material * get_itsMaterial()
    {return itsMaterial;}
  void set_itsMaterial(material * itsMaterialIn)
    {itsMaterial = itsMaterialIn;}
  real * get_globalTolerance()
    {return globalTolerance;}
  void set_globalTolerance(real * globalToleranceIn)
    {globalTolerance = globalToleranceIn;}
  workpiece * get_itsRawpiece()
    {return itsRawpiece;}
  void set_itsRawpiece(workpiece * itsRawpieceIn)
    {itsRawpiece = itsRawpieceIn;}
  advancedBrepShapeRepresentation * get_itsGeometry()
    {return itsGeometry;}
  void set_itsGeometry(advancedBrepShapeRepresentation * itsGeometryIn)
    {itsGeometry = itsGeometryIn;}
  boundingGeometrySelect * get_itsBoundingGeometry()
    {return itsBoundingGeometry;}
  void set_itsBoundingGeometry(boundingGeometrySelect * itsBoundingGeometryIn)
    {itsBoundingGeometry = itsBoundingGeometryIn;}
  parenCartesianPointList * get_clampingPositions()
    {return clampingPositions;}
  void set_clampingPositions(parenCartesianPointList * clampingPositionsIn)
    {clampingPositions = clampingPositionsIn;}
private:
  char * itsId;
  material * itsMaterial;
  real * globalTolerance;
  workpiece * itsRawpiece;
  advancedBrepShapeRepresentation * itsGeometry;
  boundingGeometrySelect * itsBoundingGeometry;
  parenCartesianPointList * clampingPositions;
};

/********************************************************************/

/* workpieceSetup

This is a class for the single definition of workpieceSetup.
It represents the following items:

WORKPIECESETUP '(' workpiece ',' axis2placement3d ',' optOffsetVector ',' optRestrictedAreaSelect ',' parenSetupInstructionList ')'

*/

class workpieceSetup :
  public instance
{
  friend int yyparse();
public:
  workpieceSetup(){}
  workpieceSetup(
    workpiece * itsWorkpieceIn,
    axis2placement3d * itsOriginIn,
    offsetVector * itsOffsetIn,
    restrictedAreaSelect * itsRestrictedAreaIn,
    parenSetupInstructionList * itsInstructionsIn)
    {
      itsWorkpiece = itsWorkpieceIn;
      itsOrigin = itsOriginIn;
      itsOffset = itsOffsetIn;
      itsRestrictedArea = itsRestrictedAreaIn;
      itsInstructions = itsInstructionsIn;
    }
  ~workpieceSetup();
  int isA(int aType)
    { return (aType == workpieceSetup_E); }
  void printSelf();
  workpiece * get_itsWorkpiece()
    {return itsWorkpiece;}
  void set_itsWorkpiece(workpiece * itsWorkpieceIn)
    {itsWorkpiece = itsWorkpieceIn;}
  axis2placement3d * get_itsOrigin()
    {return itsOrigin;}
  void set_itsOrigin(axis2placement3d * itsOriginIn)
    {itsOrigin = itsOriginIn;}
  offsetVector * get_itsOffset()
    {return itsOffset;}
  void set_itsOffset(offsetVector * itsOffsetIn)
    {itsOffset = itsOffsetIn;}
  restrictedAreaSelect * get_itsRestrictedArea()
    {return itsRestrictedArea;}
  void set_itsRestrictedArea(restrictedAreaSelect * itsRestrictedAreaIn)
    {itsRestrictedArea = itsRestrictedAreaIn;}
  parenSetupInstructionList * get_itsInstructions()
    {return itsInstructions;}
  void set_itsInstructions(parenSetupInstructionList * itsInstructionsIn)
    {itsInstructions = itsInstructionsIn;}
private:
  workpiece * itsWorkpiece;
  axis2placement3d * itsOrigin;
  offsetVector * itsOffset;
  restrictedAreaSelect * itsRestrictedArea;
  parenSetupInstructionList * itsInstructions;
};

/********************************************************************/

/* workplan

This is a class for the single definition of workplan.
It represents the following items:

WORKPLAN '(' CHARSTRING ',' parenExecutableList ',' optChannel ',' optSetup ',' optInProcessGeometry ')'

*/

class workplan :
  public instance,
  public programStructure
{
  friend int yyparse();
public:
  workplan(){}
  workplan(
    char * itsIdIn,
    parenExecutableList * itsElementsIn,
    channel * itsChannelIn,
    setup * itsSetupIn,
    inProcessGeometry * itsEffectIn) :
      programStructure(
        itsIdIn)
    {
      itsElements = itsElementsIn;
      itsChannel = itsChannelIn;
      itsSetup = itsSetupIn;
      itsEffect = itsEffectIn;
    }
  ~workplan();
  int isA(int aType)
    { return ((aType == workplan_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  parenExecutableList * get_itsElements()
    {return itsElements;}
  void set_itsElements(parenExecutableList * itsElementsIn)
    {itsElements = itsElementsIn;}
  channel * get_itsChannel()
    {return itsChannel;}
  void set_itsChannel(channel * itsChannelIn)
    {itsChannel = itsChannelIn;}
  setup * get_itsSetup()
    {return itsSetup;}
  void set_itsSetup(setup * itsSetupIn)
    {itsSetup = itsSetupIn;}
  inProcessGeometry * get_itsEffect()
    {return itsEffect;}
  void set_itsEffect(inProcessGeometry * itsEffectIn)
    {itsEffect = itsEffectIn;}
private:
  parenExecutableList * itsElements;
  channel * itsChannel;
  setup * itsSetup;
  inProcessGeometry * itsEffect;
};

/********************************************************************/

/* real

This is a class for the single definition of real.
It represents the following items:

REALSTRING

*/

class real :
  public toolpathSpeedprofile,
  public trimmingSelect
{
public:
  real(){}
  real(
    double valIn)
    {
      val = valIn;
    }
  ~real();
  int isA(int aType)
    { return ((aType == real_E) ||
	      (aType == toolpathSpeedprofile_E) ||
	      (aType == trimmingSelect_E));
    }
  void printSelf();
  double get_val()
    {return val;}
  void set_val(double valIn)
    {val = valIn;}
private:
  double val;
};

/********************************************************************/

/* angleTaper

This is a class for the single definition of angleTaper.
It represents the following items:

ANGLETAPER '(' real ')'

*/

class angleTaper :
  public instance,
  public taperSelect
{
  friend int yyparse();
public:
  angleTaper(){}
  angleTaper(
    real * angleIn)
    {
      angle = angleIn;
    }
  ~angleTaper();
  int isA(int aType)
    { return ((aType == angleTaper_E) ||
	      (aType == taperSelect_E));
    }
  void printSelf();
  real * get_angle()
    {return angle;}
  void set_angle(real * angleIn)
    {angle = angleIn;}
private:
  real * angle;
};

/********************************************************************/

/* approach

This is a class for the single definition of approach.
It represents the following items:

APPROACH

*/

class approach :
  public toolpathType
{
public:
  approach(){}
  ~approach();
  int isA(int aType)
    { return ((aType == approach_E) ||
	      (aType == toolpathType_E));
    }
  void printSelf();
};

/********************************************************************/

/* bidirectionalMilling

This is a class for the single definition of bidirectionalMilling.
It represents the following items:

BIDIRECTIONALMILLING '(' optReal ',' optBoolean ',' optDirection ',' optLeftOrRight ',' optStrokeConnectionStrategy ')'

*/

class bidirectionalMilling :
  public instance,
  public two5DmillingStrategy
{
  friend int yyparse();
public:
  bidirectionalMilling(){}
  bidirectionalMilling(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    direction * feedDirectionIn,
    leftOrRight * stepoverDirectionIn,
    strokeConnectionStrategy * itsStrokeConnectionStrategyIn) :
      two5DmillingStrategy(
        overlapIn,
        allowMultiplePassesIn)
    {
      feedDirection = feedDirectionIn;
      stepoverDirection = stepoverDirectionIn;
      itsStrokeConnectionStrategy = itsStrokeConnectionStrategyIn;
    }
  ~bidirectionalMilling();
  int isA(int aType)
    { return ((aType == bidirectionalMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }
  void printSelf();
  direction * get_feedDirection()
    {return feedDirection;}
  void set_feedDirection(direction * feedDirectionIn)
    {feedDirection = feedDirectionIn;}
  leftOrRight * get_stepoverDirection()
    {return stepoverDirection;}
  void set_stepoverDirection(leftOrRight * stepoverDirectionIn)
    {stepoverDirection = stepoverDirectionIn;}
  strokeConnectionStrategy * get_itsStrokeConnectionStrategy()
    {return itsStrokeConnectionStrategy;}
  void set_itsStrokeConnectionStrategy(strokeConnectionStrategy * itsStrokeConnectionStrategyIn)
    {itsStrokeConnectionStrategy = itsStrokeConnectionStrategyIn;}
private:
  direction * feedDirection;
  leftOrRight * stepoverDirection;
  strokeConnectionStrategy * itsStrokeConnectionStrategy;
};

/********************************************************************/

/* blindBottomCondition

This is a parent class.

*/

class blindBottomCondition :
  public holeBottomCondition
{
  friend int yyparse();
public:
  blindBottomCondition(){}
  ~blindBottomCondition(){}
  int isA(int aType)
    { return ((aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* booleanTrue

This is a class for the single definition of booleanTrue.
It represents the following items:

TRUE

*/

class booleanTrue :
  public boolean,
  public logical
{
public:
  booleanTrue(){}
  ~booleanTrue();
  int isA(int aType)
    { return ((aType == booleanTrue_E) ||
	      (aType == boolean_E) ||
	      (aType == logical_E));
    }
  void printSelf();
};

/********************************************************************/

/* booleanFalse

This is a class for the single definition of booleanFalse.
It represents the following items:

FALSE

*/

class booleanFalse :
  public boolean,
  public logical
{
public:
  booleanFalse(){}
  ~booleanFalse();
  int isA(int aType)
    { return ((aType == booleanFalse_E) ||
	      (aType == boolean_E) ||
	      (aType == logical_E));
    }
  void printSelf();
};

/********************************************************************/

/* boundingGeometrySelect

This is a parent class.

*/

class boundingGeometrySelect :
  public restrictedAreaSelect
{
  friend int yyparse();
public:
  boundingGeometrySelect(){}
  ~boundingGeometrySelect(){}
  int isA(int aType)
    { return ((aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* calendarDate

This is a class for the single definition of calendarDate.
It represents the following items:

CALENDARDATE '(' INTSTRING ',' INTSTRING ',' INTSTRING ')'

*/

class calendarDate :
  public instance,
  public date
{
  friend int yyparse();
public:
  calendarDate(){}
  calendarDate(
    int yearComponentIn,
    int dayComponentIn,
    int monthComponentIn)
    {
      yearComponent = yearComponentIn;
      dayComponent = dayComponentIn;
      monthComponent = monthComponentIn;
    }
  ~calendarDate();
  int isA(int aType)
    { return ((aType == calendarDate_E) ||
	      (aType == date_E));
    }
  void printSelf();
  int get_yearComponent()
    {return yearComponent;}
  void set_yearComponent(int yearComponentIn)
    {yearComponent = yearComponentIn;}
  int get_dayComponent()
    {return dayComponent;}
  void set_dayComponent(int dayComponentIn)
    {dayComponent = dayComponentIn;}
  int get_monthComponent()
    {return monthComponent;}
  void set_monthComponent(int monthComponentIn)
    {monthComponent = monthComponentIn;}
private:
  int yearComponent;
  int dayComponent;
  int monthComponent;
};

/********************************************************************/

/* cartesian

This is a class for the single definition of cartesian.
It represents the following items:

CARTESIAN

*/

class cartesian :
  public trimmingPreference
{
public:
  cartesian(){}
  ~cartesian();
  int isA(int aType)
    { return ((aType == cartesian_E) ||
	      (aType == trimmingPreference_E));
    }
  void printSelf();
};

/********************************************************************/

/* cartesianPoint

This is a class for the single definition of cartesianPoint.
It represents the following items:

CARTESIANPOINT '(' CHARSTRING ',' parenRealListFull ')'

*/

class cartesianPoint :
  public instance,
  public representationItem,
  public trimmingSelect
{
  friend int yyparse();
public:
  cartesianPoint(){}
  cartesianPoint(
    char * nameIn,
    parenRealListFull * coordinatesIn) :
      representationItem(
        nameIn)
    {
      coordinates = coordinatesIn;
    }
  ~cartesianPoint();
  int isA(int aType)
    { return ((aType == cartesianPoint_E) ||
	      (aType == representationItem_E) ||
	      (aType == trimmingSelect_E));
    }
  void printSelf();
  parenRealListFull * get_coordinates()
    {return coordinates;}
  void set_coordinates(parenRealListFull * coordinatesIn)
    {coordinates = coordinatesIn;}
private:
  parenRealListFull * coordinates;
};

/********************************************************************/

/* chamfer

This is a class for the single definition of chamfer.
It represents the following items:

CHAMFER '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' machiningFeature ',' machiningFeature ',' REALSTRING ',' tolerancedLengthMeasure ')'

*/

class chamfer :
  public instance,
  public transitionFeature
{
  friend int yyparse();
public:
  chamfer(){}
  chamfer(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    machiningFeature * firstFeatureIn,
    machiningFeature * secondFeatureIn,
    double angleToPlaneIn,
    tolerancedLengthMeasure * firstOffsetAmountIn) :
      transitionFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        firstFeatureIn,
        secondFeatureIn)
    {
      angleToPlane = angleToPlaneIn;
      firstOffsetAmount = firstOffsetAmountIn;
    }
  ~chamfer();
  int isA(int aType)
    { return ((aType == chamfer_E) ||
	      (aType == transitionFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  double get_angleToPlane()
    {return angleToPlane;}
  void set_angleToPlane(double angleToPlaneIn)
    {angleToPlane = angleToPlaneIn;}
  tolerancedLengthMeasure * get_firstOffsetAmount()
    {return firstOffsetAmount;}
  void set_firstOffsetAmount(tolerancedLengthMeasure * firstOffsetAmountIn)
    {firstOffsetAmount = firstOffsetAmountIn;}
private:
  double angleToPlane;
  tolerancedLengthMeasure * firstOffsetAmount;
};

/********************************************************************/

/* circularPath

This is a parent class.

*/

class circularPath :
  public travelPath
{
  friend int yyparse();
public:
  circularPath(){}
  circularPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn) :
      travelPath(
        placementIn)
    {
      radius = radiusIn;
    }
  ~circularPath(){}
  int isA(int aType)
    { return ((aType == circularPath_E) ||
	      (aType == travelPath_E));
    }
  void printSelf() = 0;
  tolerancedLengthMeasure * get_radius()
    {return radius;}
  void set_radius(tolerancedLengthMeasure * radiusIn)
    {radius = radiusIn;}
private:
  tolerancedLengthMeasure * radius;
};

/********************************************************************/

/* closedProfile

This is a parent class.

*/

class closedProfile :
  public profile
{
  friend int yyparse();
public:
  closedProfile(){}
  closedProfile(
    axis2placement3d * placementIn) :
      profile(
        placementIn)
    {}
  ~closedProfile(){}
  int isA(int aType)
    { return ((aType == closedProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* completeCircularPath

This is a class for the single definition of completeCircularPath.
It represents the following items:

COMPLETECIRCULARPATH '(' optAxis2placement3d ',' tolerancedLengthMeasure ')'

*/

class completeCircularPath :
  public instance,
  public circularPath
{
  friend int yyparse();
public:
  completeCircularPath(){}
  completeCircularPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn) :
      circularPath(
        placementIn,
        radiusIn)
    {}
  ~completeCircularPath();
  int isA(int aType)
    { return ((aType == completeCircularPath_E) ||
	      (aType == circularPath_E) ||
	      (aType == travelPath_E));
    }
  void printSelf();
};

/********************************************************************/

/* compoundFeature

This is a parent class.

*/

class compoundFeature :
  public two5DmanufacturingFeature
{
  friend int yyparse();
public:
  compoundFeature(){}
  compoundFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenCompoundFeatureSelectListFull * elementsIn) :
      two5DmanufacturingFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn)
    {
      elements = elementsIn;
    }
  ~compoundFeature(){}
  int isA(int aType)
    { return ((aType == compoundFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  parenCompoundFeatureSelectListFull * get_elements()
    {return elements;}
  void set_elements(parenCompoundFeatureSelectListFull * elementsIn)
    {elements = elementsIn;}
private:
  parenCompoundFeatureSelectListFull * elements;
};

/********************************************************************/

/* conicalHoleBottom

This is a class for the single definition of conicalHoleBottom.
It represents the following items:

CONICALHOLEBOTTOM '(' real ',' optTolerancedLengthMeasure ')'

*/

class conicalHoleBottom :
  public instance,
  public blindBottomCondition
{
  friend int yyparse();
public:
  conicalHoleBottom(){}
  conicalHoleBottom(
    real * tipAngleIn,
    tolerancedLengthMeasure * tipRadiusIn)
    {
      tipAngle = tipAngleIn;
      tipRadius = tipRadiusIn;
    }
  ~conicalHoleBottom();
  int isA(int aType)
    { return ((aType == conicalHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }
  void printSelf();
  real * get_tipAngle()
    {return tipAngle;}
  void set_tipAngle(real * tipAngleIn)
    {tipAngle = tipAngleIn;}
  tolerancedLengthMeasure * get_tipRadius()
    {return tipRadius;}
  void set_tipRadius(tolerancedLengthMeasure * tipRadiusIn)
    {tipRadius = tipRadiusIn;}
private:
  real * tipAngle;
  tolerancedLengthMeasure * tipRadius;
};

/********************************************************************/

/* connect

This is a class for the single definition of connect.
It represents the following items:

CONNECT

*/

class connect :
  public toolpathType
{
public:
  connect(){}
  ~connect();
  int isA(int aType)
    { return ((aType == connect_E) ||
	      (aType == toolpathType_E));
    }
  void printSelf();
};

/********************************************************************/

/* contact

This is a class for the single definition of contact.
It represents the following items:

CONTACT

*/

class contact :
  public toolpathType
{
public:
  contact(){}
  ~contact();
  int isA(int aType)
    { return ((aType == contact_E) ||
	      (aType == toolpathType_E));
    }
  void printSelf();
};

/********************************************************************/

/* continuous

This is a class for the single definition of continuous.
It represents the following items:

CONTINUOUS

*/

class continuous :
  public transitionCode
{
public:
  continuous(){}
  ~continuous();
  int isA(int aType)
    { return ((aType == continuous_E) ||
	      (aType == transitionCode_E));
    }
  void printSelf();
};

/********************************************************************/

/* contSameGradient

This is a class for the single definition of contSameGradient.
It represents the following items:

CONTSAMEGRADIENT

*/

class contSameGradient :
  public transitionCode
{
public:
  contSameGradient(){}
  ~contSameGradient();
  int isA(int aType)
    { return ((aType == contSameGradient_E) ||
	      (aType == transitionCode_E));
    }
  void printSelf();
};

/********************************************************************/

/* contSameGradientSameCurvature

This is a class for the single definition of contSameGradientSameCurvature.
It represents the following items:

CONTSAMEGRADIENTSAMECURVATURE

*/

class contSameGradientSameCurvature :
  public transitionCode
{
public:
  contSameGradientSameCurvature(){}
  ~contSameGradientSameCurvature();
  int isA(int aType)
    { return ((aType == contSameGradientSameCurvature_E) ||
	      (aType == transitionCode_E));
    }
  void printSelf();
};

/********************************************************************/

/* contourParallel

This is a class for the single definition of contourParallel.
It represents the following items:

CONTOURPARALLEL '(' optReal ',' optBoolean ',' rotDirection ',' optCutmodeType ')'

*/

class contourParallel :
  public instance,
  public two5DmillingStrategy
{
  friend int yyparse();
public:
  contourParallel(){}
  contourParallel(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    rotDirection * rotationDirectionIn,
    cutmodeType * cutmodeIn) :
      two5DmillingStrategy(
        overlapIn,
        allowMultiplePassesIn)
    {
      rotationDirection = rotationDirectionIn;
      cutmode = cutmodeIn;
    }
  ~contourParallel();
  int isA(int aType)
    { return ((aType == contourParallel_E) ||
	      (aType == two5DmillingStrategy_E));
    }
  void printSelf();
  rotDirection * get_rotationDirection()
    {return rotationDirection;}
  void set_rotationDirection(rotDirection * rotationDirectionIn)
    {rotationDirection = rotationDirectionIn;}
  cutmodeType * get_cutmode()
    {return cutmode;}
  void set_cutmode(cutmodeType * cutmodeIn)
    {cutmode = cutmodeIn;}
private:
  rotDirection * rotationDirection;
  cutmodeType * cutmode;
};

/********************************************************************/

/* counterboreHole

This is a class for the single definition of counterboreHole.
It represents the following items:

COUNTERBOREHOLE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' parenCompoundFeatureSelectListFull ')'

*/

class counterboreHole :
  public instance,
  public compoundFeature
{
  friend int yyparse();
public:
  counterboreHole(){}
  counterboreHole(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenCompoundFeatureSelectListFull * elementsIn) :
      compoundFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        elementsIn)
    {}
  ~counterboreHole();
  int isA(int aType)
    { return ((aType == counterboreHole_E) ||
	      (aType == compoundFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
};

/********************************************************************/

/* countersunkHole

This is a class for the single definition of countersunkHole.
It represents the following items:

COUNTERSUNKHOLE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' parenCompoundFeatureSelectListFull ')'

*/

class countersunkHole :
  public instance,
  public compoundFeature
{
  friend int yyparse();
public:
  countersunkHole(){}
  countersunkHole(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenCompoundFeatureSelectListFull * elementsIn) :
      compoundFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        elementsIn)
    {}
  ~countersunkHole();
  int isA(int aType)
    { return ((aType == countersunkHole_E) ||
	      (aType == compoundFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
};

/********************************************************************/

/* curve

This is a parent class.

*/

class curve :
  public representationItem
{
  friend int yyparse();
public:
  curve(){}
  curve(
    char * nameIn) :
      representationItem(
        nameIn)
    {}
  ~curve(){}
  int isA(int aType)
    { return ((aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* cutterLocationTrajectory

This is a class for the single definition of cutterLocationTrajectory.
It represents the following items:

CUTTERLOCATIONTRAJECTORY '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' optBoolean ',' boundedCurve ',' optBoundedCurve ',' optBoundedCurve ')'

*/

class cutterLocationTrajectory :
  public instance,
  public trajectory
{
  friend int yyparse();
public:
  cutterLocationTrajectory(){}
  cutterLocationTrajectory(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    boolean * itsDirectionIn,
    boundedCurve * basiccurveIn,
    boundedCurve * itsToolaxisIn,
    boundedCurve * surfaceNormalIn) :
      trajectory(
        itsPriorityIn,
        itsTypeIn,
        itsSpeedIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        itsDirectionIn)
    {
      basiccurve = basiccurveIn;
      itsToolaxis = itsToolaxisIn;
      surfaceNormal = surfaceNormalIn;
    }
  ~cutterLocationTrajectory();
  int isA(int aType)
    { return ((aType == cutterLocationTrajectory_E) ||
	      (aType == trajectory_E) ||
	      (aType == toolpath_E));
    }
  void printSelf();
  boundedCurve * get_basiccurve()
    {return basiccurve;}
  void set_basiccurve(boundedCurve * basiccurveIn)
    {basiccurve = basiccurveIn;}
  boundedCurve * get_itsToolaxis()
    {return itsToolaxis;}
  void set_itsToolaxis(boundedCurve * itsToolaxisIn)
    {itsToolaxis = itsToolaxisIn;}
  boundedCurve * get_surfaceNormal()
    {return surfaceNormal;}
  void set_surfaceNormal(boundedCurve * surfaceNormalIn)
    {surfaceNormal = surfaceNormalIn;}
private:
  boundedCurve * basiccurve;
  boundedCurve * itsToolaxis;
  boundedCurve * surfaceNormal;
};

/********************************************************************/

/* cuttingTool

This is a parent class.

*/

class cuttingTool :
  public machiningTool
{
  friend int yyparse();
public:
  cuttingTool(){}
  cuttingTool(
    char * itsIdIn,
    toolBody * itsToolBodyIn,
    parenCuttingComponentListFull * itsCuttingEdgeIn,
    real * overallAssemblyLengthIn) :
      machiningTool(
        itsIdIn)
    {
      itsToolBody = itsToolBodyIn;
      itsCuttingEdge = itsCuttingEdgeIn;
      overallAssemblyLength = overallAssemblyLengthIn;
    }
  ~cuttingTool(){}
  int isA(int aType)
    { return ((aType == cuttingTool_E) ||
	      (aType == machiningTool_E));
    }
  void printSelf() = 0;
  toolBody * get_itsToolBody()
    {return itsToolBody;}
  void set_itsToolBody(toolBody * itsToolBodyIn)
    {itsToolBody = itsToolBodyIn;}
  parenCuttingComponentListFull * get_itsCuttingEdge()
    {return itsCuttingEdge;}
  void set_itsCuttingEdge(parenCuttingComponentListFull * itsCuttingEdgeIn)
    {itsCuttingEdge = itsCuttingEdgeIn;}
  real * get_overallAssemblyLength()
    {return overallAssemblyLength;}
  void set_overallAssemblyLength(real * overallAssemblyLengthIn)
    {overallAssemblyLength = overallAssemblyLengthIn;}
private:
  toolBody * itsToolBody;
  parenCuttingComponentListFull * itsCuttingEdge;
  real * overallAssemblyLength;
};

/********************************************************************/

/* degouge

This is a class for the single definition of degouge.
It represents the following items:

DEGOUGE

*/

class degouge :
  public strokeConnectionStrategy
{
public:
  degouge(){}
  ~degouge();
  int isA(int aType)
    { return ((aType == degouge_E) ||
	      (aType == strokeConnectionStrategy_E));
    }
  void printSelf();
};

/********************************************************************/

/* descriptiveParameter

This is a class for the single definition of descriptiveParameter.
It represents the following items:

DESCRIPTIVEPARAMETER '(' CHARSTRING ',' CHARSTRING ')'

*/

class descriptiveParameter :
  public instance,
  public propertyParameter
{
  friend int yyparse();
public:
  descriptiveParameter(){}
  descriptiveParameter(
    char * parameterNameIn,
    char * descriptiveStringIn) :
      propertyParameter(
        parameterNameIn)
    {
      descriptiveString = descriptiveStringIn;
    }
  ~descriptiveParameter();
  int isA(int aType)
    { return ((aType == descriptiveParameter_E) ||
	      (aType == propertyParameter_E));
    }
  void printSelf();
  char * get_descriptiveString()
    {return descriptiveString;}
  void set_descriptiveString(char * descriptiveStringIn)
    {descriptiveString = descriptiveStringIn;}
private:
  char * descriptiveString;
};

/********************************************************************/

/* diameterTaper

This is a class for the single definition of diameterTaper.
It represents the following items:

DIAMETERTAPER '(' tolerancedLengthMeasure ')'

*/

class diameterTaper :
  public instance,
  public taperSelect
{
  friend int yyparse();
public:
  diameterTaper(){}
  diameterTaper(
    tolerancedLengthMeasure * finalDiameterIn)
    {
      finalDiameter = finalDiameterIn;
    }
  ~diameterTaper();
  int isA(int aType)
    { return ((aType == diameterTaper_E) ||
	      (aType == taperSelect_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_finalDiameter()
    {return finalDiameter;}
  void set_finalDiameter(tolerancedLengthMeasure * finalDiameterIn)
    {finalDiameter = finalDiameterIn;}
private:
  tolerancedLengthMeasure * finalDiameter;
};

/********************************************************************/

/* direction

This is a class for the single definition of direction.
It represents the following items:

DIRECTION '(' CHARSTRING ',' parenRealListFull ')'

*/

class direction :
  public instance,
  public representationItem
{
  friend int yyparse();
public:
  direction(){}
  direction(
    char * nameIn,
    parenRealListFull * directionRatiosIn) :
      representationItem(
        nameIn)
    {
      directionRatios = directionRatiosIn;
    }
  ~direction();
  int isA(int aType)
    { return ((aType == direction_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  parenRealListFull * get_directionRatios()
    {return directionRatios;}
  void set_directionRatios(parenRealListFull * directionRatiosIn)
    {directionRatios = directionRatiosIn;}
private:
  parenRealListFull * directionRatios;
};

/********************************************************************/

/* discontinuous

This is a class for the single definition of discontinuous.
It represents the following items:

DISCONTINUOUS

*/

class discontinuous :
  public transitionCode
{
public:
  discontinuous(){}
  ~discontinuous();
  int isA(int aType)
    { return ((aType == discontinuous_E) ||
	      (aType == transitionCode_E));
    }
  void printSelf();
};

/********************************************************************/

/* displayMessage

This is a class for the single definition of displayMessage.
It represents the following items:

DISPLAYMESSAGE '(' CHARSTRING ',' CHARSTRING ')'

*/

class displayMessage :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  displayMessage(){}
  displayMessage(
    char * itsIdIn,
    char * itsTextIn) :
      ncFunction(
        itsIdIn)
    {
      itsText = itsTextIn;
    }
  ~displayMessage();
  int isA(int aType)
    { return ((aType == displayMessage_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  char * get_itsText()
    {return itsText;}
  void set_itsText(char * itsTextIn)
    {itsText = itsTextIn;}
private:
  char * itsText;
};

/********************************************************************/

/* edgeRound

This is a class for the single definition of edgeRound.
It represents the following items:

EDGEROUND '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' machiningFeature ',' machiningFeature ',' tolerancedLengthMeasure ',' optTolerancedLengthMeasure ',' optTolerancedLengthMeasure ')'

*/

class edgeRound :
  public instance,
  public transitionFeature
{
  friend int yyparse();
public:
  edgeRound(){}
  edgeRound(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    machiningFeature * firstFeatureIn,
    machiningFeature * secondFeatureIn,
    tolerancedLengthMeasure * radiusIn,
    tolerancedLengthMeasure * firstOffsetAmountIn,
    tolerancedLengthMeasure * secondOffsetAmountIn) :
      transitionFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        firstFeatureIn,
        secondFeatureIn)
    {
      radius = radiusIn;
      firstOffsetAmount = firstOffsetAmountIn;
      secondOffsetAmount = secondOffsetAmountIn;
    }
  ~edgeRound();
  int isA(int aType)
    { return ((aType == edgeRound_E) ||
	      (aType == transitionFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_radius()
    {return radius;}
  void set_radius(tolerancedLengthMeasure * radiusIn)
    {radius = radiusIn;}
  tolerancedLengthMeasure * get_firstOffsetAmount()
    {return firstOffsetAmount;}
  void set_firstOffsetAmount(tolerancedLengthMeasure * firstOffsetAmountIn)
    {firstOffsetAmount = firstOffsetAmountIn;}
  tolerancedLengthMeasure * get_secondOffsetAmount()
    {return secondOffsetAmount;}
  void set_secondOffsetAmount(tolerancedLengthMeasure * secondOffsetAmountIn)
    {secondOffsetAmount = secondOffsetAmountIn;}
private:
  tolerancedLengthMeasure * radius;
  tolerancedLengthMeasure * firstOffsetAmount;
  tolerancedLengthMeasure * secondOffsetAmount;
};

/********************************************************************/

/* elementarySurface

This is a parent class.

*/

class elementarySurface :
  public representationItem
{
  friend int yyparse();
public:
  elementarySurface(){}
  elementarySurface(
    char * nameIn,
    axis2placement3d * positionIn) :
      representationItem(
        nameIn)
    {
      position = positionIn;
    }
  ~elementarySurface(){}
  int isA(int aType)
    { return ((aType == elementarySurface_E) ||
	      (aType == representationItem_E));
    }
  void printSelf() = 0;
  axis2placement3d * get_position()
    {return position;}
  void set_position(axis2placement3d * positionIn)
    {position = positionIn;}
private:
  axis2placement3d * position;
};

/********************************************************************/

/* exchangePallet

This is a class for the single definition of exchangePallet.
It represents the following items:

EXCHANGEPALLET '(' CHARSTRING ')'

*/

class exchangePallet :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  exchangePallet(){}
  exchangePallet(
    char * itsIdIn) :
      ncFunction(
        itsIdIn)
    {}
  ~exchangePallet();
  int isA(int aType)
    { return ((aType == exchangePallet_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
};

/********************************************************************/

/* feedstop

This is a class for the single definition of feedstop.
It represents the following items:

FEEDSTOP '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' REALSTRING ')'

*/

class feedstop :
  public instance,
  public toolpath
{
  friend int yyparse();
public:
  feedstop(){}
  feedstop(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    double dwellIn) :
      toolpath(
        itsPriorityIn,
        itsTypeIn,
        itsSpeedIn,
        itsTechnologyIn,
        itsMachineFunctionsIn)
    {
      dwell = dwellIn;
    }
  ~feedstop();
  int isA(int aType)
    { return ((aType == feedstop_E) ||
	      (aType == toolpath_E));
    }
  void printSelf();
  double get_dwell()
    {return dwell;}
  void set_dwell(double dwellIn)
    {dwell = dwellIn;}
private:
  double dwell;
};

/********************************************************************/

/* flatHoleBottom

This is a class for the single definition of flatHoleBottom.
It represents the following items:

FLATHOLEBOTTOM '(' ')'

*/

class flatHoleBottom :
  public instance,
  public blindBottomCondition
{
  friend int yyparse();
public:
  flatHoleBottom(){}
  ~flatHoleBottom();
  int isA(int aType)
    { return ((aType == flatHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }
  void printSelf();
};

/********************************************************************/

/* flatSlotEndType

This is a class for the single definition of flatSlotEndType.
It represents the following items:

FLATSLOTENDTYPE '(' tolerancedLengthMeasure ',' tolerancedLengthMeasure ')'

*/

class flatSlotEndType :
  public instance,
  public slotEndType
{
  friend int yyparse();
public:
  flatSlotEndType(){}
  flatSlotEndType(
    tolerancedLengthMeasure * cornerRadius1In,
    tolerancedLengthMeasure * cornerRadius2In)
    {
      cornerRadius1 = cornerRadius1In;
      cornerRadius2 = cornerRadius2In;
    }
  ~flatSlotEndType();
  int isA(int aType)
    { return ((aType == flatSlotEndType_E) ||
	      (aType == slotEndType_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_cornerRadius1()
    {return cornerRadius1;}
  void set_cornerRadius1(tolerancedLengthMeasure * cornerRadius1In)
    {cornerRadius1 = cornerRadius1In;}
  tolerancedLengthMeasure * get_cornerRadius2()
    {return cornerRadius2;}
  void set_cornerRadius2(tolerancedLengthMeasure * cornerRadius2In)
    {cornerRadius2 = cornerRadius2In;}
private:
  tolerancedLengthMeasure * cornerRadius1;
  tolerancedLengthMeasure * cornerRadius2;
};

/********************************************************************/

/* flatWithRadiusHoleBottom

This is a class for the single definition of flatWithRadiusHoleBottom.
It represents the following items:

FLATWITHRADIUSHOLEBOTTOM '(' tolerancedLengthMeasure ')'

*/

class flatWithRadiusHoleBottom :
  public instance,
  public blindBottomCondition
{
  friend int yyparse();
public:
  flatWithRadiusHoleBottom(){}
  flatWithRadiusHoleBottom(
    tolerancedLengthMeasure * cornerRadiusIn)
    {
      cornerRadius = cornerRadiusIn;
    }
  ~flatWithRadiusHoleBottom();
  int isA(int aType)
    { return ((aType == flatWithRadiusHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_cornerRadius()
    {return cornerRadius;}
  void set_cornerRadius(tolerancedLengthMeasure * cornerRadiusIn)
    {cornerRadius = cornerRadiusIn;}
private:
  tolerancedLengthMeasure * cornerRadius;
};

/********************************************************************/

/* generalPath

This is a class for the single definition of generalPath.
It represents the following items:

GENERALPATH '(' optAxis2placement3d ',' boundedCurve ')'

*/

class generalPath :
  public instance,
  public travelPath
{
  friend int yyparse();
public:
  generalPath(){}
  generalPath(
    axis2placement3d * placementIn,
    boundedCurve * sweptPathIn) :
      travelPath(
        placementIn)
    {
      sweptPath = sweptPathIn;
    }
  ~generalPath();
  int isA(int aType)
    { return ((aType == generalPath_E) ||
	      (aType == travelPath_E));
    }
  void printSelf();
  boundedCurve * get_sweptPath()
    {return sweptPath;}
  void set_sweptPath(boundedCurve * sweptPathIn)
    {sweptPath = sweptPathIn;}
private:
  boundedCurve * sweptPath;
};

/********************************************************************/

/* generalPocketBottomCondition

This is a class for the single definition of generalPocketBottomCondition.
It represents the following items:

GENERALPOCKETBOTTOMCONDITION '(' region ')'

*/

class generalPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
  friend int yyparse();
public:
  generalPocketBottomCondition(){}
  generalPocketBottomCondition(
    region * shapeIn)
    {
      shape = shapeIn;
    }
  ~generalPocketBottomCondition();
  int isA(int aType)
    { return ((aType == generalPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }
  void printSelf();
  region * get_shape()
    {return shape;}
  void set_shape(region * shapeIn)
    {shape = shapeIn;}
private:
  region * shape;
};

/********************************************************************/

/* helix

This is a class for the single definition of helix.
It represents the following items:

HELIX '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ')'

*/

class helix :
  public instance,
  public curve
{
  friend int yyparse();
public:
  helix(){}
  helix(
    char * nameIn,
    axis2placement3d * positionIn,
    double radiusIn,
    double pitchIn) :
      curve(
        nameIn)
    {
      position = positionIn;
      radius = radiusIn;
      pitch = pitchIn;
    }
  ~helix();
  int isA(int aType)
    { return ((aType == helix_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  axis2placement3d * get_position()
    {return position;}
  void set_position(axis2placement3d * positionIn)
    {position = positionIn;}
  double get_radius()
    {return radius;}
  void set_radius(double radiusIn)
    {radius = radiusIn;}
  double get_pitch()
    {return pitch;}
  void set_pitch(double pitchIn)
    {pitch = pitchIn;}
private:
  axis2placement3d * position;
  double radius;
  double pitch;
};

/********************************************************************/

/* indexPallet

This is a class for the single definition of indexPallet.
It represents the following items:

INDEXPALLET '(' CHARSTRING ',' INTSTRING ')'

*/

class indexPallet :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  indexPallet(){}
  indexPallet(
    char * itsIdIn,
    int its_indexIn) :
      ncFunction(
        itsIdIn)
    {
      its_index = its_indexIn;
    }
  ~indexPallet();
  int isA(int aType)
    { return ((aType == indexPallet_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  int get_its_index()
    {return its_index;}
  void set_its_index(int its_indexIn)
    {its_index = its_indexIn;}
private:
  int its_index;
};

/********************************************************************/

/* indexTable

This is a class for the single definition of indexTable.
It represents the following items:

INDEXTABLE '(' CHARSTRING ',' INTSTRING ')'

*/

class indexTable :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  indexTable(){}
  indexTable(
    char * itsIdIn,
    int its_indexIn) :
      ncFunction(
        itsIdIn)
    {
      its_index = its_indexIn;
    }
  ~indexTable();
  int isA(int aType)
    { return ((aType == indexTable_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  int get_its_index()
    {return its_index;}
  void set_its_index(int its_indexIn)
    {its_index = its_indexIn;}
private:
  int its_index;
};

/********************************************************************/

/* lift

This is a class for the single definition of lift.
It represents the following items:

LIFT

*/

class lift :
  public toolpathType
{
public:
  lift(){}
  ~lift();
  int isA(int aType)
    { return ((aType == lift_E) ||
	      (aType == toolpathType_E));
    }
  void printSelf();
};

/********************************************************************/

/* liftShiftPlunge

This is a class for the single definition of liftShiftPlunge.
It represents the following items:

LIFTSHIFTPLUNGE

*/

class liftShiftPlunge :
  public strokeConnectionStrategy
{
public:
  liftShiftPlunge(){}
  ~liftShiftPlunge();
  int isA(int aType)
    { return ((aType == liftShiftPlunge_E) ||
	      (aType == strokeConnectionStrategy_E));
    }
  void printSelf();
};

/********************************************************************/

/* limitsAndFits

This is a class for the single definition of limitsAndFits.
It represents the following items:

LIMITSANDFITS '(' REALSTRING ',' REALSTRING ',' optFittingType ')'

*/

class limitsAndFits :
  public instance,
  public toleranceSelect
{
  friend int yyparse();
public:
  limitsAndFits(){}
  limitsAndFits(
    double deviationIn,
    double gradeIn,
    fittingType * itsFittingTypeIn)
    {
      deviation = deviationIn;
      grade = gradeIn;
      itsFittingType = itsFittingTypeIn;
    }
  ~limitsAndFits();
  int isA(int aType)
    { return ((aType == limitsAndFits_E) ||
	      (aType == toleranceSelect_E));
    }
  void printSelf();
  double get_deviation()
    {return deviation;}
  void set_deviation(double deviationIn)
    {deviation = deviationIn;}
  double get_grade()
    {return grade;}
  void set_grade(double gradeIn)
    {grade = gradeIn;}
  fittingType * get_itsFittingType()
    {return itsFittingType;}
  void set_itsFittingType(fittingType * itsFittingTypeIn)
    {itsFittingType = itsFittingTypeIn;}
private:
  double deviation;
  double grade;
  fittingType * itsFittingType;
};

/********************************************************************/

/* line

This is a class for the single definition of line.
It represents the following items:

LINE '(' CHARSTRING ',' cartesianPoint ',' vector ')'

*/

class line :
  public instance,
  public curve
{
  friend int yyparse();
public:
  line(){}
  line(
    char * nameIn,
    cartesianPoint * pntIn,
    vector * dirIn) :
      curve(
        nameIn)
    {
      pnt = pntIn;
      dir = dirIn;
    }
  ~line();
  int isA(int aType)
    { return ((aType == line_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  cartesianPoint * get_pnt()
    {return pnt;}
  void set_pnt(cartesianPoint * pntIn)
    {pnt = pntIn;}
  vector * get_dir()
    {return dir;}
  void set_dir(vector * dirIn)
    {dir = dirIn;}
private:
  cartesianPoint * pnt;
  vector * dir;
};

/********************************************************************/

/* linearPath

This is a class for the single definition of linearPath.
It represents the following items:

LINEARPATH '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' direction ')'

*/

class linearPath :
  public instance,
  public travelPath
{
  friend int yyparse();
public:
  linearPath(){}
  linearPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * distanceIn,
    direction * itsDirectionIn) :
      travelPath(
        placementIn)
    {
      distance = distanceIn;
      itsDirection = itsDirectionIn;
    }
  ~linearPath();
  int isA(int aType)
    { return ((aType == linearPath_E) ||
	      (aType == travelPath_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_distance()
    {return distance;}
  void set_distance(tolerancedLengthMeasure * distanceIn)
    {distance = distanceIn;}
  direction * get_itsDirection()
    {return itsDirection;}
  void set_itsDirection(direction * itsDirectionIn)
    {itsDirection = itsDirectionIn;}
private:
  tolerancedLengthMeasure * distance;
  direction * itsDirection;
};

/********************************************************************/

/* loadTool

This is a class for the single definition of loadTool.
It represents the following items:

LOADTOOL '(' CHARSTRING ',' machiningTool ')'

*/

class loadTool :
  public instance,
  public ncFunction
{
  friend int yyparse();
public:
  loadTool(){}
  loadTool(
    char * itsIdIn,
    machiningTool * itsToolIn) :
      ncFunction(
        itsIdIn)
    {
      itsTool = itsToolIn;
    }
  ~loadTool();
  int isA(int aType)
    { return ((aType == loadTool_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  machiningTool * get_itsTool()
    {return itsTool;}
  void set_itsTool(machiningTool * itsToolIn)
    {itsTool = itsToolIn;}
private:
  machiningTool * itsTool;
};

/********************************************************************/

/* loopBack

This is a class for the single definition of loopBack.
It represents the following items:

LOOPBACK

*/

class loopBack :
  public strokeConnectionStrategy
{
public:
  loopBack(){}
  ~loopBack();
  int isA(int aType)
    { return ((aType == loopBack_E) ||
	      (aType == strokeConnectionStrategy_E));
    }
  void printSelf();
};

/********************************************************************/

/* loopSlotEndType

This is a class for the single definition of loopSlotEndType.
It represents the following items:

LOOPSLOTENDTYPE '(' ')'

*/

class loopSlotEndType :
  public instance,
  public slotEndType
{
  friend int yyparse();
public:
  loopSlotEndType(){}
  ~loopSlotEndType();
  int isA(int aType)
    { return ((aType == loopSlotEndType_E) ||
	      (aType == slotEndType_E));
    }
  void printSelf();
};

/********************************************************************/

/* machiningFeature

This is a parent class.

*/

class machiningFeature :
  public compoundFeatureSelect,
  public two5DmanufacturingFeature
{
  friend int yyparse();
public:
  machiningFeature(){}
  machiningFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn) :
      two5DmanufacturingFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn)
    {
      depth = depthIn;
    }
  ~machiningFeature(){}
  int isA(int aType)
    { return ((aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  elementarySurface * get_depth()
    {return depth;}
  void set_depth(elementarySurface * depthIn)
    {depth = depthIn;}
private:
  elementarySurface * depth;
};

/********************************************************************/

/* machiningOperation

This is a parent class.

*/

class machiningOperation :
  public operation
{
  friend int yyparse();
public:
  machiningOperation(){}
  machiningOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn) :
      operation(
        itsToolpathIn,
        itsToolDirectionIn)
    {
      itsId = itsIdIn;
      retractPlane = retractPlaneIn;
      startPoint = startPointIn;
      itsTool = itsToolIn;
      itsTechnology = itsTechnologyIn;
      itsMachineFunctions = itsMachineFunctionsIn;
    }
  ~machiningOperation(){}
  int isA(int aType)
    { return ((aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  char * get_itsId()
    {return itsId;}
  void set_itsId(char * itsIdIn)
    {itsId = itsIdIn;}
  real * get_retractPlane()
    {return retractPlane;}
  void set_retractPlane(real * retractPlaneIn)
    {retractPlane = retractPlaneIn;}
  cartesianPoint * get_startPoint()
    {return startPoint;}
  void set_startPoint(cartesianPoint * startPointIn)
    {startPoint = startPointIn;}
  machiningTool * get_itsTool()
    {return itsTool;}
  void set_itsTool(machiningTool * itsToolIn)
    {itsTool = itsToolIn;}
  technology * get_itsTechnology()
    {return itsTechnology;}
  void set_itsTechnology(technology * itsTechnologyIn)
    {itsTechnology = itsTechnologyIn;}
  machineFunctions * get_itsMachineFunctions()
    {return itsMachineFunctions;}
  void set_itsMachineFunctions(machineFunctions * itsMachineFunctionsIn)
    {itsMachineFunctions = itsMachineFunctionsIn;}
private:
  char * itsId;
  real * retractPlane;
  cartesianPoint * startPoint;
  machiningTool * itsTool;
  technology * itsTechnology;
  machineFunctions * itsMachineFunctions;
};

/********************************************************************/

/* machiningWorkingstep

This is a class for the single definition of machiningWorkingstep.
It represents the following items:

MACHININGWORKINGSTEP '(' CHARSTRING ',' elementarySurface ',' manufacturingFeature ',' machiningOperation ',' optInProcessGeometry ')'

*/

class machiningWorkingstep :
  public instance,
  public workingstep
{
  friend int yyparse();
public:
  machiningWorkingstep(){}
  machiningWorkingstep(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    manufacturingFeature * itsFeatureIn,
    machiningOperation * itsOperationIn,
    inProcessGeometry * itsEffectIn) :
      workingstep(
        itsIdIn,
        itsSecplaneIn)
    {
      itsFeature = itsFeatureIn;
      itsOperation = itsOperationIn;
      itsEffect = itsEffectIn;
    }
  ~machiningWorkingstep();
  int isA(int aType)
    { return ((aType == machiningWorkingstep_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  manufacturingFeature * get_itsFeature()
    {return itsFeature;}
  void set_itsFeature(manufacturingFeature * itsFeatureIn)
    {itsFeature = itsFeatureIn;}
  machiningOperation * get_itsOperation()
    {return itsOperation;}
  void set_itsOperation(machiningOperation * itsOperationIn)
    {itsOperation = itsOperationIn;}
  inProcessGeometry * get_itsEffect()
    {return itsEffect;}
  void set_itsEffect(inProcessGeometry * itsEffectIn)
    {itsEffect = itsEffectIn;}
private:
  manufacturingFeature * itsFeature;
  machiningOperation * itsOperation;
  inProcessGeometry * itsEffect;
};

/********************************************************************/

/* millingCuttingTool

This is a class for the single definition of millingCuttingTool.
It represents the following items:

MILLINGCUTTINGTOOL '(' CHARSTRING ',' toolBody ',' parenCuttingComponentListFull ',' optReal ',' optDirection ',' optReal ')'

*/

class millingCuttingTool :
  public instance,
  public cuttingTool
{
  friend int yyparse();
public:
  millingCuttingTool(){}
  millingCuttingTool(
    char * itsIdIn,
    toolBody * itsToolBodyIn,
    parenCuttingComponentListFull * itsCuttingEdgeIn,
    real * overallAssemblyLengthIn,
    direction * directionForSpindleOrientationIn,
    real * toolHolderDiameterForSpindleOrientationIn) :
      cuttingTool(
        itsIdIn,
        itsToolBodyIn,
        itsCuttingEdgeIn,
        overallAssemblyLengthIn)
    {
      directionForSpindleOrientation = directionForSpindleOrientationIn;
      toolHolderDiameterForSpindleOrientation = toolHolderDiameterForSpindleOrientationIn;
    }
  ~millingCuttingTool();
  int isA(int aType)
    { return ((aType == millingCuttingTool_E) ||
	      (aType == cuttingTool_E) ||
	      (aType == machiningTool_E));
    }
  void printSelf();
  direction * get_directionForSpindleOrientation()
    {return directionForSpindleOrientation;}
  void set_directionForSpindleOrientation(direction * directionForSpindleOrientationIn)
    {directionForSpindleOrientation = directionForSpindleOrientationIn;}
  real * get_toolHolderDiameterForSpindleOrientation()
    {return toolHolderDiameterForSpindleOrientation;}
  void set_toolHolderDiameterForSpindleOrientation(real * toolHolderDiameterForSpindleOrientationIn)
    {toolHolderDiameterForSpindleOrientation = toolHolderDiameterForSpindleOrientationIn;}
private:
  direction * directionForSpindleOrientation;
  real * toolHolderDiameterForSpindleOrientation;
};

/********************************************************************/

/* millingMachiningOperation

This is a parent class.

*/

class millingMachiningOperation :
  public machiningOperation
{
  friend int yyparse();
public:
  millingMachiningOperation(){}
  millingMachiningOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn) :
      machiningOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn)
    {
      overcutLength = overcutLengthIn;
    }
  ~millingMachiningOperation(){}
  int isA(int aType)
    { return ((aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  real * get_overcutLength()
    {return overcutLength;}
  void set_overcutLength(real * overcutLengthIn)
    {overcutLength = overcutLengthIn;}
private:
  real * overcutLength;
};

/********************************************************************/

/* millingTechnology

This is a class for the single definition of millingTechnology.
It represents the following items:

MILLINGTECHNOLOGY '(' optReal ',' toolReferencePoint ',' optReal ',' optReal ',' optReal ',' boolean ',' boolean ',' boolean ',' optBoolean ')'

*/

class millingTechnology :
  public instance,
  public technology
{
  friend int yyparse();
public:
  millingTechnology(){}
  millingTechnology(
    real * feedrateIn,
    toolReferencePoint * feedrateReferenceIn,
    real * cutspeedIn,
    real * spindleIn,
    real * feedratePerToothIn,
    boolean * synchronizeSpindleWithFeedIn,
    boolean * inhibitFeedrateOverrideIn,
    boolean * inhibitSpindleOverrideIn,
    boolean * itsAdaptiveControlIn) :
      technology(
        feedrateIn,
        feedrateReferenceIn)
    {
      cutspeed = cutspeedIn;
      spindle = spindleIn;
      feedratePerTooth = feedratePerToothIn;
      synchronizeSpindleWithFeed = synchronizeSpindleWithFeedIn;
      inhibitFeedrateOverride = inhibitFeedrateOverrideIn;
      inhibitSpindleOverride = inhibitSpindleOverrideIn;
      itsAdaptiveControl = itsAdaptiveControlIn;
    }
  ~millingTechnology();
  int isA(int aType)
    { return ((aType == millingTechnology_E) ||
	      (aType == technology_E));
    }
  void printSelf();
  real * get_cutspeed()
    {return cutspeed;}
  void set_cutspeed(real * cutspeedIn)
    {cutspeed = cutspeedIn;}
  real * get_spindle()
    {return spindle;}
  void set_spindle(real * spindleIn)
    {spindle = spindleIn;}
  real * get_feedratePerTooth()
    {return feedratePerTooth;}
  void set_feedratePerTooth(real * feedratePerToothIn)
    {feedratePerTooth = feedratePerToothIn;}
  boolean * get_synchronizeSpindleWithFeed()
    {return synchronizeSpindleWithFeed;}
  void set_synchronizeSpindleWithFeed(boolean * synchronizeSpindleWithFeedIn)
    {synchronizeSpindleWithFeed = synchronizeSpindleWithFeedIn;}
  boolean * get_inhibitFeedrateOverride()
    {return inhibitFeedrateOverride;}
  void set_inhibitFeedrateOverride(boolean * inhibitFeedrateOverrideIn)
    {inhibitFeedrateOverride = inhibitFeedrateOverrideIn;}
  boolean * get_inhibitSpindleOverride()
    {return inhibitSpindleOverride;}
  void set_inhibitSpindleOverride(boolean * inhibitSpindleOverrideIn)
    {inhibitSpindleOverride = inhibitSpindleOverrideIn;}
  boolean * get_itsAdaptiveControl()
    {return itsAdaptiveControl;}
  void set_itsAdaptiveControl(boolean * itsAdaptiveControlIn)
    {itsAdaptiveControl = itsAdaptiveControlIn;}
private:
  real * cutspeed;
  real * spindle;
  real * feedratePerTooth;
  boolean * synchronizeSpindleWithFeed;
  boolean * inhibitFeedrateOverride;
  boolean * inhibitSpindleOverride;
  boolean * itsAdaptiveControl;
};

/********************************************************************/

/* millingToolBody

This is a parent class.

*/

class millingToolBody :
  public toolBody
{
  friend int yyparse();
public:
  millingToolBody(){}
  millingToolBody(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn)
    {
      dimension = dimensionIn;
      numberOfTeeth = numberOfTeethIn;
      handOfCut = handOfCutIn;
      coolantThroughTool = coolantThroughToolIn;
      pilotLength = pilotLengthIn;
    }
  ~millingToolBody(){}
  int isA(int aType)
    { return ((aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
  millingToolDimension * get_dimension()
    {return dimension;}
  void set_dimension(millingToolDimension * dimensionIn)
    {dimension = dimensionIn;}
  integer * get_numberOfTeeth()
    {return numberOfTeeth;}
  void set_numberOfTeeth(integer * numberOfTeethIn)
    {numberOfTeeth = numberOfTeethIn;}
  hand * get_handOfCut()
    {return handOfCut;}
  void set_handOfCut(hand * handOfCutIn)
    {handOfCut = handOfCutIn;}
  boolean * get_coolantThroughTool()
    {return coolantThroughTool;}
  void set_coolantThroughTool(boolean * coolantThroughToolIn)
    {coolantThroughTool = coolantThroughToolIn;}
  real * get_pilotLength()
    {return pilotLength;}
  void set_pilotLength(real * pilotLengthIn)
    {pilotLength = pilotLengthIn;}
private:
  millingToolDimension * dimension;
  integer * numberOfTeeth;
  hand * handOfCut;
  boolean * coolantThroughTool;
  real * pilotLength;
};

/********************************************************************/

/* millingTypeOperation

This is a parent class.

*/

class millingTypeOperation :
  public millingMachiningOperation
{
  friend int yyparse();
public:
  millingTypeOperation(){}
  millingTypeOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn) :
      millingMachiningOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn)
    {
      approach = approachIn;
      retract = retractIn;
    }
  ~millingTypeOperation(){}
  int isA(int aType)
    { return ((aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  approachRetractStrategy * get_approach()
    {return approach;}
  void set_approach(approachRetractStrategy * approachIn)
    {approach = approachIn;}
  approachRetractStrategy * get_retract()
    {return retract;}
  void set_retract(approachRetractStrategy * retractIn)
    {retract = retractIn;}
private:
  approachRetractStrategy * approach;
  approachRetractStrategy * retract;
};

/********************************************************************/

/* nonContact

This is a class for the single definition of nonContact.
It represents the following items:

NONCONTACT

*/

class nonContact :
  public toolpathType
{
public:
  nonContact(){}
  ~nonContact();
  int isA(int aType)
    { return ((aType == nonContact_E) ||
	      (aType == toolpathType_E));
    }
  void printSelf();
};

/********************************************************************/

/* numericParameter

This is a class for the single definition of numericParameter.
It represents the following items:

NUMERICPARAMETER '(' CHARSTRING ',' REALSTRING ',' CHARSTRING ')'

*/

class numericParameter :
  public instance,
  public propertyParameter
{
  friend int yyparse();
public:
  numericParameter(){}
  numericParameter(
    char * parameterNameIn,
    double itsParameterValueIn,
    char * itsParameterUnitIn) :
      propertyParameter(
        parameterNameIn)
    {
      itsParameterValue = itsParameterValueIn;
      itsParameterUnit = itsParameterUnitIn;
    }
  ~numericParameter();
  int isA(int aType)
    { return ((aType == numericParameter_E) ||
	      (aType == propertyParameter_E));
    }
  void printSelf();
  double get_itsParameterValue()
    {return itsParameterValue;}
  void set_itsParameterValue(double itsParameterValueIn)
    {itsParameterValue = itsParameterValueIn;}
  char * get_itsParameterUnit()
    {return itsParameterUnit;}
  void set_itsParameterUnit(char * itsParameterUnitIn)
    {itsParameterUnit = itsParameterUnitIn;}
private:
  double itsParameterValue;
  char * itsParameterUnit;
};

/********************************************************************/

/* openProfile

This is a parent class.

*/

class openProfile :
  public profile
{
  friend int yyparse();
public:
  openProfile(){}
  openProfile(
    axis2placement3d * placementIn) :
      profile(
        placementIn)
    {}
  ~openProfile(){}
  int isA(int aType)
    { return ((aType == openProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* openSlotEndType

This is a class for the single definition of openSlotEndType.
It represents the following items:

OPENSLOTENDTYPE '(' ')'

*/

class openSlotEndType :
  public instance,
  public slotEndType
{
  friend int yyparse();
public:
  openSlotEndType(){}
  ~openSlotEndType();
  int isA(int aType)
    { return ((aType == openSlotEndType_E) ||
	      (aType == slotEndType_E));
    }
  void printSelf();
};

/********************************************************************/

/* parameter

This is a class for the single definition of parameter.
It represents the following items:

PARAMETER

*/

class parameter :
  public trimmingPreference
{
public:
  parameter(){}
  ~parameter();
  int isA(int aType)
    { return ((aType == parameter_E) ||
	      (aType == trimmingPreference_E));
    }
  void printSelf();
};

/********************************************************************/

/* partialCircularPath

This is a class for the single definition of partialCircularPath.
It represents the following items:

PARTIALCIRCULARPATH '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' REALSTRING ')'

*/

class partialCircularPath :
  public instance,
  public circularPath
{
  friend int yyparse();
public:
  partialCircularPath(){}
  partialCircularPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn,
    double sweepAngleIn) :
      circularPath(
        placementIn,
        radiusIn)
    {
      sweepAngle = sweepAngleIn;
    }
  ~partialCircularPath();
  int isA(int aType)
    { return ((aType == partialCircularPath_E) ||
	      (aType == circularPath_E) ||
	      (aType == travelPath_E));
    }
  void printSelf();
  double get_sweepAngle()
    {return sweepAngle;}
  void set_sweepAngle(double sweepAngleIn)
    {sweepAngle = sweepAngleIn;}
private:
  double sweepAngle;
};

/********************************************************************/

/* placement

This is a parent class.

*/

class placement :
  public representationItem
{
  friend int yyparse();
public:
  placement(){}
  placement(
    char * nameIn,
    cartesianPoint * locationIn) :
      representationItem(
        nameIn)
    {
      location = locationIn;
    }
  ~placement(){}
  int isA(int aType)
    { return ((aType == placement_E) ||
	      (aType == representationItem_E));
    }
  void printSelf() = 0;
  cartesianPoint * get_location()
    {return location;}
  void set_location(cartesianPoint * locationIn)
    {location = locationIn;}
private:
  cartesianPoint * location;
};

/********************************************************************/

/* planarFace

This is a class for the single definition of planarFace.
It represents the following items:

PLANARFACE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' linearProfile ',' optClosedProfile ',' parenBossList ')'

*/

class planarFace :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  planarFace(){}
  planarFace(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * courseOfTravelIn,
    linearProfile * removalBoundaryIn,
    closedProfile * faceBoundaryIn,
    parenBossList * itsBossIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      courseOfTravel = courseOfTravelIn;
      removalBoundary = removalBoundaryIn;
      faceBoundary = faceBoundaryIn;
      itsBoss = itsBossIn;
    }
  ~planarFace();
  int isA(int aType)
    { return ((aType == planarFace_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  linearPath * get_courseOfTravel()
    {return courseOfTravel;}
  void set_courseOfTravel(linearPath * courseOfTravelIn)
    {courseOfTravel = courseOfTravelIn;}
  linearProfile * get_removalBoundary()
    {return removalBoundary;}
  void set_removalBoundary(linearProfile * removalBoundaryIn)
    {removalBoundary = removalBoundaryIn;}
  closedProfile * get_faceBoundary()
    {return faceBoundary;}
  void set_faceBoundary(closedProfile * faceBoundaryIn)
    {faceBoundary = faceBoundaryIn;}
  parenBossList * get_itsBoss()
    {return itsBoss;}
  void set_itsBoss(parenBossList * itsBossIn)
    {itsBoss = itsBossIn;}
private:
  linearPath * courseOfTravel;
  linearProfile * removalBoundary;
  closedProfile * faceBoundary;
  parenBossList * itsBoss;
};

/********************************************************************/

/* planarPocketBottomCondition

This is a class for the single definition of planarPocketBottomCondition.
It represents the following items:

PLANARPOCKETBOTTOMCONDITION '(' ')'

*/

class planarPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
  friend int yyparse();
public:
  planarPocketBottomCondition(){}
  ~planarPocketBottomCondition();
  int isA(int aType)
    { return ((aType == planarPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }
  void printSelf();
};

/********************************************************************/

/* plane

This is a class for the single definition of plane.
It represents the following items:

PLANE '(' CHARSTRING ',' axis2placement3d ')'

*/

class plane :
  public instance,
  public elementarySurface
{
  friend int yyparse();
public:
  plane(){}
  plane(
    char * nameIn,
    axis2placement3d * positionIn) :
      elementarySurface(
        nameIn,
        positionIn)
    {}
  ~plane();
  int isA(int aType)
    { return ((aType == plane_E) ||
	      (aType == elementarySurface_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
};

/********************************************************************/

/* plusMinusValue

This is a class for the single definition of plusMinusValue.
It represents the following items:

PLUSMINUSVALUE '(' REALSTRING ',' REALSTRING ',' INTSTRING ')'

*/

class plusMinusValue :
  public instance,
  public toleranceSelect
{
  friend int yyparse();
public:
  plusMinusValue(){}
  plusMinusValue(
    double upperLimitIn,
    double lowerLimitIn,
    int significantDigitsIn)
    {
      upperLimit = upperLimitIn;
      lowerLimit = lowerLimitIn;
      significantDigits = significantDigitsIn;
    }
  ~plusMinusValue();
  int isA(int aType)
    { return ((aType == plusMinusValue_E) ||
	      (aType == toleranceSelect_E));
    }
  void printSelf();
  double get_upperLimit()
    {return upperLimit;}
  void set_upperLimit(double upperLimitIn)
    {upperLimit = upperLimitIn;}
  double get_lowerLimit()
    {return lowerLimit;}
  void set_lowerLimit(double lowerLimitIn)
    {lowerLimit = lowerLimitIn;}
  int get_significantDigits()
    {return significantDigits;}
  void set_significantDigits(int significantDigitsIn)
    {significantDigits = significantDigitsIn;}
private:
  double upperLimit;
  double lowerLimit;
  int significantDigits;
};

/********************************************************************/

/* pocket

This is a parent class.

*/

class pocket :
  public machiningFeature
{
  friend int yyparse();
public:
  pocket(){}
  pocket(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    parenBossList * itsBossIn,
    real * slopeIn,
    pocketBottomCondition * bottomConditionIn,
    tolerancedLengthMeasure * planarRadiusIn,
    tolerancedLengthMeasure * orthogonalRadiusIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      itsBoss = itsBossIn;
      slope = slopeIn;
      bottomCondition = bottomConditionIn;
      planarRadius = planarRadiusIn;
      orthogonalRadius = orthogonalRadiusIn;
    }
  ~pocket(){}
  int isA(int aType)
    { return ((aType == pocket_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  parenBossList * get_itsBoss()
    {return itsBoss;}
  void set_itsBoss(parenBossList * itsBossIn)
    {itsBoss = itsBossIn;}
  real * get_slope()
    {return slope;}
  void set_slope(real * slopeIn)
    {slope = slopeIn;}
  pocketBottomCondition * get_bottomCondition()
    {return bottomCondition;}
  void set_bottomCondition(pocketBottomCondition * bottomConditionIn)
    {bottomCondition = bottomConditionIn;}
  tolerancedLengthMeasure * get_planarRadius()
    {return planarRadius;}
  void set_planarRadius(tolerancedLengthMeasure * planarRadiusIn)
    {planarRadius = planarRadiusIn;}
  tolerancedLengthMeasure * get_orthogonalRadius()
    {return orthogonalRadius;}
  void set_orthogonalRadius(tolerancedLengthMeasure * orthogonalRadiusIn)
    {orthogonalRadius = orthogonalRadiusIn;}
private:
  parenBossList * itsBoss;
  real * slope;
  pocketBottomCondition * bottomCondition;
  tolerancedLengthMeasure * planarRadius;
  tolerancedLengthMeasure * orthogonalRadius;
};

/********************************************************************/

/* radiusedSlotEndType

This is a class for the single definition of radiusedSlotEndType.
It represents the following items:

RADIUSEDSLOTENDTYPE '(' ')'

*/

class radiusedSlotEndType :
  public instance,
  public slotEndType
{
  friend int yyparse();
public:
  radiusedSlotEndType(){}
  ~radiusedSlotEndType();
  int isA(int aType)
    { return ((aType == radiusedSlotEndType_E) ||
	      (aType == slotEndType_E));
    }
  void printSelf();
};

/********************************************************************/

/* rapidMovement

This is a class for the single definition of rapidMovement.
It represents the following items:

RAPIDMOVEMENT '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ')'

*/

class rapidMovement :
  public instance,
  public operation,
  public workingstep
{
  friend int yyparse();
public:
  rapidMovement(){}
  rapidMovement(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn) :
      operation(
        itsToolpathIn,
        itsToolDirectionIn),
      workingstep(
        itsIdIn,
        itsSecplaneIn)
    {}
  ~rapidMovement();
  int isA(int aType)
    { return ((aType == rapidMovement_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf();
};

/********************************************************************/

/* reamer

This is a parent class.

*/

class reamer :
  public millingToolBody
{
  friend int yyparse();
public:
  reamer(){}
  reamer(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingToolBody(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~reamer(){}
  int isA(int aType)
    { return ((aType == reamer_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* rectangularClosedProfile

This is a class for the single definition of rectangularClosedProfile.
It represents the following items:

RECTANGULARCLOSEDPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' tolerancedLengthMeasure ')'

*/

class rectangularClosedProfile :
  public instance,
  public closedProfile
{
  friend int yyparse();
public:
  rectangularClosedProfile(){}
  rectangularClosedProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * profileWidthIn,
    tolerancedLengthMeasure * profileLengthIn) :
      closedProfile(
        placementIn)
    {
      profileWidth = profileWidthIn;
      profileLength = profileLengthIn;
    }
  ~rectangularClosedProfile();
  int isA(int aType)
    { return ((aType == rectangularClosedProfile_E) ||
	      (aType == closedProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_profileWidth()
    {return profileWidth;}
  void set_profileWidth(tolerancedLengthMeasure * profileWidthIn)
    {profileWidth = profileWidthIn;}
  tolerancedLengthMeasure * get_profileLength()
    {return profileLength;}
  void set_profileLength(tolerancedLengthMeasure * profileLengthIn)
    {profileLength = profileLengthIn;}
private:
  tolerancedLengthMeasure * profileWidth;
  tolerancedLengthMeasure * profileLength;
};

/********************************************************************/

/* replicateFeature

This is a parent class.

*/

class replicateFeature :
  public two5DmanufacturingFeature
{
  friend int yyparse();
public:
  replicateFeature(){}
  replicateFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn) :
      two5DmanufacturingFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn)
    {
      replicateBaseFeature = replicateBaseFeatureIn;
    }
  ~replicateFeature(){}
  int isA(int aType)
    { return ((aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf() = 0;
  two5DmanufacturingFeature * get_replicateBaseFeature()
    {return replicateBaseFeature;}
  void set_replicateBaseFeature(two5DmanufacturingFeature * replicateBaseFeatureIn)
    {replicateBaseFeature = replicateBaseFeatureIn;}
private:
  two5DmanufacturingFeature * replicateBaseFeature;
};

/********************************************************************/

/* rightCircularCylinder

This is a class for the single definition of rightCircularCylinder.
It represents the following items:

RIGHTCIRCULARCYLINDER '(' CHARSTRING ',' axis1placement ',' REALSTRING ',' REALSTRING ')'

*/

class rightCircularCylinder :
  public instance,
  public boundingGeometrySelect,
  public representationItem
{
  friend int yyparse();
public:
  rightCircularCylinder(){}
  rightCircularCylinder(
    char * nameIn,
    axis1placement * positionIn,
    double heightIn,
    double radiusIn) :
      representationItem(
        nameIn)
    {
      position = positionIn;
      height = heightIn;
      radius = radiusIn;
    }
  ~rightCircularCylinder();
  int isA(int aType)
    { return ((aType == rightCircularCylinder_E) ||
	      (aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  axis1placement * get_position()
    {return position;}
  void set_position(axis1placement * positionIn)
    {position = positionIn;}
  double get_height()
    {return height;}
  void set_height(double heightIn)
    {height = heightIn;}
  double get_radius()
    {return radius;}
  void set_radius(double radiusIn)
    {radius = radiusIn;}
private:
  axis1placement * position;
  double height;
  double radius;
};

/********************************************************************/

/* roundedUProfile

This is a class for the single definition of roundedUProfile.
It represents the following items:

ROUNDEDUPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ')'

*/

class roundedUProfile :
  public instance,
  public openProfile
{
  friend int yyparse();
public:
  roundedUProfile(){}
  roundedUProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * widthIn) :
      openProfile(
        placementIn)
    {
      width = widthIn;
    }
  ~roundedUProfile();
  int isA(int aType)
    { return ((aType == roundedUProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_width()
    {return width;}
  void set_width(tolerancedLengthMeasure * widthIn)
    {width = widthIn;}
private:
  tolerancedLengthMeasure * width;
};

/********************************************************************/

/* roundHole

This is a class for the single definition of roundHole.
It represents the following items:

ROUNDHOLE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' tolerancedLengthMeasure ',' optTaperSelect ',' holeBottomCondition ')'

*/

class roundHole :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  roundHole(){}
  roundHole(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    tolerancedLengthMeasure * diameterIn,
    taperSelect * changeInDiameterIn,
    holeBottomCondition * bottomConditionIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      diameter = diameterIn;
      changeInDiameter = changeInDiameterIn;
      bottomCondition = bottomConditionIn;
    }
  ~roundHole();
  int isA(int aType)
    { return ((aType == roundHole_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_diameter()
    {return diameter;}
  void set_diameter(tolerancedLengthMeasure * diameterIn)
    {diameter = diameterIn;}
  taperSelect * get_changeInDiameter()
    {return changeInDiameter;}
  void set_changeInDiameter(taperSelect * changeInDiameterIn)
    {changeInDiameter = changeInDiameterIn;}
  holeBottomCondition * get_bottomCondition()
    {return bottomCondition;}
  void set_bottomCondition(holeBottomCondition * bottomConditionIn)
    {bottomCondition = bottomConditionIn;}
private:
  tolerancedLengthMeasure * diameter;
  taperSelect * changeInDiameter;
  holeBottomCondition * bottomCondition;
};

/********************************************************************/

/* slot

This is a class for the single definition of slot.
It represents the following items:

SLOT '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' travelPath ',' openProfile ',' parenSlotEndTypeList ')'

*/

class slot :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  slot(){}
  slot(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    travelPath * courseOfTravelIn,
    openProfile * sweptShapeIn,
    parenSlotEndTypeList * endConditionsIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      courseOfTravel = courseOfTravelIn;
      sweptShape = sweptShapeIn;
      endConditions = endConditionsIn;
    }
  ~slot();
  int isA(int aType)
    { return ((aType == slot_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  travelPath * get_courseOfTravel()
    {return courseOfTravel;}
  void set_courseOfTravel(travelPath * courseOfTravelIn)
    {courseOfTravel = courseOfTravelIn;}
  openProfile * get_sweptShape()
    {return sweptShape;}
  void set_sweptShape(openProfile * sweptShapeIn)
    {sweptShape = sweptShapeIn;}
  parenSlotEndTypeList * get_endConditions()
    {return endConditions;}
  void set_endConditions(parenSlotEndTypeList * endConditionsIn)
    {endConditions = endConditionsIn;}
private:
  travelPath * courseOfTravel;
  openProfile * sweptShape;
  parenSlotEndTypeList * endConditions;
};

/********************************************************************/

/* speedName

This is a class for the single definition of speedName.
It represents the following items:

RAPID

*/

class speedName :
  public toolpathSpeedprofile
{
public:
  speedName(){}
  ~speedName();
  int isA(int aType)
    { return ((aType == speedName_E) ||
	      (aType == toolpathSpeedprofile_E));
    }
  void printSelf();
};

/********************************************************************/

/* sphericalCap

This is a class for the single definition of sphericalCap.
It represents the following items:

SPHERICALCAP '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' numericParameter ',' numericParameter ')'

*/

class sphericalCap :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  sphericalCap(){}
  sphericalCap(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    numericParameter * internalAngleIn,
    numericParameter * radiusIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      internalAngle = internalAngleIn;
      radius = radiusIn;
    }
  ~sphericalCap();
  int isA(int aType)
    { return ((aType == sphericalCap_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  numericParameter * get_internalAngle()
    {return internalAngle;}
  void set_internalAngle(numericParameter * internalAngleIn)
    {internalAngle = internalAngleIn;}
  numericParameter * get_radius()
    {return radius;}
  void set_radius(numericParameter * radiusIn)
    {radius = radiusIn;}
private:
  numericParameter * internalAngle;
  numericParameter * radius;
};

/********************************************************************/

/* sphericalHoleBottom

This is a class for the single definition of sphericalHoleBottom.
It represents the following items:

SPHERICALHOLEBOTTOM '(' tolerancedLengthMeasure ')'

*/

class sphericalHoleBottom :
  public instance,
  public blindBottomCondition
{
  friend int yyparse();
public:
  sphericalHoleBottom(){}
  sphericalHoleBottom(
    tolerancedLengthMeasure * radiusIn)
    {
      radius = radiusIn;
    }
  ~sphericalHoleBottom();
  int isA(int aType)
    { return ((aType == sphericalHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_radius()
    {return radius;}
  void set_radius(tolerancedLengthMeasure * radiusIn)
    {radius = radiusIn;}
private:
  tolerancedLengthMeasure * radius;
};

/********************************************************************/

/* sphericalSurface

This is a class for the single definition of sphericalSurface.
It represents the following items:

SPHERICALSURFACE '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ')'

*/

class sphericalSurface :
  public instance,
  public elementarySurface
{
  friend int yyparse();
public:
  sphericalSurface(){}
  sphericalSurface(
    char * nameIn,
    axis2placement3d * positionIn,
    double radiusIn) :
      elementarySurface(
        nameIn,
        positionIn)
    {
      radius = radiusIn;
    }
  ~sphericalSurface();
  int isA(int aType)
    { return ((aType == sphericalSurface_E) ||
	      (aType == elementarySurface_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  double get_radius()
    {return radius;}
  void set_radius(double radiusIn)
    {radius = radiusIn;}
private:
  double radius;
};

/********************************************************************/

/* squareUProfile

This is a class for the single definition of squareUProfile.
It represents the following items:

SQUAREUPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' tolerancedLengthMeasure ',' REALSTRING ',' tolerancedLengthMeasure ',' REALSTRING ')'

*/

class squareUProfile :
  public instance,
  public openProfile
{
  friend int yyparse();
public:
  squareUProfile(){}
  squareUProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * widthIn,
    tolerancedLengthMeasure * firstRadiusIn,
    double firstAngleIn,
    tolerancedLengthMeasure * secondRadiusIn,
    double secondAngleIn) :
      openProfile(
        placementIn)
    {
      width = widthIn;
      firstRadius = firstRadiusIn;
      firstAngle = firstAngleIn;
      secondRadius = secondRadiusIn;
      secondAngle = secondAngleIn;
    }
  ~squareUProfile();
  int isA(int aType)
    { return ((aType == squareUProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_width()
    {return width;}
  void set_width(tolerancedLengthMeasure * widthIn)
    {width = widthIn;}
  tolerancedLengthMeasure * get_firstRadius()
    {return firstRadius;}
  void set_firstRadius(tolerancedLengthMeasure * firstRadiusIn)
    {firstRadius = firstRadiusIn;}
  double get_firstAngle()
    {return firstAngle;}
  void set_firstAngle(double firstAngleIn)
    {firstAngle = firstAngleIn;}
  tolerancedLengthMeasure * get_secondRadius()
    {return secondRadius;}
  void set_secondRadius(tolerancedLengthMeasure * secondRadiusIn)
    {secondRadius = secondRadiusIn;}
  double get_secondAngle()
    {return secondAngle;}
  void set_secondAngle(double secondAngleIn)
    {secondAngle = secondAngleIn;}
private:
  tolerancedLengthMeasure * width;
  tolerancedLengthMeasure * firstRadius;
  double firstAngle;
  tolerancedLengthMeasure * secondRadius;
  double secondAngle;
};

/********************************************************************/

/* step

This is a class for the single definition of step.
It represents the following items:

STEP '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' optVeeProfile ',' parenBossList ')'

*/

class step :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  step(){}
  step(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * openBoundaryIn,
    veeProfile * wallBoundaryIn,
    parenBossList * itsBossIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      openBoundary = openBoundaryIn;
      wallBoundary = wallBoundaryIn;
      itsBoss = itsBossIn;
    }
  ~step();
  int isA(int aType)
    { return ((aType == step_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  linearPath * get_openBoundary()
    {return openBoundary;}
  void set_openBoundary(linearPath * openBoundaryIn)
    {openBoundary = openBoundaryIn;}
  veeProfile * get_wallBoundary()
    {return wallBoundary;}
  void set_wallBoundary(veeProfile * wallBoundaryIn)
    {wallBoundary = wallBoundaryIn;}
  parenBossList * get_itsBoss()
    {return itsBoss;}
  void set_itsBoss(parenBossList * itsBossIn)
    {itsBoss = itsBossIn;}
private:
  linearPath * openBoundary;
  veeProfile * wallBoundary;
  parenBossList * itsBoss;
};

/********************************************************************/

/* straightline

This is a class for the single definition of straightline.
It represents the following items:

STRAIGHTLINE

*/

class straightline :
  public strokeConnectionStrategy
{
public:
  straightline(){}
  ~straightline();
  int isA(int aType)
    { return ((aType == straightline_E) ||
	      (aType == strokeConnectionStrategy_E));
    }
  void printSelf();
};

/********************************************************************/

/* taperedReamer

This is a class for the single definition of taperedReamer.
It represents the following items:

TAPEREDREAMER '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class taperedReamer :
  public instance,
  public reamer
{
  friend int yyparse();
public:
  taperedReamer(){}
  taperedReamer(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * taperAngleIn) :
      reamer(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {
      taperAngle = taperAngleIn;
    }
  ~taperedReamer();
  int isA(int aType)
    { return ((aType == taperedReamer_E) ||
	      (aType == reamer_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
  real * get_taperAngle()
    {return taperAngle;}
  void set_taperAngle(real * taperAngleIn)
    {taperAngle = taperAngleIn;}
private:
  real * taperAngle;
};

/********************************************************************/

/* threeAxes

This is a class for the single definition of threeAxes.
It represents the following items:

THREEAXES '(' ')'

*/

class threeAxes :
  public instance,
  public toolDirection
{
  friend int yyparse();
public:
  threeAxes(){}
  ~threeAxes();
  int isA(int aType)
    { return ((aType == threeAxes_E) ||
	      (aType == toolDirection_E));
    }
  void printSelf();
};

/********************************************************************/

/* toolpathFeature

This is a class for the single definition of toolpathFeature.
It represents the following items:

TOOLPATHFEATURE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ')'

*/

class toolpathFeature :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  toolpathFeature(){}
  toolpathFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {}
  ~toolpathFeature();
  int isA(int aType)
    { return ((aType == toolpathFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
};

/********************************************************************/

/* touchProbing

This is a parent class.

*/

class touchProbing :
  public operation,
  public workingstep
{
  friend int yyparse();
public:
  touchProbing(){}
  touchProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn) :
      operation(
        itsToolpathIn,
        itsToolDirectionIn),
      workingstep(
        itsIdIn,
        itsSecplaneIn)
    {
      measuredOffset = measuredOffsetIn;
    }
  ~touchProbing(){}
  int isA(int aType)
    { return ((aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf() = 0;
  ncVariable * get_measuredOffset()
    {return measuredOffset;}
  void set_measuredOffset(ncVariable * measuredOffsetIn)
    {measuredOffset = measuredOffsetIn;}
private:
  ncVariable * measuredOffset;
};

/********************************************************************/

/* two5DmillingOperation

This is a parent class.

*/

class two5DmillingOperation :
  public millingTypeOperation
{
  friend int yyparse();
public:
  two5DmillingOperation(){}
  two5DmillingOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn) :
      millingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn)
    {
      itsMachiningStrategy = itsMachiningStrategyIn;
    }
  ~two5DmillingOperation(){}
  int isA(int aType)
    { return ((aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  two5DmillingStrategy * get_itsMachiningStrategy()
    {return itsMachiningStrategy;}
  void set_itsMachiningStrategy(two5DmillingStrategy * itsMachiningStrategyIn)
    {itsMachiningStrategy = itsMachiningStrategyIn;}
private:
  two5DmillingStrategy * itsMachiningStrategy;
};

/********************************************************************/

/* veeProfile

This is a class for the single definition of veeProfile.
It represents the following items:

VEEPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' REALSTRING ',' REALSTRING ')'

*/

class veeProfile :
  public instance,
  public openProfile
{
  friend int yyparse();
public:
  veeProfile(){}
  veeProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * profileRadiusIn,
    double profileAngleIn,
    double tiltAngleIn) :
      openProfile(
        placementIn)
    {
      profileRadius = profileRadiusIn;
      profileAngle = profileAngleIn;
      tiltAngle = tiltAngleIn;
    }
  ~veeProfile();
  int isA(int aType)
    { return ((aType == veeProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_profileRadius()
    {return profileRadius;}
  void set_profileRadius(tolerancedLengthMeasure * profileRadiusIn)
    {profileRadius = profileRadiusIn;}
  double get_profileAngle()
    {return profileAngle;}
  void set_profileAngle(double profileAngleIn)
    {profileAngle = profileAngleIn;}
  double get_tiltAngle()
    {return tiltAngle;}
  void set_tiltAngle(double tiltAngleIn)
    {tiltAngle = tiltAngleIn;}
private:
  tolerancedLengthMeasure * profileRadius;
  double profileAngle;
  double tiltAngle;
};

/********************************************************************/

/* workpieceCompleteProbing

This is a class for the single definition of workpieceCompleteProbing.
It represents the following items:

WORKPIECECOMPLETEPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' workpiece ',' tolerancedLengthMeasure ',' touchProbe ',' offsetVector ')'

*/

class workpieceCompleteProbing :
  public instance,
  public touchProbing
{
  friend int yyparse();
public:
  workpieceCompleteProbing(){}
  workpieceCompleteProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    workpiece * itsWorkpieceIn,
    tolerancedLengthMeasure * probingDistanceIn,
    touchProbe * itsProbeIn,
    offsetVector * computedOffsetIn) :
      touchProbing(
        itsIdIn,
        itsSecplaneIn,
        itsToolpathIn,
        itsToolDirectionIn,
        measuredOffsetIn)
    {
      itsWorkpiece = itsWorkpieceIn;
      probingDistance = probingDistanceIn;
      itsProbe = itsProbeIn;
      computedOffset = computedOffsetIn;
    }
  ~workpieceCompleteProbing();
  int isA(int aType)
    { return ((aType == workpieceCompleteProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  workpiece * get_itsWorkpiece()
    {return itsWorkpiece;}
  void set_itsWorkpiece(workpiece * itsWorkpieceIn)
    {itsWorkpiece = itsWorkpieceIn;}
  tolerancedLengthMeasure * get_probingDistance()
    {return probingDistance;}
  void set_probingDistance(tolerancedLengthMeasure * probingDistanceIn)
    {probingDistance = probingDistanceIn;}
  touchProbe * get_itsProbe()
    {return itsProbe;}
  void set_itsProbe(touchProbe * itsProbeIn)
    {itsProbe = itsProbeIn;}
  offsetVector * get_computedOffset()
    {return computedOffset;}
  void set_computedOffset(offsetVector * computedOffsetIn)
    {computedOffset = computedOffsetIn;}
private:
  workpiece * itsWorkpiece;
  tolerancedLengthMeasure * probingDistance;
  touchProbe * itsProbe;
  offsetVector * computedOffset;
};

/********************************************************************/

/* workpieceProbing

This is a class for the single definition of workpieceProbing.
It represents the following items:

WORKPIECEPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' axis2placement3d ',' workpiece ',' direction ',' tolerancedLengthMeasure ',' touchProbe ')'

*/

class workpieceProbing :
  public instance,
  public touchProbing
{
  friend int yyparse();
public:
  workpieceProbing(){}
  workpieceProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    axis2placement3d * startPositionIn,
    workpiece * itsWorkpieceIn,
    direction * itsDirectionIn,
    tolerancedLengthMeasure * expectedValueIn,
    touchProbe * itsProbeIn) :
      touchProbing(
        itsIdIn,
        itsSecplaneIn,
        itsToolpathIn,
        itsToolDirectionIn,
        measuredOffsetIn)
    {
      startPosition = startPositionIn;
      itsWorkpiece = itsWorkpieceIn;
      itsDirection = itsDirectionIn;
      expectedValue = expectedValueIn;
      itsProbe = itsProbeIn;
    }
  ~workpieceProbing();
  int isA(int aType)
    { return ((aType == workpieceProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  axis2placement3d * get_startPosition()
    {return startPosition;}
  void set_startPosition(axis2placement3d * startPositionIn)
    {startPosition = startPositionIn;}
  workpiece * get_itsWorkpiece()
    {return itsWorkpiece;}
  void set_itsWorkpiece(workpiece * itsWorkpieceIn)
    {itsWorkpiece = itsWorkpieceIn;}
  direction * get_itsDirection()
    {return itsDirection;}
  void set_itsDirection(direction * itsDirectionIn)
    {itsDirection = itsDirectionIn;}
  tolerancedLengthMeasure * get_expectedValue()
    {return expectedValue;}
  void set_expectedValue(tolerancedLengthMeasure * expectedValueIn)
    {expectedValue = expectedValueIn;}
  touchProbe * get_itsProbe()
    {return itsProbe;}
  void set_itsProbe(touchProbe * itsProbeIn)
    {itsProbe = itsProbeIn;}
private:
  axis2placement3d * startPosition;
  workpiece * itsWorkpiece;
  direction * itsDirection;
  tolerancedLengthMeasure * expectedValue;
  touchProbe * itsProbe;
};

/********************************************************************/

/* advancedBrepShapeRepresentation

This is a class for the single definition of advancedBrepShapeRepresentation.
It represents the following items:

ADVANCEDBREPSHAPEREPRESENTATION '(' ')'

*/

class advancedBrepShapeRepresentation :
  public boundingGeometrySelect
{
public:
  advancedBrepShapeRepresentation(){}
  ~advancedBrepShapeRepresentation();
  int isA(int aType)
    { return ((aType == advancedBrepShapeRepresentation_E) ||
	      (aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E));
    }
  void printSelf();
};

/********************************************************************/

/* axis1placement

This is a class for the single definition of axis1placement.
It represents the following items:

AXIS1PLACEMENT '(' CHARSTRING ',' cartesianPoint ',' direction ')'

*/

class axis1placement :
  public instance,
  public placement
{
  friend int yyparse();
public:
  axis1placement(){}
  axis1placement(
    char * nameIn,
    cartesianPoint * locationIn,
    direction * axisIn) :
      placement(
        nameIn,
        locationIn)
    {
      axis = axisIn;
    }
  ~axis1placement();
  int isA(int aType)
    { return ((aType == axis1placement_E) ||
	      (aType == placement_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  direction * get_axis()
    {return axis;}
  void set_axis(direction * axisIn)
    {axis = axisIn;}
private:
  direction * axis;
};

/********************************************************************/

/* axis2placement3d

This is a class for the single definition of axis2placement3d.
It represents the following items:

AXIS2PLACEMENT3D '(' CHARSTRING ',' cartesianPoint ',' direction ',' optDirection ')'

*/

class axis2placement3d :
  public instance,
  public placement
{
  friend int yyparse();
public:
  axis2placement3d(){}
  axis2placement3d(
    char * nameIn,
    cartesianPoint * locationIn,
    direction * axisIn,
    direction * refDirectionIn) :
      placement(
        nameIn,
        locationIn)
    {
      axis = axisIn;
      refDirection = refDirectionIn;
    }
  ~axis2placement3d();
  int isA(int aType)
    { return ((aType == axis2placement3d_E) ||
	      (aType == placement_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  direction * get_axis()
    {return axis;}
  void set_axis(direction * axisIn)
    {axis = axisIn;}
  direction * get_refDirection()
    {return refDirection;}
  void set_refDirection(direction * refDirectionIn)
    {refDirection = refDirectionIn;}
private:
  direction * axis;
  direction * refDirection;
};

/********************************************************************/

/* block

This is a class for the single definition of block.
It represents the following items:

BLOCK '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ',' REALSTRING ')'

*/

class block :
  public instance,
  public boundingGeometrySelect,
  public representationItem
{
  friend int yyparse();
public:
  block(){}
  block(
    char * nameIn,
    axis2placement3d * positionIn,
    double xIn,
    double yIn,
    double zIn) :
      representationItem(
        nameIn)
    {
      position = positionIn;
      x = xIn;
      y = yIn;
      z = zIn;
    }
  ~block();
  int isA(int aType)
    { return ((aType == block_E) ||
	      (aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  axis2placement3d * get_position()
    {return position;}
  void set_position(axis2placement3d * positionIn)
    {position = positionIn;}
  double get_x()
    {return x;}
  void set_x(double xIn)
    {x = xIn;}
  double get_y()
    {return y;}
  void set_y(double yIn)
    {y = yIn;}
  double get_z()
    {return z;}
  void set_z(double zIn)
    {z = zIn;}
private:
  axis2placement3d * position;
  double x;
  double y;
  double z;
};

/********************************************************************/

/* boss

This is a class for the single definition of boss.
It represents the following items:

BOSS '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' closedProfile ',' optReal ')'

*/

class boss :
  public instance,
  public machiningFeature
{
  friend int yyparse();
public:
  boss(){}
  boss(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    closedProfile * itsBoundaryIn,
    real * slopeIn) :
      machiningFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn)
    {
      itsBoundary = itsBoundaryIn;
      slope = slopeIn;
    }
  ~boss();
  int isA(int aType)
    { return ((aType == boss_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  closedProfile * get_itsBoundary()
    {return itsBoundary;}
  void set_itsBoundary(closedProfile * itsBoundaryIn)
    {itsBoundary = itsBoundaryIn;}
  real * get_slope()
    {return slope;}
  void set_slope(real * slopeIn)
    {slope = slopeIn;}
private:
  closedProfile * itsBoundary;
  real * slope;
};

/********************************************************************/

/* bottomAndSideMilling

This is a parent class.

*/

class bottomAndSideMilling :
  public two5DmillingOperation
{
  friend int yyparse();
public:
  bottomAndSideMilling(){}
  bottomAndSideMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn,
    real * allowanceBottomIn) :
      two5DmillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn)
    {
      axialCuttingDepth = axialCuttingDepthIn;
      radialCuttingDepth = radialCuttingDepthIn;
      allowanceSide = allowanceSideIn;
      allowanceBottom = allowanceBottomIn;
    }
  ~bottomAndSideMilling(){}
  int isA(int aType)
    { return ((aType == bottomAndSideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  real * get_axialCuttingDepth()
    {return axialCuttingDepth;}
  void set_axialCuttingDepth(real * axialCuttingDepthIn)
    {axialCuttingDepth = axialCuttingDepthIn;}
  real * get_radialCuttingDepth()
    {return radialCuttingDepth;}
  void set_radialCuttingDepth(real * radialCuttingDepthIn)
    {radialCuttingDepth = radialCuttingDepthIn;}
  real * get_allowanceSide()
    {return allowanceSide;}
  void set_allowanceSide(real * allowanceSideIn)
    {allowanceSide = allowanceSideIn;}
  real * get_allowanceBottom()
    {return allowanceBottom;}
  void set_allowanceBottom(real * allowanceBottomIn)
    {allowanceBottom = allowanceBottomIn;}
private:
  real * axialCuttingDepth;
  real * radialCuttingDepth;
  real * allowanceSide;
  real * allowanceBottom;
};

/********************************************************************/

/* bottomAndSideRoughMilling

This is a class for the single definition of bottomAndSideRoughMilling.
It represents the following items:

BOTTOMANDSIDEROUGHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class bottomAndSideRoughMilling :
  public instance,
  public bottomAndSideMilling
{
  friend int yyparse();
public:
  bottomAndSideRoughMilling(){}
  bottomAndSideRoughMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn,
    real * allowanceBottomIn) :
      bottomAndSideMilling(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn,
        axialCuttingDepthIn,
        radialCuttingDepthIn,
        allowanceSideIn,
        allowanceBottomIn)
    {}
  ~bottomAndSideRoughMilling();
  int isA(int aType)
    { return ((aType == bottomAndSideRoughMilling_E) ||
	      (aType == bottomAndSideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* boundedCurve

This is a parent class.

*/

class boundedCurve :
  public curve
{
  friend int yyparse();
public:
  boundedCurve(){}
  boundedCurve(
    char * nameIn) :
      curve(
        nameIn)
    {}
  ~boundedCurve(){}
  int isA(int aType)
    { return ((aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* centerDrill

This is a class for the single definition of centerDrill.
It represents the following items:

CENTERDRILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class centerDrill :
  public instance,
  public millingToolBody
{
  friend int yyparse();
public:
  centerDrill(){}
  centerDrill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingToolBody(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~centerDrill();
  int isA(int aType)
    { return ((aType == centerDrill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* circularPattern

This is a class for the single definition of circularPattern.
It represents the following items:

CIRCULARPATTERN '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' two5DmanufacturingFeature ',' REALSTRING ',' INTSTRING ',' parenCircularOffsetList ',' parenCircularOmitList ',' optTolerancedLengthMeasure ',' REALSTRING ')'

*/

class circularPattern :
  public instance,
  public replicateFeature
{
  friend int yyparse();
public:
  circularPattern(){}
  circularPattern(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn,
    double angleIncrementIn,
    int numberOfFeatureIn,
    parenCircularOffsetList * relocatedBaseFeatureIn,
    parenCircularOmitList * missingBaseFeatureIn,
    tolerancedLengthMeasure * baseFeatureDiameterIn,
    double baseFeatureRotationIn) :
      replicateFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        replicateBaseFeatureIn)
    {
      angleIncrement = angleIncrementIn;
      numberOfFeature = numberOfFeatureIn;
      relocatedBaseFeature = relocatedBaseFeatureIn;
      missingBaseFeature = missingBaseFeatureIn;
      baseFeatureDiameter = baseFeatureDiameterIn;
      baseFeatureRotation = baseFeatureRotationIn;
    }
  ~circularPattern();
  int isA(int aType)
    { return ((aType == circularPattern_E) ||
	      (aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  double get_angleIncrement()
    {return angleIncrement;}
  void set_angleIncrement(double angleIncrementIn)
    {angleIncrement = angleIncrementIn;}
  int get_numberOfFeature()
    {return numberOfFeature;}
  void set_numberOfFeature(int numberOfFeatureIn)
    {numberOfFeature = numberOfFeatureIn;}
  parenCircularOffsetList * get_relocatedBaseFeature()
    {return relocatedBaseFeature;}
  void set_relocatedBaseFeature(parenCircularOffsetList * relocatedBaseFeatureIn)
    {relocatedBaseFeature = relocatedBaseFeatureIn;}
  parenCircularOmitList * get_missingBaseFeature()
    {return missingBaseFeature;}
  void set_missingBaseFeature(parenCircularOmitList * missingBaseFeatureIn)
    {missingBaseFeature = missingBaseFeatureIn;}
  tolerancedLengthMeasure * get_baseFeatureDiameter()
    {return baseFeatureDiameter;}
  void set_baseFeatureDiameter(tolerancedLengthMeasure * baseFeatureDiameterIn)
    {baseFeatureDiameter = baseFeatureDiameterIn;}
  double get_baseFeatureRotation()
    {return baseFeatureRotation;}
  void set_baseFeatureRotation(double baseFeatureRotationIn)
    {baseFeatureRotation = baseFeatureRotationIn;}
private:
  double angleIncrement;
  int numberOfFeature;
  parenCircularOffsetList * relocatedBaseFeature;
  parenCircularOmitList * missingBaseFeature;
  tolerancedLengthMeasure * baseFeatureDiameter;
  double baseFeatureRotation;
};

/********************************************************************/

/* closedPocket

This is a class for the single definition of closedPocket.
It represents the following items:

CLOSEDPOCKET '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' parenBossList ',' optReal ',' pocketBottomCondition ',' optTolerancedLengthMeasure ',' optTolerancedLengthMeasure ',' closedProfile ')'

*/

class closedPocket :
  public instance,
  public pocket
{
  friend int yyparse();
public:
  closedPocket(){}
  closedPocket(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    parenBossList * itsBossIn,
    real * slopeIn,
    pocketBottomCondition * bottomConditionIn,
    tolerancedLengthMeasure * planarRadiusIn,
    tolerancedLengthMeasure * orthogonalRadiusIn,
    closedProfile * featureBoundaryIn) :
      pocket(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        depthIn,
        itsBossIn,
        slopeIn,
        bottomConditionIn,
        planarRadiusIn,
        orthogonalRadiusIn)
    {
      featureBoundary = featureBoundaryIn;
    }
  ~closedPocket();
  int isA(int aType)
    { return ((aType == closedPocket_E) ||
	      (aType == pocket_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  closedProfile * get_featureBoundary()
    {return featureBoundary;}
  void set_featureBoundary(closedProfile * featureBoundaryIn)
    {featureBoundary = featureBoundaryIn;}
private:
  closedProfile * featureBoundary;
};

/********************************************************************/

/* combinedDrillAndReamer

This is a class for the single definition of combinedDrillAndReamer.
It represents the following items:

COMBINEDDRILLANDREAMER '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class combinedDrillAndReamer :
  public instance,
  public reamer
{
  friend int yyparse();
public:
  combinedDrillAndReamer(){}
  combinedDrillAndReamer(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * drillLengthIn) :
      reamer(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {
      drillLength = drillLengthIn;
    }
  ~combinedDrillAndReamer();
  int isA(int aType)
    { return ((aType == combinedDrillAndReamer_E) ||
	      (aType == reamer_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
  real * get_drillLength()
    {return drillLength;}
  void set_drillLength(real * drillLengthIn)
    {drillLength = drillLengthIn;}
private:
  real * drillLength;
};

/********************************************************************/

/* compositeCurve

This is a class for the single definition of compositeCurve.
It represents the following items:

COMPOSITECURVE '(' CHARSTRING ',' parenCompositeCurveSegmentListFull ',' logical ')'

*/

class compositeCurve :
  public instance,
  public boundedCurve
{
  friend int yyparse();
public:
  compositeCurve(){}
  compositeCurve(
    char * nameIn,
    parenCompositeCurveSegmentListFull * segmentsIn,
    logical * selfIntersectIn) :
      boundedCurve(
        nameIn)
    {
      segments = segmentsIn;
      selfIntersect = selfIntersectIn;
    }
  ~compositeCurve();
  int isA(int aType)
    { return ((aType == compositeCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  parenCompositeCurveSegmentListFull * get_segments()
    {return segments;}
  void set_segments(parenCompositeCurveSegmentListFull * segmentsIn)
    {segments = segmentsIn;}
  logical * get_selfIntersect()
    {return selfIntersect;}
  void set_selfIntersect(logical * selfIntersectIn)
    {selfIntersect = selfIntersectIn;}
private:
  parenCompositeCurveSegmentListFull * segments;
  logical * selfIntersect;
};

/********************************************************************/

/* conic

This is a parent class.

*/

class conic :
  public curve
{
  friend int yyparse();
public:
  conic(){}
  conic(
    char * nameIn,
    axis2placement3d * positionIn) :
      curve(
        nameIn)
    {
      position = positionIn;
    }
  ~conic(){}
  int isA(int aType)
    { return ((aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf() = 0;
  axis2placement3d * get_position()
    {return position;}
  void set_position(axis2placement3d * positionIn)
    {position = positionIn;}
private:
  axis2placement3d * position;
};

/********************************************************************/

/* counterboreParent

This is a parent class.

*/

class counterboreParent :
  public millingToolBody
{
  friend int yyparse();
public:
  counterboreParent(){}
  counterboreParent(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingToolBody(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~counterboreParent(){}
  int isA(int aType)
    { return ((aType == counterboreParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* countersinkParent

This is a parent class.

*/

class countersinkParent :
  public millingToolBody
{
  friend int yyparse();
public:
  countersinkParent(){}
  countersinkParent(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingToolBody(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~countersinkParent(){}
  int isA(int aType)
    { return ((aType == countersinkParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* drill

This is a parent class.

*/

class drill :
  public millingToolBody
{
  friend int yyparse();
public:
  drill(){}
  drill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingToolBody(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~drill(){}
  int isA(int aType)
    { return ((aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* drillingTypeOperation

This is a parent class.

*/

class drillingTypeOperation :
  public millingMachiningOperation
{
  friend int yyparse();
public:
  drillingTypeOperation(){}
  drillingTypeOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn) :
      millingMachiningOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn)
    {
      cuttingDepth = cuttingDepthIn;
      previousDiameter = previousDiameterIn;
      dwellTimeBottom = dwellTimeBottomIn;
      feedOnRetract = feedOnRetractIn;
      itsMachiningStrategy = itsMachiningStrategyIn;
    }
  ~drillingTypeOperation(){}
  int isA(int aType)
    { return ((aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  real * get_cuttingDepth()
    {return cuttingDepth;}
  void set_cuttingDepth(real * cuttingDepthIn)
    {cuttingDepth = cuttingDepthIn;}
  real * get_previousDiameter()
    {return previousDiameter;}
  void set_previousDiameter(real * previousDiameterIn)
    {previousDiameter = previousDiameterIn;}
  real * get_dwellTimeBottom()
    {return dwellTimeBottom;}
  void set_dwellTimeBottom(real * dwellTimeBottomIn)
    {dwellTimeBottom = dwellTimeBottomIn;}
  real * get_feedOnRetract()
    {return feedOnRetract;}
  void set_feedOnRetract(real * feedOnRetractIn)
    {feedOnRetract = feedOnRetractIn;}
  drillingTypeStrategy * get_itsMachiningStrategy()
    {return itsMachiningStrategy;}
  void set_itsMachiningStrategy(drillingTypeStrategy * itsMachiningStrategyIn)
    {itsMachiningStrategy = itsMachiningStrategyIn;}
private:
  real * cuttingDepth;
  real * previousDiameter;
  real * dwellTimeBottom;
  real * feedOnRetract;
  drillingTypeStrategy * itsMachiningStrategy;
};

/********************************************************************/

/* ellipse

This is a class for the single definition of ellipse.
It represents the following items:

ELLIPSE '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ')'

*/

class ellipse :
  public instance,
  public conic
{
  friend int yyparse();
public:
  ellipse(){}
  ellipse(
    char * nameIn,
    axis2placement3d * positionIn,
    double semiAxis1In,
    double semiAxis2In) :
      conic(
        nameIn,
        positionIn)
    {
      semiAxis1 = semiAxis1In;
      semiAxis2 = semiAxis2In;
    }
  ~ellipse();
  int isA(int aType)
    { return ((aType == ellipse_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  double get_semiAxis1()
    {return semiAxis1;}
  void set_semiAxis1(double semiAxis1In)
    {semiAxis1 = semiAxis1In;}
  double get_semiAxis2()
    {return semiAxis2;}
  void set_semiAxis2(double semiAxis2In)
    {semiAxis2 = semiAxis2In;}
private:
  double semiAxis1;
  double semiAxis2;
};

/********************************************************************/

/* freeformOperation

This is a class for the single definition of freeformOperation.
It represents the following items:

FREEFORMOPERATION '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optFreeformStrategy ')'

*/

class freeformOperation :
  public instance,
  public millingTypeOperation
{
  friend int yyparse();
public:
  freeformOperation(){}
  freeformOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    freeformStrategy * itsMachiningStrategyIn) :
      millingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn)
    {
      itsMachiningStrategy = itsMachiningStrategyIn;
    }
  ~freeformOperation();
  int isA(int aType)
    { return ((aType == freeformOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
  freeformStrategy * get_itsMachiningStrategy()
    {return itsMachiningStrategy;}
  void set_itsMachiningStrategy(freeformStrategy * itsMachiningStrategyIn)
    {itsMachiningStrategy = itsMachiningStrategyIn;}
private:
  freeformStrategy * itsMachiningStrategy;
};

/********************************************************************/

/* generalPattern

This is a class for the single definition of generalPattern.
It represents the following items:

GENERALPATTERN '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' two5DmanufacturingFeature ',' parenAxis2placement3dListFull ')'

*/

class generalPattern :
  public instance,
  public replicateFeature
{
  friend int yyparse();
public:
  generalPattern(){}
  generalPattern(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn,
    parenAxis2placement3dListFull * replicateLocationsIn) :
      replicateFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        replicateBaseFeatureIn)
    {
      replicateLocations = replicateLocationsIn;
    }
  ~generalPattern();
  int isA(int aType)
    { return ((aType == generalPattern_E) ||
	      (aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  parenAxis2placement3dListFull * get_replicateLocations()
    {return replicateLocations;}
  void set_replicateLocations(parenAxis2placement3dListFull * replicateLocationsIn)
    {replicateLocations = replicateLocationsIn;}
private:
  parenAxis2placement3dListFull * replicateLocations;
};

/********************************************************************/

/* hyperbola

This is a class for the single definition of hyperbola.
It represents the following items:

HYPERBOLA '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ')'

*/

class hyperbola :
  public instance,
  public conic
{
  friend int yyparse();
public:
  hyperbola(){}
  hyperbola(
    char * nameIn,
    axis2placement3d * positionIn,
    double semiAxisIn,
    double semiImagAxisIn) :
      conic(
        nameIn,
        positionIn)
    {
      semiAxis = semiAxisIn;
      semiImagAxis = semiImagAxisIn;
    }
  ~hyperbola();
  int isA(int aType)
    { return ((aType == hyperbola_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  double get_semiAxis()
    {return semiAxis;}
  void set_semiAxis(double semiAxisIn)
    {semiAxis = semiAxisIn;}
  double get_semiImagAxis()
    {return semiImagAxis;}
  void set_semiImagAxis(double semiImagAxisIn)
    {semiImagAxis = semiImagAxisIn;}
private:
  double semiAxis;
  double semiImagAxis;
};

/********************************************************************/

/* linearProfile

This is a class for the single definition of linearProfile.
It represents the following items:

LINEARPROFILE '(' optAxis2placement3d ',' numericParameter ')'

*/

class linearProfile :
  public instance,
  public openProfile
{
  friend int yyparse();
public:
  linearProfile(){}
  linearProfile(
    axis2placement3d * placementIn,
    numericParameter * profileLengthIn) :
      openProfile(
        placementIn)
    {
      profileLength = profileLengthIn;
    }
  ~linearProfile();
  int isA(int aType)
    { return ((aType == linearProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }
  void printSelf();
  numericParameter * get_profileLength()
    {return profileLength;}
  void set_profileLength(numericParameter * profileLengthIn)
    {profileLength = profileLengthIn;}
private:
  numericParameter * profileLength;
};

/********************************************************************/

/* millingCutter

This is a parent class.

*/

class millingCutter :
  public millingToolBody
{
  friend int yyparse();
public:
  millingCutter(){}
  millingCutter(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingToolBody(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~millingCutter(){}
  int isA(int aType)
    { return ((aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* parabola

This is a class for the single definition of parabola.
It represents the following items:

PARABOLA '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ')'

*/

class parabola :
  public instance,
  public conic
{
  friend int yyparse();
public:
  parabola(){}
  parabola(
    char * nameIn,
    axis2placement3d * positionIn,
    double focalDistIn) :
      conic(
        nameIn,
        positionIn)
    {
      focalDist = focalDistIn;
    }
  ~parabola();
  int isA(int aType)
    { return ((aType == parabola_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  double get_focalDist()
    {return focalDist;}
  void set_focalDist(double focalDistIn)
    {focalDist = focalDistIn;}
private:
  double focalDist;
};

/********************************************************************/

/* planeMilling

This is a parent class.

*/

class planeMilling :
  public two5DmillingOperation
{
  friend int yyparse();
public:
  planeMilling(){}
  planeMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * allowanceBottomIn) :
      two5DmillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn)
    {
      axialCuttingDepth = axialCuttingDepthIn;
      allowanceBottom = allowanceBottomIn;
    }
  ~planeMilling(){}
  int isA(int aType)
    { return ((aType == planeMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  real * get_axialCuttingDepth()
    {return axialCuttingDepth;}
  void set_axialCuttingDepth(real * axialCuttingDepthIn)
    {axialCuttingDepth = axialCuttingDepthIn;}
  real * get_allowanceBottom()
    {return allowanceBottom;}
  void set_allowanceBottom(real * allowanceBottomIn)
    {allowanceBottom = allowanceBottomIn;}
private:
  real * axialCuttingDepth;
  real * allowanceBottom;
};

/********************************************************************/

/* planeRoughMilling

This is a class for the single definition of planeRoughMilling.
It represents the following items:

PLANEROUGHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ')'

*/

class planeRoughMilling :
  public instance,
  public planeMilling
{
  friend int yyparse();
public:
  planeRoughMilling(){}
  planeRoughMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * allowanceBottomIn) :
      planeMilling(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn,
        axialCuttingDepthIn,
        allowanceBottomIn)
    {}
  ~planeRoughMilling();
  int isA(int aType)
    { return ((aType == planeRoughMilling_E) ||
	      (aType == planeMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* polyline

This is a class for the single definition of polyline.
It represents the following items:

POLYLINE '(' CHARSTRING ',' parenCartesianPointListFull ')'

*/

class polyline :
  public instance,
  public boundedCurve
{
  friend int yyparse();
public:
  polyline(){}
  polyline(
    char * nameIn,
    parenCartesianPointListFull * pointsIn) :
      boundedCurve(
        nameIn)
    {
      points = pointsIn;
    }
  ~polyline();
  int isA(int aType)
    { return ((aType == polyline_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  parenCartesianPointListFull * get_points()
    {return points;}
  void set_points(parenCartesianPointListFull * pointsIn)
    {points = pointsIn;}
private:
  parenCartesianPointListFull * points;
};

/********************************************************************/

/* rectangularPattern

This is a class for the single definition of rectangularPattern.
It represents the following items:

RECTANGULARPATTERN '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' two5DmanufacturingFeature tolerancedLengthMeasure ',' direction ',' optInteger ',' INTSTRING ',' optTolerancedLengthMeasure ',' optDirection ',' parenRectangularOffsetList ',' parenRectangularOmitList ')'

*/

class rectangularPattern :
  public instance,
  public replicateFeature
{
  friend int yyparse();
public:
  rectangularPattern(){}
  rectangularPattern(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn,
    tolerancedLengthMeasure * spacingIn,
    direction * itsDirectionIn,
    integer * numberOfRowsIn,
    int numberOfColumnsIn,
    tolerancedLengthMeasure * rowSpacingIn,
    direction * rowLayoutDirectionIn,
    parenRectangularOffsetList * relocatedBaseFeatureIn,
    parenRectangularOmitList * missingBaseFeatureIn) :
      replicateFeature(
        itsIdIn,
        itsWorkpieceIn,
        itsOperationsIn,
        featurePlacementIn,
        replicateBaseFeatureIn)
    {
      spacing = spacingIn;
      itsDirection = itsDirectionIn;
      numberOfRows = numberOfRowsIn;
      numberOfColumns = numberOfColumnsIn;
      rowSpacing = rowSpacingIn;
      rowLayoutDirection = rowLayoutDirectionIn;
      relocatedBaseFeature = relocatedBaseFeatureIn;
      missingBaseFeature = missingBaseFeatureIn;
    }
  ~rectangularPattern();
  int isA(int aType)
    { return ((aType == rectangularPattern_E) ||
	      (aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }
  void printSelf();
  tolerancedLengthMeasure * get_spacing()
    {return spacing;}
  void set_spacing(tolerancedLengthMeasure * spacingIn)
    {spacing = spacingIn;}
  direction * get_itsDirection()
    {return itsDirection;}
  void set_itsDirection(direction * itsDirectionIn)
    {itsDirection = itsDirectionIn;}
  integer * get_numberOfRows()
    {return numberOfRows;}
  void set_numberOfRows(integer * numberOfRowsIn)
    {numberOfRows = numberOfRowsIn;}
  int get_numberOfColumns()
    {return numberOfColumns;}
  void set_numberOfColumns(int numberOfColumnsIn)
    {numberOfColumns = numberOfColumnsIn;}
  tolerancedLengthMeasure * get_rowSpacing()
    {return rowSpacing;}
  void set_rowSpacing(tolerancedLengthMeasure * rowSpacingIn)
    {rowSpacing = rowSpacingIn;}
  direction * get_rowLayoutDirection()
    {return rowLayoutDirection;}
  void set_rowLayoutDirection(direction * rowLayoutDirectionIn)
    {rowLayoutDirection = rowLayoutDirectionIn;}
  parenRectangularOffsetList * get_relocatedBaseFeature()
    {return relocatedBaseFeature;}
  void set_relocatedBaseFeature(parenRectangularOffsetList * relocatedBaseFeatureIn)
    {relocatedBaseFeature = relocatedBaseFeatureIn;}
  parenRectangularOmitList * get_missingBaseFeature()
    {return missingBaseFeature;}
  void set_missingBaseFeature(parenRectangularOmitList * missingBaseFeatureIn)
    {missingBaseFeature = missingBaseFeatureIn;}
private:
  tolerancedLengthMeasure * spacing;
  direction * itsDirection;
  integer * numberOfRows;
  int numberOfColumns;
  tolerancedLengthMeasure * rowSpacing;
  direction * rowLayoutDirection;
  parenRectangularOffsetList * relocatedBaseFeature;
  parenRectangularOmitList * missingBaseFeature;
};

/********************************************************************/

/* sideMilling

This is a parent class.

*/

class sideMilling :
  public two5DmillingOperation
{
  friend int yyparse();
public:
  sideMilling(){}
  sideMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn) :
      two5DmillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn)
    {
      axialCuttingDepth = axialCuttingDepthIn;
      radialCuttingDepth = radialCuttingDepthIn;
      allowanceSide = allowanceSideIn;
    }
  ~sideMilling(){}
  int isA(int aType)
    { return ((aType == sideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  real * get_axialCuttingDepth()
    {return axialCuttingDepth;}
  void set_axialCuttingDepth(real * axialCuttingDepthIn)
    {axialCuttingDepth = axialCuttingDepthIn;}
  real * get_radialCuttingDepth()
    {return radialCuttingDepth;}
  void set_radialCuttingDepth(real * radialCuttingDepthIn)
    {radialCuttingDepth = radialCuttingDepthIn;}
  real * get_allowanceSide()
    {return allowanceSide;}
  void set_allowanceSide(real * allowanceSideIn)
    {allowanceSide = allowanceSideIn;}
private:
  real * axialCuttingDepth;
  real * radialCuttingDepth;
  real * allowanceSide;
};

/********************************************************************/

/* sideFinishMilling

This is a class for the single definition of sideFinishMilling.
It represents the following items:

SIDEFINISHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ')'

*/

class sideFinishMilling :
  public instance,
  public sideMilling
{
  friend int yyparse();
public:
  sideFinishMilling(){}
  sideFinishMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn) :
      sideMilling(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn,
        axialCuttingDepthIn,
        radialCuttingDepthIn,
        allowanceSideIn)
    {}
  ~sideFinishMilling();
  int isA(int aType)
    { return ((aType == sideFinishMilling_E) ||
	      (aType == sideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* sideRoughMilling

This is a class for the single definition of sideRoughMilling.
It represents the following items:

SIDEROUGHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ')'

*/

class sideRoughMilling :
  public instance,
  public sideMilling
{
  friend int yyparse();
public:
  sideRoughMilling(){}
  sideRoughMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn) :
      sideMilling(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn,
        axialCuttingDepthIn,
        radialCuttingDepthIn,
        allowanceSideIn)
    {}
  ~sideRoughMilling();
  int isA(int aType)
    { return ((aType == sideRoughMilling_E) ||
	      (aType == sideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* tapping

This is a class for the single definition of tapping.
It represents the following items:

TAPPING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy boolean ')'

*/

class tapping :
  public instance,
  public drillingTypeOperation
{
  friend int yyparse();
public:
  tapping(){}
  tapping(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * compensationChuckIn) :
      drillingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {
      compensationChuck = compensationChuckIn;
    }
  ~tapping();
  int isA(int aType)
    { return ((aType == tapping_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
  boolean * get_compensationChuck()
    {return compensationChuck;}
  void set_compensationChuck(boolean * compensationChuckIn)
    {compensationChuck = compensationChuckIn;}
private:
  boolean * compensationChuck;
};

/********************************************************************/

/* threadDrilling

This is a class for the single definition of threadDrilling.
It represents the following items:

THREADDRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy boolean ')'

*/

class threadDrilling :
  public instance,
  public drillingTypeOperation
{
  friend int yyparse();
public:
  threadDrilling(){}
  threadDrilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * helicalMovementOnForwardIn) :
      drillingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {
      helicalMovementOnForward = helicalMovementOnForwardIn;
    }
  ~threadDrilling();
  int isA(int aType)
    { return ((aType == threadDrilling_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
  boolean * get_helicalMovementOnForward()
    {return helicalMovementOnForward;}
  void set_helicalMovementOnForward(boolean * helicalMovementOnForwardIn)
    {helicalMovementOnForward = helicalMovementOnForwardIn;}
private:
  boolean * helicalMovementOnForward;
};

/********************************************************************/

/* toolProbing

This is a class for the single definition of toolProbing.
It represents the following items:

TOOLPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' cartesianPoint ',' REALSTRING ',' machiningTool ')'

*/

class toolProbing :
  public instance,
  public touchProbing
{
  friend int yyparse();
public:
  toolProbing(){}
  toolProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    cartesianPoint * offsetIn,
    double maxWearIn,
    machiningTool * itsToolIn) :
      touchProbing(
        itsIdIn,
        itsSecplaneIn,
        itsToolpathIn,
        itsToolDirectionIn,
        measuredOffsetIn)
    {
      offset = offsetIn;
      maxWear = maxWearIn;
      itsTool = itsToolIn;
    }
  ~toolProbing();
  int isA(int aType)
    { return ((aType == toolProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }
  void printSelf();
  cartesianPoint * get_offset()
    {return offset;}
  void set_offset(cartesianPoint * offsetIn)
    {offset = offsetIn;}
  double get_maxWear()
    {return maxWear;}
  void set_maxWear(double maxWearIn)
    {maxWear = maxWearIn;}
  machiningTool * get_itsTool()
    {return itsTool;}
  void set_itsTool(machiningTool * itsToolIn)
    {itsTool = itsToolIn;}
private:
  cartesianPoint * offset;
  double maxWear;
  machiningTool * itsTool;
};

/********************************************************************/

/* trimmedCurve

This is a class for the single definition of trimmedCurve.
It represents the following items:

TRIMMEDCURVE '(' CHARSTRING ',' curve ',' parenTrimmingSelectListFull ',' parenTrimmingSelectListFull ',' boolean ',' trimmingPreference ')'

*/

class trimmedCurve :
  public instance,
  public boundedCurve
{
  friend int yyparse();
public:
  trimmedCurve(){}
  trimmedCurve(
    char * nameIn,
    curve * basisCurveIn,
    parenTrimmingSelectListFull * trim1In,
    parenTrimmingSelectListFull * trim2In,
    boolean * senseAgreementIn,
    trimmingPreference * masterRepresentationIn) :
      boundedCurve(
        nameIn)
    {
      basisCurve = basisCurveIn;
      trim1 = trim1In;
      trim2 = trim2In;
      senseAgreement = senseAgreementIn;
      masterRepresentation = masterRepresentationIn;
    }
  ~trimmedCurve();
  int isA(int aType)
    { return ((aType == trimmedCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  curve * get_basisCurve()
    {return basisCurve;}
  void set_basisCurve(curve * basisCurveIn)
    {basisCurve = basisCurveIn;}
  parenTrimmingSelectListFull * get_trim1()
    {return trim1;}
  void set_trim1(parenTrimmingSelectListFull * trim1In)
    {trim1 = trim1In;}
  parenTrimmingSelectListFull * get_trim2()
    {return trim2;}
  void set_trim2(parenTrimmingSelectListFull * trim2In)
    {trim2 = trim2In;}
  boolean * get_senseAgreement()
    {return senseAgreement;}
  void set_senseAgreement(boolean * senseAgreementIn)
    {senseAgreement = senseAgreementIn;}
  trimmingPreference * get_masterRepresentation()
    {return masterRepresentation;}
  void set_masterRepresentation(trimmingPreference * masterRepresentationIn)
    {masterRepresentation = masterRepresentationIn;}
private:
  curve * basisCurve;
  parenTrimmingSelectListFull * trim1;
  parenTrimmingSelectListFull * trim2;
  boolean * senseAgreement;
  trimmingPreference * masterRepresentation;
};

/********************************************************************/

/* twistDrill

This is a class for the single definition of twistDrill.
It represents the following items:

TWISTDRILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class twistDrill :
  public instance,
  public drill
{
  friend int yyparse();
public:
  twistDrill(){}
  twistDrill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      drill(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~twistDrill();
  int isA(int aType)
    { return ((aType == twistDrill_E) ||
	      (aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* backBoring

This is a class for the single definition of backBoring.
It represents the following items:

BACKBORING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class backBoring :
  public instance,
  public drillingTypeOperation
{
  friend int yyparse();
public:
  backBoring(){}
  backBoring(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn) :
      drillingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {}
  ~backBoring();
  int isA(int aType)
    { return ((aType == backBoring_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* backsideCounterbore

This is a class for the single definition of backsideCounterbore.
It represents the following items:

BACKSIDECOUNTERBORE '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class backsideCounterbore :
  public instance,
  public counterboreParent
{
  friend int yyparse();
public:
  backsideCounterbore(){}
  backsideCounterbore(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      counterboreParent(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~backsideCounterbore();
  int isA(int aType)
    { return ((aType == backsideCounterbore_E) ||
	      (aType == counterboreParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* backsideCountersink

This is a class for the single definition of backsideCountersink.
It represents the following items:

BACKSIDECOUNTERSINK '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class backsideCountersink :
  public instance,
  public countersinkParent
{
  friend int yyparse();
public:
  backsideCountersink(){}
  backsideCountersink(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * countersinkRadiusIn) :
      countersinkParent(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {
      countersinkRadius = countersinkRadiusIn;
    }
  ~backsideCountersink();
  int isA(int aType)
    { return ((aType == backsideCountersink_E) ||
	      (aType == countersinkParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
  real * get_countersinkRadius()
    {return countersinkRadius;}
  void set_countersinkRadius(real * countersinkRadiusIn)
    {countersinkRadius = countersinkRadiusIn;}
private:
  real * countersinkRadius;
};

/********************************************************************/

/* boringOperation

This is a parent class.

*/

class boringOperation :
  public drillingTypeOperation
{
  friend int yyparse();
public:
  boringOperation(){}
  boringOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * spindleStopAtBottomIn,
    real * depthOfTestcutIn,
    cartesianPoint * waitingPositionIn) :
      drillingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {
      spindleStopAtBottom = spindleStopAtBottomIn;
      depthOfTestcut = depthOfTestcutIn;
      waitingPosition = waitingPositionIn;
    }
  ~boringOperation(){}
  int isA(int aType)
    { return ((aType == boringOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
  boolean * get_spindleStopAtBottom()
    {return spindleStopAtBottom;}
  void set_spindleStopAtBottom(boolean * spindleStopAtBottomIn)
    {spindleStopAtBottom = spindleStopAtBottomIn;}
  real * get_depthOfTestcut()
    {return depthOfTestcut;}
  void set_depthOfTestcut(real * depthOfTestcutIn)
    {depthOfTestcut = depthOfTestcutIn;}
  cartesianPoint * get_waitingPosition()
    {return waitingPosition;}
  void set_waitingPosition(cartesianPoint * waitingPositionIn)
    {waitingPosition = waitingPositionIn;}
private:
  boolean * spindleStopAtBottom;
  real * depthOfTestcut;
  cartesianPoint * waitingPosition;
};

/********************************************************************/

/* bottomAndSideFinishMilling

This is a class for the single definition of bottomAndSideFinishMilling.
It represents the following items:

BOTTOMANDSIDEFINISHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class bottomAndSideFinishMilling :
  public instance,
  public bottomAndSideMilling
{
  friend int yyparse();
public:
  bottomAndSideFinishMilling(){}
  bottomAndSideFinishMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn,
    real * allowanceBottomIn) :
      bottomAndSideMilling(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn,
        axialCuttingDepthIn,
        radialCuttingDepthIn,
        allowanceSideIn,
        allowanceBottomIn)
    {}
  ~bottomAndSideFinishMilling();
  int isA(int aType)
    { return ((aType == bottomAndSideFinishMilling_E) ||
	      (aType == bottomAndSideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* circle

This is a class for the single definition of circle.
It represents the following items:

CIRCLE '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ')'

*/

class circle :
  public instance,
  public conic
{
  friend int yyparse();
public:
  circle(){}
  circle(
    char * nameIn,
    axis2placement3d * positionIn,
    double radiusIn) :
      conic(
        nameIn,
        positionIn)
    {
      radius = radiusIn;
    }
  ~circle();
  int isA(int aType)
    { return ((aType == circle_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == representationItem_E));
    }
  void printSelf();
  double get_radius()
    {return radius;}
  void set_radius(double radiusIn)
    {radius = radiusIn;}
private:
  double radius;
};

/********************************************************************/

/* counterbore

This is a class for the single definition of counterbore.
It represents the following items:

COUNTERBORE '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class counterbore :
  public instance,
  public counterboreParent
{
  friend int yyparse();
public:
  counterbore(){}
  counterbore(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      counterboreParent(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~counterbore();
  int isA(int aType)
    { return ((aType == counterbore_E) ||
	      (aType == counterboreParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* countersink

This is a class for the single definition of countersink.
It represents the following items:

COUNTERSINK '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class countersink :
  public instance,
  public countersinkParent
{
  friend int yyparse();
public:
  countersink(){}
  countersink(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * countersinkRadiusIn) :
      countersinkParent(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {
      countersinkRadius = countersinkRadiusIn;
    }
  ~countersink();
  int isA(int aType)
    { return ((aType == countersink_E) ||
	      (aType == countersinkParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
  real * get_countersinkRadius()
    {return countersinkRadius;}
  void set_countersinkRadius(real * countersinkRadiusIn)
    {countersinkRadius = countersinkRadiusIn;}
private:
  real * countersinkRadius;
};

/********************************************************************/

/* drillingOperation

This is a parent class.

*/

class drillingOperation :
  public drillingTypeOperation
{
  friend int yyparse();
public:
  drillingOperation(){}
  drillingOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn) :
      drillingTypeOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {}
  ~drillingOperation(){}
  int isA(int aType)
    { return ((aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* endmill

This is a parent class.

*/

class endmill :
  public millingCutter
{
  friend int yyparse();
public:
  endmill(){}
  endmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingCutter(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~endmill(){}
  int isA(int aType)
    { return ((aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf() = 0;
};

/********************************************************************/

/* facemill

This is a class for the single definition of facemill.
It represents the following items:

FACEMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class facemill :
  public instance,
  public millingCutter
{
  friend int yyparse();
public:
  facemill(){}
  facemill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      millingCutter(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~facemill();
  int isA(int aType)
    { return ((aType == facemill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* multistepDrilling

This is a class for the single definition of multistepDrilling.
It represents the following items:

MULTISTEPDRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ',' REALSTRING ',' REALSTRING ',' REALSTRING ',' optReal ')'

*/

class multistepDrilling :
  public instance,
  public drillingOperation
{
  friend int yyparse();
public:
  multistepDrilling(){}
  multistepDrilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    double retractDistanceIn,
    double firstDepthIn,
    double depthOfStepIn,
    real * dwellTimeStepIn) :
      drillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {
      retractDistance = retractDistanceIn;
      firstDepth = firstDepthIn;
      depthOfStep = depthOfStepIn;
      dwellTimeStep = dwellTimeStepIn;
    }
  ~multistepDrilling();
  int isA(int aType)
    { return ((aType == multistepDrilling_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
  double get_retractDistance()
    {return retractDistance;}
  void set_retractDistance(double retractDistanceIn)
    {retractDistance = retractDistanceIn;}
  double get_firstDepth()
    {return firstDepth;}
  void set_firstDepth(double firstDepthIn)
    {firstDepth = firstDepthIn;}
  double get_depthOfStep()
    {return depthOfStep;}
  void set_depthOfStep(double depthOfStepIn)
    {depthOfStep = depthOfStepIn;}
  real * get_dwellTimeStep()
    {return dwellTimeStep;}
  void set_dwellTimeStep(real * dwellTimeStepIn)
    {dwellTimeStep = dwellTimeStepIn;}
private:
  double retractDistance;
  double firstDepth;
  double depthOfStep;
  real * dwellTimeStep;
};

/********************************************************************/

/* planeFinishMilling

This is a class for the single definition of planeFinishMilling.
It represents the following items:

PLANEFINISHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ')'

*/

class planeFinishMilling :
  public instance,
  public planeMilling
{
  friend int yyparse();
public:
  planeFinishMilling(){}
  planeFinishMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * allowanceBottomIn) :
      planeMilling(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        approachIn,
        retractIn,
        itsMachiningStrategyIn,
        axialCuttingDepthIn,
        allowanceBottomIn)
    {}
  ~planeFinishMilling();
  int isA(int aType)
    { return ((aType == planeFinishMilling_E) ||
	      (aType == planeMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* reaming

This is a class for the single definition of reaming.
It represents the following items:

REAMING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ',' boolean ',' optReal ',' optCartesianPoint ')'

*/

class reaming :
  public instance,
  public boringOperation
{
  friend int yyparse();
public:
  reaming(){}
  reaming(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * spindleStopAtBottomIn,
    real * depthOfTestcutIn,
    cartesianPoint * waitingPositionIn) :
      boringOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn,
        spindleStopAtBottomIn,
        depthOfTestcutIn,
        waitingPositionIn)
    {}
  ~reaming();
  int isA(int aType)
    { return ((aType == reaming_E) ||
	      (aType == boringOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* taperedEndmill

This is a class for the single definition of taperedEndmill.
It represents the following items:

TAPEREDENDMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class taperedEndmill :
  public instance,
  public endmill
{
  friend int yyparse();
public:
  taperedEndmill(){}
  taperedEndmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * taperAngleIn) :
      endmill(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {
      taperAngle = taperAngleIn;
    }
  ~taperedEndmill();
  int isA(int aType)
    { return ((aType == taperedEndmill_E) ||
	      (aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
  real * get_taperAngle()
    {return taperAngle;}
  void set_taperAngle(real * taperAngleIn)
    {taperAngle = taperAngleIn;}
private:
  real * taperAngle;
};

/********************************************************************/

/* ballEndmill

This is a class for the single definition of ballEndmill.
It represents the following items:

BALLENDMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class ballEndmill :
  public instance,
  public endmill
{
  friend int yyparse();
public:
  ballEndmill(){}
  ballEndmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      endmill(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~ballEndmill();
  int isA(int aType)
    { return ((aType == ballEndmill_E) ||
	      (aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* boring

This is a class for the single definition of boring.
It represents the following items:

BORING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ',' boolean ',' optReal ',' optCartesianPoint ')'

*/

class boring :
  public instance,
  public boringOperation
{
  friend int yyparse();
public:
  boring(){}
  boring(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * spindleStopAtBottomIn,
    real * depthOfTestcutIn,
    cartesianPoint * waitingPositionIn) :
      boringOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn,
        spindleStopAtBottomIn,
        depthOfTestcutIn,
        waitingPositionIn)
    {}
  ~boring();
  int isA(int aType)
    { return ((aType == boring_E) ||
	      (aType == boringOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* bullnoseEndmill

This is a class for the single definition of bullnoseEndmill.
It represents the following items:

BULLNOSEENDMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class bullnoseEndmill :
  public instance,
  public endmill
{
  friend int yyparse();
public:
  bullnoseEndmill(){}
  bullnoseEndmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn) :
      endmill(
        dimensionIn,
        numberOfTeethIn,
        handOfCutIn,
        coolantThroughToolIn,
        pilotLengthIn)
    {}
  ~bullnoseEndmill();
  int isA(int aType)
    { return ((aType == bullnoseEndmill_E) ||
	      (aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }
  void printSelf();
};

/********************************************************************/

/* centerDrilling

This is a class for the single definition of centerDrilling.
It represents the following items:

CENTERDRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class centerDrilling :
  public instance,
  public drillingOperation
{
  friend int yyparse();
public:
  centerDrilling(){}
  centerDrilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn) :
      drillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {}
  ~centerDrilling();
  int isA(int aType)
    { return ((aType == centerDrilling_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* counterSinking

This is a class for the single definition of counterSinking.
It represents the following items:

COUNTERSINKING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class counterSinking :
  public instance,
  public drillingOperation
{
  friend int yyparse();
public:
  counterSinking(){}
  counterSinking(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn) :
      drillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {}
  ~counterSinking();
  int isA(int aType)
    { return ((aType == counterSinking_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

/* drilling

This is a class for the single definition of drilling.
It represents the following items:

DRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class drilling :
  public instance,
  public drillingOperation
{
  friend int yyparse();
public:
  drilling(){}
  drilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn) :
      drillingOperation(
        itsToolpathIn,
        itsToolDirectionIn,
        itsIdIn,
        retractPlaneIn,
        startPointIn,
        itsToolIn,
        itsTechnologyIn,
        itsMachineFunctionsIn,
        overcutLengthIn,
        cuttingDepthIn,
        previousDiameterIn,
        dwellTimeBottomIn,
        feedOnRetractIn,
        itsMachiningStrategyIn)
    {}
  ~drilling();
  int isA(int aType)
    { return ((aType == drilling_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }
  void printSelf();
};

/********************************************************************/

