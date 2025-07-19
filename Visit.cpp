#include "Visit.h"

int Visit::dateGenerator = 17;


    // Constructor
	Visit::Visit(const string& arrivalDate, const string& reasonForVisit, Department& visitDepartment, Doctor& responsibleStaffMember)
		:reasonForVisit(reasonForVisit), visitDepartment(visitDepartment), responsibleStaffMember(responsibleStaffMember){}

	// Copy Constructor
	Visit::Visit(const Visit& other) 
		:reasonForVisit(other.reasonForVisit), visitDepartment(other.visitDepartment), responsibleStaffMember(other.responsibleStaffMember){}

	// Destructor
	Visit::~Visit(){}

	//////////////set/////////////
	void Visit::setArrivalDate(const string& arrivalDate)
	{
		this->arrivalDate = arrivalDate;
	}


	bool Visit::setReasonForVisit(const string& reasonForVisit)
	{
		this->reasonForVisit = reasonForVisit;
		return true;
		
	}

	///////////////print//////////
	const void Visit::print() const
	{
		cout << "Arrival date: " << arrivalDate
			<< ", Reason for visit: " << reasonForVisit
			<< ", Department: " << visitDepartment.getName()
			<< ", Responsible Doctor: " << responsibleStaffMember.getName() << "\n" << endl;
	}
