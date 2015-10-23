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
#include "PublicationProcessing.h"

using namespace std;

PublicationProcessing::PublicationProcessing(vector<vector<string>> data) {

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

int PublicationProcessing::getPublicationCounter () {
return publicationCounter ;
}
 
int PublicationProcessing::getPublishedCounter () {
return publishedCounter ;
}
 
int PublicationProcessing::getPublishedJournalArticleCounter () {
return publishedJournalArticleCounter ;
}
 
vector<string> PublicationProcessing::getPublishedJACEmp() {
return publishedJACEmp;
}
 
int PublicationProcessing::getPublishedBooksCounter () {
return publishedBooksCounter ;
}
 
vector<string> PublicationProcessing::getPublishedBC() {
return publishedBC;
}
 
int PublicationProcessing::getPublishedCasereportsCounter () {
return publishedCasereportsCounter ;
}
 
vector<string> PublicationProcessing::getPublishedCRC() {
return publishedCRC;
}
 
int PublicationProcessing::getPublishedAbstractCounter () {
return publishedAbstractCounter ;
}
 
vector<string> PublicationProcessing::getPublishedAC() {
return publishedAC;
}
 
int PublicationProcessing::getPublishedBookChaptersCounter () {
return publishedBookChaptersCounter ;
}
 
vector<string> PublicationProcessing::getPublishedBCC() {
return publishedBCC;
}
 
int PublicationProcessing::getPublishedJAMARCounter () {
return publishedJAMARCounter ;
}
 
vector<string> PublicationProcessing::getPublishedJAMAR() {
return publishedJAMAR;
}
 
int PublicationProcessing::getPublishedOSCounter () {
return publishedOSCounter ;
}
 
vector<string> PublicationProcessing::getPublishedOS() {
return publishedOS;
}
 
int PublicationProcessing::getPublishedNewsArticleCounter () {
return publishedNewsArticleCounter ;
}
 
vector<string> PublicationProcessing::getPublishedNAC() {
return publishedNAC;
}
 
int PublicationProcessing::getPublishedWorkingPaperCounter () {
return publishedWorkingPaperCounter ;
}
 
vector<string> PublicationProcessing::getPublishedWPC() {
return publishedWPC;
}
 
int PublicationProcessing::getPublishedSSPCounter () {
return publishedSSPCounter ;
}
 
vector<string> PublicationProcessing::getPublishedSSP() {
return publishedSSP;
}
 
int PublicationProcessing::getPublishedMagaizeEntryCounter () {
return publishedMagaizeEntryCounter ;
}
 
vector<string> PublicationProcessing::getPublishedMEC() {
return publishedMEC;
}
 
int PublicationProcessing::getPublishedclinicalCareGuidelinesCounter () {
return publishedclinicalCareGuidelinesCounter ;
}
 
vector<string> PublicationProcessing::getPublishedCCG() {
return publishedCCG;
}
 
int PublicationProcessing::getPublishedNewsLetterArticleCounter () {
return publishedNewsLetterArticleCounter ;
}
 
vector<string> PublicationProcessing::getPublishedNLAC() {
return publishedNLAC;
}
 
int PublicationProcessing::getPublishedMultimediaCounter () {
return publishedMultimediaCounter ;
}
 
vector<string> PublicationProcessing::getPublishedMC() {
return publishedMC;
}
 
int PublicationProcessing::getPublishedInvitedArticlesCounter () {
return publishedInvitedArticlesCounter ;
}
 
vector<string> PublicationProcessing::getPublishedIA() {
return publishedIA;
}
 
int PublicationProcessing::getPublishedCPCounter () {
return publishedCPCounter ;
}
 
vector<string> PublicationProcessing::getPublishedCPC() {
return publishedCPC;
}
 
int PublicationProcessing::getPublishedWebsiteVideoCounter () {
return publishedWebsiteVideoCounter ;
}
 
vector<string> PublicationProcessing::getPublishedWVC() {
return publishedWVC;
}
 
int PublicationProcessing::getPublishedMonographCounter () {
return publishedMonographCounter ;
}
 
vector<string> PublicationProcessing::getPublishedM() {
return publishedM;
}
 
int PublicationProcessing::getPublishedManualCounter () {
return publishedManualCounter ;
}
 
vector<string> PublicationProcessing::getPublishedMCC() {
return publishedMCC;
}
 
int PublicationProcessing::getPublishedLetterstoEditorCounter () {
return publishedLetterstoEditorCounter ;
}
 
vector<string> PublicationProcessing::getPublishedLEC() {
return publishedLEC;
}
 
int PublicationProcessing::getPublishedEditorialCounter () {
return publishedEditorialCounter ;
}
 
vector<string> PublicationProcessing::getPublishedEC() {
return publishedEC;
}
 
int PublicationProcessing::getPublishedCommentaryCounter () {
return publishedCommentaryCounter ;
}
 
vector<string> PublicationProcessing::getPublishedC() {
return publishedC;
}
 
int PublicationProcessing::getPublishedBooksEditedCounter () {
return publishedBooksEditedCounter ;
}
 
vector<string> PublicationProcessing::getPublishedBE() {
return publishedBE;
}
 
int PublicationProcessing::getPublishedGPCounter () {
return publishedGPCounter ;
}
 
vector<string> PublicationProcessing::getPublishedGP() {
return publishedGP;
}
 
int PublicationProcessing::getAcceptedCounter () {
return acceptedCounter ;
}
 
int PublicationProcessing::getAcceptedJournalArticleCounter () {
return acceptedJournalArticleCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedJACEmp() {
return acceptedJACEmp;
}
 
int PublicationProcessing::getAcceptedBooksCounter () {
return acceptedBooksCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedBC() {
return acceptedBC;
}
 
int PublicationProcessing::getAcceptedCasereportsCounter () {
return acceptedCasereportsCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedCRC() {
return acceptedCRC;
}
 
int PublicationProcessing::getAcceptedAbstractCounter () {
return acceptedAbstractCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedAC() {
return acceptedAC;
}
 
int PublicationProcessing::getAcceptedBookChaptersCounter () {
return acceptedBookChaptersCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedBCC() {
return acceptedBCC;
}
 
int PublicationProcessing::getAcceptedJAMARCounter () {
return acceptedJAMARCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedJAMAR() {
return acceptedJAMAR;
}
 
int PublicationProcessing::getAcceptedOSCounter () {
return acceptedOSCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedOS() {
return acceptedOS;
}
 
int PublicationProcessing::getAcceptedNewsArticleCounter () {
return acceptedNewsArticleCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedNAC() {
return acceptedNAC;
}
 
int PublicationProcessing::getAcceptedWorkingPaperCounter () {
return acceptedWorkingPaperCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedWPC() {
return acceptedWPC;
}
 
int PublicationProcessing::getAcceptedSSPCounter () {
return acceptedSSPCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedSSP() {
return acceptedSSP;
}
 
int PublicationProcessing::getAcceptedMagaizeEntryCounter () {
return acceptedMagaizeEntryCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedMEC() {
return acceptedMEC;
}
 
int PublicationProcessing::getAcceptedclinicalCareGuidelinesCounter () {
return acceptedclinicalCareGuidelinesCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedCCG() {
return acceptedCCG;
}
 
int PublicationProcessing::getAcceptedNewsLetterArticleCounter () {
return acceptedNewsLetterArticleCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedNLAC() {
return acceptedNLAC;
}
 
int PublicationProcessing::getAcceptedMultimediaCounter () {
return acceptedMultimediaCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedMC() {
return acceptedMC;
}
 
int PublicationProcessing::getAcceptedInvitedArticlesCounter () {
return acceptedInvitedArticlesCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedIA() {
return acceptedIA;
}
 
int PublicationProcessing::getAcceptedCPCounter () {
return acceptedCPCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedCPC() {
return acceptedCPC;
}
 
int PublicationProcessing::getAcceptedWebsiteVideoCounter () {
return acceptedWebsiteVideoCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedWVC() {
return acceptedWVC;
}
 
int PublicationProcessing::getAcceptedMonographCounter () {
return acceptedMonographCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedM() {
return acceptedM;
}
 
int PublicationProcessing::getAcceptedManualCounter () {
return acceptedManualCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedMCC() {
return acceptedMCC;
}
 
int PublicationProcessing::getAcceptedLetterstoEditorCounter () {
return acceptedLetterstoEditorCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedLEC() {
return acceptedLEC;
}
 
int PublicationProcessing::getAcceptedEditorialCounter () {
return acceptedEditorialCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedEC() {
return acceptedEC;
}
 
int PublicationProcessing::getAcceptedCommentaryCounter () {
return acceptedCommentaryCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedC() {
return acceptedC;
}
 
int PublicationProcessing::getAcceptedBooksEditedCounter () {
return acceptedBooksEditedCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedBE() {
return acceptedBE;
}
 
int PublicationProcessing::getAcceptedGPCounter () {
return acceptedGPCounter ;
}
 
vector<string> PublicationProcessing::getAcceptedGP() {
return acceptedGP;
}
 
int PublicationProcessing::getSubmittedCounter () {
return submittedCounter ;
}
 
int PublicationProcessing::getSubmittedJournalArticleCounter () {
return submittedJournalArticleCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedJACEmp() {
return submittedJACEmp;
}
 
int PublicationProcessing::getSubmittedBooksCounter () {
return submittedBooksCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedBC() {
return submittedBC;
}
 
int PublicationProcessing::getSubmittedCasereportsCounter () {
return submittedCasereportsCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedCRC() {
return submittedCRC;
}
 
int PublicationProcessing::getSubmittedAbstractCounter () {
return submittedAbstractCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedAC() {
return submittedAC;
}
 
int PublicationProcessing::getSubmittedBookChaptersCounter () {
return submittedBookChaptersCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedBCC() {
return submittedBCC;
}
 
int PublicationProcessing::getSubmittedJAMARCounter () {
return submittedJAMARCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedJAMAR() {
return submittedJAMAR;
}
 
int PublicationProcessing::getSubmittedOSCounter () {
return submittedOSCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedOS() {
return submittedOS;
}
 
int PublicationProcessing::getSubmittedNewsArticleCounter () {
return submittedNewsArticleCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedNAC() {
return submittedNAC;
}
 
int PublicationProcessing::getSubmittedWorkingPaperCounter () {
return submittedWorkingPaperCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedWPC() {
return submittedWPC;
}
 
int PublicationProcessing::getSubmittedSSPCounter () {
return submittedSSPCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedSSP() {
return submittedSSP;
}
 
int PublicationProcessing::getSubmittedMagaizeEntryCounter () {
return submittedMagaizeEntryCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedMEC() {
return submittedMEC;
}
 
int PublicationProcessing::getSubmittedclinicalCareGuidelinesCounter () {
return submittedclinicalCareGuidelinesCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedCCG() {
return submittedCCG;
}
 
int PublicationProcessing::getSubmittedNewsLetterArticleCounter () {
return submittedNewsLetterArticleCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedNLAC() {
return submittedNLAC;
}
 
int PublicationProcessing::getSubmittedMultimediaCounter () {
return submittedMultimediaCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedMC() {
return submittedMC;
}
 
int PublicationProcessing::getSubmittedInvitedArticlesCounter () {
return submittedInvitedArticlesCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedIA() {
return submittedIA;
}
 
int PublicationProcessing::getSubmittedCPCounter () {
return submittedCPCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedCPC() {
return submittedCPC;
}
 
int PublicationProcessing::getSubmittedWebsiteVideoCounter () {
return submittedWebsiteVideoCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedWVC() {
return submittedWVC;
}
 
int PublicationProcessing::getSubmittedMonographCounter () {
return submittedMonographCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedM() {
return submittedM;
}
 
int PublicationProcessing::getSubmittedManualCounter () {
return submittedManualCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedMCC() {
return submittedMCC;
}
 
int PublicationProcessing::getSubmittedLetterstoEditorCounter () {
return submittedLetterstoEditorCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedLEC() {
return submittedLEC;
}
 
int PublicationProcessing::getSubmittedEditorialCounter () {
return submittedEditorialCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedEC() {
return submittedEC;
}
 
int PublicationProcessing::getSubmittedCommentaryCounter () {
return submittedCommentaryCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedC() {
return submittedC;
}
 
int PublicationProcessing::getSubmittedBooksEditedCounter () {
return submittedBooksEditedCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedBE() {
return submittedBE;
}
 
int PublicationProcessing::getSubmittedGPCounter () {
return submittedGPCounter ;
}
 
vector<string> PublicationProcessing::getSubmittedGP() {
return submittedGP;
}
