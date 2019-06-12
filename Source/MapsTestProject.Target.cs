// Copyright (c) 2018 Nineva Studios

using UnrealBuildTool;
using System.Collections.Generic;

public class MapsTestProjectTarget : TargetRules
{
	public MapsTestProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "MapsTestProject" } );

        // If you are experiencing errors like "pointer beeing freed was not allocated"
        // uncomment these lines and add the similar lines to the Engine/UE4/Source/UE4Game.Target.cs
        /*
        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
           GlobalDefinitions.Add("FORCE_ANSI_ALLOCATOR=1");
        }*/
    }
}
