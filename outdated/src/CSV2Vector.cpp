//
//  main.cpp
//  parseCSV
//
//  Created by Long Be on 2015-10-22.
//  Copyright © 2015 Long Le. All rights reserved.
//

/*
 * This file will implement a CSV parsing mechanism
 *
 *
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "csv.h"
using namespace std;

#define DEBUG  0

void myData::myData()
{
	publications = NULL;
	teaching = NULL;
	funding = NULL;
	presentations = NULL;

}



bool myData::isPublications()
{
	if (publications != NULL) return true;
	return false;
}
bool myData::isTeaching()
{
	if (teaching != NULL) return true;
	return false;
}
bool myData::isFunding()
{
	if (funding != NULL) return true;
	return false;
}
bool myData::isPresentations()
{
	if (presentations != NULL) return true;
	return false;
}

string * myData::readPublications(publicationField myField, int entryNum)
{
	if (!isPublications()) return NULL;
	return publications[myField][entryNum];
}

bool myData::createParsePublications(string filePath)
{
	publications = new vector<vector <string>> ();
	if (publications == NULL) return false;
	publications = parsePublications(filePath);
	return true;
}
bool myData::createParseTeaching(string filePath)
{
	/* TODO: Implement*/
	return true;
}
bool myData::createParseFunding(string filePath)
{
	/*TODO: Implement */
	return true;
}
bool myData::createParsePresentations(string filePath)
{
	/*TODO: Implement */
	return true;
}


vector<vector<string >> parseTeaching(string filePath)
{
	/*TODO: Implement */
	vector<vector<string>> Data;
	return Data;

}
vector<vector<string >> parseFunding(string filePath)
{
	/*TODO: Implement */
	vector<vector<string>> Data ;
	return Data;
}
vector<vector<string >> parsePresentations(string filePath)
{
	/*TODO: Implement */
	vector<vector<string>> Data;
	return Data;
}

vector<vector<string >> myData::parsePublications(string filePath) {

    // If the file is in the same folder as your source code, then there is no need to include file path
    io::CSVReader<44, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
    
    // Check if column headings exist with the CSV Files
    in.read_header(io::ignore_extra_column, "Record Info", "Last Modified User",                                                    \
        "Last Modified Date", "ID", "Member Name", "Primary Domain", "Publication Status",                                          \
        "Pubmed Article ID", "Type", "Area", "Status Date", "Role", "Peer Reviewed?", "Number Of Contributors",                     \
        "Author #", "Journal Name | Published In | Book Title | etc.", "Volume", "Issue", "Page Range", "DOI",                      \
        "Website", "Number of Citations", "Journal Impact Factor", "International", "Publication Country",                          \
        "Publication Province", "Publication City", "Publisher", "Level of Contribution", "Is Presentation?",                       \
        "Impact", "Open Access?", "Personal Remuneration", "Is Trainee?", "Trainee Details", "Is Most Significant Publication?",    \
        "Most Significant Contribution Details", "Education Publication", "Other Details (doesn't print)", "Author(s)", "Title",    \
        "Rest of Citation", "ISBNISSN", "Funding Reference Number"); 
    
    // Attributes related to the column headings
    string r_i, lmu, lmd, id, m_name, p_domain, p_status, pa_id, p_type, area, s_date, role, p_rev, num_contri, author,             \
    jn_pi_bt, vol, issue, p_range, doi, web, num_cita, jif, inter, p_country, p_prov, p_city, pbsr, loc, is_pres, impact,           \
    open_a, p_remu, train, t_det, imsp, mscd, e_pub, o_det, auths, title, roc, isbn, frn;                                           
    
    // Vector storing each column values
    vector<string> vr_i, vlmu, vlmd, vid, vm_name, vp_domain, vp_status, vpa_id, vp_type, varea, vs_date, vrole, vp_rev,            \
    vnum_contri, vauthor, vjn_pi_bt, vvol, vissue, vp_range, vdoi, vweb, vnum_cita, vjif, vinter, vp_country, vp_prov,              \
    vp_city, vpbsr, vloc, vis_pres, vimpact, vopen_a, vp_remu, vtrain, vt_det, vimsp, vmscd, ve_pub, vo_det, vauths, vtitle,        \
    vroc, visbn, vfrn;
    
    // Vector storing each vector of column values
    vector<vector<string>> data;
    
    // Iterate until there are no more rows
    while (in.read_row(r_i, lmu, lmd, id, m_name, p_domain, p_status, pa_id, p_type, area, s_date, role, p_rev, num_contri, author, \
        jn_pi_bt, vol, issue, p_range, doi, web, num_cita, jif, inter, p_country, p_prov, p_city, pbsr, loc, is_pres, impact,       \
         open_a, p_remu, train, t_det, imsp, mscd, e_pub, o_det, auths, title, roc, isbn, frn)) {

        // Store the values
        vm_name.push_back(m_name);
        vp_domain.push_back(p_domain);
        vp_status.push_back(p_status);
        vp_type.push_back(p_type);
        vs_date.push_back(s_date);
        vrole.push_back(role);
        vauthor.push_back(author);
        vjn_pi_bt.push_back(jn_pi_bt);
        vtitle.push_back(title);
        
    }
    
        // Store the vectors
        data.push_back(vm_name);
        data.push_back(vp_domain);
        data.push_back(vp_status);
        data.push_back(vp_type);
        data.push_back(vs_date);
        data.push_back(vrole);
        data.push_back(vauthor);
        data.push_back(vjn_pi_bt);
        data.push_back(vtitle);

        return data;
    
#if (DEBUG)
    // Print the first 100 values of domain dates
    for (int i = 0; i < 100; i++){
    	cout << i << " : " << data.at(4).at(i) << "\n";
    }
#endif

#if 0
    exit(EXIT_SUCCESS);
#endif

}
