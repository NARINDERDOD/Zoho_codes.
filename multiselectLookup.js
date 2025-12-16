	   multiselectlookupMap = Map();

    // Add Multi-Select Lookup values Api names wil be from that module which is  you want to attach  
    multiselectlookupMap.put("Contacts", "6481782000008028162"); //id from where multiselect lookup is created 
    multiselectlookupMap.put("Leads","6481782000008288011"); //  id which recod need to attach 

    // Create record in X_Contacts
    create_response = zoho.crm.createRecord("X_Leads", multiselectlookupMap);

	
    info "Create Response : " + create_response;
	
