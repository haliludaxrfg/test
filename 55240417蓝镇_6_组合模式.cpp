/*> 1. (论述题) 每个公司都有总部、多个分公司、多个办事处等，为上下级同构实体关系。  
   每个实体均有人力部、财务部、销售部等职能部门，不再有下级部门。分公司下面继续有子公司。。。。  
   总部需要快速了解总公司的：组织结构+实体职责展示。（两个多态函数，输出文字即可）  
（1）实现组合模式的设计，以及测试用main函数。  
（2）详细分类描述题目要求；  
（3）画出组合模式思想流程图，并给出必要的文字说明；  
（4）分析程序难点，并讨论解决问题思路；  
（5）不用多态实现应该如何实现功能？有何困难？  
（6）有何收获？  
   提交内容：程序代码（请删除可执行文件）+报告  
   文件命名规范：学号+姓名+题号+代码；学号+姓名+题号+报告*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Component {//
protected:
    std::string name;
public:
    Component(const std::string& name) : name(name) {}
    virtual ~Component() = default;
    virtual void displayStructure(int indent) const = 0;
    virtual void displayDuty() const = 0;
    virtual void add(Component* component) {
        throw std::runtime_error("Cannot add to a leaf");
    }
};

class Company : public Component {
private:
    std::vector<Component*> children;
    std::string duty;
public:
    Company(const std::string& name, const std::string& duty) 
        : Component(name), duty(duty) {}
    
    ~Company() override {
        for (auto child : children) {
            delete child;
        }
    }
    
    void displayStructure(int indent) const override {
        std::string indentation(indent * 2, ' ');
        std::cout << indentation << "公司: " << name << std::endl;
        for (const auto& child : children) {
            child->displayStructure(indent + 1);
        }
    }
    
    void displayDuty() const override {
        std::cout << "公司职责[" << name << "]: " << duty << std::endl;
        for (const auto& child : children) {
            child->displayDuty();
        }
    }
    
    void add(Component* component) override {
        children.push_back(component);
    }
};

class Department : public Component {
private:
    std::string duty;
public:
    Department(const std::string& name, const std::string& duty) 
        : Component(name), duty(duty) {}
    
    void displayStructure(int indent) const override {
        std::string indentation(indent * 2, ' ');
        std::cout << indentation << "部门: " << name << std::endl;
    }
    
    void displayDuty() const override {
        std::cout << "部门职责[" << name << "]: " << duty << std::endl;
    }
};

int main() {
    system("chcp 65001");
    Component* headquarters = new Company("总部", "统筹管理所有分支机构");
    
    // 添加总部部门
    headquarters->add(new Department("总部人力资源部", "全球人才招聘与管理"));
    headquarters->add(new Department("总部财务部", "全球资金管理"));
    
    Company* branch = new Company("华东分公司", "管理华东地区业务");
    branch->add(new Department("分公司人力资源部", "区域招聘与培训"));
    branch->add(new Department("分公司财务部", "区域预算管理"));
    
    Company* subCompany = new Company("上海子公司", "上海本地业务运营");
    subCompany->add(new Department("子公司销售部", "产品推广与销售"));
    subCompany->add(new Department("子公司客服部", "客户关系维护"));
    
    Company* office = new Company("浦东办事处", "浦东地区业务处理");
    office->add(new Department("办事处后勤部", "物资调配支持"));
    
    // 构建组织结构
    branch->add(subCompany);
    branch->add(office);
    headquarters->add(branch);
    
    std::cout << "===== 组织结构展示 =====" << std::endl;
    headquarters->displayStructure(0);
    
    std::cout << "\n===== 实体职责展示 =====" << std::endl;
    headquarters->displayDuty();
    
    delete headquarters;
    return 0;
}