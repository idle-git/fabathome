// The Xylotex amplifier generates 1/8 steps by default, so adjust distance per step here
; written by Evan Malone, May 8, 2007

//////////////////FREQUENTLY CHANGED PARAMETERS//////////////////////////////////////////////////////

DESCRIPTION 	10cc Syringe (EFD 5111LL-B), Amber Needle, Left of two, Silver-filled silicone
TIPDIAM		1.36				//[mm], internal diameter of syringe needle/tip
PATHWIDTH	1.5				//[mm] width of stream of material deposited
PATHHEIGHT	0.49				//[mm] height of layers of material deposited
PUSHOUT		0.13  				//[seconds] early dispensing to start flow quickly
SUCKBACK	0.13				//[seconds] reverse plunger motion to stop flow quickly
SUCKBACKDELAY	0.1				//[seconde] delay in onset of suckback 
DEPOSITIONRATE  0.0043				//(mm plunger motion per mm of path length)
CLEARANCE	2.0				//[mm] clearance between tip and last layer when traversing
PATHSPEED	6				//[mm/s] speed along paths when depositing material
PAUSEPATHS	30				//number of paths after which to trigger an automatic pause

//////////////////RARELY CHANGED PARAMETERS//////////////////////////////////////////////////////////

TOOLGEOM	New2SyringeTool.STL 		//name of the stl file describing the tool body geometry
TOOLOFFSET	200 -220 -151			//dx dy dz graphics offset of tool body
TOOLCOLOR	0.1 0.1 0.1 0.5 		//R G B Alpha in range 0-1 (alpha=transparency)
BARRELGEOM	New2Syringe10ccBarrelLeft.STL  	//name of the stl file describing the syringe barrel geometry
BARRELOFFSET	0 0 -10				//dx dy dz graphics offset of syringe barrel
BARRELCOLOR	0.2 0.2 0.2 0.5			//R G B Alpha in range 0-1 (alpha=transparency)
BARRELDIAM	15.8				//[mm] internal diameter of syringe barrel
TIPGEOM		New2SyringeAmberNeedleLeft.STL 	//name of the stl file describing the nozzle/needle geometry
TIPOFFSET	0 0 0				//dx dy dz graphics offset of syringe nozzle/needle
TIPCOLOR	1 0 0 0.9			//R G B Alpha in range 0-1 (alpha=transparency)
TIPPOINT	99,-332.478,-60			//x,y,z tip location in geometry file coordinates
PLUNGERGEOM	New2Syringe10ccPlungerLeft.STL	//name of the stl file describing the syringe plunger geometry
PLUNGEROFFSET	0 0 80				//dx dy dz graphics offset of syringe plunger
PLUNGERCOLOR	0 1 0 0.5			//R G B Alpha in range 0-1 (alpha=transparency)
DIRECTION	0 0 -1				//orientation of graphical display of motion of plunger
VOLUME		10				//[mL] volume of syringe barrel
MOTOR		3 -1 0.000396875		//amplifier axis #, axis direction(+/-1), mm per (1/8) step
RANGE		0 83 0 				//[mm] start end home of graphical range of motion for plunger
BACKFILL	2 				//[mm] maximum depth allowed for backfill deposition (NOT YET IMPLEMENTED)
LIMITSWITCH	0 0 				//+direction -direction (0 -> limit switch not connected; 1 if it is)
INCREMENT	0.1 				//[mm] default distance to move plunger in manual jog
