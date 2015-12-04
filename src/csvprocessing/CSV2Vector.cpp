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
#include "CSV2Vector.hpp"
#include "csv.h"
using namespace std;

#define DEBUG  0

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

myData::myData()
{
    publications = NULL;
    teaching = NULL;
    funding = NULL;
    presentations = NULL;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*TODO: ONE PROBLEM, THIS BECOMES VERY VERY VERY VERY TIME CONSUMING WHEN EDITING FILE. */
vector<vector<string>> myData::invertVector(vector<vector<string>> myVector)
{
    /* Currently, every vector is a field and users information are rows in each vector*/
    /* Transition to every vector is a user, and each field in that vector are elements of fields */
    vector<vector<string>> newVector;

    for (int i = 0; i < myVector.size(); i++)
    {
        vector<string> currUser;
        for (int j = 0; j < myVector.at(i).size(); j++)
        {
            currUser.push_back(myVector.at(i).at(j));
        }
        newVector.push_back(currUser);
    }

    return newVector;
}

vector<vector<int>> myData::getErrors(CSVType type)
{

    vector<vector<int>> errors;

    vector<vector<string>> *csvFile;

    switch(type) {

        case pubType:
            csvFile = publications;
            break;
        case presType:
            csvFile = presentations;
            break;
        case teachType:
            csvFile = teaching;
            break;
        case fundType:
            csvFile = teaching;
            break;
        default:
            /* This should not happen */
            csvFile = NULL;
            break;
    }

    /* If it's null return a empty vector */
    if (csvFile == NULL) {
        return errors;
    }

    for (int i = 0; i < csvFile->size(); i++)
    {
        vector<int> currUser;
        errors.push_back(currUser);


        for (int j = 0; j < csvFile->at(i).size(); j++) {
            if (csvFile->at(i).at(j).compare("") == 0) {
                errors.at(i).push_back(j);
            }
        }
    }


    return errors;
}

void myData::changeField(int myField, int userNumber, CSVType type, string newMsg)
{

    vector<vector<string>> *csvFile;

    switch(type) {

        case pubType:
            csvFile = publications;
            break;
        case presType:
            csvFile = presentations;
            break;
        case teachType:
            csvFile = teaching;
            break;
        case fundType:
            csvFile = teaching;
            break;
        default:
            /* This should not happen */
            csvFile = NULL;
            break;
    }

    if (csvFile == NULL) return;
    csvFile->at(userNumber).at(myField) = newMsg;
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

#if 0
::readPublications(publicationField myField, int entryNum)
{
    if (!isPublications()) return NULL;
    return &publications->at(myField).at[entryNum);
}
#endif

bool myData::createParsePublications(string filePath)
{
    publications = new vector<vector <string>> ();
    if (publications == NULL) return false;
    *publications = parsePublications(filePath);
    return true;
}

bool myData::createParseTeaching(string filePath)
{
    teaching = new vector<vector <string>> ();
    if (teaching == NULL) return false;
    *teaching = parseTeaching(filePath);
    return true;
}

bool myData::createParseFunding(string filePath)
{
    funding = new vector<vector <string>> ();
    if (funding == NULL) return false;
    *funding = parseFunding(filePath);
    return true;
}

bool myData::createParsePresentations(string filePath)
{
    presentations = new vector<vector <string>> ();
    if (presentations == NULL) return false;
    *presentations = parsePresentations(filePath);
    return true;
}

/*vector<vector<string >> parseTeaching(string filePath)
{

    vector<vector<string>> Data;
    return Data;

}
vector<vector<string >> parseFunding(string filePath)
{

    vector<vector<string>> Data ;
    return Data;
}
vector<vector<string >> parsePresentations(string filePath)
{

    vector<vector<string>> Data;
    return Data;
}*/

enum presentations_members {RecordInfo, LastModifiedUser, LastModifiedDate, ID, MemberName, PrimaryDomain, Date, Type, Area, Role, ActivityType, GeographicalScope, Host, Country, Province, City, \
                            NumberOfAttendees, MainAudience, Hours, TeachingEffectivenessScore, URL, Competitve, EducationPresentation, Remarks, FundingOrganization, Authorship, Title, RestOfCitation, \
                           PersonalRemuneration, OtherInfo};

vector<vector<string >> myData::parsePresentations(string filePath) {

    // If the file is in the same folder as your source code, then there is no need to include file path
        io::CSVReader<6, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
        in.read_header(io::ignore_extra_column, "Member Name",\
                                                "Primary Domain",\
                                                "Date",\
                                                "Type",\
                                                "Role",\
                                                "Title");

        /* Declare variables for each data within the row */
        string member_name,\
               primary_domain,\
               date,\
               type,\
               role,\
               title;

        /* Create data structure to store each row of infromation relative to their column header */
        vector<string>  vector_member_name,\
                        vector_primary_domain,\
                        vector_date,\
                        vector_type,\
                        vector_role,\
                        vector_title;

        /* Create data structure to store each vector of data within each column */
        vector<vector<string>> data;

        /* Loop until there are no more information within the CSV file */
        while (in.read_row(	member_name,\
                            primary_domain,\
                            date,\
                            type,\
                            role,\
                            title)){

                            /* Push each data within each column to their respected data structure */
                            vector_member_name.push_back(member_name);
                            vector_primary_domain.push_back(primary_domain);
                            vector_date.push_back(date);
                            vector_type.push_back(type);
                            vector_role.push_back(role);
                            vector_title.push_back(title);
    }

                            /* Push each vector of data into main data */
                            data.push_back(vector_member_name);
                            data.push_back(vector_date);
                            data.push_back(vector_type);
                            data.push_back(vector_primary_domain);
                            data.push_back(vector_role);
                            data.push_back(vector_title);

                            /* Return database */
                            return data;

    #if 0
    exit(EXIT_SUCCESS);
    #endif

}

vector<vector<string >> myData::parseTeaching(string filePath) {

    // If the file is in the same folder as your source code, then there is no need to include file path
        io::CSVReader<11, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
        in.read_header(io::ignore_extra_column, "Member Name",\
                                                "Primary Domain",\
                                                "Start Date",\
                                                "End Date",\
                                                "Program",\
                                                "Type of Course / Activity",\
                                                "Geographical Scope",\
                                                "Course / Activity",\
                                                "Hours per Teaching Session or Week",\
                                                "Number of Teaching Sessions or Weeks",\
                                                "Total Hours");

        /* Declare variables for each data within the row */
        string  member_name,\
                primary_domain,\
                start_date,\
                end_date,\
                program,\
                type_course_activity,\
                course_activity,\
                geographical_scope,
                hours_teaching_ses ,\
                nums_teaching_ses ,\
                total_hours;

        /* Create data structure to store each row of infromation relative to their column header */
        vector<string>	vector_member_name,\
                        vector_primary_domain,\
                        vector_start_date,\
                        vector_end_date,\
                        vector_program,\
                        vector_type_course_activity,\
                        vector_course_activity,\
                        vector_geographical_scope,\
                        vector_hours_teaching_ses ,\
                        vector_nums_teaching_ses ,\
                        vector_total_hours;

        /* Create data structure to store each vector of data within each column */
        vector<vector<string>> data;

        /* Loop until there are no more information within the CSV file */
        while (in.read_row(	member_name,\
                            primary_domain,\
                            start_date,\
                            end_date,\
                            program,\
                            type_course_activity,\
                            course_activity,\
                            geographical_scope,\
                            hours_teaching_ses ,\
                            nums_teaching_ses ,\
                            total_hours)){

                            /* Push each data within each column to their respected data structure */
                            vector_member_name.push_back(member_name);
    //                      vector_primary_domain.push_back(primary_domain);
                            vector_start_date.push_back(start_date);
    //                      vector_end_date.push_back(end_date);
                            vector_program.push_back(program);
                            vector_total_hours.push_back(total_hours);
    //                      vector_type_course_activity.push_back(type_course_activity);
    //                      vector_course_activity.push_back(course_activity);
    //                      vector_geographical_scope.push_back(geographical_scope);
    //                      vector_hours_teaching_ses.push_back(hours_teaching_ses);
                            vector_nums_teaching_ses.push_back(nums_teaching_ses);
    //
    }

                            /* Push each vector of data into main data */
                            data.push_back(vector_member_name);
    //                      data.push_back(vector_primary_domain);
                            data.push_back(vector_start_date);
    //                      data.push_back(vector_end_date);
                            data.push_back(vector_program);
    //                      data.push_back(vector_type_course_activity);
    //                      data.push_back(vector_course_activity);
    //                      data.push_back(vector_geographical_scope);
                            data.push_back(vector_total_hours);
    //                      data.push_back(vector_hours_teaching_ses) ;
                            data.push_back(vector_nums_teaching_ses) ;

                            /* Return database */
                            return data;

    #if 0
    exit(EXIT_SUCCESS);
    #endif

}

vector<vector<string >> myData::parsePublications(string filePath) {

    /* If the file is in the same folder as your source code, then there is no need to include file path */
    io::CSVReader<9, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
    /* Column header names */
    in.read_header(io::ignore_extra_column, "Member Name",\
                                            "Primary Domain",\
                                            "Publication Status",\
                                            "Type",\
                                            "Status Date",\
                                            "Role",\
                                            "Journal Name | Published In | Book Title | etc.",\
                                            "Author(s)",\
                                            "Title");

    /* Declare variables for each data within the row */
    string 	member_name,\
            primary_domain,\
            publication_status,\
            type,\
            status_date,\
            role,\
            journal_name_published_in_book_title,\
            authors,\
            title;

    /* Create data structure to store each row of infromation relative to their column header */
    vector<string>	vector_member_name,\
                    vector_primary_domain,\
                    vector_publication_status,\
                    vector_type,\
                    vector_status_date,\
                    vector_role,\
                    vector_journal_name_published_in_book_title,\
                    vector_authors,\
                    vector_title;

    /* Create data structure to store each vector of data within each column */
    vector<vector<string>> data;

    /* Loop until there are no more information within the CSV file */
    while (in.read_row(	member_name,\
                        primary_domain,\
                        publication_status,\
                        type,\
                        status_date,\
                        role,\
                        journal_name_published_in_book_title,\
                        authors,\
                        title)){

                        /* Push each vector of data into main data */
                        vector_member_name.push_back(member_name);
                        vector_primary_domain.push_back(primary_domain);
                        vector_publication_status.push_back(publication_status);
                        vector_type.push_back(type);
                        vector_status_date.push_back(status_date);
                        vector_role.push_back(role);
                        vector_journal_name_published_in_book_title.push_back(journal_name_published_in_book_title);
//                      vector_authors.push_back(authors);
                        vector_title.push_back(title);
}
                        /* Push each vector of data into main data */
                        data.push_back(vector_member_name);
                        data.push_back(vector_status_date);
//                      data.push_back(vector_primary_domain);
                        data.push_back(vector_publication_status);
                        data.push_back(vector_type);
                        data.push_back(vector_role);
                        data.push_back(vector_journal_name_published_in_book_title);
                        data.push_back(vector_authors);
                        data.push_back(vector_title);
                        /* Return database */
                        return data;

#if 0
    exit(EXIT_SUCCESS);
#endif

}

vector<vector<string >> myData::parseFunding(string filepath){

    // Read in CSV file, igoring specific special characters
    io::CSVReader<37, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filepath);
    in.read_header(io::ignore_extra_column, "Record Info",\
                                            "Last Modified User",\
                                            "Last Modified Date",\
                                            "ID",\
                                            "Member Name",\
                                            "Primary Domain",\
                                            "Start Date",\
                                            "End Date",\
                                            "Funding Type",\
                                            "Status",\
                                            "Peer Reviewed?",\
                                            "Industry Grant?",\
                                            "Role",\
                                            "Short Title",\
                                            "Title",\
                                            "Application Summary",\
                                            "Grant Purpose",\
                                            "Area",\
                                            "Principal Investigator",\
                                            "Co-Investigators",\
                                            "Grant and\/or Account #",\
                                            "Administered By",\
                                            "Funding Source",\
                                            "Project",\
                                            "Currency",\
                                            "Received Amount",\
                                            "Total Amount",\
                                            "Member Share",\
                                            "Monetary",\
                                            "Rpt",\
                                            "Hours Per Week",\
                                            "Personnel Paid",\
                                            "Rnw",\
                                            "Education Grant",\
                                            "Duplicate Reported",\
                                            "Other Details (doesn't print)",\
                                            "Year");

    /* Declare variables for each data within the row */
    string 	record_info,\
            last_modified_user,\
            last_modified_date,\
            id,\
            member_name,\
            primary_domain,\
            start_date,\
            end_date,\
            funding_type,\
            status,\
            peer_reviewed,\
            industry_grant,\
            role,\
            short_title,\
            title,\
            application_summary,\
            grant_purpose,\
            area,\
            principal_inv,\
            co_inv,\
            grant_account,\
            administered,\
            funding_source,\
            project,\
            currency,\
            rec_amount,\
            tot_amount,\
            member_share,\
            monetary,\
            rpt,\
            hours_per_week,\
            personnel_paid,\
            rnw,\
            education_grant,\
            duplicate_rep,\
            other_details,\
            year;

    /* Create data structure to store each row of infromation relative to their column header */
    vector<string>  vector_record_info,\
                    vector_last_modified_user,\
                    vector_last_modified_date,\
                    vector_id,\
                    vector_member_name,\
                    vector_primary_domain,\
                    vector_start_date,\
                    vector_end_date,\
                    vector_funding_type,\
                    vector_status,\
                    vector_peer_reviewed,\
                    vector_industry_grant,\
                    vector_role,\
                    vector_short_title,\
                    vector_title,\
                    vector_application_summary,\
                    vector_grant_purpose,\
                    vector_area,\
                    vector_principal_inv,\
                    vector_co_inv,\
                    vector_grant_account,\
                    vector_administered,\
                    vector_funding_source,\
                    vector_project,\
                    vector_currency,\
                    vector_rec_amount,\
                    vector_tot_amount,\
                    vector_member_share,\
                    vector_monetary,\
                    vector_rpt,\
                    vector_hours_per_week,\
                    vector_personnel_paid,\
                    vector_rnw,\
                    vector_education_grant,\
                    vector_duplicate_rep,\
                    vector_other_details,\
                    vector_year;

    /* Create data structure to store each vector of data within each column */
    vector<vector<string>> data;

    /* Loop until there are no more information within the CSV file */
    while (in.read_row(	record_info,\
                        last_modified_user,\
                        last_modified_date,\
                        id,\
                        member_name,\
                        primary_domain,\
                        start_date,\
                        end_date,\
                        funding_type,\
                        status,\
                        peer_reviewed,\
                        industry_grant,\
                        role,\
                        short_title,\
                        title,\
                        application_summary,\
                        grant_purpose,\
                        area,\
                        principal_inv,\
                        co_inv,\
                        grant_account,\
                        administered,\
                        funding_source,\
                        project,\
                        currency,\
                        rec_amount,\
                        tot_amount,\
                        member_share,\
                        monetary,\
                        rpt,\
                        hours_per_week,\
                        personnel_paid,\
                        rnw,\
                        education_grant,\
                        duplicate_rep,\
                        other_details,\
                        year)){

                        /* Push each vector of data into main data */
//                      vector_record_info.push_back(record_info);
//                      vector_last_modified_user.push_back(last_modified_user);
//                      vector_last_modified_date.push_back(last_modified_user);
//                      vector_id.push_back(id);
                        vector_member_name.push_back(member_name);
//                      vector_primary_domain.push_back(primary_domain);
                        vector_start_date.push_back(start_date);
//                      vector_end_date.push_back(end_date);
                        vector_funding_type.push_back(funding_type);
                        vector_status.push_back(status);
                        vector_peer_reviewed.push_back(peer_reviewed);
                        vector_industry_grant.push_back(industry_grant);
                        vector_role.push_back(role);
//                      vector_short_title.push_back(short_title);
                        vector_tot_amount.push_back(tot_amount);
                        vector_title.push_back(title);
//                      vector_application_summary.push_back(application_summary);
//                      vector_grant_purpose.push_back(grant_purpose);
//                      vector_area.push_back(area);
                        vector_principal_inv.push_back(principal_inv);
                        vector_co_inv.push_back(co_inv);
//                      vector_grant_account.push_back(grant_account);
//                      vector_administered.push_back(administered);
//                      vector_funding_source.push_back(funding_source);
//                      vector_project.push_back(project);
//                      vector_currency.push_back(currency);
//                      vector_rec_amount.push_back(rec_amount);
//                      vector_member_share.push_back(member_share);
//                      vector_monetary.push_back(monetary);
//                      vector_rpt.push_back(rpt);
//                      vector_hours_per_week.push_back(hours_per_week);
//                      vector_personnel_paid.push_back(personnel_paid);
//                      vector_rnw.push_back(rnw);
//                      vector_education_grant.push_back(education_grant);
//                      vector_duplicate_rep.push_back(duplicate_rep);
//                      vector_other_details.push_back(other_details);
//                      vector_year.push_back(year);
}
                        /* Push each vector of data into main data */
//                      data.push_back(vector_record_info);
//                      data.push_back(vector_last_modified_user);
//                      data.push_back(vector_last_modified_date);
//                      data.push_back(vector_id);
                        data.push_back(vector_member_name);
//                      data.push_back(vector_primary_domain);
                        data.push_back(vector_start_date);
//                      data.push_back(vector_end_date);
                        data.push_back(vector_funding_type);
                        data.push_back(vector_status);
                        data.push_back(vector_peer_reviewed);
                        data.push_back(vector_industry_grant);
                        data.push_back(vector_role);
                        data.push_back(vector_tot_amount);
//                      data.push_back(vector_short_title);
                        data.push_back(vector_title);
//                      data.push_back(vector_application_summary);
//                      data.push_back(vector_grant_purpose);
//                      data.push_back(vector_area);
//                      data.push_back(vector_principal_inv);
//                      data.push_back(vector_co_inv);
//                      data.push_back(vector_grant_account);
//                      data.push_back(vector_administered);
//                      data.push_back(vector_funding_source);
//                      data.push_back(vector_project);
//                      data.push_back(vector_currency);
//                      data.push_back(vector_rec_amount);
//                      data.push_back(vector_member_share);
//                      data.push_back(vector_monetary);
//                      data.push_back(vector_rpt);
//                      data.push_back(vector_hours_per_week);
//                      data.push_back(vector_personnel_paid);
//                      data.push_back(vector_rnw);
//                      data.push_back(vector_education_grant);
//                      data.push_back(vector_duplicate_rep);
//                      data.push_back(vector_other_details);
//                      data.push_back(vector_year);

                        /* Return database */
                        return data;

#if 0
    exit(EXIT_SUCCESS);
#endif

}
