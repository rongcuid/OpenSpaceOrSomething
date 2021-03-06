// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class OpenSpaceOrSomething : ModuleRules
{
	public OpenSpaceOrSomething(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CISQLite3" });

		PrivateDependencyModuleNames.AddRange(new string[] { "CISQLite3" });

		//  using Slate UI for the main menu
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
 		PrivateIncludePaths.Add( "../Physics" );	 		
		//  PrivateIncludePaths.Add( "../../ThirdParty/eigen" );		
		// PrivateIncludePaths.Add( "../../ThirdParty/boost_1_68_0" );
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
