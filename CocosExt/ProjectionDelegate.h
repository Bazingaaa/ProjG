
#ifndef PROJECTION_DELEGATE_H__
#define PROJECTION_DELEGATE_H__


#include "CCProtocols.h"

namespace ProjG
{

using namespace cocos2d;

class ProjectionDelegate : public CCDirectorDelegate
{
public:

	ProjectionDelegate();
	~ProjectionDelegate();

	///<override
	virtual void updateProjection();

	void setCenter( float fX, float fY );

	void resetCenter( );

	CCPoint getCenter() const { return m_center; }

	static ProjectionDelegate* sharedPointer();

protected:

	///<the origin point of projeciton view
	CCPoint m_center;
};

};

#endif

