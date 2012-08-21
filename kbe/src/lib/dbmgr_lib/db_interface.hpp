/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __KBE_DB_INTERFACE__
#define __KBE_DB_INTERFACE__

#include "cstdkbe/cstdkbe.hpp"
#include "cstdkbe/singleton.hpp"
#include "helper/debug_helper.hpp"

namespace KBEngine { 

class DBUtil;

/*
	数据库接口
*/
class DBInterface
{
public:
	friend class DBUtil;
	DBInterface(){};
	virtual ~DBInterface(){};

	/**
		与某个数据库关联
	*/
	virtual bool attach(const char* databaseName) = 0;
	virtual bool detach() = 0;

	/**
		查询表
	*/
	virtual bool query(const char* strCommand) = 0;

	/**
		返回这个接口的描述
	*/
	virtual const char* c_str() = 0;

	/** 
		获取错误
	*/
	virtual const char* getstrerror() = 0;

	/** 
		获取错误编号
	*/
	virtual int getlasterror() = 0;
protected:
	char db_type_[MAX_BUF];									// 数据库的类别
	uint32 db_port_;										// 数据库的端口
	char db_ip_[MAX_IP];									// 数据库的ip地址
	char db_username_[MAX_BUF];								// 数据库的用户名
	char db_password_[MAX_BUF];								// 数据库的密码
	char db_name_[MAX_BUF];									// 数据库名
	uint16 db_numConnections_;								// 数据库最大连接
};

/*
	数据库操作单元
*/
class DBUtil : public Singleton<DBUtil>
{
public:
	DBUtil();
	~DBUtil();

	static DBInterface* create(const char* dbtype, const char* ip, uint32 port, const char* db_username, 
		const char* db_password, uint16 db_numConnections);
private:

};

}

#endif // __KBE_DB_INTERFACE__
