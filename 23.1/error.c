/******************************************************************************
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE. This file and program are licensed    *
 * under the GNU Lesser General Public License Version 3, 29 June 2007.       *
 * The complete license can be accessed from the following location:          *
 * http://opensource.org/licenses/lgpl-3.0.html                               *
 *                                                                            *
 * Author: Yun Li (yunli.open@gmail.com)                                      *
 *   Date: 09/11/2009                                                         *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
  REVISION HISTORY
  ================
  
  Date     Version  Name          Description
  -------- -------  ------------  --------------------------------------------

  -------- -------  ------------  --------------------------------------------

 ******************************************************************************/

#include "primitive.h"
#include "error.h"
#include "module.h"

static struct errstr_t {
    int available_;                    // 标记是否存在数组
    int last_error_;                   // 模块内的最后一个错误号
    const char **error_array_;         // 错误名数组
} g_errstr_array [MODULE_COUNT];

#include "errstr.def"

// 错误名查找函数
const char *errstr (error_t _error)
{
    static bool initialized = false;
    module_t module_id = MODULE_ID (_error);
    int error_id = MODULE_ERROR (_error);

	// 将自动生成的错误名数组映射到对应的模块ID
    if (!initialized) {
        errstr_init ();
        initialized = true;
    }
    
	// 防御性编程
    if (0 == _error) {
        return "SUCCESS";
    }

    if (_error > 0) {
        return "ERROR_ERRSTR_NOT_NEGATIVE";
    }
    
    if (module_id > MODULE_LAST) {
        return "ERROR_ERRSTR_INVALID_MODULEID";
    }
    
    if (!g_errstr_array [module_id].available_) {
        return "ERROR_ERRSTR_NOT_AVAILABLE";
    }
    
    if (error_id > g_errstr_array [module_id].last_error_) {
        return "ERROR_ERRSTR_OUT_OF_LAST";
    }
    
	// 检测字符数组的地址是不是为0
    if (0 == g_errstr_array [module_id].error_array_ [error_id]) {
        return "ERROR_ERRSTR_NOT_DEFINED";
    }

	// 返回错误名
    return g_errstr_array [module_id].error_array_ [error_id];
}

