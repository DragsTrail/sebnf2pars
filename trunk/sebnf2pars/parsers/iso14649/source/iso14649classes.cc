
/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

#include "iso14649classes.hh"
#include <stdio.h>   // for printf, etc.

void printDouble(
 double num)
{
  int n;
  int k;
  char buffer[50];

  k = sprintf(buffer, "%f", num);
  for (n = (k-1); ((buffer[n] == '0') && (buffer[n-1] != '.')); n--)
    buffer[n] = 0;
  printf("%s", buffer);
}

void printString(
 char * aString)
{
  int n;
  putchar('\'');
  for (n=0; aString[n]; n++)
    {
      putchar(aString[n]);
      if (aString[n] == '\'')
	putchar('\''); // if apostrophe, print another apostrophe
    }
  putchar('\'');
}


/********************************************************************/

void inputFile::printSelf()
{
  inputStart->printSelf();
  inputHeader->printSelf();
  inputData->printSelf();
  inputEnd->printSelf();
}

/********************************************************************/

inputFile::~inputFile()
{
  delete inputStart;
  delete inputHeader;
  delete inputData;
  delete inputEnd;
}

/********************************************************************/

void dataSection::printSelf()
{
  dataStart->printSelf();
  if (items->begin() != items->end())
    {
      std::list<instance *>::iterator iter;
      for (iter = items->begin();
           iter != items->end();
           iter++)
        {
          (*iter)->get_id()->printSelf();
          printf("=");
          (*iter)->printSelf();
          printf(";\n");
        }
    }
  sectionEnd->printSelf();
}

/********************************************************************/

dataSection::~dataSection()
{
  delete dataStart;
  {
    std::list<instance *>::iterator iter;
    for (iter = items->begin(); iter != items->end(); ++iter)
      {
        delete *iter;
      }
  }
  delete items;
  delete sectionEnd;
}

/********************************************************************/

void dataStarter::printSelf()
{
  printf("DATA");
  printf(";\n");
}

/********************************************************************/

dataStarter::~dataStarter()
{
}

/********************************************************************/

void endSection::printSelf()
{
  printf("ENDSEC");
  printf(";\n");
}

/********************************************************************/

endSection::~endSection()
{
}

/********************************************************************/

void fileDescription::printSelf()
{
  printf("FILE_DESCRIPTION");
  printf("(");
  description->printSelf();
  printf(",");
  printString(implementationLevel);
  printf(")");
  printf(";\n");
}

/********************************************************************/

fileDescription::~fileDescription()
{
  delete description;
  delete implementationLevel;
}

/********************************************************************/

void fileEnd::printSelf()
{
  printf("END-ISO-10303-21");
  printf(";\n");
}

/********************************************************************/

fileEnd::~fileEnd()
{
}

/********************************************************************/

void fileName::printSelf()
{
  printf("FILE_NAME");
  printf("(");
  printString(name);
  printf(",");
  printString(timeStamp);
  printf(",");
  author->printSelf();
  printf(",");
  organization->printSelf();
  printf(",");
  printString(preprocessorVersion);
  printf(",");
  printString(originatingSystem);
  printf(",");
  printString(authorization);
  printf(")");
  printf(";\n");
}

/********************************************************************/

fileName::~fileName()
{
  delete name;
  delete timeStamp;
  delete author;
  delete organization;
  delete preprocessorVersion;
  delete originatingSystem;
  delete authorization;
}

/********************************************************************/

void fileSchema::printSelf()
{
  printf("FILE_SCHEMA");
  printf("(");
  schemaIdentifiers->printSelf();
  printf(")");
  printf(";\n");
}

/********************************************************************/

fileSchema::~fileSchema()
{
  delete schemaIdentifiers;
}

/********************************************************************/

void fileStart::printSelf()
{
  printf("ISO-10303-21");
  printf(";\n");
}

/********************************************************************/

fileStart::~fileStart()
{
}

/********************************************************************/

void headerSection::printSelf()
{
  headerStart->printSelf();
  headerDescription->printSelf();
  headerName->printSelf();
  headerSchema->printSelf();
  sectionEnd->printSelf();
}

/********************************************************************/

headerSection::~headerSection()
{
  delete headerStart;
  delete headerDescription;
  delete headerName;
  delete headerSchema;
  delete sectionEnd;
}

/********************************************************************/

void headerStarter::printSelf()
{
  printf("HEADER");
  printf(";\n");
}

/********************************************************************/

headerStarter::~headerStarter()
{
}

/********************************************************************/

void instanceId::printSelf()
{
  printf("#");
  printf("%d", val);
}

/********************************************************************/

instanceId::~instanceId()
{
}

/********************************************************************/

void parenRealListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<real *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenRealListFull::~parenRealListFull()
{
  {
    std::list<real *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

/********************************************************************/

void parenStringList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<char *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          printString(*iter);
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenStringList::~parenStringList()
{
  {
    std::list<char *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

/********************************************************************/

void parenStringListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<char *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          printString(*iter);
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenStringListFull::~parenStringListFull()
{
  {
    std::list<char *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

/********************************************************************/

void approval::printSelf()
{
  printf("APPROVAL");
  printf("(");
  status->get_id()->printSelf();
  printf(",");
  printString(level);
  printf(")");
}

/********************************************************************/

approval::~approval()
{
  delete level;
}

/********************************************************************/

void approvalStatus::printSelf()
{
  printf("APPROVAL_STATUS");
  printf("(");
  printString(name);
  printf(")");
}

/********************************************************************/

approvalStatus::~approvalStatus()
{
  delete name;
}

/********************************************************************/

void channel::printSelf()
{
  printf("CHANNEL");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

channel::~channel()
{
  delete itsId;
}

/********************************************************************/

void circularOffset::printSelf()
{
  printf("CIRCULAR_OFFSET");
  printf("(");
  printDouble(angularOffset);
  printf(",");
  printf("%d", index);
  printf(")");
}

/********************************************************************/

circularOffset::~circularOffset()
{
}

/********************************************************************/

void circularOmit::printSelf()
{
  printf("CIRCULAR_OMIT");
  printf("(");
  printf("%d", index);
  printf(")");
}

/********************************************************************/

circularOmit::~circularOmit()
{
}

/********************************************************************/

void compositeCurveSegment::printSelf()
{
  printf("COMPOSITE_CURVE_SEGMENT");
  printf("(");
  transition->printSelf();
  printf(",");
  sameSense->printSelf();
  printf(",");
  (dynamic_cast<instance *>(parentCurve))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

compositeCurveSegment::~compositeCurveSegment()
{
  delete transition;
  delete sameSense;
}

/********************************************************************/

void cutmodeTypeClimb::printSelf()
{
  printf(".CLIMB.");
}

/********************************************************************/

cutmodeTypeClimb::~cutmodeTypeClimb()
{
}

/********************************************************************/

void cutmodeTypeConventional::printSelf()
{
  printf(".CONVENTIONAL.");
}

/********************************************************************/

cutmodeTypeConventional::~cutmodeTypeConventional()
{
}

/********************************************************************/

void cuttingComponent::printSelf()
{
  printf("CUTTING_COMPONENT");
  printf("(");
  printDouble(toolOffsetLength);
  printf(",");
  if (itsMaterial)
    itsMaterial->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (technologicalData)
    technologicalData->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (expectedToolLife)
    expectedToolLife->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    itsTechnology->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

cuttingComponent::~cuttingComponent()
{
  delete expectedToolLife;
}

/********************************************************************/

void cuttingEdgeTechnologicalData::printSelf()
{
  printf("CUTTING_EDGE_TECHNOLOGICAL_DATA");
  printf("(");
  if (cuttingAngle)
    cuttingAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (freeAngle)
    freeAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (auxAngle)
    auxAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

cuttingEdgeTechnologicalData::~cuttingEdgeTechnologicalData()
{
  delete cuttingAngle;
  delete freeAngle;
  delete auxAngle;
}

/********************************************************************/

void dateAndTime::printSelf()
{
  printf("DATE_AND_TIME");
  printf("(");
  (dynamic_cast<instance *>(dateComponent))->get_id()->printSelf();
  printf(",");
  printString(timeComponent);
  printf(")");
}

/********************************************************************/

dateAndTime::~dateAndTime()
{
  delete timeComponent;
}

/********************************************************************/

void drillingTypeStrategy::printSelf()
{
  printf("DRILLING_TYPE_STRATEGY");
  printf("(");
  if (reducedCutAtStart)
    reducedCutAtStart->printSelf();
  else
    printf("$");
  printf(",");
  if (reducedFeedAtStart)
    reducedFeedAtStart->printSelf();
  else
    printf("$");
  printf(",");
  if (depthOfStart)
    depthOfStart->printSelf();
  else
    printf("$");
  printf(",");
  if (reducedCutAtEnd)
    reducedCutAtEnd->printSelf();
  else
    printf("$");
  printf(",");
  if (reducedFeedAtEnd)
    reducedFeedAtEnd->printSelf();
  else
    printf("$");
  printf(",");
  if (depthOfEnd)
    depthOfEnd->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

drillingTypeStrategy::~drillingTypeStrategy()
{
  delete reducedCutAtStart;
  delete reducedFeedAtStart;
  delete depthOfStart;
  delete reducedCutAtEnd;
  delete reducedFeedAtEnd;
  delete depthOfEnd;
}

/********************************************************************/

void fittingTypeHole::printSelf()
{
  printf(".HOLE.");
}

/********************************************************************/

fittingTypeHole::~fittingTypeHole()
{
}

/********************************************************************/

void fittingTypeShaft::printSelf()
{
  printf(".SHAFT.");
}

/********************************************************************/

fittingTypeShaft::~fittingTypeShaft()
{
}

/********************************************************************/

void handRight::printSelf()
{
  printf(".RIGHT.");
}

/********************************************************************/

handRight::~handRight()
{
}

/********************************************************************/

void handLeft::printSelf()
{
  printf(".LEFT.");
}

/********************************************************************/

handLeft::~handLeft()
{
}

/********************************************************************/

void inProcessGeometry::printSelf()
{
  printf("IN_PROCESS_GEOMETRY");
  printf("(");
  if (asIs)
    asIs->printSelf();
  else
    printf("$");
  printf(",");
  if (toBe)
    toBe->printSelf();
  else
    printf("$");
  printf(",");
  if (removal)
    removal->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

inProcessGeometry::~inProcessGeometry()
{
  delete asIs;
  delete toBe;
  delete removal;
}

/********************************************************************/

void integer::printSelf()
{
  printf("%d", val);
}

/********************************************************************/

integer::~integer()
{
}

/********************************************************************/

void leadingLineStrategy::printSelf()
{
  printf("LEADING_LINE_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_id()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsLine))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

leadingLineStrategy::~leadingLineStrategy()
{
  delete get_pathmode();
  delete get_cutmode();
  delete get_stepover();
}

/********************************************************************/

void leftOrRightLeft::printSelf()
{
  printf(".LEFT.");
}

/********************************************************************/

leftOrRightLeft::~leftOrRightLeft()
{
}

/********************************************************************/

void leftOrRightRight::printSelf()
{
  printf(".RIGHT.");
}

/********************************************************************/

leftOrRightRight::~leftOrRightRight()
{
}

/********************************************************************/

void logicalUnknown::printSelf()
{
  printf(".U.");
}

/********************************************************************/

logicalUnknown::~logicalUnknown()
{
}

/********************************************************************/

void material::printSelf()
{
  printf("MATERIAL");
  printf("(");
  printString(standardIdentifier);
  printf(",");
  printString(materialIdentifier);
  printf(",");
  materialProperty->printSelf();
  printf(")");
}

/********************************************************************/

material::~material()
{
  delete standardIdentifier;
  delete materialIdentifier;
  delete materialProperty;
}

/********************************************************************/

void millingMachineFunctions::printSelf()
{
  printf("MILLING_MACHINE_FUNCTIONS");
  printf("(");
  coolant->printSelf();
  printf(",");
  if (coolantPressure)
    coolantPressure->printSelf();
  else
    printf("$");
  printf(",");
  if (mist)
    mist->printSelf();
  else
    printf("$");
  printf(",");
  throughSpindleCoolant->printSelf();
  printf(",");
  if (throughPressure)
    throughPressure->printSelf();
  else
    printf("$");
  printf(",");
  axisClamping->printSelf();
  printf(",");
  chipRemoval->printSelf();
  printf(",");
  if (orientedSpindleStop)
    orientedSpindleStop->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsProcessModel)
    itsProcessModel->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  otherFunctions->printSelf();
  printf(")");
}

/********************************************************************/

millingMachineFunctions::~millingMachineFunctions()
{
  delete coolant;
  delete coolantPressure;
  delete mist;
  delete throughSpindleCoolant;
  delete throughPressure;
  delete axisClamping;
  delete chipRemoval;
  delete otherFunctions;
}

/********************************************************************/

void millingToolDimension::printSelf()
{
  printf("MILLING_TOOL_DIMENSION");
  printf("(");
  printDouble(diameter);
  printf(",");
  if (toolTopAngle)
    toolTopAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (toolCircumferenceAngle)
    toolCircumferenceAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingEdgeLength)
    cuttingEdgeLength->printSelf();
  else
    printf("$");
  printf(",");
  if (edgeRadius)
    edgeRadius->printSelf();
  else
    printf("$");
  printf(",");
  if (edgeCenterVertical)
    edgeCenterVertical->printSelf();
  else
    printf("$");
  printf(",");
  if (edgeCenterHorizontal)
    edgeCenterHorizontal->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

millingToolDimension::~millingToolDimension()
{
  delete toolTopAngle;
  delete toolCircumferenceAngle;
  delete cuttingEdgeLength;
  delete edgeRadius;
  delete edgeCenterVertical;
  delete edgeCenterHorizontal;
}

/********************************************************************/

void ncVariable::printSelf()
{
  printf("NC_VARIABLE");
  printf("(");
  printString(itsName);
  printf(",");
  if (initialValue)
    initialValue->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

ncVariable::~ncVariable()
{
  delete itsName;
  delete initialValue;
}

/********************************************************************/

void offsetVector::printSelf()
{
  printf("OFFSET_VECTOR");
  printf("(");
  translate->printSelf();
  printf(",");
  if (rotate)
    rotate->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

offsetVector::~offsetVector()
{
  delete translate;
  delete rotate;
}

/********************************************************************/

void optionalStop::printSelf()
{
  printf("OPTIONAL_STOP");
  printf("(");
  printString(get_itsId());
  printf(")");
}

/********************************************************************/

optionalStop::~optionalStop()
{
  delete get_itsId();
}

/********************************************************************/

void parenAxis2placement3dListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<axis2placement3d *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenAxis2placement3dListFull::~parenAxis2placement3dListFull()
{
  delete theList;
}

/********************************************************************/

void parenBossList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<boss *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenBossList::~parenBossList()
{
  delete theList;
}

/********************************************************************/

void parenCartesianPointList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<cartesianPoint *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCartesianPointList::~parenCartesianPointList()
{
  delete theList;
}

/********************************************************************/

void parenCartesianPointListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<cartesianPoint *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCartesianPointListFull::~parenCartesianPointListFull()
{
  delete theList;
}

/********************************************************************/

void parenCircularOffsetList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<circularOffset *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCircularOffsetList::~parenCircularOffsetList()
{
  delete theList;
}

/********************************************************************/

void parenCircularOmitList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<circularOmit *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCircularOmitList::~parenCircularOmitList()
{
  delete theList;
}

/********************************************************************/

void parenCompositeCurveSegmentListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<compositeCurveSegment *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCompositeCurveSegmentListFull::~parenCompositeCurveSegmentListFull()
{
  delete theList;
}

/********************************************************************/

void parenCompoundFeatureSelectListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<compoundFeatureSelect *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCompoundFeatureSelectListFull::~parenCompoundFeatureSelectListFull()
{
  delete theList;
}

/********************************************************************/

void parenCuttingComponentListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<cuttingComponent *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenCuttingComponentListFull::~parenCuttingComponentListFull()
{
  delete theList;
}

/********************************************************************/

void parenExecutableList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<executable *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenExecutableList::~parenExecutableList()
{
  delete theList;
}

/********************************************************************/

void parenMachiningOperationList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<machiningOperation *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenMachiningOperationList::~parenMachiningOperationList()
{
  delete theList;
}

/********************************************************************/

void parenNcVariableListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<ncVariable *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenNcVariableListFull::~parenNcVariableListFull()
{
  delete theList;
}

/********************************************************************/

void parenProcessModelLiszt::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<processModel *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenProcessModelLiszt::~parenProcessModelLiszt()
{
  delete theList;
}

/********************************************************************/

void parenPropertyParameterList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<propertyParameter *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenPropertyParameterList::~parenPropertyParameterList()
{
  delete theList;
}

/********************************************************************/

void parenRectangularOffsetList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<rectangularOffset *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenRectangularOffsetList::~parenRectangularOffsetList()
{
  delete theList;
}

/********************************************************************/

void parenRectangularOmitList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<rectangularOmit *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenRectangularOmitList::~parenRectangularOmitList()
{
  delete theList;
}

/********************************************************************/

void parenSetupInstructionList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<setupInstruction *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenSetupInstructionList::~parenSetupInstructionList()
{
  delete theList;
}

/********************************************************************/

void parenSlotEndTypeList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<slotEndType *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenSlotEndTypeList::~parenSlotEndTypeList()
{
  delete theList;
}

/********************************************************************/

void parenToolpathLisztFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<toolpath *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenToolpathLisztFull::~parenToolpathLisztFull()
{
  delete theList;
}

/********************************************************************/

void parenTrimmingSelectListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<trimmingSelect *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenTrimmingSelectListFull::~parenTrimmingSelectListFull()
{
  delete theList;
}

/********************************************************************/

void parenWorkpieceList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<workpiece *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenWorkpieceList::~parenWorkpieceList()
{
  delete theList;
}

/********************************************************************/

void parenWorkpieceSetupList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<workpieceSetup *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->get_id()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

parenWorkpieceSetupList::~parenWorkpieceSetupList()
{
  delete theList;
}

/********************************************************************/

void pathmodeTypeForward::printSelf()
{
  printf(".FORWARD.");
}

/********************************************************************/

pathmodeTypeForward::~pathmodeTypeForward()
{
}

/********************************************************************/

void pathmodeTypeZigzag::printSelf()
{
  printf(".ZIGZAG.");
}

/********************************************************************/

pathmodeTypeZigzag::~pathmodeTypeZigzag()
{
}

/********************************************************************/

void personAndAddress::printSelf()
{
  printf("PERSON_AND_ADDRESS");
  printf("(");
  printString(itsPerson);
  printf(",");
  printString(itsAddress);
  printf(")");
}

/********************************************************************/

personAndAddress::~personAndAddress()
{
  delete itsPerson;
  delete itsAddress;
}

/********************************************************************/

void planeCcStrategy::printSelf()
{
  printf("PLANE_CC_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_id()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  itsPlaneNormal->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

planeCcStrategy::~planeCcStrategy()
{
  delete get_pathmode();
  delete get_cutmode();
  delete get_stepover();
}

/********************************************************************/

void planeClStrategy::printSelf()
{
  printf("PLANE_CL_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_id()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  itsPlaneNormal->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

planeClStrategy::~planeClStrategy()
{
  delete get_pathmode();
  delete get_cutmode();
  delete get_stepover();
}

/********************************************************************/

void plungeHelix::printSelf()
{
  printf("PLUNGE_HELIX");
  printf("(");
  if (get_toolOrientation())
    get_toolOrientation()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(",");
  printDouble(angle);
  printf(")");
}

/********************************************************************/

plungeHelix::~plungeHelix()
{
}

/********************************************************************/

void plungeRamp::printSelf()
{
  printf("PLUNGE_RAMP");
  printf("(");
  if (get_toolOrientation())
    get_toolOrientation()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(")");
}

/********************************************************************/

plungeRamp::~plungeRamp()
{
}

/********************************************************************/

void plungeToolaxis::printSelf()
{
  printf("PLUNGE_TOOLAXIS");
  printf("(");
  if (get_toolOrientation())
    get_toolOrientation()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

plungeToolaxis::~plungeToolaxis()
{
}

/********************************************************************/

void plungeZigzag::printSelf()
{
  printf("PLUNGE_ZIGZAG");
  printf("(");
  if (get_toolOrientation())
    get_toolOrientation()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(width);
  printf(")");
}

/********************************************************************/

plungeZigzag::~plungeZigzag()
{
}

/********************************************************************/

void processModel::printSelf()
{
  printf("PROCESS_MODEL");
  printf("(");
  printString(iniDataFile);
  printf(",");
  printString(itsType);
  printf(")");
}

/********************************************************************/

processModel::~processModel()
{
  delete iniDataFile;
  delete itsType;
}

/********************************************************************/

void processModelList::printSelf()
{
  printf("PROCESS_MODEL_LIST");
  printf("(");
  itsList->printSelf();
  printf(")");
}

/********************************************************************/

processModelList::~processModelList()
{
  delete itsList;
}

/********************************************************************/

void programStop::printSelf()
{
  printf("PROGRAM_STOP");
  printf("(");
  printString(get_itsId());
  printf(")");
}

/********************************************************************/

programStop::~programStop()
{
  delete get_itsId();
}

/********************************************************************/

void project::printSelf()
{
  printf("PROJECT");
  printf("(");
  printString(itsId);
  printf(",");
  mainWorkplan->get_id()->printSelf();
  printf(",");
  itsWorkpieces->printSelf();
  printf(",");
  if (itsOwner)
    itsOwner->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRelease)
    itsRelease->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsStatus)
    itsStatus->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

project::~project()
{
  delete itsId;
  delete itsWorkpieces;
}

/********************************************************************/

void radiusedPocketBottomCondition::printSelf()
{
  printf("RADIUSED_POCKET_BOTTOM_CONDITION");
  printf("(");
  floorRadiusCenter->get_id()->printSelf();
  printf(",");
  floorRadius->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

radiusedPocketBottomCondition::~radiusedPocketBottomCondition()
{
}

/********************************************************************/

void rectangularOffset::printSelf()
{
  printf("RECTANGULAR_OFFSET");
  printf("(");
  offsetDirection->get_id()->printSelf();
  printf(",");
  printDouble(offsetDistance);
  printf(",");
  printf("%d", rowIndex);
  printf(",");
  printf("%d", columnIndex);
  printf(")");
}

/********************************************************************/

rectangularOffset::~rectangularOffset()
{
}

/********************************************************************/

void rectangularOmit::printSelf()
{
  printf("RECTANGULAROMIT");
  printf("(");
  printf("%d", rowIndex);
  printf(",");
  printf("%d", columnIndex);
  printf(")");
}

/********************************************************************/

rectangularOmit::~rectangularOmit()
{
}

/********************************************************************/

void regionProjection::printSelf()
{
  printf("REGION_PROJECTION");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  if (get_featurePlacement())
    get_featurePlacement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(projCurve))->get_id()->printSelf();
  printf(",");
  projDir->get_id()->printSelf();
  printf(",");
  depth->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

regionProjection::~regionProjection()
{
  delete get_itsId();
  delete get_itsOperations();
}

/********************************************************************/

void rotDirectionCw::printSelf()
{
  printf(".CW.");
}

/********************************************************************/

rotDirectionCw::~rotDirectionCw()
{
}

/********************************************************************/

void rotDirectionCcw::printSelf()
{
  printf(".CCW.");
}

/********************************************************************/

rotDirectionCcw::~rotDirectionCcw()
{
}

/********************************************************************/

void setMark::printSelf()
{
  printf("SET_MARK");
  printf("(");
  printString(get_itsId());
  printf(")");
}

/********************************************************************/

setMark::~setMark()
{
  delete get_itsId();
}

/********************************************************************/

void setup::printSelf()
{
  printf("SETUP");
  printf("(");
  printString(itsId);
  printf(",");
  if (itsOrigin)
    itsOrigin->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->get_id()->printSelf();
  printf(",");
  itsWorkpieceSetup->printSelf();
  printf(")");
}

/********************************************************************/

setup::~setup()
{
  delete itsId;
  delete itsWorkpieceSetup;
}

/********************************************************************/

void setupInstruction::printSelf()
{
  printf("SETUP_INSTRUCTION");
  printf("(");
  printString(description);
  printf(",");
  printString(externalDocument);
  printf(")");
}

/********************************************************************/

setupInstruction::~setupInstruction()
{
  delete description;
  delete externalDocument;
}

/********************************************************************/

void throughBottomCondition::printSelf()
{
  printf("THROUGH_BOTTOM_CONDITION");
  printf("(");
  printf(")");
}

/********************************************************************/

throughBottomCondition::~throughBottomCondition()
{
}

/********************************************************************/

void throughPocketBottomCondition::printSelf()
{
  printf("THROUGH_POCKET_BOTTOM_CONDITION");
  printf("(");
  printf(")");
}

/********************************************************************/

throughPocketBottomCondition::~throughPocketBottomCondition()
{
}

/********************************************************************/

void tolerancedLengthMeasure::printSelf()
{
  printf("TOLERANCED_LENGTH_MEASURE");
  printf("(");
  printDouble(theoreticalSize);
  printf(",");
  implicitTolerance->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

tolerancedLengthMeasure::~tolerancedLengthMeasure()
{
}

/********************************************************************/

void tolerances::printSelf()
{
  printf("TOLERANCES");
  printf("(");
  printDouble(chordalTolerance);
  printf(",");
  printDouble(scallopHeight);
  printf(")");
}

/********************************************************************/

tolerances::~tolerances()
{
}

/********************************************************************/

void toolpathList::printSelf()
{
  printf("TOOLPATH_LIST");
  printf("(");
  itsList->printSelf();
  printf(")");
}

/********************************************************************/

toolpathList::~toolpathList()
{
  delete itsList;
}

/********************************************************************/

void toolReferencePointCcp::printSelf()
{
  printf(".CCP.");
}

/********************************************************************/

toolReferencePointCcp::~toolReferencePointCcp()
{
}

/********************************************************************/

void toolReferencePointTcp::printSelf()
{
  printf(".TCP.");
}

/********************************************************************/

toolReferencePointTcp::~toolReferencePointTcp()
{
}

/********************************************************************/

void touchProbe::printSelf()
{
  printf("TOUCH_PROBE");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

touchProbe::~touchProbe()
{
  delete itsId;
}

/********************************************************************/

void trajectoryPath::printSelf()
{
  printf(".TRAJECTORY_PATH.");
}

/********************************************************************/

trajectoryPath::~trajectoryPath()
{
}

/********************************************************************/

void twoAxes::printSelf()
{
  printf("TWO_AXES");
  printf("(");
  printf(")");
}

/********************************************************************/

twoAxes::~twoAxes()
{
}

/********************************************************************/

void unidirectionalMilling::printSelf()
{
  printf("UNIDIRECTIONAL_MILLING");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (cutmode)
    cutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

unidirectionalMilling::~unidirectionalMilling()
{
  delete get_overlap();
  delete get_allowMultiplePasses();
  delete cutmode;
}

/********************************************************************/

void unloadTool::printSelf()
{
  printf("UNLOAD_TOOL");
  printf("(");
  printString(get_itsId());
  printf(",");
  if (itsTool)
    (dynamic_cast<instance *>(itsTool))->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

unloadTool::~unloadTool()
{
  delete get_itsId();
}

/********************************************************************/

void unspecified::printSelf()
{
  printf(".UNSPECIFIED.");
}

/********************************************************************/

unspecified::~unspecified()
{
}

/********************************************************************/

void uvStrategy::printSelf()
{
  printf("UV_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_id()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  forwardDirection->get_id()->printSelf();
  printf(",");
  sidewardDirection->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

uvStrategy::~uvStrategy()
{
  delete get_pathmode();
  delete get_cutmode();
  delete get_stepover();
}

/********************************************************************/

void vector::printSelf()
{
  printf("VECTOR");
  printf("(");
  printString(get_name());
  printf(",");
  orientation->get_id()->printSelf();
  printf(",");
  printDouble(magnitude);
  printf(")");
}

/********************************************************************/

vector::~vector()
{
  delete get_name();
}

/********************************************************************/

void waitForMark::printSelf()
{
  printf("WAIT_FOR_MARK");
  printf("(");
  printString(get_itsId());
  printf(",");
  itsChannel->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

waitForMark::~waitForMark()
{
  delete get_itsId();
}

/********************************************************************/

void woodruffSlotEndType::printSelf()
{
  printf("WOODRUFF_SLOT_END_TYPE");
  printf("(");
  radius->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

woodruffSlotEndType::~woodruffSlotEndType()
{
}

/********************************************************************/

void workpiece::printSelf()
{
  printf("WORKPIECE");
  printf("(");
  printString(itsId);
  printf(",");
  if (itsMaterial)
    itsMaterial->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (globalTolerance)
    globalTolerance->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRawpiece)
    itsRawpiece->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsGeometry)
    itsGeometry->printSelf();
  else
    printf("$");
  printf(",");
  if (itsBoundingGeometry)
    (dynamic_cast<instance *>(itsBoundingGeometry))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  clampingPositions->printSelf();
  printf(")");
}

/********************************************************************/

workpiece::~workpiece()
{
  delete itsId;
  delete globalTolerance;
  delete itsGeometry;
  delete clampingPositions;
}

/********************************************************************/

void workpieceSetup::printSelf()
{
  printf("WORKPIECE_SETUP");
  printf("(");
  itsWorkpiece->get_id()->printSelf();
  printf(",");
  itsOrigin->get_id()->printSelf();
  printf(",");
  if (itsOffset)
    itsOffset->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRestrictedArea)
    (dynamic_cast<instance *>(itsRestrictedArea))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  itsInstructions->printSelf();
  printf(")");
}

/********************************************************************/

workpieceSetup::~workpieceSetup()
{
  delete itsOffset;
  delete itsInstructions;
}

/********************************************************************/

void workplan::printSelf()
{
  printf("WORKPLAN");
  printf("(");
  printString(get_itsId());
  printf(",");
  itsElements->printSelf();
  printf(",");
  if (itsChannel)
    itsChannel->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsSetup)
    itsSetup->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsEffect)
    itsEffect->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

workplan::~workplan()
{
  delete get_itsId();
  delete itsElements;
  delete itsEffect;
}

/********************************************************************/

void real::printSelf()
{
  printDouble(val);
}

/********************************************************************/

real::~real()
{
}

/********************************************************************/

void angleTaper::printSelf()
{
  printf("ANGLE_TAPER");
  printf("(");
  angle->printSelf();
  printf(")");
}

/********************************************************************/

angleTaper::~angleTaper()
{
  delete angle;
}

/********************************************************************/

void approach::printSelf()
{
  printf(".APPROACH.");
}

/********************************************************************/

approach::~approach()
{
}

/********************************************************************/

void bidirectionalMilling::printSelf()
{
  printf("BIDIRECTIONAL_MILLING");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (stepoverDirection)
    stepoverDirection->printSelf();
  else
    printf("$");
  printf(",");
  if (itsStrokeConnectionStrategy)
    itsStrokeConnectionStrategy->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

bidirectionalMilling::~bidirectionalMilling()
{
  delete get_overlap();
  delete get_allowMultiplePasses();
  delete stepoverDirection;
  delete itsStrokeConnectionStrategy;
}

/********************************************************************/

void booleanTrue::printSelf()
{
  printf(".T.");
}

/********************************************************************/

booleanTrue::~booleanTrue()
{
}

/********************************************************************/

void booleanFalse::printSelf()
{
  printf(".F.");
}

/********************************************************************/

booleanFalse::~booleanFalse()
{
}

/********************************************************************/

void calendarDate::printSelf()
{
  printf("CALENDAR_DATE");
  printf("(");
  printf("%d", yearComponent);
  printf(",");
  printf("%d", dayComponent);
  printf(",");
  printf("%d", monthComponent);
  printf(")");
}

/********************************************************************/

calendarDate::~calendarDate()
{
}

/********************************************************************/

void cartesian::printSelf()
{
  printf(".CARTESIAN.");
}

/********************************************************************/

cartesian::~cartesian()
{
}

/********************************************************************/

void cartesianPoint::printSelf()
{
  printf("CARTESIAN_POINT");
  printf("(");
  printString(get_name());
  printf(",");
  coordinates->printSelf();
  printf(")");
}

/********************************************************************/

cartesianPoint::~cartesianPoint()
{
  delete get_name();
  delete coordinates;
}

/********************************************************************/

void chamfer::printSelf()
{
  printf("CHAMFER");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_firstFeature()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_secondFeature()))->get_id()->printSelf();
  printf(",");
  printDouble(angleToPlane);
  printf(",");
  firstOffsetAmount->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

chamfer::~chamfer()
{
  delete get_itsId();
  delete get_itsOperations();
}

/********************************************************************/

void completeCircularPath::printSelf()
{
  printf("COMPLETE_CIRCULAR_PATH");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_radius()->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

completeCircularPath::~completeCircularPath()
{
}

/********************************************************************/

void conicalHoleBottom::printSelf()
{
  printf("CONICAL_HOLE_BOTTOM");
  printf("(");
  tipAngle->printSelf();
  printf(",");
  if (tipRadius)
    tipRadius->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

conicalHoleBottom::~conicalHoleBottom()
{
  delete tipAngle;
}

/********************************************************************/

void connect::printSelf()
{
  printf(".CONNECT.");
}

/********************************************************************/

connect::~connect()
{
}

/********************************************************************/

void contact::printSelf()
{
  printf(".CONTACT.");
}

/********************************************************************/

contact::~contact()
{
}

/********************************************************************/

void continuous::printSelf()
{
  printf(".CONTINUOUS.");
}

/********************************************************************/

continuous::~continuous()
{
}

/********************************************************************/

void contSameGradient::printSelf()
{
  printf(".CONT_SAME_GRADIENT.");
}

/********************************************************************/

contSameGradient::~contSameGradient()
{
}

/********************************************************************/

void contSameGradientSameCurvature::printSelf()
{
  printf(".CONT_SAME_GRADIENT_SAME_CURVATURE.");
}

/********************************************************************/

contSameGradientSameCurvature::~contSameGradientSameCurvature()
{
}

/********************************************************************/

void contourParallel::printSelf()
{
  printf("CONTOUR_PARALLEL");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  rotationDirection->printSelf();
  printf(",");
  if (cutmode)
    cutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

contourParallel::~contourParallel()
{
  delete get_overlap();
  delete get_allowMultiplePasses();
  delete rotationDirection;
  delete cutmode;
}

/********************************************************************/

void counterboreHole::printSelf()
{
  printf("COUNTERBORE_HOLE");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  get_elements()->printSelf();
  printf(")");
}

/********************************************************************/

counterboreHole::~counterboreHole()
{
  delete get_itsId();
  delete get_itsOperations();
  delete get_elements();
}

/********************************************************************/

void countersunkHole::printSelf()
{
  printf("COUNTERSUNK_HOLE");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  get_elements()->printSelf();
  printf(")");
}

/********************************************************************/

countersunkHole::~countersunkHole()
{
  delete get_itsId();
  delete get_itsOperations();
  delete get_elements();
}

/********************************************************************/

void cutterLocationTrajectory::printSelf()
{
  printf("CUTTER_LOCATION_TRAJECTORY");
  printf("(");
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsDirection())
    get_itsDirection()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(basiccurve))->get_id()->printSelf();
  printf(",");
  if (itsToolaxis)
    (dynamic_cast<instance *>(itsToolaxis))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (surfaceNormal)
    (dynamic_cast<instance *>(surfaceNormal))->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

cutterLocationTrajectory::~cutterLocationTrajectory()
{
  delete get_itsPriority();
  delete get_itsType();
  delete get_itsSpeed();
  delete get_itsDirection();
}

/********************************************************************/

void degouge::printSelf()
{
  printf("DEGOUGE");
}

/********************************************************************/

degouge::~degouge()
{
}

/********************************************************************/

void descriptiveParameter::printSelf()
{
  printf("DESCRIPTIVE_PARAMETER");
  printf("(");
  printString(get_parameterName());
  printf(",");
  printString(descriptiveString);
  printf(")");
}

/********************************************************************/

descriptiveParameter::~descriptiveParameter()
{
  delete get_parameterName();
  delete descriptiveString;
}

/********************************************************************/

void diameterTaper::printSelf()
{
  printf("DIAMETER_TAPER");
  printf("(");
  finalDiameter->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

diameterTaper::~diameterTaper()
{
}

/********************************************************************/

void direction::printSelf()
{
  printf("DIRECTION");
  printf("(");
  printString(get_name());
  printf(",");
  directionRatios->printSelf();
  printf(")");
}

/********************************************************************/

direction::~direction()
{
  delete get_name();
  delete directionRatios;
}

/********************************************************************/

void discontinuous::printSelf()
{
  printf(".DISCONTINUOUS.");
}

/********************************************************************/

discontinuous::~discontinuous()
{
}

/********************************************************************/

void displayMessage::printSelf()
{
  printf("DISPLAY_MESSAGE");
  printf("(");
  printString(get_itsId());
  printf(",");
  printString(itsText);
  printf(")");
}

/********************************************************************/

displayMessage::~displayMessage()
{
  delete get_itsId();
  delete itsText;
}

/********************************************************************/

void edgeRound::printSelf()
{
  printf("EDGE_ROUND");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_firstFeature()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_secondFeature()))->get_id()->printSelf();
  printf(",");
  radius->get_id()->printSelf();
  printf(",");
  if (firstOffsetAmount)
    firstOffsetAmount->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (secondOffsetAmount)
    secondOffsetAmount->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

edgeRound::~edgeRound()
{
  delete get_itsId();
  delete get_itsOperations();
}

/********************************************************************/

void exchangePallet::printSelf()
{
  printf("EXCHANGE_PALLET");
  printf("(");
  printString(get_itsId());
  printf(")");
}

/********************************************************************/

exchangePallet::~exchangePallet()
{
  delete get_itsId();
}

/********************************************************************/

void feedstop::printSelf()
{
  printf("FEEDSTOP");
  printf("(");
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(dwell);
  printf(")");
}

/********************************************************************/

feedstop::~feedstop()
{
  delete get_itsPriority();
  delete get_itsType();
  delete get_itsSpeed();
}

/********************************************************************/

void flatHoleBottom::printSelf()
{
  printf("FLAT_HOLE_BOTTOM");
  printf("(");
  printf(")");
}

/********************************************************************/

flatHoleBottom::~flatHoleBottom()
{
}

/********************************************************************/

void flatSlotEndType::printSelf()
{
  printf("FLAT_SLOT_END_TYPE");
  printf("(");
  cornerRadius1->get_id()->printSelf();
  printf(",");
  cornerRadius2->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

flatSlotEndType::~flatSlotEndType()
{
}

/********************************************************************/

void flatWithRadiusHoleBottom::printSelf()
{
  printf("FLAT_WITH_RADIUS_HOLE_BOTTOM");
  printf("(");
  cornerRadius->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

flatWithRadiusHoleBottom::~flatWithRadiusHoleBottom()
{
}

/********************************************************************/

void generalPath::printSelf()
{
  printf("GENERAL_PATH");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(sweptPath))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

generalPath::~generalPath()
{
}

/********************************************************************/

void generalPocketBottomCondition::printSelf()
{
  printf("GENERAL_POCKET_BOTTOM_CONDITION");
  printf("(");
  (dynamic_cast<instance *>(shape))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

generalPocketBottomCondition::~generalPocketBottomCondition()
{
}

/********************************************************************/

void helix::printSelf()
{
  printf("HELIX");
  printf("(");
  printString(get_name());
  printf(",");
  position->get_id()->printSelf();
  printf(",");
  printDouble(radius);
  printf(",");
  printDouble(pitch);
  printf(")");
}

/********************************************************************/

helix::~helix()
{
  delete get_name();
}

/********************************************************************/

void indexPallet::printSelf()
{
  printf("INDEX_PALLET");
  printf("(");
  printString(get_itsId());
  printf(",");
  printf("%d", its_index);
  printf(")");
}

/********************************************************************/

indexPallet::~indexPallet()
{
  delete get_itsId();
}

/********************************************************************/

void indexTable::printSelf()
{
  printf("INDEX_TABLE");
  printf("(");
  printString(get_itsId());
  printf(",");
  printf("%d", its_index);
  printf(")");
}

/********************************************************************/

indexTable::~indexTable()
{
  delete get_itsId();
}

/********************************************************************/

void lift::printSelf()
{
  printf(".LIFT.");
}

/********************************************************************/

lift::~lift()
{
}

/********************************************************************/

void liftShiftPlunge::printSelf()
{
  printf("LIFT_SHIFT_PLUNGE");
}

/********************************************************************/

liftShiftPlunge::~liftShiftPlunge()
{
}

/********************************************************************/

void limitsAndFits::printSelf()
{
  printf("LIMITSANDFITS");
  printf("(");
  printDouble(deviation);
  printf(",");
  printDouble(grade);
  printf(",");
  if (itsFittingType)
    itsFittingType->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

limitsAndFits::~limitsAndFits()
{
  delete itsFittingType;
}

/********************************************************************/

void line::printSelf()
{
  printf("LINE");
  printf("(");
  printString(get_name());
  printf(",");
  pnt->get_id()->printSelf();
  printf(",");
  dir->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

line::~line()
{
  delete get_name();
}

/********************************************************************/

void linearPath::printSelf()
{
  printf("LINEAR_PATH");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  distance->get_id()->printSelf();
  printf(",");
  itsDirection->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

linearPath::~linearPath()
{
}

/********************************************************************/

void loadTool::printSelf()
{
  printf("LOAD_TOOL");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(itsTool))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

loadTool::~loadTool()
{
  delete get_itsId();
}

/********************************************************************/

void loopBack::printSelf()
{
  printf("LOOP_BACK");
}

/********************************************************************/

loopBack::~loopBack()
{
}

/********************************************************************/

void loopSlotEndType::printSelf()
{
  printf("LOOP_SLOT_END_TYPE");
  printf("(");
  printf(")");
}

/********************************************************************/

loopSlotEndType::~loopSlotEndType()
{
}

/********************************************************************/

void machiningWorkingstep::printSelf()
{
  printf("MACHINING_WORKINGSTEP");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsFeature))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsOperation))->get_id()->printSelf();
  printf(",");
  if (itsEffect)
    itsEffect->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

machiningWorkingstep::~machiningWorkingstep()
{
  delete get_itsId();
  delete itsEffect;
}

/********************************************************************/

void millingCuttingTool::printSelf()
{
  printf("MILLING_CUTTING_TOOL");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsToolBody()))->get_id()->printSelf();
  printf(",");
  get_itsCuttingEdge()->printSelf();
  printf(",");
  if (get_overallAssemblyLength())
    get_overallAssemblyLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (directionForSpindleOrientation)
    directionForSpindleOrientation->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (toolHolderDiameterForSpindleOrientation)
    toolHolderDiameterForSpindleOrientation->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

millingCuttingTool::~millingCuttingTool()
{
  delete get_itsId();
  delete get_itsCuttingEdge();
  delete get_overallAssemblyLength();
  delete toolHolderDiameterForSpindleOrientation;
}

/********************************************************************/

void millingTechnology::printSelf()
{
  printf("MILLING_TECHNOLOGY");
  printf("(");
  if (get_feedrate())
    get_feedrate()->printSelf();
  else
    printf("$");
  printf(",");
  get_feedrateReference()->printSelf();
  printf(",");
  if (cutspeed)
    cutspeed->printSelf();
  else
    printf("$");
  printf(",");
  if (spindle)
    spindle->printSelf();
  else
    printf("$");
  printf(",");
  if (feedratePerTooth)
    feedratePerTooth->printSelf();
  else
    printf("$");
  printf(",");
  synchronizeSpindleWithFeed->printSelf();
  printf(",");
  inhibitFeedrateOverride->printSelf();
  printf(",");
  inhibitSpindleOverride->printSelf();
  printf(",");
  if (itsAdaptiveControl)
    itsAdaptiveControl->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

millingTechnology::~millingTechnology()
{
  delete get_feedrate();
  delete get_feedrateReference();
  delete cutspeed;
  delete spindle;
  delete feedratePerTooth;
  delete synchronizeSpindleWithFeed;
  delete inhibitFeedrateOverride;
  delete inhibitSpindleOverride;
  delete itsAdaptiveControl;
}

/********************************************************************/

void nonContact::printSelf()
{
  printf(".NONCONTACT.");
}

/********************************************************************/

nonContact::~nonContact()
{
}

/********************************************************************/

void numericParameter::printSelf()
{
  printf("NUMERIC_PARAMETER");
  printf("(");
  printString(get_parameterName());
  printf(",");
  printDouble(itsParameterValue);
  printf(",");
  printString(itsParameterUnit);
  printf(")");
}

/********************************************************************/

numericParameter::~numericParameter()
{
  delete get_parameterName();
  delete itsParameterUnit;
}

/********************************************************************/

void openSlotEndType::printSelf()
{
  printf("OPEN_SLOT_END_TYPE");
  printf("(");
  printf(")");
}

/********************************************************************/

openSlotEndType::~openSlotEndType()
{
}

/********************************************************************/

void parameter::printSelf()
{
  printf(".PARAMETER.");
}

/********************************************************************/

parameter::~parameter()
{
}

/********************************************************************/

void partialCircularPath::printSelf()
{
  printf("PARTIAL_CIRCULAR_PATH");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_radius()->get_id()->printSelf();
  printf(",");
  printDouble(sweepAngle);
  printf(")");
}

/********************************************************************/

partialCircularPath::~partialCircularPath()
{
}

/********************************************************************/

void planarFace::printSelf()
{
  printf("PLANAR_FACE");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  courseOfTravel->get_id()->printSelf();
  printf(",");
  removalBoundary->get_id()->printSelf();
  printf(",");
  if (faceBoundary)
    (dynamic_cast<instance *>(faceBoundary))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  itsBoss->printSelf();
  printf(")");
}

/********************************************************************/

planarFace::~planarFace()
{
  delete get_itsId();
  delete get_itsOperations();
  delete itsBoss;
}

/********************************************************************/

void planarPocketBottomCondition::printSelf()
{
  printf("PLANAR_POCKET_BOTTOM_CONDITION");
  printf("(");
  printf(")");
}

/********************************************************************/

planarPocketBottomCondition::~planarPocketBottomCondition()
{
}

/********************************************************************/

void plane::printSelf()
{
  printf("PLANE");
  printf("(");
  printString(get_name());
  printf(",");
  get_position()->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

plane::~plane()
{
  delete get_name();
}

/********************************************************************/

void plusMinusValue::printSelf()
{
  printf("PLUS_MINUS_VALUE");
  printf("(");
  printDouble(upperLimit);
  printf(",");
  printDouble(lowerLimit);
  printf(",");
  printf("%d", significantDigits);
  printf(")");
}

/********************************************************************/

plusMinusValue::~plusMinusValue()
{
}

/********************************************************************/

void radiusedSlotEndType::printSelf()
{
  printf("RADIUSED_SLOT_END_TYPE");
  printf("(");
  printf(")");
}

/********************************************************************/

radiusedSlotEndType::~radiusedSlotEndType()
{
}

/********************************************************************/

void rapidMovement::printSelf()
{
  printf("RAPID_MOVEMENT");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_id()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

rapidMovement::~rapidMovement()
{
  delete get_itsId();
}

/********************************************************************/

void rectangularClosedProfile::printSelf()
{
  printf("RECTANGULAR_CLOSED_PROFILE");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  profileWidth->get_id()->printSelf();
  printf(",");
  profileLength->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

rectangularClosedProfile::~rectangularClosedProfile()
{
}

/********************************************************************/

void rightCircularCylinder::printSelf()
{
  printf("RIGHT_CIRCULAR_CYLINDER");
  printf("(");
  printString(get_name());
  printf(",");
  position->get_id()->printSelf();
  printf(",");
  printDouble(height);
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

rightCircularCylinder::~rightCircularCylinder()
{
  delete get_name();
}

/********************************************************************/

void roundedUProfile::printSelf()
{
  printf("ROUNDED_U_PROFILE");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  width->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

roundedUProfile::~roundedUProfile()
{
}

/********************************************************************/

void roundHole::printSelf()
{
  printf("ROUND_HOLE");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  diameter->get_id()->printSelf();
  printf(",");
  if (changeInDiameter)
    (dynamic_cast<instance *>(changeInDiameter))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(bottomCondition))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

roundHole::~roundHole()
{
  delete get_itsId();
  delete get_itsOperations();
}

/********************************************************************/

void slot::printSelf()
{
  printf("SLOT");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(courseOfTravel))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(sweptShape))->get_id()->printSelf();
  printf(",");
  endConditions->printSelf();
  printf(")");
}

/********************************************************************/

slot::~slot()
{
  delete get_itsId();
  delete get_itsOperations();
  delete endConditions;
}

/********************************************************************/

void speedName::printSelf()
{
  printf(".RAPID.");
}

/********************************************************************/

speedName::~speedName()
{
}

/********************************************************************/

void sphericalCap::printSelf()
{
  printf("SPHERICAL_CAP");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  internalAngle->get_id()->printSelf();
  printf(",");
  radius->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

sphericalCap::~sphericalCap()
{
  delete get_itsId();
  delete get_itsOperations();
}

/********************************************************************/

void sphericalHoleBottom::printSelf()
{
  printf("SPHERICAL_HOLE_BOTTOM");
  printf("(");
  radius->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

sphericalHoleBottom::~sphericalHoleBottom()
{
}

/********************************************************************/

void sphericalSurface::printSelf()
{
  printf("SPHERICAL_SURFACE");
  printf("(");
  printString(get_name());
  printf(",");
  get_position()->get_id()->printSelf();
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

sphericalSurface::~sphericalSurface()
{
  delete get_name();
}

/********************************************************************/

void squareUProfile::printSelf()
{
  printf("SQUARE_U_PROFILE");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  width->get_id()->printSelf();
  printf(",");
  firstRadius->get_id()->printSelf();
  printf(",");
  printDouble(firstAngle);
  printf(",");
  secondRadius->get_id()->printSelf();
  printf(",");
  printDouble(secondAngle);
  printf(")");
}

/********************************************************************/

squareUProfile::~squareUProfile()
{
}

/********************************************************************/

void step::printSelf()
{
  printf("STEP");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  openBoundary->get_id()->printSelf();
  printf(",");
  if (wallBoundary)
    wallBoundary->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  itsBoss->printSelf();
  printf(")");
}

/********************************************************************/

step::~step()
{
  delete get_itsId();
  delete get_itsOperations();
  delete itsBoss;
}

/********************************************************************/

void straightline::printSelf()
{
  printf("STRAIGHTLINE");
}

/********************************************************************/

straightline::~straightline()
{
}

/********************************************************************/

void taperedReamer::printSelf()
{
  printf("TAPERED_REAMER");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

taperedReamer::~taperedReamer()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
  delete taperAngle;
}

/********************************************************************/

void threeAxes::printSelf()
{
  printf("THREE_AXES");
  printf("(");
  printf(")");
}

/********************************************************************/

threeAxes::~threeAxes()
{
}

/********************************************************************/

void toolpathFeature::printSelf()
{
  printf("TOOLPATH_FEATURE");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

toolpathFeature::~toolpathFeature()
{
  delete get_itsId();
  delete get_itsOperations();
}

/********************************************************************/

void veeProfile::printSelf()
{
  printf("VEE_PROFILE");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  profileRadius->get_id()->printSelf();
  printf(",");
  printDouble(profileAngle);
  printf(",");
  printDouble(tiltAngle);
  printf(")");
}

/********************************************************************/

veeProfile::~veeProfile()
{
}

/********************************************************************/

void workpieceCompleteProbing::printSelf()
{
  printf("WORKPIECE_COMPLETE_PROBING");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_id()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_id()->printSelf();
  printf(",");
  itsWorkpiece->get_id()->printSelf();
  printf(",");
  probingDistance->get_id()->printSelf();
  printf(",");
  itsProbe->get_id()->printSelf();
  printf(",");
  computedOffset->printSelf();
  printf(")");
}

/********************************************************************/

workpieceCompleteProbing::~workpieceCompleteProbing()
{
  delete get_itsId();
  delete computedOffset;
}

/********************************************************************/

void workpieceProbing::printSelf()
{
  printf("WORKPIECE_PROBING");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_id()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_id()->printSelf();
  printf(",");
  startPosition->get_id()->printSelf();
  printf(",");
  itsWorkpiece->get_id()->printSelf();
  printf(",");
  itsDirection->get_id()->printSelf();
  printf(",");
  expectedValue->get_id()->printSelf();
  printf(",");
  itsProbe->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

workpieceProbing::~workpieceProbing()
{
  delete get_itsId();
}

/********************************************************************/

void advancedBrepShapeRepresentation::printSelf()
{
  printf("ADVANCED_BREP_SHAPE_REPRESENTATION");
  printf("(");
  printf(")");
}

/********************************************************************/

advancedBrepShapeRepresentation::~advancedBrepShapeRepresentation()
{
}

/********************************************************************/

void axis1placement::printSelf()
{
  printf("AXIS1_PLACEMENT");
  printf("(");
  printString(get_name());
  printf(",");
  get_location()->get_id()->printSelf();
  printf(",");
  axis->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

axis1placement::~axis1placement()
{
  delete get_name();
}

/********************************************************************/

void axis2placement3d::printSelf()
{
  printf("AXIS2_PLACEMENT_3D");
  printf("(");
  printString(get_name());
  printf(",");
  get_location()->get_id()->printSelf();
  printf(",");
  axis->get_id()->printSelf();
  printf(",");
  if (refDirection)
    refDirection->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

axis2placement3d::~axis2placement3d()
{
  delete get_name();
}

/********************************************************************/

void block::printSelf()
{
  printf("BLOCK");
  printf("(");
  printString(get_name());
  printf(",");
  position->get_id()->printSelf();
  printf(",");
  printDouble(x);
  printf(",");
  printDouble(y);
  printf(",");
  printDouble(z);
  printf(")");
}

/********************************************************************/

block::~block()
{
  delete get_name();
}

/********************************************************************/

void boss::printSelf()
{
  printf("BOSS");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsBoundary))->get_id()->printSelf();
  printf(",");
  if (slope)
    slope->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

boss::~boss()
{
  delete get_itsId();
  delete get_itsOperations();
  delete slope;
}

/********************************************************************/

void bottomAndSideRoughMilling::printSelf()
{
  printf("BOTTOM_AND_SIDE_ROUGH_MILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

bottomAndSideRoughMilling::~bottomAndSideRoughMilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_axialCuttingDepth();
  delete get_radialCuttingDepth();
  delete get_allowanceSide();
  delete get_allowanceBottom();
}

/********************************************************************/

void centerDrill::printSelf()
{
  printf("CENTER_DRILL");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

centerDrill::~centerDrill()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void circularPattern::printSelf()
{
  printf("CIRCULAR_PATTERN");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_replicateBaseFeature()))->get_id()->printSelf();
  printf(",");
  printDouble(angleIncrement);
  printf(",");
  printf("%d", numberOfFeature);
  printf(",");
  relocatedBaseFeature->printSelf();
  printf(",");
  missingBaseFeature->printSelf();
  printf(",");
  if (baseFeatureDiameter)
    baseFeatureDiameter->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(baseFeatureRotation);
  printf(")");
}

/********************************************************************/

circularPattern::~circularPattern()
{
  delete get_itsId();
  delete get_itsOperations();
  delete relocatedBaseFeature;
  delete missingBaseFeature;
}

/********************************************************************/

void closedPocket::printSelf()
{
  printf("CLOSED_POCKET");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_id()->printSelf();
  printf(",");
  get_itsBoss()->printSelf();
  printf(",");
  if (get_slope())
    get_slope()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_bottomCondition()))->get_id()->printSelf();
  printf(",");
  if (get_planarRadius())
    get_planarRadius()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_orthogonalRadius())
    get_orthogonalRadius()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(featureBoundary))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

closedPocket::~closedPocket()
{
  delete get_itsId();
  delete get_itsOperations();
  delete get_itsBoss();
  delete get_slope();
}

/********************************************************************/

void combinedDrillAndReamer::printSelf()
{
  printf("COMBINED_DRILL_AND_REAMER");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (drillLength)
    drillLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

combinedDrillAndReamer::~combinedDrillAndReamer()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
  delete drillLength;
}

/********************************************************************/

void compositeCurve::printSelf()
{
  printf("COMPOSITE_CURVE");
  printf("(");
  printString(get_name());
  printf(",");
  segments->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

compositeCurve::~compositeCurve()
{
  delete get_name();
  delete segments;
  delete selfIntersect;
}

/********************************************************************/

void ellipse::printSelf()
{
  printf("ELLIPSE");
  printf("(");
  printString(get_name());
  printf(",");
  get_position()->get_id()->printSelf();
  printf(",");
  printDouble(semiAxis1);
  printf(",");
  printDouble(semiAxis2);
  printf(")");
}

/********************************************************************/

ellipse::~ellipse()
{
  delete get_name();
}

/********************************************************************/

void freeformOperation::printSelf()
{
  printf("FREEFORM_OPERATION");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

freeformOperation::~freeformOperation()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
}

/********************************************************************/

void generalPattern::printSelf()
{
  printf("GENERAL_PATTERN");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_replicateBaseFeature()))->get_id()->printSelf();
  printf(",");
  replicateLocations->printSelf();
  printf(")");
}

/********************************************************************/

generalPattern::~generalPattern()
{
  delete get_itsId();
  delete get_itsOperations();
  delete replicateLocations;
}

/********************************************************************/

void hyperbola::printSelf()
{
  printf("HYPERBOLA");
  printf("(");
  printString(get_name());
  printf(",");
  get_position()->get_id()->printSelf();
  printf(",");
  printDouble(semiAxis);
  printf(",");
  printDouble(semiImagAxis);
  printf(")");
}

/********************************************************************/

hyperbola::~hyperbola()
{
  delete get_name();
}

/********************************************************************/

void linearProfile::printSelf()
{
  printf("LINEAR_PROFILE");
  printf("(");
  if (get_placement())
    get_placement()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  profileLength->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

linearProfile::~linearProfile()
{
}

/********************************************************************/

void parabola::printSelf()
{
  printf("PARABOLA");
  printf("(");
  printString(get_name());
  printf(",");
  get_position()->get_id()->printSelf();
  printf(",");
  printDouble(focalDist);
  printf(")");
}

/********************************************************************/

parabola::~parabola()
{
  delete get_name();
}

/********************************************************************/

void planeRoughMilling::printSelf()
{
  printf("PLANE_ROUGH_MILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

planeRoughMilling::~planeRoughMilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_axialCuttingDepth();
  delete get_allowanceBottom();
}

/********************************************************************/

void polyline::printSelf()
{
  printf("POLYLINE");
  printf("(");
  printString(get_name());
  printf(",");
  points->printSelf();
  printf(")");
}

/********************************************************************/

polyline::~polyline()
{
  delete get_name();
  delete points;
}

/********************************************************************/

void rectangularPattern::printSelf()
{
  printf("RECTANGULAR_PATTERN");
  printf("(");
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_id()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_replicateBaseFeature()))->get_id()->printSelf();
  spacing->get_id()->printSelf();
  printf(",");
  itsDirection->get_id()->printSelf();
  printf(",");
  if (numberOfRows)
    numberOfRows->printSelf();
  else
    printf("$");
  printf(",");
  printf("%d", numberOfColumns);
  printf(",");
  if (rowSpacing)
    rowSpacing->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (rowLayoutDirection)
    rowLayoutDirection->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  relocatedBaseFeature->printSelf();
  printf(",");
  missingBaseFeature->printSelf();
  printf(")");
}

/********************************************************************/

rectangularPattern::~rectangularPattern()
{
  delete get_itsId();
  delete get_itsOperations();
  delete numberOfRows;
  delete relocatedBaseFeature;
  delete missingBaseFeature;
}

/********************************************************************/

void sideFinishMilling::printSelf()
{
  printf("SIDE_FINISH_MILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

sideFinishMilling::~sideFinishMilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_axialCuttingDepth();
  delete get_radialCuttingDepth();
  delete get_allowanceSide();
}

/********************************************************************/

void sideRoughMilling::printSelf()
{
  printf("SIDE_ROUGH_MILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

sideRoughMilling::~sideRoughMilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_axialCuttingDepth();
  delete get_radialCuttingDepth();
  delete get_allowanceSide();
}

/********************************************************************/

void tapping::printSelf()
{
  printf("TAPPING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  compensationChuck->printSelf();
  printf(")");
}

/********************************************************************/

tapping::~tapping()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
  delete compensationChuck;
}

/********************************************************************/

void threadDrilling::printSelf()
{
  printf("THREAD_DRILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  helicalMovementOnForward->printSelf();
  printf(")");
}

/********************************************************************/

threadDrilling::~threadDrilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
  delete helicalMovementOnForward;
}

/********************************************************************/

void toolProbing::printSelf()
{
  printf("TOOL_PROBING");
  printf("(");
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_id()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_id()->printSelf();
  printf(",");
  offset->get_id()->printSelf();
  printf(",");
  printDouble(maxWear);
  printf(",");
  (dynamic_cast<instance *>(itsTool))->get_id()->printSelf();
  printf(")");
}

/********************************************************************/

toolProbing::~toolProbing()
{
  delete get_itsId();
}

/********************************************************************/

void trimmedCurve::printSelf()
{
  printf("TRIMMED_CURVE");
  printf("(");
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(basisCurve))->get_id()->printSelf();
  printf(",");
  trim1->printSelf();
  printf(",");
  trim2->printSelf();
  printf(",");
  senseAgreement->printSelf();
  printf(",");
  masterRepresentation->printSelf();
  printf(")");
}

/********************************************************************/

trimmedCurve::~trimmedCurve()
{
  delete get_name();
  delete trim1;
  delete trim2;
  delete senseAgreement;
  delete masterRepresentation;
}

/********************************************************************/

void twistDrill::printSelf()
{
  printf("TWIST_DRILL");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

twistDrill::~twistDrill()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void backBoring::printSelf()
{
  printf("BACK_BORING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

backBoring::~backBoring()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
}

/********************************************************************/

void backsideCounterbore::printSelf()
{
  printf("BACKSIDE_COUNTERBORE");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

backsideCounterbore::~backsideCounterbore()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void backsideCountersink::printSelf()
{
  printf("BACKSIDE_COUNTERSINK");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (countersinkRadius)
    countersinkRadius->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

backsideCountersink::~backsideCountersink()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
  delete countersinkRadius;
}

/********************************************************************/

void bottomAndSideFinishMilling::printSelf()
{
  printf("BOTTOM_AND_SIDE_FINISH_MILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

bottomAndSideFinishMilling::~bottomAndSideFinishMilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_axialCuttingDepth();
  delete get_radialCuttingDepth();
  delete get_allowanceSide();
  delete get_allowanceBottom();
}

/********************************************************************/

void circle::printSelf()
{
  printf("CIRCLE");
  printf("(");
  printString(get_name());
  printf(",");
  get_position()->get_id()->printSelf();
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

circle::~circle()
{
  delete get_name();
}

/********************************************************************/

void counterbore::printSelf()
{
  printf("COUNTERBORE");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

counterbore::~counterbore()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void countersink::printSelf()
{
  printf("COUNTERSINK");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (countersinkRadius)
    countersinkRadius->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

countersink::~countersink()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
  delete countersinkRadius;
}

/********************************************************************/

void facemill::printSelf()
{
  printf("FACEMILL");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

facemill::~facemill()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void multistepDrilling::printSelf()
{
  printf("MULTISTEP_DRILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(retractDistance);
  printf(",");
  printDouble(firstDepth);
  printf(",");
  printDouble(depthOfStep);
  printf(",");
  if (dwellTimeStep)
    dwellTimeStep->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

multistepDrilling::~multistepDrilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
  delete dwellTimeStep;
}

/********************************************************************/

void planeFinishMilling::printSelf()
{
  printf("PLANE_FINISH_MILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

planeFinishMilling::~planeFinishMilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_axialCuttingDepth();
  delete get_allowanceBottom();
}

/********************************************************************/

void reaming::printSelf()
{
  printf("REAMING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_spindleStopAtBottom()->printSelf();
  printf(",");
  if (get_depthOfTestcut())
    get_depthOfTestcut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_waitingPosition())
    get_waitingPosition()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

reaming::~reaming()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
  delete get_spindleStopAtBottom();
  delete get_depthOfTestcut();
}

/********************************************************************/

void taperedEndmill::printSelf()
{
  printf("TAPERED_ENDMILL");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

taperedEndmill::~taperedEndmill()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
  delete taperAngle;
}

/********************************************************************/

void ballEndmill::printSelf()
{
  printf("BALL_ENDMILL");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

ballEndmill::~ballEndmill()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void boring::printSelf()
{
  printf("BORING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  get_spindleStopAtBottom()->printSelf();
  printf(",");
  if (get_depthOfTestcut())
    get_depthOfTestcut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_waitingPosition())
    get_waitingPosition()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

boring::~boring()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
  delete get_spindleStopAtBottom();
  delete get_depthOfTestcut();
}

/********************************************************************/

void bullnoseEndmill::printSelf()
{
  printf("BULLNOSE_ENDMILL");
  printf("(");
  get_dimension()->get_id()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

bullnoseEndmill::~bullnoseEndmill()
{
  delete get_numberOfTeeth();
  delete get_handOfCut();
  delete get_coolantThroughTool();
  delete get_pilotLength();
}

/********************************************************************/

void centerDrilling::printSelf()
{
  printf("CENTER_DRILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

centerDrilling::~centerDrilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
}

/********************************************************************/

void counterSinking::printSelf()
{
  printf("COUNTER_SINKING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

counterSinking::~counterSinking()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
}

/********************************************************************/

void drilling::printSelf()
{
  printf("DRILLING");
  printf("(");
  if (get_itsToolpath())
    get_itsToolpath()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_id()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_id()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_id()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_id()->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

drilling::~drilling()
{
  delete get_itsId();
  delete get_retractPlane();
  delete get_overcutLength();
  delete get_cuttingDepth();
  delete get_previousDiameter();
  delete get_dwellTimeBottom();
  delete get_feedOnRetract();
}

/********************************************************************/

