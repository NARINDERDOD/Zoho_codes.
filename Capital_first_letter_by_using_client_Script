/** 
 * log("sample logging statement") --> can be used to print any data in the browser console.
 * ZDK module can be used for customising the UI and other functionalities.
 * return false to prevent <SAVE> action
**/

var Child_Details = ZDK.Apps.CRM.Child_Details.fetchById($Page.record_id);

var S_f_n, S_l_n, G_f_n, G_l_n;

S_f_n = Child_Details.Student_First_Name;
S_l_n = Child_Details.Student_Last_Name;
G_f_n = Child_Details.First_Name;
G_l_n = Child_Details.Last_Name;


if (S_f_n != null)
{
let first_sf_n = S_f_n.substring(0, 1);
let firstStringUpper_s_f_n = first_sf_n.toUpperCase();
let S_first_name = S_f_n.replace(first_sf_n, firstStringUpper_s_f_n);
var new_s_first_name_ = S_first_name.toString();

} else {

    log(JSON.stringify("Student First Name " + S_f_n ));
}

if (S_l_n != null)
{
let first_sln = S_l_n.substring(0, 1);
let firstStringUpper_s_l_n = first_sln.toUpperCase();
let S_last_name = S_l_n.replace(first_sln, firstStringUpper_s_l_n);
var new_s_last_name_ = S_last_name.toString();
} else
{
    log(JSON.stringify("Student Last Name " + S_l_n ));

}


if (G_f_n !=null)
{
let first_gfn = G_f_n.substring(0, 1);
let firstStringUpper_g_f_n = first_gfn.toUpperCase();
let G_first_name = G_f_n.replace(first_gfn, firstStringUpper_g_f_n);
var new_g_first_name_ = G_first_name.toString();
} else
{
    log(JSON.stringify("G First Name " + G_f_n ));


}


if (G_l_n != null)
{
let first_gln = G_l_n.substring(0, 1);
let firstStringUpper_g_l_n = first_gln.toUpperCase();
let G_last_name = G_l_n.replace(first_gln, firstStringUpper_g_l_n);
var new_g_last_name_ = G_last_name.toString();
} else {

    log(JSON.stringify("G Last Name " + G_f_n ));

    
}


log(JSON.stringify(new_s_first_name_));
log(JSON.stringify(new_s_last_name_));
log(JSON.stringify(new_g_first_name_));
log(JSON.stringify(new_g_last_name_));

 
var Child_Details = ZDK.Apps.CRM.Child_Details.fetchById($Page.record_id);
Child_Details.Student_First_Name = new_s_first_name_;
Child_Details.Student_Last_Name = new_s_last_name_;
Child_Details.First_Name = new_g_first_name_;
Child_Details.Last_Name = new_g_last_name_;
var response = Child_Details.update();
var response = ZDK.Apps.CRM.Leads.update(leadsArray);


log(response);


