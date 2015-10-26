//
//  main.cpp
//  parseCSV
//
//  Created by Long Le on 2015-10-22.
//  Copyright © 2015 Long Le. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "csv.h"
#include <unordered_map>

using namespace std;

class PublicationProcessing {

int publicationCounter = 0;
int publishedCounter = 0;
int publishedJournalArticleCounter = 0;
vector<string> publishedJACEmp;
int publishedBooksCounter = 0;
vector<string> publishedBC;
int publishedCasereportsCounter = 0;
vector<string> publishedCRC;
int publishedAbstractCounter = 0;
vector<string> publishedAC;
int publishedBookChaptersCounter = 0;
vector<string> publishedBCC;
int publishedJAMARCounter = 0;
vector<string> publishedJAMAR;
int publishedOSCounter = 0;
vector<string> publishedOS;
int publishedNewsArticleCounter = 0;
vector<string> publishedNAC;
int publishedWorkingPaperCounter = 0;
vector<string> publishedWPC;
int publishedSSPCounter = 0;
vector<string> publishedSSP;
int publishedMagaizeEntryCounter = 0;
vector<string> publishedMEC;
int publishedclinicalCareGuidelinesCounter = 0;
vector<string> publishedCCG;
int publishedNewsLetterArticleCounter = 0;
vector<string> publishedNLAC;
int publishedMultimediaCounter = 0;
vector<string> publishedMC;
int publishedInvitedArticlesCounter = 0;
vector<string> publishedIA;
int publishedCPCounter = 0;
vector<string> publishedCPC;
int publishedWebsiteVideoCounter = 0;
vector<string> publishedWVC;
int publishedMonographCounter = 0;
vector<string> publishedM;
int publishedManualCounter = 0;
vector<string> publishedMCC;
int publishedLetterstoEditorCounter = 0;
vector<string> publishedLEC;
int publishedEditorialCounter = 0;
vector<string> publishedEC;
int publishedCommentaryCounter = 0;
vector<string> publishedC;
int publishedBooksEditedCounter = 0;
vector<string> publishedBE;
int publishedGPCounter = 0;
vector<string> publishedGP;

int acceptedCounter = 0;
int acceptedJournalArticleCounter = 0;
vector<string> acceptedJACEmp;
int acceptedBooksCounter = 0;
vector<string> acceptedBC;
int acceptedCasereportsCounter = 0;
vector<string> acceptedCRC;
int acceptedAbstractCounter = 0;
vector<string> acceptedAC;
int acceptedBookChaptersCounter = 0;
vector<string> acceptedBCC;
int acceptedJAMARCounter = 0;
vector<string> acceptedJAMAR;
int acceptedOSCounter = 0;
vector<string> acceptedOS;
int acceptedNewsArticleCounter = 0;
vector<string> acceptedNAC;
int acceptedWorkingPaperCounter = 0;
vector<string> acceptedWPC;
int acceptedSSPCounter = 0;
vector<string> acceptedSSP;
int acceptedMagaizeEntryCounter = 0;
vector<string> acceptedMEC;
int acceptedclinicalCareGuidelinesCounter = 0;
vector<string> acceptedCCG;
int acceptedNewsLetterArticleCounter = 0;
vector<string> acceptedNLAC;
int acceptedMultimediaCounter = 0;
vector<string> acceptedMC;
int acceptedInvitedArticlesCounter = 0;
vector<string> acceptedIA;
int acceptedCPCounter = 0;
vector<string> acceptedCPC;
int acceptedWebsiteVideoCounter = 0;
vector<string> acceptedWVC;
int acceptedMonographCounter = 0;
vector<string> acceptedM;
int acceptedManualCounter = 0;
vector<string> acceptedMCC;
int acceptedLetterstoEditorCounter = 0;
vector<string> acceptedLEC;
int acceptedEditorialCounter = 0;
vector<string> acceptedEC;
int acceptedCommentaryCounter = 0;
vector<string> acceptedC;
int acceptedBooksEditedCounter = 0;
vector<string> acceptedBE;
int acceptedGPCounter = 0;
vector<string> acceptedGP;

int submittedCounter = 0;
int submittedJournalArticleCounter = 0;
vector<string> submittedJACEmp;
int submittedBooksCounter = 0;
vector<string> submittedBC;
int submittedCasereportsCounter = 0;
vector<string> submittedCRC;
int submittedAbstractCounter = 0;
vector<string> submittedAC;
int submittedBookChaptersCounter = 0;
vector<string> submittedBCC;
int submittedJAMARCounter = 0;
vector<string> submittedJAMAR;
int submittedOSCounter = 0;
vector<string> submittedOS;
int submittedNewsArticleCounter = 0;
vector<string> submittedNAC;
int submittedWorkingPaperCounter = 0;
vector<string> submittedWPC;
int submittedSSPCounter = 0;
vector<string> submittedSSP;
int submittedMagaizeEntryCounter = 0;
vector<string> submittedMEC;
int submittedclinicalCareGuidelinesCounter = 0;
vector<string> submittedCCG;
int submittedNewsLetterArticleCounter = 0;
vector<string> submittedNLAC;
int submittedMultimediaCounter = 0;
vector<string> submittedMC;
int submittedInvitedArticlesCounter = 0;
vector<string> submittedIA;
int submittedCPCounter = 0;
vector<string> submittedCPC;
int submittedWebsiteVideoCounter = 0;
vector<string> submittedWVC;
int submittedMonographCounter = 0;
vector<string> submittedM;
int submittedManualCounter = 0;
vector<string> submittedMCC;
int submittedLetterstoEditorCounter = 0;
vector<string> submittedLEC;
int submittedEditorialCounter = 0;
vector<string> submittedEC;
int submittedCommentaryCounter = 0;
vector<string> submittedC;
int submittedBooksEditedCounter = 0;
vector<string> submittedBE;
int submittedGPCounter = 0;
vector<string> submittedGP;
int publicationCounter = 0;





    for (int i = 0; i < data.at(0).size(); i++){
        if ((data.at(0).at(i).compare("")) != 0) {
            publicationCounter++;
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


    for (int i = 0; i < data.at(0).size(); i++){
        if ((data.at(2).at(i).compare("Published")) == 0){
            publishedCounter++;
            if ((data.at(3).at(i).compare("Journal Article")) == 0) {
                publishedJournalArticleCounter++;
                publishedJACEmp.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Books")) == 0) {
                publishedBooksCounter++;
                publishedBC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Case Reports")) == 0) {
                publishedCasereportsCounter++;
                publishedCRC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Published Abstract")) == 0) {
                publishedAbstractCounter++;
                publishedAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Book Chapters")) == 0) {
                publishedBookChaptersCounter++;
                publishedBCC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Journal Article, Meta-Analysis, Review")) == 0) {
                publishedJAMARCounter++;
                publishedJAMAR.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Other -status")) == 0) {
                publishedOSCounter++;
                publishedOS.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Newspaper Artitcles")) == 0) {
                publishedNewsArticleCounter++;
                publishedNAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Working Papers")) == 0) {
                publishedWorkingPaperCounter++;
                publishedWPC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Supervised Student Publications")) == 0) {
                publishedSSPCounter++;
                publishedSSP.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Magazine Entries")) == 0) {
                publishedMagaizeEntryCounter++;
                publishedMEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Clinical Care Guidelines")) == 0) {
                publishedclinicalCareGuidelinesCounter++;
                publishedCCG.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Newsletter Articles")) == 0) {
                publishedNewsLetterArticleCounter++;
                publishedNLAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Multimedia")) == 0) {
                publishedMultimediaCounter++;
                publishedMC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Invited Artciles")) == 0) {
                publishedInvitedArticlesCounter++;
                publishedIA.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Conference Proceedings")) == 0) {
                publishedCPCounter++;
                publishedCPC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Websites / Videos")) == 0) {
                publishedWebsiteVideoCounter++;
                publishedWVC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Monographs")) == 0) {
                publishedMonographCounter++;
                publishedM.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Manuals")) == 0) {
                publishedManualCounter++;
                publishedMCC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Letters to Editor")) == 0) {
                publishedLetterstoEditorCounter++;
                publishedLEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Editorials")) == 0) {
                publishedEditorialCounter++;
                publishedEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Commentaries")) == 0) {
                publishedCommentaryCounter++;
                publishedC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Books Edited")) == 0) {
                publishedBooksEditedCounter++;
                publishedBE.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Group Publication")) == 0) {
                publishedGPCounter++;
                publishedGP.push_back(data.at(6).at(i));
            }
        }
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////


    for (int i = 0; i < data.at(0).size(); i++){
        if ((data.at(2).at(i).compare("Accepted / In Press")) == 0){
            acceptedCounter++;
            if ((data.at(3).at(i).compare("Journal Article")) == 0) {
                acceptedJournalArticleCounter++;
                acceptedJACEmp.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Books")) == 0) {
                acceptedBooksCounter++;
                acceptedBC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Case Reports")) == 0) {
                acceptedCasereportsCounter++;
                acceptedCRC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Published Abstract")) == 0) {
                acceptedAbstractCounter++;
                acceptedAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Book Chapters")) == 0) {
                acceptedBookChaptersCounter++;
                acceptedBCC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Journal Article, Meta-Analysis, Review")) == 0) {
                acceptedJAMARCounter++;
                acceptedJAMAR.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Other -status")) == 0) {
                acceptedOSCounter++;
                acceptedOS.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Newspaper Artitcles")) == 0) {
                acceptedNewsArticleCounter++;
                acceptedNAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Working Papers")) == 0) {
                acceptedWorkingPaperCounter++;
                acceptedWPC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Supervised Student Publications")) == 0) {
                acceptedSSPCounter++;
                acceptedSSP.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Magazine Entries")) == 0) {
                acceptedMagaizeEntryCounter++;
                acceptedMEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Clinical Care Guidelines")) == 0) {
                acceptedclinicalCareGuidelinesCounter++;
                acceptedCCG.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Newsletter Articles")) == 0) {
                acceptedNewsLetterArticleCounter++;
                acceptedNLAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Multimedia")) == 0) {
                acceptedMultimediaCounter++;
                acceptedMC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Invited Artciles")) == 0) {
                acceptedInvitedArticlesCounter++;
                acceptedIA.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Conference Proceedings")) == 0) {
                acceptedCPCounter++;
                acceptedCPC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Websites / Videos")) == 0) {
                acceptedWebsiteVideoCounter++;
                acceptedWVC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Monographs")) == 0) {
                acceptedMonographCounter++;
                acceptedM.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Manuals")) == 0) {
                acceptedManualCounter++;
                acceptedMCC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Letters to Editor")) == 0) {
                acceptedLetterstoEditorCounter++;
                acceptedLEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Editorials")) == 0) {
                acceptedEditorialCounter++;
                acceptedEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Commentaries")) == 0) {
                acceptedCommentaryCounter++;
                acceptedC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Books Edited")) == 0) {
                acceptedBooksEditedCounter++;
                acceptedBE.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Group Publication")) == 0) {
                acceptedGPCounter++;
                acceptedGP.push_back(data.at(6).at(i));
            }
        }
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < data.at(0).size(); i++){
        if ((data.at(2).at(i).compare("Submitted")) == 0){
            submittedCounter++;
            if ((data.at(3).at(i).compare("Journal Article")) == 0) {
                submittedJournalArticleCounter++;
                submittedJACEmp.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Books")) == 0) {
                submittedBooksCounter++;
                submittedBC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Case Reports")) == 0) {
                submittedCasereportsCounter++;
                submittedCRC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Published Abstract")) == 0) {
                submittedAbstractCounter++;
                submittedAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Book Chapters")) == 0) {
                submittedBookChaptersCounter++;
                submittedBCC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Journal Article, Meta-Analysis, Review")) == 0) {
                submittedJAMARCounter++;
                submittedJAMAR.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Other -status")) == 0) {
                submittedOSCounter++;
                submittedOS.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Newspaper Artitcles")) == 0) {
                submittedNewsArticleCounter++;
                submittedNAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Working Papers")) == 0) {
                submittedWorkingPaperCounter++;
                submittedWPC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Supervised Student Publications")) == 0) {
                submittedSSPCounter++;
                submittedSSP.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Magazine Entries")) == 0) {
                submittedMagaizeEntryCounter++;
                submittedMEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Clinical Care Guidelines")) == 0) {
                submittedclinicalCareGuidelinesCounter++;
                submittedCCG.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Newsletter Articles")) == 0) {
                submittedNewsLetterArticleCounter++;
                submittedNLAC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Multimedia")) == 0) {
                submittedMultimediaCounter++;
                submittedMC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Invited Artciles")) == 0) {
                submittedInvitedArticlesCounter++;
                submittedIA.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Conference Proceedings")) == 0) {
                submittedCPCounter++;
                submittedCPC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Websites / Videos")) == 0) {
                submittedWebsiteVideoCounter++;
                submittedWVC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Monographs")) == 0) {
                submittedMonographCounter++;
                submittedM.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Manuals")) == 0) {
                submittedManualCounter++;
                submittedMCC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Letters to Editor")) == 0) {
                submittedLetterstoEditorCounter++;
                submittedLEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Editorials")) == 0) {
                submittedEditorialCounter++;
                submittedEC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Commentaries")) == 0) {
                submittedCommentaryCounter++;
                submittedC.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("Books Edited")) == 0) {
                submittedBooksEditedCounter++;
                submittedBE.push_back(data.at(6).at(i));
            }
            else if ((data.at(3).at(i).compare("* Group Publication")) == 0) {
                submittedGPCounter++;
                submittedGP.push_back(data.at(6).at(i));
            }
        }
    }

    //Get name of author with number of times it appears
    unordered_map<string, int> hashtable;
    unordered_map<string, int> hashtable2;
    for (int i = 0; i < acceptedBC.size(); i++) {
        hashtable.emplace(acceptedBC.at(i), i);
    }
    for (int x = 0; x < acceptedBC.size(); x++) {
        int y = hashtable.count(acceptedBC.at(x));
        hashtable2.emplace(acceptedBC.at(x), y);
    }





////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

   }
