using UnityEngine;
using UnityEditor;
using System.Text;

namespace GirafflingHook
{
	[System.Flags]
	public enum StagePartsType
	{
		Wall = 0b00001,
		GiraffePoint = 0b00010,
	}

	public class GHStageConverter : MonoBehaviour
	{
		[Tooltip("グラッフポイントとするゲームオブジェクト名の接頭辞")]
		public string giraffePointPrefix;
		[Tooltip("変換対象とするルートトランスフォーム")]
		public Transform stageRootTransform;
		[Tooltip("ステージパーツの変換有無オプション")]
		public StagePartsType convertPartsTypes;
	}

#if UNITY_EDITOR
	[CustomEditor(typeof(GHStageConverter))]
	public class GHStageEditor : Editor
	{

		private static string giraffePointPrefix = "";

		public override void OnInspectorGUI()
		{
			base.OnInspectorGUI();

			var t = target as GHStageConverter;

			giraffePointPrefix = t.giraffePointPrefix;

			if (GUILayout.Button("Convert"))
			{
				var outCode = new StringBuilder();
				ConvertChilds(t.stageRootTransform, ref outCode);
				Debug.Log(outCode);
			}

			void ConvertChilds(Transform parent, ref StringBuilder builder)
			{
				foreach (Transform child in parent)
				{
					var type = child.name[..giraffePointPrefix.Length] == giraffePointPrefix
						? StagePartsType.GiraffePoint
						: StagePartsType.Wall;

					if (t.convertPartsTypes.HasFlag(type) == false)
					{
						continue;
					}

					builder.AppendLine(ConvertCpp(child, type));
					ConvertChilds(child, ref builder);
				}
			}
		}

		static string ConvertCpp(Transform transform, StagePartsType type)
		{
			return type switch
			{
				StagePartsType.GiraffePoint => string.Join("\n", new string[]
					{
					$"\tInstantiate<GiraffePoint>(",
					$"\t\t\"{transform.name}\",",
					$"\t\tVector3{{ {transform.position.x * 100f:f4}f, {transform.position.y * 100f:f4}f, {transform.position.z * 100f:f4}f }});",
					}),
				StagePartsType.Wall => string.Join("\n", new string[]
					{
					$"\tInstantiate<StageBoard>(",
					$"\t\t\"{transform.name}\",",
					$"\t\tVector3{{ {transform.position.x * 100f:f4}f, {transform.position.y * 100f:f4}f, {transform.position.z * 100f:f4}f }},",
					$"\t\tVector3{{ {transform.localScale.x * 100f:f4}f, {transform.localScale.y * 100f:f4}f, {transform.localScale.z * 100f:f4}f }});",
					}),
				_ => ""
			};
		}
	}
#endif
}