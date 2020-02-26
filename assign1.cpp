#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double calcMean(double charCount, int attemptCount){//declare function to calculate the mean
  double mean = charCount/attemptCount;
  return mean;
}

int main(int argc, char const *argv[]) {

  if(argc<2){ //make sure valid command line parameters
    cout<<"invalid command line parameters."<<endl;
    return 1;

  }
  ofstream outFS; //output file stream
  ifstream inFS; //input file stream
  string fileNum; //string to read in from the file.
  string fName; //file name

  char letter; //create char of letter to iterate through later
  char secondLetter;
  int Acounter = 0; //initialize all counters and variables
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

  string blankString = "";
  int failLineCount = 0;
  int attemptCount = 0;
  double vSum = 0;
  double variance = 0;
  double vCount = 0;
  double meanLength =0;
  double standardDeviation=0;
  // int argFile = 1;
  bool enter = true;
  fName = argv[1];

  while(enter){ //enter while loop

    cout<<"File name: "<<fName<<endl;
    inFS.open(fName); //open file
    outFS.open("aidanWall.out",std::ios_base::app );//append to file


    if(!inFS.is_open()){ //is_open() function returns boolean if it is open
      cout<< "could not open file "<< fName<<endl;
      return 1; //break program
    }



    while(!inFS.eof()){ //while != end of file
      inFS >> fileNum;


      blankString+=fileNum+",";//create blank string



      if(!inFS.fail()){ //if it does not fail

        attemptCount+= fileNum.size();
        failLineCount++;

        for(int i= 0; i<fileNum.size();++i){
          fileNum[i] = toupper(fileNum[i]);//make all capital


          letter = fileNum[i];//iterate through each char

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

          else{
            otherCounter++;

          }
        }

        for(int i = 0; i<fileNum.size(); i+=2 ){ //iterate through each bigram
          fileNum[i] = toupper(fileNum[i]);
          letter = fileNum[i];
          secondLetter = fileNum[i+1];


          if(letter == 'A' && secondLetter =='A'){
            AAcounter++;

          }
          else if(letter == 'A'&& secondLetter == 'C'){
            ACcounter++;

          }
          else if(letter == 'A'&& secondLetter == 'T'){
            ATcounter++;

          }
          else if(letter == 'A'&& secondLetter == 'G'){
              AGcounter++;

            }
          else if(letter == 'C'&& secondLetter == 'A'){
            CAcounter++;

          }
          else if(letter == 'C'&& secondLetter == 'C'){
            CCcounter++;

          }
          else if(letter == 'C'&& secondLetter == 'T'){
            CTcounter++;

          }
          else if(letter == 'C'&& secondLetter == 'G'){
            CGcounter++;

          }
          else if(letter == 'T'&& secondLetter == 'A'){
            TAcounter++;

          }
          else if(letter == 'T'&& secondLetter == 'C'){
            TCcounter++;

          }
          else if(letter == 'T'&& secondLetter == 'T'){
            TTcounter++;

          }
          else if(letter == 'T'&& secondLetter == 'G'){
            TGcounter++;

          }
          else if(letter == 'G'&& secondLetter == 'A'){
            GAcounter++;

          }
          else if(letter == 'G'&& secondLetter == 'C'){
            GCcounter++;

          }
          else if(letter == 'G'&& secondLetter == 'T'){
            GTcounter++;

          }
          else if(letter == 'G'&& secondLetter == 'G'){
            GGcounter++;

          }
          else{
            otherCounter++;
          }

        }

      }


    } //close while loop, AFTER HERE
    meanLength = double(attemptCount)/failLineCount; //mean string length



    for(int i = 0;i<blankString.size()-1;++i){ //loop to calculate variance
      if(blankString[i]==','){
        vSum = vSum+ pow((vCount-double(meanLength)),2);
        vCount = 0;
      }else{
        vCount++;


      }
    }

    variance = double(vSum)/(failLineCount);


    standardDeviation = sqrt(variance);



    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    a = ((double) rand() / (RAND_MAX));
    b = ((double) rand()/(RAND_MAX));

    c=sqrt((-2*log(a)))*cos(2*b*M_PI);

    d=(c*standardDeviation)+meanLength;


    // cout<<"rand a "<<a<<endl;
    // cout<<"rand b "<<b<<endl;
    // cout<<"c: "<<c<<endl;
    // cout<<"d: "<<d<<endl;

    string writeString = "";


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



    outFS<<"The Mean of the length of the DNA strings is: " << meanLength<<endl;
    outFS<<"The Variance of the length of the DNA strings is: "<<variance<<endl;
    outFS<<"The Standard Deviation of the length of the DNA strings is: "<<standardDeviation<<endl;



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


        for(int i = 0; i<1000;++i){ //loop to create random strings
          for(int j = 0;j<int(d);++j ){
              double randNum = ((double) rand() / (RAND_MAX));
              if(randNum>0&& randNum<=aMean){
                writeString+="A";
              }
              else if(randNum>aMean && randNum<=(cMean+aMean)){
                writeString+="C";
              }
              else if(randNum>(cMean+aMean) && randNum<=(cMean+aMean+tMean)){
                writeString+="T";
              }
              else{
                writeString+="G";
              }
              // outFS>>;

            }
            outFS<<writeString<<endl;
            writeString="";
        }
        int anotherFile = 0;
        string addFile;
        cout<<"Enter 1 if you want to analyze another file: "<<endl;
        cin>> anotherFile;
        if(anotherFile==1){ //prompt for another file
          cout<<"enter the name of the file: "<<endl;
          cin>>addFile;
          fName=addFile;
          // break;
        }
        else{
          enter = false;
        }
}
  
  inFS.close();//close streams
  outFS.close();
  return 0;
}
