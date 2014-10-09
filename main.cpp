
#include <cassert>
#include <fstream>

#include <boost/variant.hpp>
#include <boost/serialization/variant.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


typedef boost::variant < uint32_t, float > t_data;


int main()
{
	t_data var00(0.4f);
	t_data var01((uint32_t)57);

	t_data var02, var03;

	{
		std::ofstream ofs("filename");
		boost::archive::text_oarchive oa(ofs);

		boost::serialization::serialize(oa, var00, 0);
		boost::serialization::serialize(oa, var01, 0);
	}

	{
		std::ifstream ifs("filename");
		boost::archive::text_iarchive ia(ifs);

		boost::serialization::serialize(ia, var02, 0);
		boost::serialization::serialize(ia, var03, 0);
	}

	assert(var00 == var02);
	assert(var01 == var03);

	std::cout << "done" << std::endl;

	return 0;
}
