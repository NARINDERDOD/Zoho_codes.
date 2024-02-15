lead_record = zoho.crm.getRecordById("Leads",record_id);
if(lead_record.getJSON("Move_To") == false)
{
	parent_email = lead_record.getJSON("Guardian_Email_Address");
	if(!parent_email.isNull())
	{
		searchrec = zoho.crm.searchRecords("Leads","Guardian_Email_Address:equals:" + parent_email,1,200,{"sort_by":"Created_Time","sort_order":"asc"});
		lead_id = "";
		if(searchrec.size() > 0)
		{
			lead_id = searchrec.get(0).getJSON("id");
			resp = zoho.crm.updateRecord("Leads",lead_id,{"Move_To":true});
		}
		for each  search_lead in searchrec
		{
			create_mp = Map();
			create_mp.put("Age",search_lead.getJSON("Student_Age"));
			create_mp.put("Email",search_lead.getJSON("Email"));
			create_mp.put("First_Name",search_lead.getJSON("First_Name"));
			create_mp.put("Guardian_Email_Address",search_lead.getJSON("Guardian_Email_Address"));
			create_mp.put("Guardian_Name",search_lead.getJSON("Guardian_Name"));
			create_mp.put("Last_Name",search_lead.getJSON("Last_Name"));
			create_mp.put("Leads",search_lead.getJSON("id"));
			create_mp.put("Mobile",search_lead.getJSON("Mobile"));
			create_mp.put("Student_First_Name",search_lead.getJSON("Student_Name"));
			create_mp.put("Student_Gender",search_lead.getJSON("Gender"));
			create_mp.put("Name",search_lead.getJSON("Student_ID"));
			create_mp.put("Student_Last_Name",search_lead.getJSON("Student_Last_Name"));
			create_mp.put("Student_Native_Language",search_lead.getJSON("Student_s_Native_Language"));
			create_mp.put("Total_Score",search_lead.getJSON("Total_Score"));
			result = zoho.crm.createRecord("Child_Details",create_mp,{"trigger":{"workflow"}});
			if(result.getJSON("id") != null)
			{
				info "record created";
				if(lead_id != search_lead.getJSON("id"))
				{
					deleteRecordMap = Map();
					deleteRecordMap = {"module":"Leads","id":search_lead.getJSON("id")};
					deleteResp = zoho.crm.invokeConnector("crm.delete",deleteRecordMap);
					info "delete record";
				}
			}
			else
			{
				info "failure " + search_lead.getJSON("id") + " : " + result;
			}
		}
	}
}