#pragma once

class TypeDescriptor
{
public:
	TypeDescriptor(const char* name, const size_t size) : m_Name(name), m_Size(size) {}
	virtual ~TypeDescriptor() {}
	virtual std::string GetTypeName() const { return m_Name; }
	virtual void Dump(const void* obj, const size_t indentLevel = 0) const = 0;

private:
	const char* m_Name;
	size_t m_Size;
};

struct TypeDescriptor_Struct : TypeDescriptor
{
	struct Member
	{
		const char* m_Name;
		size_t m_Offset;
		TypeDescriptor* m_Type;
	};

	std::vector<Member> m_Members;

	TypeDescriptor_Struct(void(*init)(TypeDescriptor_Struct*)) : TypeDescriptor(nullptr, 0)
	{
		init(this);
	}

	TypeDescriptor_Struct(const char* name, size_t size, const std::initializer_list<Member>& init) : TypeDescriptor(name, size), m_Members(init) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override
	{
		std::cout << m_Name << " {" << std::endl;
		for (const Member& member : m_Members)
		{
			std::cout << std::string(4 * (indentLevel + 1), ' ') << member.name << " = ";
			member.m_Type->Dump((char*)obj + member.m_Offset, indentLevel + 1);
			std::cout << std::endl;
		}

		std::cout << std::string(4*indentLevel, ' ') << "}";
	}
};

struct TypeDescriptor_STDVector : TypeDescriptor
{
	TypeDescriptor* m_ItemTypeDesc;
	size_t(*GetSize)(const void*);
	const void* (*GetItem)(const void*, size_t)l

		template<typename ItemType>
	TypeDescriptor_STDVector(ItemType*) : TypeDescriptor("std::vector<>", sizeof(std::vector<ItemType>)), m_ItemTypeDesc(TypeResolver<ItemType>::GetTypeDescriptor())
	{
		GetSize = [](const void* voidVectorPtr) -> size_t
		{
			const auto& vec = *(static_cast<const std::vector<ItemType>*>(voidVectorPtr));
			return vec.size();
		};

		GetItem = [](const void* voidVecPtr, size_t index) -> const void*
		{
			const auto& vec = *(static_cast<const std::vector<ItemType>*>(voidVecPtr));
			return &vec[index];
		};
	}

	virtual std::string GetTypeName() const override
	{
		return std::string("std::vector<") + m_ItemTypeDesc->GetTypeName() + ">";
	}

	virtual void Dump(const void* obj, const size_t indentLevel) const override
	{
		const size_t numItems = GetSize(obj);
		std::cout << GetTypeName();
		std::cout << std::endl << "{";
		for (size_t iter = 0; iter < numItems; ++iter)
		{
			std::cout << std::string(4 * (indentLevel + 1), ' ') << "[" << index << "] ";
			m_ItemTypeDesc->Dump(GetItem(obj, index), indentLevel + 1);
			std::cout << std::endl;
		}
		std::cout << "}" << std::endl;
	}
};