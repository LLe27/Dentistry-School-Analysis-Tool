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

myData::myData()
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

vector<vector<string >> myData::parsePresentations(string filePath) {

    // If the file is in the same folder as your source code, then there is no need to include file path
    io::CSVReader<30, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
    in.read_header(io::ignore_extra_column, "Record Info",\
                                            "Last Modified User",\
                                            "Last Modified Date",\
                                            "ID",\
                                            "Member Name",\
                                            "Primary Domain",\
                                            "Date",\
                                            "Type",\
                                            "Area",\
                                            "Role",\
                                            "Activity Type",\
                                            "Geographical Scope",\
                                            "Host",\
                                            "Country",\
                                            "Province",\
                                            "City",\
                                            "Number of Attendees",\
                                            "Main Audience",\
                                            "Hours",\
                                            "Teaching Effectiveness Score",\
                                            "URL",\
                                            "Competitive",\
                                            "Education Presentation",\
                                            "Remarks",\
                                            "Funding Organization",\
                                            "Authorship",\
                                            "Title",\
                                            "Rest of Citation",\
                                            "Personal Remuneration",\
                                            "Other Details (doesn't print)");

    string record_info,\
           last_modified_user,\
           last_modified_date,\
           id,\
           member_name,\
           primary_domain,\
           date,\
           type,\
           area,\
           role,\
           activity_type,\
           geographical_scope,\
           host,\
           country,\
           province,\
           city,\
           number_attendees,\
           main_audience,\
           hours,\
           teaching_effect_score,\
           url,\
           competitive,\
           education_presentation,\
           remarks,\
           funding_organization,\
           authorship,\
           title,\
           rest_citation,\
           personal_remuneration,\
           other_details;



    vector<string>  vector_record_info,\
                    vector_last_modified_user,\
                    vector_last_modified_date,\
                    vector_id,\
                    vector_member_name,\
                    vector_primary_domain,\
                    vector_date,\
                    vector_type,\
                    vector_area,\
                    vector_role,\
                    vector_activity_type,\
                    vector_geographical_scope,\
                    vector_host,\
                    vector_country,\
                    vector_province,\
                    vector_city,\
                    vector_number_attendees,\
                    vector_main_audience,\
                    vector_hours,\
                    vector_teaching_effect_score,\
                    vector_url,\
                    vector_competitive,\
                    vector_education_presentation,\
                    vector_remarks,\
                    vector_funding_organization,\
                    vector_authorship,\
                    vector_title,\
                    vector_rest_citation,\
                    vector_personal_remuneration,\
                    vector_other_details;


    vector<vector<string>> data;

    while (in.read_row(	record_info,\
                        last_modified_user,\
                        last_modified_date,\
                        id,\
                        member_name,\
                        primary_domain,\
                        date,\
                        type,\
                        area,\
                        role,\
                        activity_type,\
                        geographical_scope,\
                        host,\
                        country,\
                        province,\
                        city,\
                        number_attendees,\
                        main_audience,\
                        hours,\
                        teaching_effect_score,\
                        url,\
                        competitive,\
                        education_presentation,\
                        remarks,\
                        funding_organization,\
                        authorship,\
                        title,\
                        rest_citation,\
                        personal_remuneration,\
                        other_details)){



                        vector_record_info.push_back(record_info);
                        vector_last_modified_user.push_back(last_modified_user);
                        vector_last_modified_date.push_back(last_modified_date);
                        vector_id.push_back(id);
                        vector_member_name.push_back(member_name);
                        vector_primary_domain.push_back(primary_domain);
                        vector_date.push_back(date);
                        vector_type.push_back(type);
                        vector_area.push_back(area);
                        vector_role.push_back(role);
                        vector_activity_type.push_back(activity_type);
                        vector_geographical_scope.push_back(geographical_scope);
                        vector_host.push_back(host);
                        vector_country.push_back(country);
                        vector_province.push_back(province);
                        vector_city.push_back(city);
                        vector_number_attendees.push_back(number_attendees);
                        vector_main_audience.push_back(main_audience);
                        vector_hours.push_back(hours);
                        vector_teaching_effect_score.push_back(teaching_effect_score);
                        vector_url.push_back(url);
                        vector_competitive.push_back(competitive);
                        vector_education_presentation.push_back(education_presentation);
                        vector_remarks.push_back(remarks);
                        vector_funding_organization.push_back(funding_organization);
                        vector_authorship.push_back(authorship);
                        vector_title.push_back(title);
                        vector_rest_citation.push_back(rest_citation);
                        vector_personal_remuneration.push_back(personal_remuneration);
                        vector_other_details.push_back(other_details);

}
    //data.push_back(vector_record_info);

    data.push_back(vector_record_info);
                    data.push_back(vector_record_info);
                    data.push_back(vector_last_modified_user);
                    data.push_back(vector_last_modified_date);
                    data.push_back(vector_id);
                    data.push_back(vector_member_name);
                    data.push_back(vector_primary_domain);
                    data.push_back(vector_date);
                    data.push_back(vector_type);
                    data.push_back(vector_area);
                    data.push_back(vector_role);
                    data.push_back(vector_activity_type);
                    data.push_back(vector_geographical_scope);
                    data.push_back(vector_host);
                    data.push_back(vector_country);
                    data.push_back(vector_province);
                    data.push_back(vector_city);
                    data.push_back(vector_number_attendees);
                    data.push_back(vector_main_audience);
                    data.push_back(vector_hours);
                    data.push_back(vector_teaching_effect_score);
                    data.push_back(vector_url);
                    data.push_back(vector_competitive);
                    data.push_back(vector_education_presentation);
                    data.push_back(vector_remarks);
                    data.push_back(vector_funding_organization);
                    data.push_back(vector_authorship);
                    data.push_back(vector_title);
                    data.push_back(vector_rest_citation);
                    data.push_back(vector_personal_remuneration);
                    data.push_back(vector_other_details);



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


vector<vector<string >> myData::parseTeaching(string filePath) {

    // If the file is in the same folder as your source code, then there is no need to include file path
    io::CSVReader<28, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
    in.read_header(io::ignore_extra_column, "Record Info",\
                                            "Last Modified User",\
                                            "Last Modified Date",\
                                            "ID",\
                                            "Member Name",\
                                            "Primary Domain",\
                                            "Start Date",\
                                            "End Date",\
                                            "Program",\
                                            "Type of Course / Activity",\
                                            "Course / Activity",\
                                            "Geographical Scope",\
                                            "Institution / Organization",\
                                            "Faculty",\
                                            "Department",\
                                            "Division",\
                                            "Location",\
                                            "Hours per Teaching Session or Week",\
                                            "Number of Teaching Sessions or Weeks",\
                                            "Faculty Member Additional Comments ",\
                                            "Number Of Trainees",\
                                            "Student Name(s)",\
                                            "Initial Lecture",\
                                            "Faculty Development",\
                                            "Stipend Received",\
                                            "Comment",\
                                            "Other Details (doesn't print)",\
                                            "Total Hours");

    string 	record_info,\
            last_modified_user,\
            last_modified_date,\
            id,\
            member_name,\
            primary_domain,\
            start_date,\
            end_date,\
            program,\
            type_course_activity,\
            course_activity,\
            geographical_scope,\
            institution_organization,\
            faculty,\
            department,\
            division,\
            location,\
            hours_teaching_ses ,\
            nums_teaching_ses ,\
            faculty_member_add ,\
            number_of_rainees,\
            student_name,\
            initial_lecture,\
            faculty_development,\
            stipend_received,\
            comment,\
            other_details,\
            total_hours;






    vector<string>	vector_record_info,\
                    vector_last_modified_user,\
                    vector_last_modified_date,\
                    vector_id,\
                    vector_member_name,\
                    vector_primary_domain,\
                    vector_start_date,\
                    vector_end_date,\
                    vector_program,\
                    vector_type_course_activity,\
                    vector_course_activity,\
                    vector_geographical_scope,\
                    vector_institution_organization,\
                    vector_faculty,\
                    vector_department,\
                    vector_division,\
                    vector_location,\
                    vector_hours_teaching_ses ,\
                    vector_nums_teaching_ses ,\
                    vector_faculty_member_add ,\
                    vector_number_of_rainees,\
                    vector_student_name,\
                    vector_initial_lecture,\
                    vector_faculty_development,\
                    vector_stipend_received,\
                    vector_comment,\
                    vector_other_details,\
                    vector_total_hours;



    vector<vector<string>> data;

    while (in.read_row(	record_info,\
                        last_modified_user,\
                        last_modified_date,\
                        id,\
                        member_name,\
                        primary_domain,\
                        start_date,\
                        end_date,\
                        program,\
                        type_course_activity,\
                        course_activity,\
                        geographical_scope,\
                        institution_organization,\
                        faculty,\
                        department,\
                        division,\
                        location,\
                        hours_teaching_ses ,\
                        nums_teaching_ses ,\
                        faculty_member_add ,\
                        number_of_rainees,\
                        student_name,\
                        initial_lecture,\
                        faculty_development,\
                        stipend_received,\
                        comment,\
                        other_details,\
                        total_hours)){


                            vector_record_info.push_back(record_info);
                            vector_last_modified_user.push_back(last_modified_user);
                            vector_last_modified_date.push_back(last_modified_date);
                            vector_id.push_back(id);
                            vector_member_name.push_back(member_name);
                            vector_primary_domain.push_back(primary_domain);
                            vector_start_date.push_back(start_date);
                            vector_end_date.push_back(end_date);
                            vector_program.push_back(program);
                            vector_type_course_activity.push_back(type_course_activity);
                            vector_course_activity.push_back(course_activity);
                            vector_geographical_scope.push_back(geographical_scope);
                            vector_institution_organization.push_back(institution_organization);
                            vector_faculty.push_back(faculty);
                            vector_department.push_back(department);
                            vector_division.push_back(division);
                            vector_location.push_back(location);
                            vector_hours_teaching_ses.push_back(hours_teaching_ses);
                            vector_nums_teaching_ses.push_back(nums_teaching_ses);
                            vector_faculty_member_add.push_back(faculty_member_add);
                            vector_number_of_rainees.push_back(number_of_rainees);
                            vector_student_name.push_back(student_name);
                            vector_initial_lecture.push_back(initial_lecture);
                            vector_faculty_development.push_back(faculty_development);
                            vector_stipend_received.push_back(stipend_received);
                            vector_comment.push_back(comment);
                            vector_other_details.push_back(other_details);
                            vector_total_hours.push_back(total_hours);
    }


//data.push_back(vector_record_info);

                        data.push_back(vector_record_info);
                        data.push_back(vector_last_modified_user);
                        data.push_back(vector_last_modified_date);
                        data.push_back(vector_id);
                        data.push_back(vector_member_name);
                        data.push_back(vector_primary_domain);
                        data.push_back(vector_start_date);
                        data.push_back(vector_end_date);
                        data.push_back(vector_program);
                        data.push_back(vector_type_course_activity);
                        data.push_back(vector_course_activity);
                        data.push_back(vector_geographical_scope);
                        data.push_back(vector_institution_organization);
                        data.push_back(vector_faculty);
                        data.push_back(vector_department);
                        data.push_back(vector_division);
                        data.push_back(vector_location);
                        data.push_back(vector_hours_teaching_ses) ;
                        data.push_back(vector_nums_teaching_ses) ;
                        data.push_back(vector_faculty_member_add);
                        data.push_back(vector_number_of_rainees);
                        data.push_back(vector_student_name);
                        data.push_back(vector_initial_lecture);
                        data.push_back(vector_faculty_development);
                        data.push_back(vector_stipend_received);
                        data.push_back(vector_comment);
                        data.push_back(vector_other_details);
                        data.push_back(vector_total_hours);



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


vector<vector<string >> myData::parsePublications(string filePath) {

    // If the file is in the same folder as your source code, then there is no need to include file path
    io::CSVReader<44, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in(filePath);
	in.read_header(io::ignore_extra_column, "Record Info",\
											"Last Modified User",\
											"Last Modified Date",\
											"ID",\
											"Member Name",\
											"Primary Domain",\
											"Publication Status",\
											"Pubmed Article ID",\
											"Type",\
											"Area",\
											"Status Date",\
											"Role",\
											"Peer Reviewed?",\
											"Number Of Contributors",\
											"Author #",\
											"Journal Name | Published In | Book Title | etc.",\
											"Volume",\
											"Issue",\
											"Page Range",\
											"DOI",\
											"Website",\
											"Number of Citations",\
											"Journal Impact Factor",\
											"International",\
											"Publication Country",\
											"Publication Province",\
											"Publication City",\
											"Publisher",\
											"Level of Contribution",\
											"Is Presentation?",\
											"Impact",\
											"Open Access?",\
											"Personal Remuneration",\
											"Is Trainee?",\
											"Trainee Details",\
											"Is Most Significant Publication?",\
											"Most Significant Contribution Details",\
											"Education Publication",\
											"Other Details (doesn't print)",\
											"Author(s)",\
											"Title",\
											"Rest of Citation",\
											"ISBNISSN",\
											"Funding Reference Number");
	
	string 	record_info,\
			last_modified_user,\
			last_modified_date,\
			id,\
			member_name,\
			primary_domain,\
			publication_status,\
			pubmed_article_id,\
			type,\
			area,\
			status_date,\
			role,\
			peer_reviewed,\
			number_of_contributors,\
			author_number,\
			journal_name_published_in_book_title,\
			volume,\
			issue,\
			page_range,\
			doi,\
			website,\
			number_of_citations,\
			journal_impact_factor,\
			international,\
			publication_country,\
			publication_province,\
			publication_city,\
			publisher,\
			level_of_contribution,\
			is_presentation,\
			impact,\
			open_access,\
			personal_remuneration,\
			is_trainee,\
			trainee_details,\
			is_most_significant_publication,\
			most_significant_contribution_details,\
			education_publication,\
			other_details,\
			authors,\
			title,\
			rest_of_citation,\
			isbnissn,\
			funding_reference_number;
			
	vector<string>	vector_record_info,\
					vector_last_modified_user,\
					vector_last_modified_date,\
					vector_id,\
					vector_member_name,\
					vector_primary_domain,\
					vector_publication_status,\
					vector_pubmed_article_id,\
					vector_type,\
					vector_area,\
					vector_status_date,\
					vector_role,\
					vector_peer_reviewed,\
					vector_number_of_contributors,\
					vector_author_number,\
					vector_journal_name_published_in_book_title,\
					vector_volume,\
					vector_issue,\
					vector_page_range,\
					vector_doi,\
					vector_website,\
					vector_number_of_citations,\
					vector_journal_impact_factor,\
					vector_international,\
					vector_publication_country,\
					vector_publication_province,\
					vector_publication_city,\
					vector_publisher,\
					vector_level_of_contribution,\
					vector_is_presentation,\
					vector_impact,\
					vector_open_access,\
					vector_personal_remuneration,\
					vector_is_trainee,\
					vector_trainee_details,\
					vector_is_most_significant_publication,\
					vector_most_significant_contribution_details,\
					vector_education_publication,\
					vector_other_details,\
					vector_authors,\
					vector_title,\
					vector_rest_of_citation,\
					vector_isbnissn,\
					vector_funding_reference_number;
			
	vector<vector<string>> data;
	
	while (in.read_row(	record_info,\
						last_modified_user,\
						last_modified_date,\
						id,\
						member_name,\
						primary_domain,\
						publication_status,\
						pubmed_article_id,\
						type,\
						area,\
						status_date,\
						role,\
						peer_reviewed,\
						number_of_contributors,\
						author_number,\
						journal_name_published_in_book_title,\
						volume,\
						issue,\
						page_range,\
						doi,\
						website,\
						number_of_citations,\
						journal_impact_factor,\
						international,\
						publication_country,\
						publication_province,\
						publication_city,\
						publisher,\
						level_of_contribution,\
						is_presentation,\
						impact,\
						open_access,\
						personal_remuneration,\
						is_trainee,\
						trainee_details,\
						is_most_significant_publication,\
						most_significant_contribution_details,\
						education_publication,\
						other_details,\
						authors,\
						title,\
						rest_of_citation,\
						isbnissn,\
						funding_reference_number)){
	
		//vector_record_info.push_back(record_info);
		//vector_last_modified_user.push_back(last_modified_user);
		//vector_last_modified_date.push_back(last_modified_date);
		//vector_id.push_back(id);
		vector_member_name.push_back(member_name);
		vector_primary_domain.push_back(primary_domain);
		vector_publication_status.push_back(publication_status);
		//vector_pubmed_article_id.push_back(pubmed_article_id);
		vector_type.push_back(type);
		//vector_area.push_back(area);
		vector_status_date.push_back(status_date);
		vector_role.push_back(role);
		//vector_peer_reviewed.push_back(peer_reviewed);
		//vector_number_of_contributors.push_back(number_of_contributers);
		//vector_author_number.push_back(author_number);
		vector_journal_name_published_in_book_title.push_back(journal_name_published_in_book_title);
		//vector_volume.push_back(volume);
		//vector_issue.push_back(issue);
		//vector_page_range.push_back(page_range);
		//vector_doi.push_back(doi);
		//vector_website.push_back(website);
		//vector_number_of_citations.push_back(number_of_citations);
		//vector_journal_impact_factor.push_back(journal_impact_factor);
		//vector_international.push_back(international);
		//vector_publication_country.push_back(publication_country);
		//vector_publication_province.push_back(publication_province);
		//vector_publication_city.push_back(publication_city);
		//vector_publisher.push_back(publisher);
		//vector_level_of_contribution.push_back(level_of_contribution);
		//vector_is_presentation.push_back(is_presentation);
		//vector_impact.push_back(impact);
		//vector_open_access.push_back(open_access);
		//vector_personal_remuneration.push_back(personal_remuneration);
		//vector_is_trainee.push_back(trainee);
		//vector_trainee_details.push_back(trainee_details);
		//vector_is_most_significant_publication.push_back(is_most_significant_publication);
		//vector_most_significant_contribution_details.push_back(most_significant_contribution_details);
		//vector_education_publication.push_back(education_publication);
		//vector_other_details.push_back(other_details);
		vector_authors.push_back(authors);
		vector_title.push_back(title);
		//vector_rest_of_citation.push_back(rest_of_citation);
		//vector_isbnissn.push_back(ibsnissn);
		//vector_funding_reference_number.push_back(funding_reference_number);
	
	}
	
	//data.push_back(vector_record_info);
	//data.push_back(vector_last_modified_user);
	//data.push_back(vector_last_modified_date);
	//data.push_back(vector_id);
	data.push_back(vector_member_name);
	data.push_back(vector_status_date);
	//////data.push_back(vector_primary_domain);
	data.push_back(vector_publication_status);
	//data.push_back(vector_pubmed_article_id);
	data.push_back(vector_type);
	//data.push_back(vector_area);
	data.push_back(vector_role);
	//data.push_back(vector_peer_reviewed);
	//data.push_back(vector_number_of_contributors);
	//data.push_back(vector_author_number);
	data.push_back(vector_journal_name_published_in_book_title);
	//data.push_back(vector_volume);
	//data.push_back(vector_issue);
	//data.push_back(vector_page_range);
	//data.push_back(vector_doi);
	//data.push_back(vector_website);
	//data.push_back(vector_number_of_citations);
	//data.push_back(vector_journal_impact_factor);
	//data.push_back(vector_international);
	//data.push_back(vector_publication_country);
	//data.push_back(vector_publication_province);
	//data.push_back(vector_publication_city);
	//data.push_back(vector_publisher);
	//data.push_back(vector_level_of_contribution);
	//data.push_back(vector_is_presentation);
	//data.push_back(vector_impact);
	//data.push_back(vector_open_access);
	//data.push_back(vector_personal_remuneration);
	//data.push_back(vector_is_trainee);
	//data.push_back(vector_trainee_details);
	//data.push_back(vector_is_most_significant_publication);
	//data.push_back(vector_most_significant_contribution_details);
	//data.push_back(vector_education_publication);
	//data.push_back(vector_other_details);
	data.push_back(vector_authors);
	data.push_back(vector_title);
	//data.push_back(vector_rest_of_citation);
	//data.push_back(vector_isbnissn);
	//data.push_back(vector_funding_reference_number);

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