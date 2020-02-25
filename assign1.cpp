#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double calcMean(double charCount, int attemptCount){
  double mean = charCount/attemptCount;
  return mean;
}

int main(int argc, char const *argv[]) {

  if(argc<2){
    cout<<"invalid command line parameters."<<endl;
    return 1;

  }
  ofstream outFS; //output file stream
  ifstream inFS; //input file stream
  string fileNum; //string to read in from the file.
  string fName; //file name

  char letter; //create char of letter to iterate through later
  char secondLetter;
  int Acounter = 0; //initialize all counters
  int Ccounter = 0;
  int Tcounter = 0;
  int Gcounter = 0;
  int otherCounter = 0;
  int AAcounter = 0;
  int ACcounter = 0;
  int ATcounter = 0;
  int AGcounter = 0;
  int CAcounter = 0;
  int CCcounter = 0;
  int CTcounter = 0;
  int CGcounter = 0;
  int TAcounter = 0;
  int TCcounter = 0;
  int TTcounter = 0;
  int TGcounter = 0;
  int GAcounter = 0;
  int GCcounter = 0;
  int GTcounter = 0;
  int GGcounter = 0;
  int totalCount = 0;
  int lineCount=0;
  string blankString = "";
  int failLineCount = 0;
  int attemptCount = 0;
  double vSum = 0;
  double variance = 0;
  double vCount = 0;
  double meanLength =0;
  // string line = "";
  double standardDeviation=0;
  // string charCounter = "";

  // for(int i = 1; i<argc;++i){
    fName = argv[1];
    inFS.open(fName);
    // outFS.open("aidanWall.out",std::ios_base::app );
    outFS.open("aidanWall.out",std::ios_base::out );

    if(!inFS.is_open()){ //is_open() function returns boolean if it is open
      cout<< "could not open file "<< fName<<endl;
      return 1; //break program
    }

    cout<< "reading letters "<<endl;

    while(!inFS.eof()){ //while != end of file
      inFS >> fileNum;

      lineCount++;
      blankString+=fileNum+",";
      // for(int i = 0;i<blankString.size();++i){
      //   charCounter+= blankString[i]+",";
      // }


      if(!inFS.fail()){ //if it does not fail

        attemptCount+= fileNum.size();
        failLineCount++;

        for(int i= 0; i<fileNum.size();++i){
          fileNum[i] = toupper(fileNum[i]);


          letter = fileNum[i];
          cout<<letter<<endl;
          // blankString+=letter+",";
          if (letter == 'A') {
            Acounter++;
            totalCount++;
          }
          else if(letter == 'C'){
            Ccounter++;
            totalCount++;
          }
          else if(letter == 'T'){
            Tcounter++;
            totalCount++;
          }
          else if(letter == 'G'){
            Gcounter++;
            totalCount++;
          }
          // else if(letter =="\n"){
          //   lineCount++;
          // }
          else{
            otherCounter++;
            // totalCount++;//dont include because if non ACTG not in mean or stdvs
          }
        }

        for(int i = 0; i<fileNum.size(); i+=2 ){
          fileNum[i] = toupper(fileNum[i]);
          letter = fileNum[i];
          secondLetter = fileNum[i+1];


          if(letter == 'A' && secondLetter =='A'){
            AAcounter++;
            // totalCount++;
          }
          else if(letter == 'A'&& secondLetter == 'C'){
            ACcounter++;
            // totalCount++;
          }
          else if(letter == 'A'&& secondLetter == 'T'){
            ATcounter++;
            // totalCount++;
          }
          else if(letter == 'A'&& secondLetter == 'G'){
              AGcounter++;
              // totalCount++;
            }
          else if(letter == 'C'&& secondLetter == 'A'){
            CAcounter++;
            totalCount++;
          }
          else if(letter == 'C'&& secondLetter == 'C'){
            CCcounter++;
            // totalCount++;
          }
          else if(letter == 'C'&& secondLetter == 'T'){
            CTcounter++;
            // totalCount++;
          }
          else if(letter == 'C'&& secondLetter == 'G'){
            CGcounter++;
            // totalCount++;
          }
          else if(letter == 'T'&& secondLetter == 'A'){
            TAcounter++;
            // totalCount++;
          }
          else if(letter == 'T'&& secondLetter == 'C'){
            TCcounter++;
            // totalCount++;
          }
          else if(letter == 'T'&& secondLetter == 'T'){
            TTcounter++;
            // totalCount++;
          }
          else if(letter == 'T'&& secondLetter == 'G'){
            TGcounter++;
            // totalCount++;
          }
          else if(letter == 'G'&& secondLetter == 'A'){
            GAcounter++;
            // totalCount++;
          }
          else if(letter == 'G'&& secondLetter == 'C'){
            GCcounter++;
            // totalCount++;
          }
          else if(letter == 'G'&& secondLetter == 'T'){
            GTcounter++;
            // totalCount++;
          }
          else if(letter == 'G'&& secondLetter == 'G'){
            GGcounter++;
            // totalCount++;
          }
          else{
            otherCounter++;
          }

        }

      }


    } //close while loop, AFTER HERE
    meanLength = double(attemptCount)/failLineCount;
    cout<<"BLANK STRING: " << blankString<<endl;


    for(int i = 0;i<blankString.size()-1;++i){
      if(blankString[i]==','){
        vSum = vSum+ pow((vCount-double(meanLength)),2);
        vCount = 0;
      }else{
        vCount++;


      }
    }

    variance = double(vSum)/(failLineCount);
    cout<<"Variance: "<< variance<<endl;

    standardDeviation = sqrt(variance);
    cout<<"standard deviation "<<standardDeviation<<endl;


    double aMean = calcMean(double(Acounter),attemptCount);
    double cMean = calcMean(double(Ccounter),attemptCount);
    double tMean = calcMean(double(Tcounter),attemptCount);
    double gMean = calcMean(double(Gcounter),attemptCount);

    double AAMean = 2*calcMean(double(AAcounter),attemptCount);
    double ACMean = 2*calcMean(double(ACcounter),attemptCount);
    double AGMean = 2*calcMean(double(ATcounter),attemptCount);
    double ATMean = 2*calcMean(double(AGcounter),attemptCount);

    double CAMean = 2*calcMean(double(CAcounter),attemptCount);
    double CCMean = 2*calcMean(double(CCcounter),attemptCount);
    double CTMean = 2*calcMean(double(CTcounter),attemptCount);
    double CGMean = 2*calcMean(double(CGcounter),attemptCount);

    double TAMean = 2*calcMean(double(TAcounter),attemptCount);
    double TCMean = 2*calcMean(double(TCcounter),attemptCount);
    double TTMean = 2*calcMean(double(TTcounter),attemptCount);
    double TGMean = 2*calcMean(double(TGcounter),attemptCount);

    double GAMean = 2*calcMean(double(GAcounter),attemptCount);
    double GCMean = 2*calcMean(double(GCcounter),attemptCount);
    double GTMean = 2*calcMean(double(GTcounter),attemptCount);
    double GGMean = 2*calcMean(double(GGcounter),attemptCount);


    outFS<<"The Mean of the length of the DNA strings is: " << (double(attemptCount)/failLineCount)<<endl;
    outFS<<"The Mean of the length of the DNA strings is: " << meanLength<<endl;
    outFS<<"The Variance of the length of the DNA strings is: "<<variance<<endl;
    outFS<<"The Standard Deviation of the length of the DNA strings is: "<<standardDeviation<<endl;
    cout<<"fail line count "<<failLineCount<<endl;
    // variance = meanLength


    outFS<<endl;
    outFS<<"Here is the relative probability of each nucleotide:"<<endl;

    outFS<< "A: "<<aMean<<endl;
    outFS<< "C: "<<cMean<<endl;
    outFS<< "T: "<<tMean<<endl;
    outFS<< "G: "<<gMean<<endl;

    outFS<<endl;
    outFS<<"Here is the relative probability of each nucleotide bigram: "<<endl;
    // outFS<< endl;
    outFS<< "AA: "<<AAMean<<endl;
    outFS<< "AC: "<<ACMean<<endl;
    outFS<< "AT: "<<ATMean<<endl;
    outFS<< "AG: "<<AGMean<<endl;

    outFS<< "CA: "<<CAMean<<endl;
    outFS<< "CC: "<<CCMean<<endl;
    outFS<< "CT: "<<CTMean<<endl;
    outFS<< "CG: "<<CGMean<<endl;

    outFS<< "TA: "<<TAMean<<endl;
    outFS<< "TC: "<<TCMean<<endl;
    outFS<< "TT: "<<TTMean<<endl;
    outFS<< "TG: "<<TGMean<<endl;

    outFS<< "GA: "<<GAMean<<endl;
    outFS<< "GC: "<<GCMean<<endl;
    outFS<< "GT: "<<GTMean<<endl;
    outFS<< "GG: "<<GGMean<<endl;

    outFS<<endl;
  // }
  inFS.close();
  outFS.close();
  return 0;
}
