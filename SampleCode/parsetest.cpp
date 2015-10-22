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
#include "csv.h"


int main(int argc, const char * argv[]) {

    io::CSVReader<44, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>> in("/Users/Long/Desktop/Publications_sample.csv");
    int count=0;
    
    // cehck if column headings exists
    in.read_header(io::ignore_extra_column, "IRecord Info", "Last Modified User", "Last Modified Date", "ID", "Member Name", "Primary Domain", "Publication Status", "Pubmed Article ID", "Type", "Area", "Status Date", "Role", "Peer Reviewed?", "Number Of Contributors", "Author #", "Journal Name | Published In | Book Title | etc.", "Volume", "Issue", "Page Range", "DOI", "Website", "Number of Citations", "Journal Impact Factor", "International", "Publication Country", "Publication Province", "Publication City", "Publisher", "Level of Contribution", "Is Presentation?", "Impact", "Open Access?", "Personal Remuneration", "Is Trainee?", "Trainee Details", "Is Most Significant Publication?", "Most Significant Contribution Details", "Education Publication", "Other Details (doesn't print)", "Author(s)", "Title", "Rest of Citation", "ISBNISSN", "Funding Reference Number");
    
    // attributes
    std::string ir_i, lmu, lmd, id, m_name, p_domain, p_status, pa_id, p_type, area, s_date, role, p_rev, num_contri, author, jn_pi_bt, vol, issue, p_range, doi, web, num_cita, jif, inter, p_country, p_prov, p_city, pbsr, loc, is_pres, impact, open_a, p_remu, train, t_det, imsp, mscd, e_pub, o_det, auths, title, roc, isbn, frn;
    
    
    //  print each attribute and their value in each row
    while (in.read_row(ir_i, lmu, lmd, id, m_name, p_domain, p_status, pa_id, p_type, area, s_date, role, p_rev, num_contri, author, jn_pi_bt, vol, issue, p_range, doi, web, num_cita, jif, inter, p_country, p_prov, p_city, pbsr, loc, is_pres, impact, open_a, p_remu, train, t_det, imsp, mscd, e_pub, o_det, auths, title, roc, isbn, frn)) {
        printf("%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,  %s\n ", ir_i.c_str(), lmu.c_str(), lmd.c_str(), id.c_str(), m_name.c_str(), p_domain.c_str(), p_status.c_str(), pa_id.c_str(), p_type.c_str(), area.c_str(), s_date.c_str(), role.c_str(), p_rev.c_str(), num_contri.c_str(), author.c_str(), jn_pi_bt.c_str(), vol.c_str(), issue.c_str(), p_range.c_str(), doi.c_str(), web.c_str(), num_cita.c_str(), jif.c_str(), inter.c_str(), p_country.c_str(), p_prov.c_str(), p_city.c_str(), pbsr.c_str(), loc.c_str(), is_pres.c_str(), impact.c_str(), open_a.c_str(), p_remu.c_str(), train.c_str(), t_det.c_str(), imsp.c_str(), mscd.c_str(), e_pub.c_str(), o_det.c_str(), auths.c_str(), title.c_str(), roc.c_str(), isbn.c_str(), frn.c_str());
    }
    
    printf("%d\n", count);
    
    
    
    
    
    exit(EXIT_SUCCESS);
}
